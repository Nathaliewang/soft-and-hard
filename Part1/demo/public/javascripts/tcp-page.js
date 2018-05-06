/**
 * 文件：public/javascripts/tcp-page.js
 * 作者：alwxkxk
 * 修改时间：2018/04/30
 * 描述：tcp-page页面 的js脚本
 * 整个教程在不断迭代更新中，最新教程获取：https://github.com/alwxkxk/sofe-and-hard
 */

 // 按键点击监听
$('#openLed1').click(function () {
  $.post('/tcp-page/LED1', {LED1: '1'})
})

$('#closeLed1').click(function () {
  $.post('/tcp-page/LED1', {LED1: '0'})
})

$('#openLed2').click(function () {
  $.post('/tcp-page/LED2', {LED2: '1'})
})

$('#closeLed2').click(function () {
  $.post('/tcp-page/LED2', {LED2: '0'})
})

// 每500ms请求一次，获取状态并修改页面内容
setInterval(() => {
  $.get('/tcp-page/text', (obj) => {
    $('#text').text(obj.text)
  })
  $.get('/tcp-page/socketSatus', (obj) => {
    $('#status').text('TCP socket 连接状态：' + obj.status)
  })
  $.get('/tcp-page/LED1', (obj) => {
    $('#LED1Text').text(obj)
  })
  $.get('/tcp-page/LED2', (obj) => {
    $('#LED2Text').text(obj)
  })
}, 500)
