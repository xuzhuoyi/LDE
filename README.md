LDE
===
LDE，全名为 L Desktop Environment，可在 i386/amd64/mipsel(龙芯)/armv5/armv7 等平台上执行。最近，LDE正在准备向 iOS/Android 移动平台进行移植。LDE 项目旨在向用户提供一个低硬件门槛的桌面环境，在轻量化的前提下，尽可能实现更强大的功能。LDE 以 Qt 5 作为图形界面库，有强大的移植性，在 mipsel 以外的平台也可编译运行。LDE 提供了一些配套的可独立运行元件。LDE 使用 Openbox 为其默认视窗管理器，并且希望能够提供一个建立在可独立的套件上的轻巧而快速的桌面。
一些信息
---
### 源码包括
* LooFM 文件管理器，提供多种视图模式，即将推出面板功能。
* Looplorer 2 网页浏览器，基于 Webkit 设计的浏览器，重写上一版几乎所有代码，针对小内存设备优化。
* LCalc 计算器。
* LooFTP FTP 客户端。（基于 QtFtp）
* InitLDE 会话管理器，当使用者启动会话时建立桌面环境并自动启动程序的工具，提供对配置文件的管理功能。
* Looget 可指定存储位置，带进度条的下载工具。
* Lootepad 文字编辑器，基于 Qt 的文本编辑器。最新的版本支持恢复功能。
* Loogout 注销管理器。
* LRun 程序快速启动器。
* Ldeabout 内嵌于 LDE 软件中，显示 LDE 版本、作者等信息的模块。
* Ldecc LDE 控制中心，控制硬件与软件的各项设置。

### 已经测试支持的Linux系统/版本:
* Linux Mint 16/17/17.1
* Debian stable/testing/sid
* Gentoo
* Arch Linux
* OpenSuse 13.1/Factory
* Ubuntu 13.10-15.04 alpha 1

LDE 理论上支持所有 Linux 发行版

###已经测试编译通过的平台:
* MIPS (little endian)
* amd64
* i386

###LDE 即将移植到以下平台
* armv7
* iphoneos-arm
* armv5

其他平台可自行测试。
编译与安装
---
### 编译安装


### 二进制安装包安装
用户可以从 Github 的 Releases 中获取已编译完成的二进制安装包。

同一目录下的 ldemanual.txt/ldemanual.abw 是两种格式的用户手册，里面有安装方法。
共同开发
---
### 贡献代码
LDE 使用 Git 作为版本控制系统. 我们所有的代码都可以在 Github 找到

你可以直接从 Github Clone 一份 LDE 的源码

    git clone https://github.com/xuzhuoyi/LDE/
Git 的更多信息，参见官方网站: http://git-scm.com/
### 撰写文档
ldemanual.txt/ldemanual.abw 是两种格式的用户手册，你可以修改或添加里面的内容
### 报告 Bugs
我们所有的问题都记录在 GitHub 上。
