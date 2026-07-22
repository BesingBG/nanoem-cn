==========================================
常见问题与回答
==========================================

.. note::
   有关效果的问题请参考「:doc:`faq_effect`」

这里汇总了使用 nanoem 时可能遇到的问题及其回答。出现问题时的处理方法请参考「:doc:`trouble_shooting`」。

如果这里没有涵盖到，请参考「:ref:`37420267-8E5A-41EA-A159-FFF490DF1D8D`」进行提问。

.. caution::
    也可以在 Twitter 上添加 `#nanoem <https://twitter.com/search?q=#nanoem>`_ 或 `#nanoem互助会 <https://twitter.com/search?q=#nanoem互助会>`_ 标签发推，但请注意开发者本人不会在此回复。

与 MikuMikuDance 的区别是什么？
=======================================================

.. important::
    nanoem 是 MikuMikuDance 的兼容实现，但 **并非 MikuMikuDance。** 因此不能替代 MikuMikuDance。

    其他兼容或类似运动编辑能力的实现还有：

   * `MikuMikuMoving <https://sites.google.com/site/mikumikumoving/>`_（简称 MMM）
   * `NexGiMa <https://sites.google.com/view/nexgima/Home>`_

    两者均基于 DirectX，仅支持 Windows。

* nanoem 使用 DirectX11，而 MikuMikuDance 使用 DirectX9
* 外观类似 MikuMikuDance，但无法还原细节操作体验
* 可以读取 MikuMikuDance 使用的绝大部分文件，但效果、IK 及物理模拟不具有完全的再现性

如果试图将其作为 MikuMikuDance 的简单替代品，第二和第三个原因会带来很大问题，建议放弃。
如果在 macOS 上想运行 MikuMikuDance 而不是 nanoem，请参考 :doc:`alternative`。

nanoem 特有的特点如下：

* 在利用 DirectX11 的同时，通过自实现的效果加载功能确保与 MME 的兼容性

  * 这是因为 MME 使用的技术依赖 DirectX9，无法在 DirectX11 中使用

    * MMM 的 DirectX11 版也因使用专属效果格式而无法使用 MME

  * 并非支持所有 MME 效果，有些无法加载

* 集成模型编辑功能

  * MikuMikuDance 也有部分功能，但仅限于物理模拟相关

* 支持高分辨率显示器，并通过 Per-Monitor V2 支持不同显示器 DPI 不同的环境
* 理论上原生支持 ARM64

可以进行模型编辑吗？
=======================================================

从 33.0 开始在一定程度上可以实现。但操作方法上与模型编辑的事实标准——实际上是唯一实现的 PMXEditor 有很大差异，无法以相同的操作感受使用。
此外，无法使用 PMXEditor 的插件（例外是「:ref:`CCDE11E1-3416-425D-80DF-A347F79E7BDD`」）。

虽然可以进行模型编辑，但与 PMXEditor 一样，原则上假设模型已预先基本成型后使用，从零开始制作极其困难。
因此，请使用以下建模软件，转换成 X/PMD/PMX 格式后再导入 nanoem。
以下软件均支持 Windows/macOS。

- `Blender <http://www.blender.org>`_

  - 需要安装 `mmd_tools <https://github.com/powroupi/blender_mmd_tools>`_ 插件
  - mmd_tools 安装时 ``Shared Toon Textures`` 设置所需的共享纹理文件夹不存在

    - 这是因为 nanoem 已将共享纹理直接集成到应用程序中
    - 请下载并解压 MikuMikuDance，指定其中的 ``Data`` 文件夹路径

- `Metasequoia <http://www.metaseq.net>`_

  - 以 PMD（非 PMX）格式输出需要付费版

- `Xismo <http://mqdl.jpn.org>`_

  - ver 2.0 之后不再支持 macOS
  - ver 1.x 也使用 OpenGL，未来可能无法运行

- `VRoid Studio <https://studio.vroid.com/>`_

  - 仅支持 VRM 输出，按「:ref:`EFC55993-3D0E-4D90-855F-860FBBA5A90F`」所述，无法直接在 nanoem 中加载

.. _28185A65-88E5-4C4C-BF60-41BBB5520B70:

可以进行视频编辑吗？
=======================================================

不行。需要进行视频编辑时，请使用以下专门用于视频编辑的软件。

- macOS

  - `iMovie <https://www.apple.com/jp/imovie/>`_
  - `Final Cut Pro <https://www.apple.com/jp/final-cut-pro/>`_ 🈶
  - `Adobe Premiere Pro <https://www.adobe.com/jp/products/premiere.html>`_ 🈶
  - `DaVinci Resolve <https://www.blackmagicdesign.com/jp/products/davinciresolve/>`_
  - `Javie <https://ja.osdn.net/projects/javie/>`_
  - `OpenShot Video Editor <https://www.openshot.org>`_
  - `Avidemux <http://avidemux.sourceforge.net>`_

- Windows

  - `Adobe Premiere Pro <https://www.adobe.com/jp/products/premiere.html>`_ 🈶
  - `AviUtl <http://spring-fragrance.mints.ne.jp/aviutl/>`_
  - `DaVinci Resolve <https://www.blackmagicdesign.com/jp/products/davinciresolve/>`_
  - `OpenShot Video Editor <https://www.openshot.org>`_
  - `Avidemux <http://avidemux.sourceforge.net>`_

※ 🈶 表示仅付费版

有教程视频吗？
=======================================================

没有。也没有制作的计划。开发者本人认为制作成本与收益不匹配。

可以商用吗？
=======================================================

首先，大前提是权责关系是乘法关系，严格来说是逻辑与关系，只要有一项不满足使用条件即为 NG。
这意味着项目中使用的模型、运动、附件、效果、音频、背景视频等所有资源都必须满足使用条件。

在此基础上回答：在满足上述使用条件的前提下，与 MikuMikuDance 相同，nanoem 本身无需取得商用许可。

最新版创建的项目能在旧版中加载吗？
=======================================================

如果文件格式为 nmm 则可以。保存也基本可行，但最新版的项目数据可能会丢失或以异常状态保存，因此在旧版中保存时请使用另存为。

其他格式的情况下，不保证最新版保存的数据能在旧版中加载或保存，即使可能也请尽量避免。

可以加载 MMD 的项目文件吗？
=======================================================

可以。根据项目文件的内容，可能会出现一些问题。

另外，也可以导出，但存在一些限制。详情请确认「:ref:`D90328CC-C39A-4854-BB48-B49039D8E31B`」。

.. _EFC55993-3D0E-4D90-855F-860FBBA5A90F:

VRoid Studio 制作的 VRM 可以加载吗？
=======================================================

不行。今后也没有计划实现。请使用 `VRoid→MMD变得简单了 <https://aideq.goat.me/bnbRNcrIfC>`_
或 `再次尝试使用 VRMtoPMXExporter【2019年4月版】 <https://aideq.goat.me/h70ydDLPP2>`_ 中的方法转换为 PMX。

.. caution::
    上述文章中提到的 ``VRM2PMXConverter`` 仅限 Windows，macOS 版只能使用 ``VRMtoPMXExporter``（即需要使用 Unity）。

即使使用上述工具，也不会创建分发运动中事实必需的半标准骨骼（取决于转换工具及版本，也有可能支持）。
此时可以使用为 nanoem 制作的「:ref:`CCDE11E1-3416-425D-80DF-A347F79E7BDD`」来创建。

.. _1AF55799-DCCF-4989-AA91-C186F073FDA0:

想要输出竖长图像或视频
=============================================================

需要 26.0 及以上版本的「保持视口宽高比」功能，按以下步骤可以输出竖长视频

.. note::
    竖长主要面向智能手机，但由于各终端分辨率不同，未提供分辨率预设

- 选择「项目」>「打开视口设置对话框」
- 将「输出尺寸」更改為所需分辨率
- 在图像或视频导出中进行以下设置

  - 输出分辨率选择「与视口相同」
  - 勾选「保持视口宽高比」
  - 27.1 以下且视频导出时，取消勾选「启用操作系统自带编码器」

- 点击 OK 按钮输出

.. _8DE98D42-1894-4002-B629-4D64580EF404:

想要输出带透明通道的视频
=============================================================

按以下步骤可以输出带透明通道的视频。

* 选择「项目」>「打开视口设置对话框」
* 勾选「启用透明背景」
* 视频导出时确认「启用操作系统自带编码器」已取消勾选
* 从 ``Plugins`` 选择 ``plugin_ffmpeg``，并进行以下设置

  * ``Video Codec`` 设为 ``UT Video Codec``
  * ``Video Pixel Format`` 设为 ``RGBA``
  * ``Audio Codec`` 设为 ``PCM``

* 点击 OK 指定文件名后导出

导出的带透明通道视频

* Windows 请安装 `Ut Video Codec Suite <http://umezawa.dyndns.info/wordpress/?cat=28>`_
* macOS 可以使用 macOS 的视频播放器 `IINA <https://iina.io/>`_ 播放确认

.. important::

    上述步骤中，以下两项缺一不可，否则无法导出带透明通道的视频：

    * 勾选「启用透明背景」
    * ``Video Pixel Format`` 设为 ``RGBA``

    效果（尤其是后期效果）也需要使用支持透明输出的效果。
    是否支持请查阅效果的 README 或使用说明书。

.. _2BEF62AC-4929-485B-9909-2BF027EBF2F8:

为了调整运动，想在开头插入静音
=============================================================

nanoem 不具备插入静音的功能。请使用 `Audacity <https://www.audacityteam.org>`_ 参考以下文章插入静音。

.. note::
    nanoem 以及 MMD 的运动以 1 秒 30 帧计算。因此每帧的采样数如下：

   * 音频采样率为 44100Hz 时为 **1470** (= 44100 / 30)
   * 音频采样率为 48000Hz 时为 **1600** (= 48000 / 30)

    例如要偏移 5 帧，音频采样率为 44100Hz 时指定 **7350** 个采样。

`Audacity 中在音乐中途添加静音部分的方法！<https://aprico-media.com/posts/5741>`_

如何让 nanoem 休眠？
=============================================================

macOS 版可采取以下任一方式使 nanoem 休眠，从而将 CPU/GPU 消耗降至最低：

* 最小化 nanoem 窗口
* 在其他应用程序窗口上覆盖 nanoem 窗口

Windows 版可通过最小化 nanoem 窗口获得同等效果。

与 MMDAI2/VPVM 有何不同？
=======================================================

.. note::
    MMDAI2/VPVM 是截至 2014 年分发的、与 nanoem 同开发者的 MMD 兼容实现。

    以 `MMDAgent <http://sourceforge.net/projects/mmdagent/>`_ 为源流，为支持 macOS 于 2010年1月 提供的实现是 MMDAI，
    在其基础上增加运动编辑功能的是 MMDAI2。VPVM 是复用 MMDAI2 基础实现派生开发的。

    目前两者均已停止开发和维护。

功能几乎相同，但主要区别如下：

* 支持 Metal

  * MMDAI2/VPVM 在设计上严重依赖 OpenGL，无法支持 Metal

* 支持 MME

  * MMDAI2/VPVM 使用外部库，与 MME 不兼容，因此需要制作专属效果文件，成为开发负担

此外，还有以下 MMDAI2/VPVM 不具备的功能，且 MMDAI2/VPVM 的实现问题在 nanoem 中已修复：

* 支持 PMM 加载
* 支持 SDEF

想给一个模型应用两个以上运动
=======================================================

.. note::
    1.15 之后默认已启用合并功能，无需任何操作

1.14 及之前，默认每个模型只能应用一个运动，
但启用「合并关键帧」后可以合成两个以上的运动。[#f3]_

#. 打开左侧面板的「模型」，选择要应用的模型
#. 点击「运动」，启用「合并关键帧」
#. 加载运动

如果舞蹈运动和口型运动是分开的，请使用上述方法。

想要旧版本
=======================================================

32.0.0 及之后可以从 `GitHub 的 All Releases <https://github.com/hkrn/nanoem/releases/>`_ 获取。这些与 bowlroll 分发的版本相同。

如果无论如何都需要更早的版本，请指定版本（仅限一个，不可多个）并说明使用旧版本的原因，
按照 :doc:`install` 的「问题反馈方式」发送。

想要卸载
=======================================================

macOS 请使用 `AppCleaner <https://freemacsoft.net/appcleaner/>`_ 搜索 `nanoem`，删除找到的所有文件。

.. warning::
    仅将 `nanoem.app` 扔进垃圾桶的方法会留下未删除文件，不推荐。

Windows 请将 nanoem.exe 所在文件夹和 ``%USERPROFILE%\AppData\Roaming\nanoem`` 文件夹一起扔进垃圾桶。

杂项问题
=======================================================

nanoem 怎么读？
-------------------------------------------------------

中文读作「纳米诶姆」。以下是各语言的读法：

================== =========
语言                读法
================== =========
日本語(ja_JP)       なのえむ
繁體字(zh_TW)       納米
简体字(zh_CN)       纳米
한글(ko_KR)         나노에무
================== =========

nanoem 之外，macOS 上还有能用的 MMD 兼容软件吗？
-------------------------------------------------------

要达到像 MikuMikuDance 那样使用的话，没有。而且今后很可能也不会有，原因如下：

* 本身制作难度极高

  * MikuMikuDance 依赖于 DirectX 生态系统，需要自行实现其对应功能
  * 此外还需要 GUI 应用程序及其他知识，制作所需的知识量巨大

    * 相当于同时制作一个游戏和一个游戏引擎所需的知识

  * 顺便一提，`MikuMikuMoving 的开发者也对 macOS 版的支持计划含糊其辞 <http://ch.nicovideo.jp/mogg/blomaga/ar1284791/9>`_

* macOS 用户数量少

  * macOS 的市场份额不到 Windows 的 1/10

* `VRM <https://vrm-consortium.org/>`_ 的出现

  * 虽然有人形限制，但基于行业标准，撰写本文时 (2018/5/27) 预计未来会进一步发展

一句话概括就是 **高风险低回报**。

可以用英语沟通吗？
-------------------------------------------------------

.. note::
    考虑到会通过 Google Translate 等翻译来阅读，此处特意用中文书写。

可以，但原则上用中文沟通回复更快。不过如果为了写中文而使用机器翻译，还不如直接用英语写。

有计划支持中文以外的语言吗？
-------------------------------------------------------

官方支持的语言只有中文和英文 [#f2]_，目前没有计划支持其他语言，但如果有能翻译成中文或英文以外语言的翻译者，也许有可能。

如果想申请成为翻译者，请通过 `@shimacpyon <https://twitter.com/shimacpyon>`_ 的反馈或 DM 联系。

有哪些人在使用？
-------------------------------------------------------

基于 Google Analytics 的使用情况结果如下（请参阅 :doc:`privacy`）：

- 由于最初是为 macOS 开发的应用程序，大多数用户使用 macOS
- 约 7 成来自国内（日本），约 3 成来自国外，最多的是美国

.. [#f1] 本义是「纳米」，直接音译。日文则为「年贡を納める」之意，含义不同
.. [#f2] UI 本身支持英文，但手册只有中文的矛盾
.. [#f3] 原则上关键帧不应重叠。如果发生冲突，优先应用已有的关键帧
