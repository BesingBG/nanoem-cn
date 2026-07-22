=======================================================
nanoem 使用手册
=======================================================

nanoem 是 `MikuMikuDance <https://sites.google.com/view/vpvp/>`_（以下简称 MMD）的兼容实现应用程序，可以加载、编辑和保存 MMD 使用的模型和运动数据。

nanoem 在保持与 MMD 兼容的同时，还以以下目标进行开发：

- 可移植性

  - 除主要目标的 macOS 外，还可在 Windows 上运行
  - 虽然未公开发布，但也可在 Linux / Raspberry Pi / Windows 10 on ARM64 上运行 [#f1]_

- 启动轻量

  - 约 1 秒内启动 [#f2]_

- 体积小巧

  - 约 10MB [#f3]_

.. toctree::
   :maxdepth: 2
   :caption: 目录

   install.rst
   guide.rst
   application.rst
   menu.rst
   preference.rst
   effect.rst
   plugin.rst
   faq.rst
   faq_effect.rst
   trouble_shooting.rst
   privacy.rst
   change_log.rst
   known_bugs.rst
   alternative.rst
   license.rst
   architecture.rst

.. [#f1] 如有需要请通过 :ref:`37420267-8E5A-41EA-A159-FFF490DF1D8D` 联系
.. [#f2] 虽然和 MMD 同样需要一定时间，但目标是能够像编辑器一样使用
.. [#f3] macOS 下的压缩包大小。31.0 之后由于采用通用二进制，体积约为原来的两倍
