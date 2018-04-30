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
let tcpServer = require('../bin/tcp-server')
router.get('/', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  let text = tcpServer.mySocket ? tcpServer.mySocket.myText : ''
  res.render('tcp-page', {text: text, LED1: tcpServer.LED1, LED2: tcpServer.LED2, status: status})
})
router.get('/LED1', function (req, res, next) {
  res.send(`LED1:${tcpServer.LED1}`).end()
})
router.get('/LED2', function (req, res, next) {
  res.send(`LED2:${tcpServer.LED2}`).end()
})

router.post('/LED1', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  if (status) {
    let sendText = 'LED1:' + tcpServer.LED1 + '\n'
    tcpServer.mySocket.write(sendText, 'ascii')
    tcpServer.mySocket.myText += moment().format('hh:mm:ss ') + ' --> ：' + sendText
  }
  res.send(req.body).end()
})

router.post('/LED2', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  if (status) {
    let sendText = 'LED2:' + tcpServer.LED2 + '\n'
    tcpServer.mySocket.write(sendText, 'ascii')
    tcpServer.mySocket.myText += moment().format('hh:mm:ss ') + ' --> ：' + sendText
  }
  res.send(req.body).end()
})

router.get('/text', function (req, res, next) {
  let text = tcpServer.mySocket ? tcpServer.mySocket.myText : ''
  res.json({text: text}).end()
})

router.get('/socketSatus', function (req, res, next) {
  let status = tcpServer.mySocket ? !tcpServer.mySocket.destroyed : false
  res.json({status: status}).end()
})
module.exports = router
