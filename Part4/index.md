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
完整代码及代码说明参考`Part4/exercise1`
### 作业
1. 用Echart折腾一个图表出来，学会怎么用。

## 数据库——MongoDB

## 协议讨论
### TCP
### HTTP
### Webscoket
### MQTT
