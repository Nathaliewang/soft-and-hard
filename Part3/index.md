<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Part3](#part3)
	* [自学linux基础](#自学linux基础)
		* [本地 虚拟机安装linux](#本地-虚拟机安装linux)
		* [学习基本命令](#学习基本命令)
		* [curl请求一下网页](#curl请求一下网页)
		* [作业](#作业)
	* [云服务器部署](#云服务器部署)
		* [阅读帮助文档](#阅读帮助文档)
		* [云服务器上安装nodejs](#云服务器上安装nodejs)
		* [云服务器上部署demo1](#云服务器上部署demo1)
		* [作业](#作业-1)

<!-- /code_chunk_output -->
# Part3
这部分主要是将demo1部署到云服务器里。
## 自学linux基础
linux入门书籍是《鳥哥的 Linux 私房菜》[网上自学](http://linux.vbird.org)，学习的时候注意挑着学习，阅读的时候要明白哪些是会用到的多试一下，哪些短时间内用不到的就快速翻阅。Linux 私房菜所用的系统是CentOS，部分命令与结构与Ubuntu不尽相同，但一通百通，若不行就搜索Ubuntu某个命令即可解决。
### 本地 虚拟机安装linux
linux整个学习过程大约在5-10天左右能入个门。
[VirtualBox](https://pan.baidu.com/s/1XB6Lao8fwz4f88wzGqZnUA) 是一款开源虚拟机软件，大家可以利用它来安装linux，在本地上练习linux，尽可放心折腾，搞坏了重装即可。怎么折腾，搜索有很详细的介绍，我就不重复搬水了。[ubuntu桌面版镜像](https://pan.baidu.com/s/1m8HpYPUZJJ1ceA4zWCqUNw)
@import "./images/VirtualBox安装Ubuntu.png"
### 学习基本命令
虽然是桌面版，但其实整个教程都是以终端命令行的形式进行的，基本不用到图形化界面的功能。
按 `Ctrl + Alt+ t`进入终端，就能输入命令了。
@import "./images/进入终端.png"
学习Linux 私房菜时，以下命令要求必须学习，会使用：
- 创建用户、修改用户密码、切换用户、以管理员身份运行某个命令、切换为超级用户（`useradd`,`passwd`,`su`,`sudo`,`sudo -s`,）
- 文件列表、改变文件权限、编辑文本（`ls`,`chmod`,`vi`）
- 通道、搜索过滤（`|`,`grep`）
- 打包解压（`tar`,`zip`）
- 下载网络资源、模拟HTTP请求、命令行下访问网页(`wget`,`curl`,`links`)
- 查看当前运行程序、网络连接状态(`ps`,`netstat`)
- 后台运行，将前台程序暂停并放到后台，查看后台程序，让后台程序在后台运行，将后台运行切换到前台（`&`,`Ctrl + z`，`jobs`,`bg`,`fg`）
- 杀掉进程(`kill`)
- 安装某个软件(`apt-get install`)  

---
不常用的命令我也常常不记得，真正用却忘记的时候我会翻翻笔记，笔记没有的时候，只要搜索`linux 做某事 命令`。
@import "./images/搜索linux命令.png"  
而常用的命令自然很容易记住，一般命令是英文的缩写，比如列出文件列表,`ls`可联想到list。大家花几天时候把linux私房菜学一下先，我就不重复搬水了~
接下来我简单地示范个动作~
### curl请求一下网页
@import "./images/示范浏览网页.png"
使用`curl`命令时提示没有这个命令（not installed），系统在提示我们安装。
我第一次安装时提示没有权限（Permission denied），没有权限这个很常见，所以我故意模拟一下。当输入命令时出现一行提示，新手一般会直接复制这一行还没尝试阅读过的英文去搜索，一般也能搜到什么问题，怎么解决。但玩多了的人，会静下心来看这一串英文讲的是什么，一看就知道是什么问题，一下就能解决。什么？英文差？我一反手就扔给你一个翻译软件，你心中有的只是对英文的恐惧，不要逃了，也不必绕了，这是必须克服恐惧，拿上翻译我们一起走天下。
执行完`sudo apt-get install curl`，同意安装，安装完毕后再重新尝试。
`curl www.qq.com`，就能得到QQ页面的页面响应，就是一堆HTML与JS代码。

### 作业
1. 使用VirtualBox安装Ubuntu，安装VirtualBox虚拟机增强功能，配置成桥接网卡。
2. 学习基本的vi操作。
3. 配置共享文件，实现把windows某个文件移到虚拟机里，并且在linux下修改保存，再移回到windows下。

## 云服务器部署
购买一台最低配置的云服务器，大学生可以验证身份后以学生价购买服务器，大约在10元一个月左右（这个价格可以说是高于成本的，人家可是亏本给你们学习的。）。国内云服务器以阿里云为首，腾讯云其次，大家可以从这两个里选一个购买并学习。由于我学生时代用的是腾讯云（当年我一元一个月用了两三年，那真叫爽。），我就以腾讯云为例[我的推广网址，能赚个几块钱推广费，谢谢大家支持哈](https://cloud.tencent.com/redirect.php?redirect=1010&cps_key=baa84ded7a9778d3aa1addcd4fbb8b24)，选择阿里云的读者们也一样，毕竟我是教大家怎么通过帮助文档来学习。
建议大家购买服务器，几十块钱对于出来工作的人来说真不算钱，十块钱对于大学生来说也就一杯奶荼的事。然而，有些人就喜欢图个免费（比如说我自己），行，咱们继续在本地安装服务器版的Linux继续模拟，安装起来相对比较麻烦,[对应教程](./本地linux-server.html)。但最后模拟过后，要想看真实效果，还得花个白菜钱买服务器来部署，这是个弯路（因为这样做，手机与硬件与电脑都必须在同一个局域网里）。
云服务器安装的Linux与之前我们玩的桌面版（desktop）不同，服务器版（server）默认不会有图形化界面，所有操作都必须通过终端。
### 阅读帮助文档
腾讯云有专门的实验室，免费开放给大家学习（提供一两个小时的云服务器）。大家可以在购买云服务器之前，先在实验室里折腾。个人感觉对新手蛮友好的，阿里云也应该会有。
@import "./images/腾讯云实验室.png"
购买云服务器后，怎么折腾？当然看帮助文档啦，我是看帮助文档入门的。
@import "./images/云服务器帮助文档.png"
在文档中，你会学习到，如何通过终端登陆服务器，如何上传文件到服务器等基本操作。文档介绍的真是太详细了，我根本不用搬。
@import "./images/登陆linux文档.png"
@import "./images/WinSCP上传文件.png"
我一般使用[Xshell](https://pan.baidu.com/s/1gJcej3AA_CK5IXIOW_W83Q)作为终端登陆、[WinSCP](https://pan.baidu.com/s/1jl03NlfsG24FE16DfIHUwg)上传文件。
### 云服务器上安装nodejs
现在，我示范一下，怎么通过apt-get在ubuntu安装 nodejs。
访问[nodejs的官网(英文版)](https://nodejs.org/en/)，点击其它下载方式。
@import "./images/nodejs-other-downloads.png"
点击通过软件管理包安装
@import "./images/installing-nodejs-via-package-manager.png"
找到我们的linux版本，我们用的是ubuntu:
@import "./images/ubuntu install nodejs.png"
根据文档，执行命令，别执行多了，把英文看清楚了，就两行。
@import "./images/ubuntu install nodejs2.png"
```bash
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
sudo apt-get install -y nodejs
```

安装完毕后，就可以像之前一样，执行`node -v`，验证安装成功。

看到没了，只要不怕英文，真的是可以为所欲为的，回头看看Nodejs中文网，有这种操作吗？中文网根本没有！！（当然，nodejs官方网中文版还是有的，但百度Nodejs就是搜出了Nodejs中文网，最终文档仍然是英文。）
习惯看英文与因恐惧而不敢阅读英文的人，差距就是这样拉开的，第一年差距拉开几千块钱的工资差距，十年呢？__克服恐惧，你将得到自由与力量。__
@import "./images/中文版Nodejs官网.png"

### 云服务器上部署demo1

出于安全考虑，一开始服务器除了几个端口对外开放，其它端口都会被拦截。而我们demo1默认使用8888端口为HTTP服务器端口，2424为TCP服务器端口，所以我们还必须先配置安全组。
首先我们要新建安全组，并配置入站、出站规则。
@import "./images/新增安全组.png"
入站就让8888与2424端口允许进来吧。（HTTP是基于TCP协议之上的应用层协议）
@import "./images/添加入站规则.png"
出站规则就全部允许吧。
@import "./images/出站规则.png"
然后给你的服务器配置你刚配置好的安全组：
@import "./images/给服务器配置安全组.png"

如果安全组没有配置正确，将会无法访问，毕竟腾讯云拦截了。

为了方便部署，特意将服务器的代码分隔到另一个github项目（这样就不用下载一堆图片与其它无关的东西）。
登陆云服务器，安装git，`sudo apt-get install -y git`
下载服务器代码`git clone https://github.com/alwxkxk/sofe-and-hard-server.git`
进入Part1/demo 安装依赖`npm install`，修改配置文件`vi ./config/config.js`，然后运行`npm start`。

云服务器的内网IP地址在服务器平台可以看到，也可以执行`ifconfig`找到。
注意，配置使用的是内网IP，浏览器访问页面时用的是外网IP地址。（一定要区分好内网IP、外网IP）
以我的服务器为例，内网IP地址是10.135.13.174，外网地址为119.29.107.47。

配置文件写的是10.135.13.174。(可以看到我用Xshell终端登陆的是外网IP)
@import "./images/匹配内网IP地址.png"
运行起来，并且多开一个终端使用curl验证一下：
@import "./images/使用curl 验证.png"
浏览器访问的页面是http://119.29.107.47:8888/tcp-page
@import "./images/外网访问.png"

最后，你就可以重复Part1的联调，实现真正意义上的物联网系统。（虽然暂时又丑功能又不足，罗马城不是一天建成的，后面会继续优化）
@import "./images/云服务器与网络调试助手.gif"

---  


如果你是在2019年才看到这个教程，你或许已经不能通过这个IP来访问到这个页面，因为极有可能我因为“穷”而不再续费这台云服务器（因为这台服务器我用120元租了一年，而下一年可能就没有这个优惠了）。然而，你应该还是能通过http://www.scaugreen.cn:8888/tcp-page访问到。网址的原理：通过www.scaugreen.cn这个网址，查询DNS获取服务器的IP地址，就会转换成119.29.107.47地址，可能下一年我会换一台没那么贵的服务器，到时就会转换成新的IP地址。国内申请域名需要备案，大家可以申请一个回来玩玩。



### 作业
1. 部署并运行demo1。
2. 将IP地址改为你云服务器的IP地址（注意区分内网IP与外网IP），重新把demo1软硬件跑一遍感受一下。此时，你的硬件在A地方，你在B地方，也一样能通过手机远程监控硬件，真正意义上的物联网系统。







