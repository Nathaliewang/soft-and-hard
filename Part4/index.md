<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Part 4](#part-4)
	* [可视化——Echart](#可视化echart)
		* [作业](#作业)
	* [数据库——MongoDB（未完成TODO）](#数据库mongodb未完成todo)
		* [安装](#安装)
			* [windows安装](#windows安装)
			* [linux安装](#linux安装)
		* [使用可视化客户端Robo 3T连接MongoDB](#使用可视化客户端robo-3t连接mongodb)
		* [使用mongoose控制数据库](#使用mongoose控制数据库)
		* [作业](#作业-1)
	* [通信协议讨论（未完成TODO）](#通信协议讨论未完成todo)
		* [TCP](#tcp)
				* [linux下的tcpdump](#linux下的tcpdump)
				* [windows下的wireshark](#windows下的wireshark)
				* [自定义TCP协议](#自定义tcp协议)
		* [HTTP](#http)
			* [cookies 与 session](#cookies-与-session)
		* [WebScoket](#webscoket)
			* [socketio的使用](#socketio的使用)
		* [MQTT](#mqtt)
		* [作业](#作业-2)
	* [扩展](#扩展)

<!-- /code_chunk_output -->
# Part 4 
这部分主要讨论可视化库（Echart），数据库（MongoDB），以及协议的讨论（TCP、HTTP、Websocket、MQTT）。

## 可视化——Echart
可视化极其重要，一个炫丽的页面带来的冲击效果十分强烈。__在项目的前期，外表远比性能要重要。__ Echart是百度开源的可视化库，效果在全世界范围内都属于好用，（当然文档相对还有些问题）。
先看看别人的效果： 
@import "./images/可视化效果.png"
能不能打动买家的心，靠的就是前端。
当然，这么炫至少也要半年经验的前端工程师才能比较好地驾驭（我做的能比他们更炫，因为这个我也能做，而且我还能在这基础上引入3D模型，更炫。但涉及到公司的作品我就不放出来了），新手肯定是先从简单的开始。
我们假设要展示一条数据曲线，比如说我要看某传感器的实时数值（30秒内）。

1. 首先我们先从学习官网教程，自己在本地跑一个最简demo。
@import "./images/echart官方教程.png"

2. 在Echart官方实例里挑一个,在线调整成自己喜欢的样式。
@import "./images/echart官方实例.png"
@import "./images/echart在线调试.png"
@import "./images/echartAPI.png"
在实际使用时，echart就是不断地参考别人的例子，结合API文档，修改出自己想要的样式。

3. 在本地先模拟每秒钟接收到数据，实时更新Echart图表。
@import "./images/exercise1 效果1.gif"
@import "./images/exercise1 效果2.gif"
完整代码及代码说明参考`Part4/exercise1`，大约一两天时间。
### 作业
- 用Echart折腾一个图表出来，学会怎么用。

## 数据库——MongoDB（未完成TODO）
首先，我们要搞明白，为什么使用数据库？  
上面Echart的例子可以看到，页面在一开始时是需要过去30秒的数据，这些数据当然是可以暂时少量地存在nodejs程序里，但如果是100万个数据，那么内存就不够用了，我们需要把数据存到硬盘里。
我们可以选择创建一个文件，不断地把数据存进去，用的时候再读取出来。这样做文件一般长成这个样子的：
```bash
# 时间 - 设备名 - 数据名 - 数据值
[13/May/2018:06:26:31 +0800] - 深圳XX大厦XX楼ABC主板 - A传感器 - 24.5
[13/May/2018:06:28:38 +0800] - 广州XX学校XX楼EFG主板 - A传感器 - 26.5
[13/May/2018:06:30:44 +0800] - 深圳XX大厦XX楼ABC主板 - A传感器 - 24.5
[13/May/2018:06:31:56 +0800] - 广州XX学校XX楼EFG主板 - B传感器 - 24.5
# ...后面省略千千万万条
```
当你想从中想显示A设备B数据在C时段的数据时，从这个文件里搜索你会选择go die。由于数据库里搜索某个数据很方便很快，所以一般会把这种数据存放到数据库里。而这种直接写文件的方式，虽然写入性能高于数据库，但是一般只会用来存放日志（log），当出现问题需要排查时查看最近的日志以定位问题。
关系型数据库杰出代表MySQL与非关系型数据库杰出代表[MongoDB](https://www.mongodb.com/)，对于全栈开发人员来说，两个都是要学习的，两者分别有不同的应用场景。物联网应用一般较多使用后者。
### 安装
[MongoDB官网](https://www.mongodb.com/)去下载，注意使用稳定版本即可。
#### windows安装
有些同学想先在windows下折腾一下mongodb，安装配置比linux要复杂一点：
@import "./images/windows安装mongodb.png"
然后还要配置些东西，具体可看文档：
@import "./images/windows安装mongodb 2.png"
然后搜索mongodb教程，自学去，大约三四天时间。
#### linux安装
@import "./images/安装mongodb.png"
@import "./images/安装mongodb 2.png"
按着文档来安装并运行。
### 使用可视化客户端Robo 3T连接MongoDB
云服务器注意设置安全组对应放开端口，配置向外开放，让windows客户端也能连接到云服务器的数据库。TODO

在Authentication 的 Auth Mechanism选择MONGODB-CR(旧版的验证机制)。
@import "./images/Robo 3T.png"

### 使用mongoose控制数据库
nodejs里控制mongodb的模块一般使用[mongoose](https://github.com/Automattic/mongoose)，我们尝试在demo1的基础上添加mongoose，把接收到的数据都存入到数据库，详情看`sofe-and-hard-server/Part4/demo1.2`（为了更方便部署在服务器，所以特意将服务器部分的代码放到另一个项目）。TODO
### 作业
- 使用图形化工具远程连接数据库（需要配置数据库，并开放安全组端口）
- （扩展）尝试备份恢复数据库

## 通信协议讨论（未完成TODO）
先看《计算机网络》（谢希仁作）,先大概学习TCP/IP的基础知识。然后结合经典书籍《TCP/IP详解 卷一》一起学习。
现在我们来讨论一下通信协议，TCP协议是基础，需要通过抓包来学习。有了TCP基础后，我们讨论一下HTTP，Websocket，MQTT协议。
### TCP
我们直接通过抓包，来看看TCP到底传输了什么数据。
##### linux下的tcpdump
linux下使用tcpdump，tcpdump的数据可以下载到windows本地来用wireshark加载以方便阅读。
##### windows下的wireshark
windows下可以使用图形化工具wireshark。
##### 自定义TCP协议
我们用假设法来定义一下自己的TCP通信协议。
再TLV格式来定义一下。
### HTTP
#### cookies 与 session

### WebScoket
搜索WebScoket，你就能发现很多文章讨论WebScoket的原理，优点以及相比于HTTP轮询（AJAX轮询）的优势。
#### socketio的使用
注意socketio不是WebScoket的服务器，而是进行了封装（如自动重连，若不支持WebScoket协议则自动使用HTTP轮询代替），要想通过抓包研究WebScoket，请使用[ws模块](https://github.com/websockets/ws)搭建WebScoket服务器进行抓包研究。

### MQTT

### 作业
- 搞明白WebScoket相对于HTTP轮询的优势。

## 扩展
- [HTTP协议规范 RCF2646](https://tools.ietf.org/html/rfc2616)
- [WebScoket协议规范 RFC6455](https://tools.ietf.org/html/rfc6455)