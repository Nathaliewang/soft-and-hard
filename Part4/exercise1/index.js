// 基于准备好的dom，初始化echarts实例
var myChart = echarts.init(document.getElementById('main'))
var dataX = []
var dataY = []
// 指定图表的配置项和数据
var option = {
	color: ['#3398DB'],
	title:{
		text:'Part4/exercise1示例'
	},
  tooltip: {
    trigger: 'axis',
    axisPointer: { // 坐标轴指示器，坐标轴触发有效
      type: 'shadow' // 默认为直线，可选为：'line' | 'shadow'
    }
  },
  grid: {
    left: '3%',
    right: '4%',
    bottom: '3%',
    containLabel: true
  },
  xAxis: [
    {
      type: 'category',
      data: dataX,
      axisTick: {
        alignWithLabel: true
      }
    }
  ],
  yAxis: [
    {
      type: 'value'
    }
  ],
  series: [
    {
      name: '直接访问',
      type: 'bar',
      barWidth: '60%',
      data: dataY
    }
  ]
}

// 使用刚指定的配置项和数据显示图表。
myChart.setOption(option)

setInterval(() => {
  dataX.push(moment().format('mm:ss'))// 时间 分:秒
	dataY.push(3.3 * Math.random()) // 用随机数模拟输入 0~3.3
	if(dataX.length >= 30){
		// 如果数据长度超过30，则把最旧（即在数组里的最左的）的数据删除
		dataX.shift()
		dataY.shift()
	}
	myChart.setOption(option)
}, 1000)
