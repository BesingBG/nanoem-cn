=======================================================
安装
=======================================================

所需运行环境
=======================================================

macOS 版
-------------------------------------------------------

.. important::
    35.0 之后将仅提供 Apple Silicon 版，Intel Mac 版计划废除

- macOS 11.0 及以上且 64bit 环境（从 31.0 开始支持 Apple Silicon）[#f1]_

  - 请确认 `支持 Metal 的环境 <https://support.apple.com/zh-cn/HT205073>`_
  - `macOS 10.13.4 开始支持外接 GPU <https://support.apple.com/zh-cn/HT208544>`_，但在 nanoem 中未经验证
  - 即使低于 macOS 11.0，只要 macOS 10.13 及以上即可运行，但不属于支持范围

    - 34.8.1 及之前的版本在 10.9 及以上即可运行，但可能因硬件问题无法流畅运行，同样不属于支持范围

- 1280x800 以上分辨率

Windows 版
-------------------------------------------------------

.. important::
    Windows 版 nanoem 在 DirectX 11 上运行。因此无需安装 MMD 及相关工具所需的 DirectX 9 运行时。

- Windows7 及以上且 64bit 环境 [#f2]_

  - 需要安装 `Visual Studio 2017 的 Visual C++ 可再发行包 <https://support.microsoft.com/zh-cn/help/2977003/the-latest-supported-visual-c-downloads>`_

- 1280x800 以上分辨率

Linux 版
-------------------------------------------------------

.. caution::
    不包含在发布包中。因此仅限 `从源代码构建 <https://github.com/hkrn/nanoem/>`_

- 64bit 环境
- OpenGL 3.3 及以上或 OpenGL ES 3.0 及以上
- 1280x800 以上分辨率

关于 Retina 等高分屏环境
-------------------------------------------------------

nanoem 支持 Retina 等高分辨率环境，但高分辨率模式负载较大，如果感觉卡顿

  - macOS 版请使用「`低分辨率模式 <https://support.apple.com/zh-cn/HT202471>`_」打开。
  - Windows 版请降低显示设置的缩放比例 (DPI) 后运行。

使用条款
=======================================================

※ 本使用条款可能随时更改，恕不另行通知。

- 开发者及贡献者不对因使用 nanoem 而产生的任何索赔、损害或义务承担责任

  - nanoem 的 `源代码 <https://github.com/hkrn/nanoem>`_ 以 `Mozilla Public License 2.0 <https://licenses.opensource.jp/MPL-2.0/MPL-2.0.html>`_ 形式公开

- 同意 :doc:`privacy` 中的条款
- （过去曾存在禁止再分发的规定，现已删除）

下载方式
=======================================================

.. important::
  * 视为已同意上述「使用条款」
  * 下载方式今后可能会变更
  * 从旧版本升级时如需回退，请从 GitHub 下载过往版本

    * 与过去在 bowlroll 上分发的版本相同

* 从 github 或 bowlroll 任一下载（内容相同）

  * github 请从 `Releases <https://github.com/hkrn/nanoem/releases>`_ 页面下载
  * bowlroll 请从以下链接点击 `Download` 按钮

    * `macOS 版分发页 <https://bowlroll.net/file/71328>`_
    * `Windows 版分发页 <https://bowlroll.net/file/122592>`_

下载后的运行方法
-------------------------------------------------------

* 解压 zip 文件
* 将 ``nanoem`` 拖放到 ``Applications`` 文件夹 ※ 仅限 macOS 版

  * 会显示需要管理员权限的对话框
  * 如果您不是管理员，请拖放到个人文件夹中的「应用程序」文件夹

    * 如果个人文件夹中不存在「应用程序」文件夹，请创建该文件夹

* 点击 ``nanoem`` 启动

  * 如果无法打开，请参考 :ref:`0ACEC098-CB5E-40E2-99C5-01DB3BCBE080`

.. caution::
  macOS 版首次运行时会出现开发者未确认的警告对话框，这是正常现象。详情请查看「`在 Mac 上安全地打开 App <https://support.apple.com/zh-cn/HT202491>`_」的「如何打开未公证或来自未识别开发者的 App」。

安装后
=======================================================

需要帮助时
-------------------------------------------------------

在 Twitter 上添加 `#nanoem互助会 <https://twitter.com/search?q=%23nanoem互助会>`_ 标签发推，或许会有人帮忙。
但互助会标签采用开发者不介入的方针，如需直接联系开发者，请使用后述问题反馈方法中的 marshmallow。

Facebook 或 LINE 等平台只能询问可能知道的朋友了。

.. _37420267-8E5A-41EA-A159-FFF490DF1D8D:

问题反馈方式
-------------------------------------------------------

.. important::
    以前也通过「`Marshmallow <https://marshmallow-qa.com>`_」提供支持，但由于 2023年4月 Twitter 的形势问题，已将其移出支持范围。今后请使用 GitHub。

首先请确认「:doc:`faq`」或「:doc:`trouble_shooting`」，然后在「`GitHub Discussions 的 Q/A 板块 <https://github.com/hkrn/nanoem/discussions/categories/q-a>`_」中提问。

* 需要 GitHub 账户
* 由于服务性质，通常为英文，但 ``Discussions`` 标签页可以使用日文提问
* ``Issues`` 标签页原则上用英文回复，如需提交请使用英文

问题反馈时的注意事项
-------------------------------------------------------

- 以下内容有助于开发者调查。可能需要提供重现现象所需的文件。

  - 保存了项目但文件无法加载
  - 尝试导出图像或视频时每次都崩溃
  - 尝试加载附件/模型/运动时出错

.. important::
    以下情况不处理问题：

  * 启用物理模拟时模型穿透类问题
  * 在 macOS 10.9 (Mavericks) 到 10.12 (Sierra) 环境中运行时发生的问题
  * macOS 下使用 OpenGL :ref:`9816D13E-ADA9-44D9-A869-1F61537D7753` 时的效果使用相关问题

    * 使用效果时请切换到 Metal 后再使用

  此外，仅以个人用户身份进行调查，如果模型存在分发限制，根据限制程度可能无法调查模型。

.. warning::
  - 如果内容「从开发者角度看」过于粗糙，将不予处理

    - 例如「不知道为什么崩溃了，帮我处理一下」

  - 在 bowlroll 页面留言也不会回复

截图方法
-------------------------------------------------------

难以用文字说明的内容请截图。方法如下：

- 图像请参考 `Mac 截图方法 <https://support.apple.com/zh-cn/HT201361>`_
- 视频请参考 `录制屏幕 <https://support.apple.com/zh-cn/HT208721>`_

  - 使用 `RetroClip <https://www.realartists.com/retroclip/>`_ 可以像 Nintendo Switch 一样事后录制屏幕

.. [#f1] nanoem 也不例外，在 MacBook 上，同尺寸的 Apple Silicon 版性能明显优于 Intel 版。事实上，即使在高分辨率模式下，也能以 60FPS 运行重量级后期效果 `Ray-MMD <https://github.com/ray-cast/ray-mmd>`_
.. [#f2] 如果使用 N/KN 版本，需要根据 Windows 版本额外安装 Media Feature Pack
