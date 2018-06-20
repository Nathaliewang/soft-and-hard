# Part 6 (TODO：还不是完全傻瓜式教程，有待完善)
这部分介绍如何把做网页的那一套（HTML,CSS,JavsScirpt）搬到APP，PC端软件，从而减少学习其它语言的学习成本。同时这种写一个多处用的跨平台方案，是软件开发的一大追求。（谁都想一石N鸟）

## APP
将网页那一套搬到手机上，一般会使用[cordova](https://cordova.apache.org/)。写这教程时使用的是8.x版本。
国际惯例，阅读官网，从get started 开始先体验一下效果，这我没遇到什么问题就略了。

### Andriod
点击文档，开始阅读创建APP的。
首先是安装Android开发环境，Android Studio与配置JAVA环境。
Android Studio可能需要翻墙，并配置代理。
我试的时候好像是说必须要JAVA8的。

安装JAVA8EE并用命令行测试是否安装配置正确
在命令行输入`java`，`javac`如果提示找不到命令，请检查环境变量配置。
‘我的电脑’-右键-高级系统设置：
@import "./images/JAVA环境配置.png"
是的，环境变量PATH就是为了让命令行找到某个命令，如果执行到某个命令找不到，你就可以去找到那个命令文件并配置到环境变量PATH里。

### IOS


## PC端
PC端一般会用[electron](https://electronjs.org/)，超流行的。

### electron
安装electron之前可能需要先配置中国镜像。
windos powshell 下设置中国镜像的方法：
`$env:ELECTRON_MIRROR = "https://npm.taobao.org/mirrors/electron/"`




