/**
 * 文件：routers/tcp-page.js
 * 作者：alwxkxk
 * 修改时间：2018/04/30
 * 描述：tcp-page路由文件
 * 整个教程在不断迭代更新中，最新教程获取：https://github.com/alwxkxk/sofe-and-hard
 */
var express = require('express')
const moment = require('moment')
var router = express.Router()
//引入TCP服务器server，方便调用它里面的变量。
let tcpServer = require('../bin/tcp-server')
//GET /tcp-page 渲染jade并响应页面
router.get('/', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  let text = tcpServer.mySocket ? tcpServer.mySocket.myText : ''
  res.render('tcp-page', {text: text, LED1: tcpServer.LED1, LED2: tcpServer.LED2, status: status})
})
//GET /tcp-page/LED1 返回LED1的状态
router.get('/LED1', function (req, res, next) {
  res.send(`LED1:${tcpServer.LED1}`).end()
})
//GET /tcp-page/LED2 返回LED2的状态
router.get('/LED2', function (req, res, next) {
  res.send(`LED2:${tcpServer.LED2}`).end()
})

//post /tcp-page/LED1 开关LED1
router.post('/LED1', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  if (status) {
    let sendText = 'LED1:' + tcpServer.LED1 + '\n'
    tcpServer.mySocket.write(sendText, 'ascii')
    tcpServer.mySocket.myText += moment().format('hh:mm:ss ') + ' --> ：' + sendText
  }
  res.send(req.body).end()
})
//post /tcp-page/LED2 开关LED2
router.post('/LED2', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  if (status) {
    let sendText = 'LED2:' + tcpServer.LED2 + '\n'
    tcpServer.mySocket.write(sendText, 'ascii')
    tcpServer.mySocket.myText += moment().format('hh:mm:ss ') + ' --> ：' + sendText
  }
  res.send(req.body).end()
})
//GET /tcp-page/text 读取文本信息
router.get('/text', function (req, res, next) {
  let text = tcpServer.mySocket ? tcpServer.mySocket.myText : ''
  res.json({text: text}).end()
})
//GET /tcp-page/socketSatus 返回TCP客户端连接状态
router.get('/socketSatus', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  res.json({status: status}).end()
})
module.exports = router
