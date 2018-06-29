<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Part2](#part2)
	* [前端基础](#前端基础)
		* [自学HTML、CSS、Javascript](#自学html-css-javascript)
		* [一切皆是盒子](#一切皆是盒子)
		* [Chrome DevTools](#chrome-devtools)
		* [自学Jquery、Bootstrap](#自学jquery-bootstrap)
		* [作业](#作业)
	* [Nodejs](#nodejs)
		* [自学Nodejs](#自学nodejs)
		* [按官网指引部署express框架](#按官网指引部署express框架)
		* [自学Jade](#自学jade)
		* [postman](#postman)
	* [demo1项目讲解](#demo1项目讲解)
		* [项目文件纵览](#项目文件纵览)
		* [nodejs 打断点debug](#nodejs-打断点debug)
		* [分析讲解](#分析讲解)
		* [作业](#作业-1)
	* [Part2 总结](#part2-总结)
	* [扩展](#扩展)
	* [声明](#声明)
	* [Part 3](#part-3)

<!-- /code_chunk_output -->
# Part2
web开发主要包括前端，后端。后端可以理解为跑在服务器上的程序，在demo1里后端包含了TCP与HTTP服务器。前端可以理解为在客户端跑的程序，包含了HTML、CSS、Javascript等等。
最后修改时间：2018/5/25
## 前端基础
主要是学习HTML、CSS、Javascript、Jquery、Bootstrap。
### 自学HTML、CSS、Javascript
当我百度`HTML教程`时，搜索排名第一第二是w3school，排名第三是菜鸟教程，而右侧是各种书籍的介绍。如果有图书馆资源就可以随便借一本书，在网上学习的效果也是相当的好！按书学习相对系统完整一些，按网上教程学习速度相对快很多，大家结合多个教程来对比学习。学习目标是学会简单的页面布局与样式修改。同理，百度搜索`javascript教程`时也会找到对应的教程，其中廖雪峰的教程比较出名。大约是3至7天左右就会有个大概初步的认识。学习完后可以看一下我下面补充的学习内容。随着读者提问我知道要补充什么内容，下面会不断更新补充。
@import "./images/百度HTML教程.png"  
相关优秀的入门书籍：__《JavaScript DOM编程艺术》__

### 一切皆是盒子
在网页上创建的元素本质是一个盒子，利用CSS我可以把这个盒子按我的想法放哪里都行~
@import "./images/一切皆是盒子.png"  
而盒子上面你又可以放盒子，按想法放哪里都行~
@import "./images/盒子中盒子.png"  
利用Chrome Devtools我们分析一下百度页面的盒子是怎么放的：
在控制台输入以下命令（右上菜单-更多工具-开发者工具-console标签）：`$('div').css('border','1px solid red')`
这个命令是将所有div元素加1px的红框：
@import "./images/百度盒子.png"  
我们可以看到，一堆盒子做出来的网页，做网页本质就是堆盒子。大家先自学一下怎么随心所欲地在随意位置堆盒子，并把盒子装饰得好看的样子。
### Chrome DevTools
大家统一使用Chrome浏览器，下载一个~  
这里我简单介绍一下Chrome DevTools（开发者工具）常用技巧，示例文件在`Part2/exercise1/index.html`，点击打开就行。
1. 定位元素
定位元素可以很轻松地看到元素的margin,padding等信息，常用于分析别人某个效果是怎么布局元素的。
@import "./images/devTool 定位元素.gif"
2. 动态改变样式  
想看看某个样式效果怎么样，不用修改html文件，保存，再刷新，可以直接在浏览器上修改看效果~
@import "./images/动态修改样式.gif"
3. 查看网络请求  
看浏览器请求页面时到底请求了什么资源，花了多少时间。
@import "./images/查看网络请求.gif"
3. 控制台打印信息与运行javascript脚本
可以在控制台上打印js的调试信息（index.js以每秒打印数值为例），更可以直接在上面运行程序。
@import "./images/控制台打印信息与运行javascript脚本.gif"
很多公司都会把招聘广告放到控制台里去~
@import "./images/知乎控制台.png"  
4. Javascript打断点
也可以在脚本上打断点，能暂时看变量，这是最常用的调试技巧之一。
@import "./images/Javascript打断点.gif"
更多用途介绍[参考官网](https://developer.chrome.com/devtools)，谷歌家的网站肯定需要翻墙~翻墙将会是开发人员最难跨过的关卡之一。当然，直接百度`chrome devtool`应该有人介绍的。

### 自学Jquery、Bootstrap
由于能过javascript直接操作DOM很麻烦（如果你有学习《JavaScript DOM编程艺术》的话就知道了），所以诞生了Jquery来更好地偷懒，哦不，是更高效地写代码。必学。国际惯例，百度`Jquery教程`，几个教程对比地学习一下，花不了两天。  

好看的皮囊三千一晚，有趣的灵魂两百斤重。漂亮就是生产力，但一个个地改样式太累了，有没有别人已经做好的轮子，我拿来就用？自学Bootstrap吧，你会沉迷于漂亮的样式不能自拔~国际惯例，百度`Jquery教程`。
至此，你已经有资格，有能力画出一个漂漂亮亮的前端页面了。（搞得越多越熟练，越快）

### APP 与 PC端软件
APP可以使用cordova 进行开发，demo1效果如下：
@import "./images/cordova 安卓虚拟机 效果.gif"

PC端可以用electron 进行开发。他们本质还是html,js,css来进行界面布局，所以说你只要会做网页，做APP与PC端软件，就是配置然后搬过去而已。是的，不用学JAVA，不用学C#，不用学QT等等，直接用上漂亮的前端各种组件。

当然配置是蛮麻烦的。
### 作业

- 选用一款笔记软件，最好带有搜索功能的，记录下你学习的笔记，因为要学习的内容是多到“爆炸”，脑是记不下的，记录下来有个印象，真正用的时候却想不起来怎么用，翻翻就能找到，节约时间（大家用oneNote来记笔记）。
- 学会利用CSS的position，float，flex进行布局。
- 明白Jquery的作用，学会使用Jquery常用的功能：选择器，添加事件，修改样式等。
- 明白Bootstrap的作用，学会利用Bootstrap快速自己的页面。
- 从零开始，做一个与demo1差不多的页面。（不需要完全一样，可按自己爱好修改。）参考答案见`Part2/exercise2`。
## Nodejs
主要学习Nodejs,express框架。
### 自学Nodejs
国际惯例，百度`nodejs教程`，[CNODE社区推荐教程](https://cnodejs.org/getstart)，多个教程结合着学习。
相关优秀的入门书籍：__《深入浅出nodejs》__
### 按官网指引部署express框架
由于网上的教程不一定是最新的，也有可能版本太旧了而导致一些问题，__最新稳定的版本与最好的指引永远在官网（而且是英文版的官网，中文版有时会没同步跟上）__。现在我以官网的例子大家尝试一下express框架部署，就算换新版本，大家也能参考参考。
搜索`express`应该能找到官网了，就用中文版先学习着吧。__（英语阅读恐惧症的朋友是必须要克服的，反正我是硬啃了几本全英的书就不怕了，英文没提升多少，反正是恐惧是没了。翻译在手，天下我有。）__
@import "./images/express1.png"  
看到安装这里，扔出一堆命令叫我执行，如何执行命令？ 可别忘记了cmd（命令提示符）。
召唤出cmd后，我们开始跟着它输入命令了。__别看了，命令行输入是必用技能，别总幻想着图形化界面了，我们可是程序员也，不用命令行怎么在师妹面前装逼。__
当我跟着输入`mkdir app`，我怎么知道有什么效果？搜索mkdir命令的作用后知道了，这是创建文件夹，但又是在哪里创建文件夹？哦，原来是当前路径，如图所示，已经创建出app这个文件夹了。如果想改个路径呢？当然是使用`cd`命令啦。搜索了解一下。下面所有命令若有不明白的，同理搜索自己折腾，不再重复讲了~
@import "./images/express2.png"  

按命令跑了一下，就可以看到myapp目录下已经出现一些东西了。(自学过nodejs，应该明白的。）
进入下一步，Hello world。它叫我创建个JS脚本我就创建吧。（用的是vscode，没有的话装一下，环境尽量跟我一样。）
运行起来，并输入网址（这个指引竟然没有说，要访问哪个网址才能看到效果，浏览器输入`http://127.0.0.1:3000`）__我是一个每一步都要看到实际效果的人。__
@import "./images/express3.gif"  
我看了看，讲到这里就行了，后面的内容继续，自学,这个框架自学估计也要折腾几天。
我故意在vscode秀了一下，vscode里面也是能输入命令的。具体更多的技巧，请搜索vscode的介绍。

### 自学Jade
在利用express生成器时，会引入模板引擎，我们的demo是用默认值jade。
在知乎搜索一下，jade,你就会得到一些关键字，如模板引擎。没明白不要紧，__先用后学__。
搜索`jade`，就可以看到官网，直接对照着语法来尝试体验一下就知道了。
### postman
之前在打开`exercise1/index.html`时不知有没注意到，协议是file，意思就是打开本地文件。
而使用了nodejs，协议是HTTP，注意两者区别，打开网址，向HTTP服务器发出网络请求，HTTP服务器根据请求后进行运算并返回响应，我们就能看到响应回来的文件。
@import "./images/file协议打开.png"  
在调试时，经常用到postman（[网盘分享](https://pan.baidu.com/s/1sNrLk1y9ukb3xpjxoU8A9w)），来模拟请求。国际惯例，搜索自学。
## demo1项目讲解
经过十几天超高强度的学习，大概可以讲一下demo1项目了。
### 项目文件纵览
我们用vscode打开`Part1/demo`项目，看目录结构就知道是Express应用程序生成器生成的应用框架。
- `bin/tcp-server.js` TCP服务器的脚本
- `bin/www` express生成器的程序入口文件，启动程序的时候第一个运行的脚本
- `config/config.js` 配置文件
- `node_modules` 依赖模块
- `public` 放静态资源的地方，这里面主要放了Bootstrap，jquery脚本，其中tcp-page.js脚本会在tcp-page页面里引用到。
- `routes` 路由目录，所有tcp-page页面的请求响应都在tcp-page.js中。
- `views` 视图层目录，tcp-page.jade就是会被渲染成tcp-page.html的模板。
- `app.js` express生成器生成的express应用脚本，里面多加了一个路由文件tcp-page
- `package-lock.json` 与 `package.json` 此项目用到的模拟依赖，一般我会看别人的项目用了哪些我没见过的模块，搜索一下，看是否有用。
- `运行.bat` windows下的命令脚本，运行就执行`npm start`
### nodejs 打断点debug
vscode 下打断点 debug，能在程序中查看变量的实时状态:
@import "./images/nodejs debug.gif"  
注意，不管在哪个脚本上打断点，都必须在`bin/www`这个程序入口开始调试。
### 分析讲解
首先，代码会从`bin/www`这个入口文件开始执行。前面一开始就require引入了`app.js`、`./tcp-server.js`、以及一些模块与配置文件，require引入某个脚本时，就会跳到对应的脚本运行并缓存起来。应用框架的代码我就不多讲了，最后运行完了，HTTP服务器开始监听端口时，就会使用open模块自动打开浏览器，访问内网网址。
```javascript
//用浏览器打开网址
//反双引号``(在Esc按键下面)会将包含变量${variable}的字符串 转换成 字符串。
open(`http://${HOST}:${HTTP_PORT}/tcp-page`)
```
接下来看一看`bin/tcp-server.js`TCP服务器的代码，分析都以备注的形式写上去了，读备注就行了，讲完。（摊手~） 
再看一下`routes/tcp-page.js`路由脚本，继续读代码备注（摊手~），可以打个断点运行起来，用postman来模拟一下请求加深理解。
`views/tcp-page.jade`视图文件，如果有按之前顺序学习jade语法就会懂的了，没学过就去学。
`public/javascripts/tcp-page.js` tcp-page页面执行的脚本，使用Jquery写了按键的点击事件监听，以及AJAX请求。
整个代码已经分析完了，项目就是这样，express生成器生成应用框架，添加自己的tcp-page路由，加上TCP服务器的代码，用bootstrap写一个简单又不丑的界面，基本完成。剩下的就是你们瞎折腾，乱改动代码、看效果、加深理解，直到自己可以从零开始自己搞一个效果差不多的项目，这demo1你们就算是吃透了。
### 作业
- 明白GET 与 POST的区别。
- 搞明白nodejs的error first风格。
- 明白express框架的作用与使用。
- 明白Jade的作用与使用。
- 从零开始，做一个完整的demo1。（不需要完全相同，能实现相同功能即可。）
## Part2 总结
- 硬件问题可能搜索不到，但软件问题95%都可以通过搜索来解决问题。  
搜索“为什么我的液晶屏不能显示？”，影响因素实在是太多，基本不可能由别人回答来解决问题，最多也就答检查一下电源，硬件解决问题的方法一般是找模块的技术支持来解答。
而软件问题基本上都可以搜出来，把报错信息复制粘贴一搜索，基本上就有答案了。
- 软件开发最重要的是快速自学能力与解决问题的能力，网上资源与搜索引擎是开发者手中的核武器。
遇到报错怎么办？搜索！遇到不懂的词语怎么办？搜索！
- 不能翻墙上网、使用百度而不用Google搜索、拒绝阅读英语、不善用github的开发者，永远不能解决最新的一线问题，永远无法学习最新的官方指引，永远只能当初级开发人员。
翻墙的话，我是在逗比网上学习到的。发送邮件到 toyoooooooooooo@gmail.com，主题为 逗比根据地，即会回复最新镜像域名。
## 扩展
- 了解RESTful  api接口规范
- 尽快学会科学上网
- [MDN网站 JS参考](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference)
我一般查JS API会到这个网站里找，最近几个月发现只有翻墙才能访问。 MDN是web开发人员最佳的技术文档网站。
- [《ECMAScript 6 入门》](http://es6.ruanyifeng.com/)
一本开源的 JavaScript 语言教程，全面介绍 ECMAScript 6 新引入的语法特性。在进阶时必须学习promise与await语法。
- [命名风格]()
还没写~TODO。
- 常用的Nodejs模块
1. PM2：node进程管理工具，linux下部署Nodejs程序常用它来部署。
2. nodemon： 开发必备 自动重启良器
3. http-server：可很方便地运行本地html
4. moment：时间模块
- 了解TypeScript
- 了解JS代码检查工具：Jslint、eslint、standard
我用[standard](https://github.com/standard/standard)作为我的代码检查工具。
- 了解与对比新三大前端框架Vue、React、Angularjs
## 声明
保留一切权利，禁止商业转载，非商业转载时必须保留此声明与网址：https://github.com/alwxkxk/soft-and-hard
## Part 3
将会学习Linux,并研究如何将demo1部署到服务器里。开始[Part3阅读](../Part3/index.html)





