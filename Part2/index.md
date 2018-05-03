# Part2
web开发主要包括前端，后端。后端可以理解为跑在服务器上的程序，在demo1里后端包含了TCP与HTTP服务器。前端可以理解为在客户端跑的程序，包含了HTML、CSS、Javascript等等。
最后修改时间：2018/5/3
## 前端基础
主要是学习HTML、CSS、Javascript、Jquery、Bootstrap。
### 自学HTML、CSS、Javascript
当我百度`HTML教程`时，搜索排名第一第二是w3school，排名第三是菜鸟教程，而右侧是各种书籍的介绍。如果有图书馆资源就可以随便借一本书，在网上学习的效果也是相当的好！按书学习相对系统完整一些，按网上教程学习速度相对快很多，大家结合多个教程来对比学习。学习目标是学会简单的页面布局与样式修改。同理，百度搜索`javascript教程`时也会找到对应的教程，其中廖雪峰的教程比较出名。大约是3至7天左右就会有个大概初步的认识。学习完后可以看一下我下面补充的学习内容。（为什么我不从基础教起？眼前有景道不得，崔颢题诗在上头。别人的教程更好更优，推荐给大家就行了。）
@import "./images/百度HTML教程.png"  

相关优秀的入门书籍：__《JavaScript DOM编程艺术》__

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
## Nodejs
主要学习Nodejs，express框架。
国际惯例，百度`nodejs教程`
相关优秀的入门书籍：__《深入浅出nodejs》__

## demo1项目讲解
主要讲解demo1项目。


