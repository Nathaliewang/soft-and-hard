# soft-and-hard
《软硬结合——写给硬件开发工程师的全栈入门实战》，软硬件结合可以说是所有硬件开发人员心中的一大追求，当一个人技能树上点亮了软硬件，所有创意想法基本都能靠自己去实现。整个教程与源码都是免费公开的，但不允许别人通过这教程赚钱，我就赚个人气~

## 起源
2017年毕业时做的毕业设计是一个物联网项目，硬件上是STM32+ESP8266，自己搭服务器（nodejs+mongodb），客户端做网站做微信小程序（我觉得我是第一个用微信小程序做毕设的人），打算将这个项目重构并写出教程，针对硬件开发人员写的全栈应用开发入门实战。2018年开始写这教程时，我的水平是不足一年工作经难的初级全栈工程师+ 略懂硬件开发。
由于整个教程在缓慢更新中，会有不少问题，欢迎进Q群交流：__638456092__。
## 如何开始
1. 百度git 并运行安装
![百度git 并运行安装示意图](http://ww1.sinaimg.cn/large/005BIQVbgy1fqtnovsgrmj31hc0qdjxv.jpg)
2. 在桌面上右键点击 `git bash Here`
3. `git clone https://github.com/alwxkxk/soft-and-hard.git`
4. 可以看到下载了一个文件夹，进去点击`第一次阅读.html`
5. 整个教程在不断更新中，进入文件并运行`git pull`即可更新。
![git clone示意](http://ww1.sinaimg.cn/large/005BIQVbgy1fqtnqg91l9g31h30rmu0z.gif)
6. 之后就进入到Part1 点击`index.html`正式开始阅读。

## 教程特点
- 整个项目部署运行傻瓜式地教，保证整个项目能在读者手上运行起来。
- 尽可能地解答会卡住大家继续项目走下去的所有问题。
- 我不生产水，我只是水的搬运工，别人已经写好的教程不再重复写，比如HTML的学习，nodejs的学习,linux学习等等，都会告诉你们怎么利用网络搜索需要自学的教程，__眼前有景道不得，崔颢题诗在上头。__此教程做的只是连珠成串，__此教程重点在于点明方向，告诉你将要学习的东西__。
- __要学习的东西千千万万，唯一不变的是搜索。__ 整个教程，我不会直接告诉你答案，而是反反复复地使用搜索引擎去示范，我是怎么通过搜索找到我想要的答案。培养解决问题的能力十分重要。
- 教程涉及的内容十分广，如果是去培训班估计也要培训几个月，学起来会有一种“炸”的感觉，大家切记，不要深究难点，多用笔记软件来记录。__因为要做某件事，所以我要学习某个知识点，进而解决某个问题__ 暂时用不到的只需要知道有这东西存在，知道它能解决什么问题即可
- __先用后学__，一开始不必搞懂所有概念，先用起来，知道是有什么效果的，然后再学习。
- 这个教程会随着读者的提问，反思是哪个环节内容不足，然后不断补充内容。也会随着我能力的提升，不断增加教程里的内容。
## 教程目录 与 安排
### Part1
整个项目介绍并让大家先简单地运行起来~ 包含ESP8622烧录固件，各环节自调与联调。
- 前提：有一定硬件调试经验（USART串口调试，AT指令）
- 成果：把Part1 的demo运行起来，实现本地WIFI下手机监控硬件。
- 关键词：STM32、串口调试、AT指令、ESP8266、git、网络调试助手

### Part2
讲解Part1 demo，包含静态网页制作，express框架。
- 成果：简单的网页开发与Nodejs应该能入门了，有能力修改出自己想要的页面效果。
- 关键词：HTML、Javascript、CSS、Jquery、bootstrap、w3cschool、菜鸟教程、《深入浅出nodejs》、《七天学会NodeJS》、TCP服务器、express
### Part3
将Part1 demo运行在云服务器上，主要是学习linux（ubuntu），云服务器各种折腾。
- 成果：Linux初步入门、部署到云服务器上，此时真正实现远程监控硬件。
- 关键词：ubuntu、云服务器、vi、《鳥哥的 Linux 私房菜》、bash、Xshell、winSCP
### Part4
引入mongoDB数据库，将数据保存到数据库里，并将历史数据可视化。  
（可选学）并讲一些协议，包含TCP协议(讲一下基于TCP自定义自己的协议规则)，HTTP协议，websocket协议。然后会进行优化，如把HTTP轮询换成websocket协议。
- 成果：完成Part4 demo，数据可视化会让整个效果更炫，增加实时性，这个物联网项目基本成型。
- 关键词：《计算机网络》、tcpdump、wireshark、《TCP/IP详解》、socketio库、echart库、TLV格式
### Part5
Part5及往后看阅读情况写吧。
各种性能测试与优化，ESP8266的AT固件改成自己编译的固件（这个蛮难搞的），说一下各物联网平台。
- 关键词：redis、nginx、CDN
### Part6
使用electron开发PC桌面软件，使用cordova开发手机APP。
- 关键词：electron、cordova
## 声明
保留一切权利，禁止商业转载，非商业转载时必须保留此声明与网址：https://github.com/alwxkxk/soft-and-hard。


