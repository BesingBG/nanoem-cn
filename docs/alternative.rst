=======================================================
macOS 上使用 MMD 的方法
=======================================================

.. important::
    如果只是在 macOS 上使用 nanoem，则无需阅读本文档

.. warning::
  ※ 这部分不是关于 Mac，而是关于 Windows PC 的内容

  第12代及之后的 Intel CPU 已不再原生支持 DirectX 9 [#f1]_ [#f2]_。此外，截至2022年8月尚未销售的 Intel 外置显卡 Intel Arc GPU 也存在同样问题。

  如果符合以上任一情况并尝试使用 MMD，预览画面将无法正常工作，因此实际上必须使用 Intel 以外的外置显卡。遗憾的是，这不是重新安装 Windows 或必要的运行时可以解决的问题。

  如果您使用的是笔记本电脑等无法直接安装显卡的环境，则需要使用外置 GPU 扩展盒。

.. note::
  ※ 这部分不是关于 Mac，而是关于 Windows PC 的内容

  * 如果想舒适地使用 MMD，建议使用台式机而非笔记本

    * 因为可以使用对 MMD 至关重要的高性能显卡
    * 如果非得用笔记本，至少应选择 15 英寸以上

      * 小于此尺寸会因物理限制而无法使用高性能显卡

  * 选择适合 MMD 的 Windows 机器的要点

    * 不知道如何选择时，请选择游戏用或 VR Ready 的机型
    * 购买预算至少 12 万日元，最好准备 20 万日元以上

      * 便宜也能运行，但如果想大量使用效果，可能会后悔

    * 预算有限且只能选笔记本时，可以从「`面向学生游戏开发者的低价高性能笔记本 <https://github.com/Reputeless/Laptops>`_」中选择

  * 详情请参考「`MMD 的电脑选择 <https://3d-arts.misanyan.com/2567>`_」

    2021年1月末，Microsoft 临时删除了 DirectX9 最终用户运行时的安装程序下载 [#f3]_，现已恢复提供。

    只要 x86 继续存在，MMD 的运行环境就不会消失，但考虑到 Mac 向 Apple Silicon 迁移，Windows 也可能跟随其他 CPU 的潮流，未来几年内「如预期般」运行的环境可能会减少。
    （关于 MMD 面临的严峻情况，请参阅「:ref:`10CEA069-F59B-4596-B8D7-2F788303F611`」）

虽然与 nanoem 无直接关系，但这里说明在 macOS 上使用 MMD 的方法。

使用 BootCamp
==========================================

.. note::
    `仅 Intel Mac 可用的方法 <https://support.apple.com/zh-cn/HT201468>`_。Apple Silicon Mac 无法使用。

使用 macOS 附带的 BootCamp 在其上运行 Windows 来使用 MMD 的方法。
如果以 Windows 为主、偶尔使用 macOS，这种方法最为合适。

* 优点

  * 虽然是 Mac，但可以当作 Windows 机器使用
  * 可以充分利用最大性能

* 缺点

  * 必须购买 Windows 许可
  * macOS 和 Windows 只能在启动时切换
  * 需要为 BootCamp 划分专用分区
  * macOS 版本与对应的 Windows 版本紧密绑定
  * `不支持外置显卡 <https://support.apple.com/zh-cn/HT208544>`_

    * 使用 MacBook Air 或 MacBook Pro 时需注意这一点

使用虚拟机
==========================================

.. note::
    Windows11 之后可通过 Parallels Desktop 支持 Apple Silicon Mac，但基于以下原因，建议直接使用 x86 CPU 的 PC 以获得更稳定的运行体验，不推荐此方法。

   * 效果出现问题后难以修复
   * 由于是 x86 模拟运行，速度会变慢

     * 物理模拟尤其容易受到性能影响

使用免费或付费的虚拟机软件，在其上安装 Windows 来使用 MMD 的方法。
代表性的虚拟机软件如下（🈶 表示仅付费版）：

- `VMware Fusion <https://www.vmware.com/jp/products/fusion.html>`_ 🈶
- `Parallels Desktop <https://www.parallels.com/jp/products/desktop/>`_ 🈶
- `VirtualBox <https://www.virtualbox.org/>`_

从使用经验来看，实际上只能选择前两者之一。如果以 macOS 为主并同时使用 Windows，这种方法比较好。

优点
------------------------------------------

* 切换简单，可以在运行 macOS 的同时使用 Windows
* 无需分区，迁移到其他 Mac 只需复制文件

  * 但将文件移动到其他 Mac 上运行时需要重新激活 Windows 许可

* 不依赖 Windows 版本

缺点
------------------------------------------

* 必须购买 Windows 许可
* （付费版）必须购买虚拟机许可
* 由于需要经过虚拟机，性能相比 BootCamp 较差

使用 Unity + MMD4Mechanim
==========================================

通过游戏引擎 `Unity <https://www.unity3d.com>`_ 及其插件 `MMD4Mechanim <http://stereoarts.jp>`_ 导入模型和运动来运行的方法。

优点
------------------------------------------

* 无需使用 Windows，完全无许可成本
* 可以搭建 VRM 输出环境

缺点
------------------------------------------

* 安装体积非常大 (2GB 以上)
* 操作方法完全不同，需要重新学习

  * Unity 最新版本也可以选择中文版，但基本 UI 为英文

    * 搜索到的文档也大多以英文为前提

  * MMD4Mechanim 只能加载模型或运动，无法从零创建运动并输出

* 模型作者的政策可能禁止使用此方法

  * 请务必确认模型附带的 README 是否允许在 Unity 上使用

    * 在 Unity 上的使用通常被视为超出预期用途

  * 上述问题常见于女性向二次创作模型

使用 Wine
==========================================

通过模拟 Windows API 来运行 Windows 应用程序的软件 `Wine <https://www.winehq.org>`_ 来运行的方法。
商业版 `CrossOver Mac <https://www.codeweavers.com/>`_ 也存在，但实质上只有英文版。

优点
------------------------------------------

* 无需使用 Windows，完全无许可成本

  * 可直接在 macOS 上运行

缺点
------------------------------------------

* 应用程序的外观和操作感与 macOS 差异很大
* 使用经验极少，信息匮乏

  * 无法运行时的解决方法需要自行查找
  * `AppDB 显示运行评级为 Bronze 或 Silver <https://appdb.winehq.org/objectManager.php?sClass=application&iId=13443>`_

.. [#f1] https://www.intel.co.jp/content/www/jp/ja/support/articles/000091238/graphics.html
.. [#f2] 可以使用 `D3D9On12 <https://github.com/microsoft/D3D9On12>`_，但需要应用程序支持，因此 MMD 无法使用
.. [#f3] https://www.gamespark.jp/article/2021/02/19/106238.html
