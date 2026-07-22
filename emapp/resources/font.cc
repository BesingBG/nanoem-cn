/*
   Copyright (c) 2015-2023 hkrn All rights reserved

   This file is part of emapp component and it's licensed under Mozilla Public License. see LICENSE.md for more details.
 */

#include "emapp/ResourceBundle.h"

#include "imgui/imgui.h"
#include "lz4/lib/lz4.h"

#include "emapp/private/resources/font_awesome.h"
#include "emapp/private/resources/noto_sans_sc.h"

namespace nanoem {
namespace resources {

ImFont *
initializeTextFont(ImFontAtlas *fontAtlas, nanoem_f32_t pointSize, void *ranges)
{
    static const ImWchar glyphs[] = {
        0x0020, 0x007E, 0x00A0, 0x00FF,
        0x0100, 0x024F, 0x02B0, 0x02FF, 0x0300, 0x036F,
        0x0370, 0x03FF, 0x0400, 0x04FF, 0x0500, 0x052F,
        0x2000, 0x206F, 0x2070, 0x209F, 0x20A0, 0x20CF, 0x20D0, 0x20FF,
        0x2100, 0x214F, 0x2150, 0x218F,
        0x2190, 0x21FF, 0x2200, 0x22FF, 0x2300, 0x23FF,
        0x2400, 0x243F, 0x2440, 0x245F,
        0x2460, 0x24FF, 0x2500, 0x257F, 0x2580, 0x259F,
        0x25A0, 0x25FF, 0x2600, 0x26FF, 0x2700, 0x27BF,
        0x27C0, 0x27EF, 0x27F0, 0x27FF,
        0x2800, 0x28FF, 0x2900, 0x297F, 0x2980, 0x29FF,
        0x2A00, 0x2AFF, 0x2B00, 0x2BFF,
        0x2C00, 0x2C5F, 0x2C60, 0x2C7F,
        0x2E00, 0x2E7F, 0x2E80, 0x2EFF, 0x2F00, 0x2FDF,
        0x2FF0, 0x2FFF,
        0x3000, 0x303F, 0x3040, 0x309F, 0x30A0, 0x30FF,
        0x3100, 0x312F, 0x3130, 0x318F, 0x3190, 0x319F,
        0x31A0, 0x31BF, 0x31C0, 0x31EF, 0x31F0, 0x31FF,
        0x3200, 0x32FF, 0x3300, 0x33FF,
        0x3400, 0x4DBF, 0x4E00, 0x9FFF,
        0xA000, 0xA4CF, 0xA4D0, 0xA4FF,
        0xA500, 0xA63F, 0xA640, 0xA69F,
        0xA700, 0xA71F, 0xA720, 0xA7FF,
        0xA800, 0xA82F, 0xA840, 0xA87F, 0xA880, 0xA8DF, 0xA8E0, 0xA8FF,
        0xA900, 0xA92F, 0xA930, 0xA95F, 0xA960, 0xA97F,
        0xA980, 0xA9DF, 0xAA00, 0xAA5F, 0xAA60, 0xAA7F, 0xAA80, 0xAADF,
        0xAB00, 0xAB2F, 0xAB30, 0xAB6F, 0xAB70, 0xABBF, 0xABC0, 0xABFF,
        0xAC00, 0xD7AF,
        0xF900, 0xFAFF, 0xFB00, 0xFB06, 0xFB13, 0xFB17,
        0xFB50, 0xFDFF, 0xFE00, 0xFE0F, 0xFE10, 0xFE1F,
        0xFE20, 0xFE2F, 0xFE30, 0xFE4F, 0xFE50, 0xFE6F,
        0xFE70, 0xFEFF, 0xFF00, 0xFFEF, 0xFFF0, 0xFFFF,
    };
    ImFontGlyphRangesBuilder builder;
    for (int i = 0; i < IM_ARRAYSIZE(glyphs); i += 2) {
        builder.AddRanges(&glyphs[i]);
    }
    ImVector<ImWchar> *rangesPtr = static_cast<ImVector<ImWchar> *>(ranges);
    builder.BuildRanges(rangesPtr);
    char *bytes = static_cast<char *>(ImGui::MemAlloc(noto_sans_sc_ttf_inflated_size));
    LZ4_decompress_safe(reinterpret_cast<const char *>(noto_sans_sc_ttf_data),
        bytes, noto_sans_sc_ttf_deflated_size, noto_sans_sc_ttf_inflated_size);
    ImFontConfig config;
    config.FontData = bytes;
    config.FontDataSize = noto_sans_sc_ttf_inflated_size;
    config.SizePixels = pointSize;
    config.GlyphRanges = rangesPtr->Data;
    return fontAtlas->AddFont(&config);
}

ImFont *
initializeIconFont(ImFontAtlas *fontAtlas, nanoem_f32_t pointSize)
{
    static const ImWchar ranges[] = {
        0xf000, 0xf3ff, 0,
    };
    char *bytes = static_cast<char *>(ImGui::MemAlloc(font_awesome_ttf_inflated_size));
    LZ4_decompress_safe(reinterpret_cast<const char *>(font_awesome_ttf_data), bytes,
        font_awesome_ttf_deflated_size, font_awesome_ttf_inflated_size);
    ImFontConfig config;
    config.FontData = bytes;
    config.FontDataSize = font_awesome_ttf_inflated_size;
    config.SizePixels = pointSize;
    config.GlyphRanges = ranges;
    config.MergeMode = true;
    return fontAtlas->AddFont(&config);
}

} /* namespace resources */
} /* namespace nanoem */
