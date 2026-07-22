==========================================
常见问题与回答 (效果篇)
==========================================

.. important::
    macOS 下使用 OpenGL 时发生的效果问题不属于支持范围（适用于 macOS 10.13 以下或明确将渲染器设置为 OpenGL 的情况）。
   请切换到 Metal 后再使用。

非效果类的常见问题与回答请参考「:doc:`faq`」。与故障相关的内容请参考「:doc:`trouble_shooting`」。

可以加载效果吗？
============================================================

可以。与模型或附件同时加载。详情请参阅 :ref:`3F20FD13-9F9B-49FD-9072-0DE3FE50CE58` 或
:ref:`14C11FDE-A0FC-4415-A408-383B0132F735`。

后期效果类及不太复杂的效果基本都能加载，但由于硬件（尤其是 GPU）环境的差异，不保证与 MME 结果一致。

.. _596AB6F3-51F6-4C4C-8A0A-5428B6381499:

显示为品红色
============================================================

满足以下所有条件时，视口画面会显示为品红色，无法正常显示。其他 GPU 上不会发生此现象，因此认为是 Apple Silicon GPU 特有的问题。

* 使用搭载 Apple Silicon 的 Mac
* 启用了「:ref:`6D009308-F906-4BFB-B118-17DB0B526DA0`」

  * 视频导出的抗锯齿设置也同样
  * 禁用时不会发生

* 使用了通过透明度叠加方式的效果

  * 具体例子包括 XDOF，但当然也存在其他例子

如果符合上述情况并显示为品红色，请采取以下措施：

* 禁用「:ref:`6D009308-F906-4BFB-B118-17DB0B526DA0`」
* 使用以下介绍的抗锯齿后期效果代替抗锯齿设置

  * `o_DLAA <https://okoneya.jp/mmd_files/#o_DLAA>`_
  * `FXAA <https://github.com/MikuMikuShaders/FXAA>`_
  * `SMAA <https://github.com/MikuMikuShaders/SMAA>`_

.. _986802EC-851B-46B8-A7D0-287AA1294F0E:

找不到效果合集...
============================================================

.. note::
    效果合集是在实现效果插件之前，nanoem 专用的效果包。
    由于只能在 OpenGL 上使用，并且以二进制形式提供无法修改，现已停止提供。

效果合集已于 2020/8/31 停止分发。也不再进行维护，请使用以下原始来源：

- otamon 的 `Okoneya <https://okoneya.jp/mmd_files/>`_
- sovoro 的 `效果集放置处 <https://onedrive.live.com/?id=EF581C37A4524EDA%21108&cid=EF581C37A4524EDA>`_

ray-mmd 可以用吗？
============================================================

可以。但有条件。

.. warning::
    导出图像或视频时请禁用抗锯齿。

.. warning::
    在高分辨率下使用时，实际上必须使用 iMac Pro 或 `外置 GPU 的 Mac <https://support.apple.com/zh-cn/HT208544>`_。
    （参考：`MBP 13 英寸 2018 年款 <https://support.apple.com/kb/SP775>`_ 上无外置 GPU 且不改变窗口大小时低于 20FPS）

    此外，即使切换到低分辨率运行，也建议在带 GPU 的 iMac 或 MacBook Pro 15 英寸上使用。

.. note::
    由于技术规格问题，在 OpenGL 上无法正常运行

从 1.22.0 开始可以临时使用，但无法直接加载，需要修改文件。
macOS 需要将渲染器切换到 Metal，请从「设置」中将渲染器切换到 Metal。
（不支持 Metal 时无法切换）

注意事项中已说明，ray-mmd 由于特性原因性能要求非常高，请确认您的机器配置。
如果不符合要求，nanoem 会变得非常卡顿，可能不得不重启。

修改位置
-------------------------------------------------------

.. important::
    不限于 ray-mmd，修改效果时请备份以便恢复。
    此外，macOS 下使用文本编辑器编辑时，换行部分可能无法正确保存，导致加载时出错。

请使用 `Visual Studio Code <https://azure.microsoft.com/products/visual-studio-code/>`_ 等编程用编辑器，将以下文件中 ``FOG_ENABLE`` 的值从 1 改为 0，然后加载 ray-mmd 并调整效果分配。

.. code-block:: none
   :caption: ray.conf

   #define FOG_ENABLE 0

1.22.3 以下由于问题需要进一步将 ``Sky*box*`` 改为小写 ``sky*box*``，共需修改 3 处
（1.22.3 之后不需要）。

.. code-block:: none
   :caption: Shader/textures.fxsub

   "sky*box*.* =./Skybox/skylighting_none.fx;"

ikPolishShader 可以用吗？
============================================================

.. warning::
    重量与 ray-mmd 相当或更高

28.0 开始可用。但有一些注意事项：

* ikPolishShader v0.26 支持高质量 (2)

  * 默认的自定义设置 3 无法编译

* ikPolishShader v0.27 仅支持低质量 (1)

  * 普通 (2) 存在显示问题
  * 高质量 (3) 或默认的自定义设置 (0) 会崩溃

0.26 和 0.27 之间存在不兼容的显示更改，两者均已确认。

MotionBlur 系列不工作...
============================================================

需要部分修改。这是由于 nanoem 使用的渲染后端与 MMD 的渲染后端 (DirectX9) 的光栅化规格差异造成的。[#f1]_

.. caution::
    28.1 及之前，即使进行以下修改，在两个以上模型存在时使用 MotionBlur 也无法正常工作。
    此问题已在 28.2 中修复。

以 Soboro 的 MotionBlur2 为例，编辑 ``VelocityMap.fx``，在「从这里添加」行到「到这里」部分添加以下内容即可正常使用。

.. code-block:: none
   :caption: VelocityMap.fx:343

   Out.Pos.xy = (tpos * 2 - 1) * float2(1,-1);
   Out.Pos.zw = float2(0, 1);

   // 从这里添加
   #if defined(NANOEM)
   Out.Pos.x += VPBufOffset;
   Out.Pos.y -= VPBufOffset;
   #endif
   // 到这里

同样，使用运动模糊的 TrueCamera/TrueCameraLX 的文件
``TrueCameraObject.fx`` 或 ``TCLX_Object.fxsub`` 中修改的行位置不同，但修改内容相同。

出现 ``'#' : invalid directive``
============================================================

这是因为未实现以下代码时会发生：

.. code-block:: none

  #define some_macro(n) replaced_result_##n

这是一种称为字符串拼接的处理，删除上述 ``define`` 行后，例如在使用时：

.. code-block:: none

  some_macro(test)

请将替换后的字符串应用到所有使用位置：

.. code-block:: none

  replaced_result_test

详情请参考 `Token-pasting operator (##) <https://docs.microsoft.com/zh-cn/cpp/preprocessor/token-pasting-operator-hash-hash>`_

画面像卡住了一样显示
============================================================

部分效果在切换视口时没有清除处理，导致视口看起来像卡住了一样。解决方法需要添加清除处理。

已确认存在该问题的 `DropShadow <http://www.nicovideo.jp/watch/sm19160219>`_ 需要进行以下修改：

.. code-block:: none
   :caption: DropShadow.fx:212

   "RenderColorTarget0=;"
       "RenderDepthStencilTarget=;"
       // 从这里添加
       #if defined(NANOEM)
       "ClearSetColor=ClearColor;"
       "ClearSetDepth=ClearDepth;"
       "Clear=Color;"
       "Clear=Depth;"
       #endif
       // 到这里
       "Pass=Gaussian_Y;"

如何判断是在 nanoem 上运行还是在 MME 上运行？
============================================================

``NANOEM`` 宏已预先定义，可以通过是否存在来判断。

此外，nanoem 会根据运行时的渲染器，从 MME 进行转换的需要，定义了表示转换目标着色器格式的宏。

这些宏均在定义后，值为 1 表示目标格式，值为 0 表示非目标格式，
因此不仅需要判断宏是否存在，还需要判断数值。

.. csv-table::

  宏名,对应的渲染器,转换后的着色器格式（语言）
  ``NANOEM_OUTPUT_SHADER_LANGUAGE_GLSL``,OpenGL,GLSL
  ``NANOEM_OUTPUT_SHADER_LANGUAGE_ESSL``,OpenGL (ES),GLSL
  ``NANOEM_OUTPUT_SHADER_LANGUAGE_HLSL``,DirectX,HLSL
  ``NANOEM_OUTPUT_SHADER_LANGUAGE_MSL``,Metal,MSL
  ``NANOEM_OUTPUT_SHADER_LANGUAGE_SPIRV``,(将来预留),SPIR-V

.. [#f1] 技术上，nanoem 在 ``Draw=Buffer`` 时会先在顶点着色器前有意识地引起子像素偏移，通过顶点着色器处理使其归零来吸收差异，但像运动模糊中使用的顶点纹理获取等情况属于例外，需要修改。
