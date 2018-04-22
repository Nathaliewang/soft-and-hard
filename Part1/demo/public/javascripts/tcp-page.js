/**
 * 文件：public/javascripts/tcp-page.js
 * 作者：alwxkxk
 * 修改时间：2018/04/22
 * 描述：tcp-page页面 的js脚本
 */

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

setInterval(() => {
  $.get('/tcp-page/text', (obj) => {
    $('#text').text(obj.text)
  })
  $.get('/tcp-page/socketSatus', (obj) => {
    $('#status').text('TCP socket 连接状态：' + obj.status)
  })
}, 500)
