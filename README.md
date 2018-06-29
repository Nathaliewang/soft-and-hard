# soft-and-hard
《软硬结合——写给硬件开发工程师的全栈入门实战》，软硬件结合可以说是所有硬件开发人员心中的一大追求，当一个人技能树上点亮了软硬件，所有创意想法基本都能靠自己去实现。整个教程与源码都是免费公开的，但不允许别人通过这教程赚钱，我就赚个人气~

## 起源
2017年毕业时做的毕业设计是一个物联网项目，硬件上是STM32+ESP8266，自己搭服务器（nodejs+mongodb），客户端做网站做微信小程序（我觉得我是第一个用微信小程序做毕设的人），打算将这个项目重构并写出教程，针对硬件开发人员写的全栈应用开发入门实战。2018年开始写这教程时，我的水平是不足一年工作经难的初级全栈工程师+ 略懂硬件开发。
由于整个教程在缓慢更新中，会有不少问题，欢迎进Q群交流：__638456092__。
## 如何开始
1. 在github上点击下载，并解压
![在github上下载](http://ww1.sinaimg.cn/large/005BIQVbgy1fsr38x82u2j31hc0t4adw.jpg)
2. 打开文件夹，点击`第一次阅读.html`，先从整体阅读整个教程的特点，先从整体了解思路。
3. Part1内容：点击`Part1/index.html`正式开始阅读，其它部分同理。

学习过git：
因为整个教程在不断更新中，进入文件并运行`git pull`即可更新。
![git clone示意](http://ww1.sinaimg.cn/large/005BIQVbgy1fqtnqg91l9g31h30rmu0z.gif)

## 教程目录 与 安排
章节 | 情况 | 备注
------------ | ------------- | -------------
Part1 | 基本完成 |有待优化
Part2 | 基本完成 |有待优化
Part3 | 基本完成 |有待优化
Part4 | 正在做 | 
Part5 | 还没计划 | 
Part6 | 还没计划 | 

虽然整个教程没有完成，要点已经列出来，并不影响你们提前学习~
### Part1
整个项目介绍并让大家先简单地运行起来~ 包含ESP8622烧录固件，各环节自调与联调。
- 前提：有一定硬件调试经验（USART串口调试，AT指令）
- 目标：把Part1 的demo运行起来，实现本地WIFI下手机监控硬件。
- 关键词：STM32、串口调试、AT指令、ESP8266、git、网络调试助手
### Part2
讲解Part1 demo，包含静态网页制作，express框架。
- 目标：简单的网页开发与Nodejs应该能入门了，有能力修改出自己想要的页面效果。
- 关键词：HTML、Javascript、CSS、Jquery、bootstrap、w3cschool、菜鸟教程、《深入浅出nodejs》、《七天学会NodeJS》、TCP服务器、express
### Part3
将Part1 demo运行在云服务器上，主要是学习linux（ubuntu），云服务器各种折腾。
- 目标：Linux初步入门、部署到云服务器上，此时真正实现远程监控硬件。最后讨论一下demo1的不足，向demo2进化。
- 关键词：ubuntu、云服务器、vi、《鳥哥的 Linux 私房菜》、bash、Xshell、winSCP
### Part4
引入mongoDB数据库，将数据保存到数据库里，并将历史数据可视化。  
（可选学）并讲一些协议，包含TCP协议(讲一下基于TCP自定义自己的协议规则)，HTTP协议，websocket协议。然后会进行优化，如把HTTP轮询换成websocket协议。
- 目标：完成Part4 demo，数据可视化会让整个效果更炫，增加实时性，这个物联网项目基本成型。
- 关键词：《计算机网络》、tcpdump、wireshark、《TCP/IP详解》、socketio库、echart库、TLV格式
### Part5
Part5及往后看阅读情况写吧。
各种性能测试与优化，ESP8266的AT固件改成自己编译的固件（这个蛮难搞的），说一下各物联网平台。
- 关键词：redis、nginx、CDN
### Part6
使用electron开发PC桌面软件，使用cordova开发手机APP。
- 关键词：electron、cordova
### 这难吗？
![教程不难](http://ww1.sinaimg.cn/large/005BIQVbgy1fss6qz59w6j30jj0a2t9h.jpg)

## 声明
保留一切权利，禁止商业转载，非商业转载时必须保留此声明与网址：https://github.com/alwxkxk/soft-and-hard。


