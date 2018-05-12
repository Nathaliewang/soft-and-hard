<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Part3](#part3)
	* [自学linux基础](#自学linux基础)
		* [本地 虚拟机安装linux](#本地-虚拟机安装linux)
		* [作业](#作业)
	* [云服务器部署](#云服务器部署)
		* [作业](#作业-1)

<!-- /code_chunk_output -->
# Part3
这部分主要是将demo1部署到云服务器里。
## 自学linux基础
linux入门书籍是《鳥哥的 Linux 私房菜》[网上自学](http://linux.vbird.org)，学习的时候注意挑着学习，阅读的时候要明白哪些是会用到的多试一下，哪些短时间内用不到的就快速翻阅。
### 本地 虚拟机安装linux
[VirtualBox](https://pan.baidu.com/s/1XB6Lao8fwz4f88wzGqZnUA) 是一款开源虚拟机软件，大家可以利用它来安装linux，在本地上练习linux，尽可放心折腾，搞坏了重装即可。
@import "./images/VirtualBox安装Ubuntu.png"
### 作业
1. 使用VirtualBox安装Ubuntu，安装VirtualBox虚拟机增强功能，配置成桥接网卡。
2. 学习常用的linux命令，基本的vi操作。
3. 配置共享文件，实现把windows某个文件移到虚拟机里，并且在linux下修改保存，再移回到windows下。

## 云服务器部署
购买一台最低配置的云服务器，大学生可以验证身份后以学生价购买服务器，大约在10元一个月左右（这个价格可以说是高于成本的，人家可是亏本给你们学习的。）。国内云服务器以阿里云为首，腾讯云其次，大家可以从这两个里选一个购买并学习。由于我学生时代用的是腾讯云（当年我一元一个月用了两三年，那真叫爽。现在大约是10元左右。），我就以腾讯云为例[我的推广网址，能赚个几块钱推广费，谢谢大家支持哈](https://cloud.tencent.com/redirect.php?redirect=1010&cps_key=baa84ded7a9778d3aa1addcd4fbb8b24)，选择阿里云的读者们也一样，毕竟我是教大家怎么通过帮助文档来学习。
建议大家购买服务器，几十块钱对于出来工作的人来说真不算钱，十块钱对于大学生来说也就一杯奶荼的事。然而，有些人就喜欢图个免费（比如说我自己），行，咱们继续在本地安装服务器版的Linux继续模拟，安装起来相对比较麻烦,[对应教程](./本地linux-server.html)。但最后模拟过后，要想看真实效果，还得花个白菜钱买服务器来部署。
云服务器安装的Linux与之前我们玩的桌面版（desktop）不同，服务器版（server）默认不会有图形化界面，所有操作都通过命令行执行。
Xshell、WinSCP

### 作业
1. 云服务器上安装nodejs，打包demo1，通过WinSCP上传云服务器，解压，通过PM2部署demo1。
2. 将IP地址改为你云服务器的IP地址，重新把demo1软硬件跑一遍感受一下。此时，你的硬件在A地方，你在B地方，也一样能通过手机远程监控硬件，真正意义上的物联网系统。



