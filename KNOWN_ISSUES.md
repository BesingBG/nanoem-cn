# Known Issues (Windows)

## Issue 1: Sub-windows cannot be clicked / tabs cannot be switched / menus cannot be clicked

### Symptoms
- Opening sub-windows (e.g., Preferences, export dialogs) renders them visually, but mouse clicks on their content have no effect
- Tab items within dialog windows cannot be switched
- Popup menus that appear during close/cancel operations cannot be clicked
- Clicks appear to be consumed by the main window instead of reaching the sub-window

### Root Cause

Two problems in `win32/src/MainWindow.cc` combine to cause this:

#### 1a. Mouse capture leak (`SetCapture` without paired `ReleaseCapture`)

**File:** `win32/src/MainWindow.cc`
**Lines:** ~1635 (SetCapture), ~1668 (ReleaseCapture)

```cpp
// handleMouseDown: unconditional capture
SetCapture(hwnd);

// handleMouseUp: conditional release — only when cursor is visible
if (!isCursorHidden()) {
    ReleaseCapture();  // ← NOT called when cursor is hidden
}
```

When the cursor is hidden (e.g., during 3D viewport orbit/navigation), `ReleaseCapture` is never called. The main HWND retains mouse capture indefinitely, causing all subsequent mouse messages (including clicks on sub-windows) to be redirected to the main window. ImGui sub-windows never receive the click events.

**Fix:** Ensure `ReleaseCapture()` is called in all cases, or use `WM_CAPTURECHANGED` to manage capture lifecycle properly.

#### 1b. Empty `WM_ACTIVATE` handler

**File:** `win32/src/MainWindow.cc`
**Lines:** ~494-499

```cpp
case WM_ACTIVATE: {
    // EMPTY — no DefWindowProcW call
    break;
}
```

`DefWindowProcW` is not called for `WM_ACTIVATE`, so Windows does not perform standard focus/activation processing. The OS focus state may become incorrect, causing ImGui to reject input on sub-windows.

**Fix:** Add `DefWindowProcW(hwnd, msg, wparam, lparam)` to the `WM_ACTIVATE` handler.

### Affected Files
- `win32/src/MainWindow.cc` (primary: mouse handlers, WM_ACTIVATE)
- `emapp/src/internal/ImGuiWindow.cc` (secondary: input routing)

### Severity
High — makes most sub-window interactions unusable on Windows.

---

## Issue 2: UI layout shifted upward, gap at bottom of window

### Symptoms
- The main UI content appears shifted upward, leaving a blank strip at the bottom of the window
- The gap size varies depending on display DPI scaling settings (125%, 150%, 175%)

### Root Cause

DPI scaling inconsistencies in the ImGui initialization and resize paths.

#### 2a. `FontGlobalScale` inconsistency between init and DPI change

**File:** `emapp/src/internal/ImGuiWindow.cc`
**Lines:** 1325 (init), 1835 (DPI change)

```cpp
// initialize() — DPR set correctly
io.FontGlobalScale = windowDevicePixelRatio;

// setDevicePixelRatio() — always reset to 1.0
io.FontGlobalScale = 1.0f;  // ← inconsistency
```

When DPI changes at runtime, `FontGlobalScale` is unconditionally reset to `1.0`, while during initial setup it was set to the actual device pixel ratio. This inconsistency causes font and layout sizes to be miscalculated after any DPI change event.

#### 2b. Floating-point truncation in DPI conversion

**File:** `win32/src/MainWindow.cc`
**Lines:** ~548

```cpp
const Vector2UI32 newSize(width * invertDevicePixelRatio, height * invertDevicePixelRatio);
```

At non-integer DPI scales (e.g., 150% → 1.5x), `width * (1/1.5)` produces fractional values that are truncated to integers by `Vector2UI32`. Accumulated rounding errors cause the window client area to be slightly smaller than expected, leaving a gap at the bottom.

#### 2c. `BaseNonModalDialogWindow` size scaling uses `DisplayFramebufferScale`

**File:** `emapp/src/internal/imgui/BaseNonModalDialogWindow.cc`
**Lines:** 103, 117

```cpp
const float scaleFactor = ImGui::GetIO().DisplayFramebufferScale.x;
```

Dialog window sizes are multiplied by this scale factor. At non-integer DPI settings, rounding in combination with the above issues can compound the layout error.

### Affected Files
- `emapp/src/internal/ImGuiWindow.cc` (`initialize()`, `setDevicePixelRatio()`)
- `win32/src/MainWindow.cc` (`WM_DPICHANGED` handler)
- `emapp/src/internal/imgui/BaseNonModalDialogWindow.cc` (`open()`)

### Severity
Medium — visual issue only, functionality unaffected. Most noticeable on 125%–175% DPI scaling.

---

## Notes

- These issues are present in the original upstream release (`nanoem-v34.10.0`). They are **not** introduced by the Chinese translation.
- Both issues are Windows-only (macOS uses a different windowing path via Cocoa and does not have these problems).
- Issue 1 (mouse capture) is the higher priority as it blocks essential UI interaction.
