/**
 * 文件：bin/tcp-server.js
 * 作者：alwxkxk
 * 修改时间：2018/04/30
 * 描述：TCP服务器，对socket操作
 * 整个教程在不断迭代更新中，最新教程获取：https://github.com/alwxkxk/sofe-and-hard
 */

const HOST = require('../config/config.js').HOST
const moment = require('moment')
const net = require('net')
const TCP_PORT = require('../config/config.js').TCP_PORT
const server = net.createServer((socket) => {
  socket.write('OK\n', 'ascii')
  // 暂时简单地将socket引出来
  server.mySocket = socket
  socket.myText = moment().format('hh:mm:ss ') + ' tcp 建立连接!\n'
  socket.on('data', function (data) {
    socket.myText += moment().format('hh:mm:ss ') + ' <--' + data + ' \n'
    // data 是buffer，需要转换为ascii
    // console.log(data.toString('ascii'))
    switch (data.toString('ascii')) {
      case 'LED1:0':
        server.LED1 = '0'
        break
      case 'LED1:1':
        server.LED1 = '1'
        break
      case 'LED2:0':
        server.LED2 = '0'
        break
      case 'LED2:1':
        server.LED2 = '1'
        break
      default:
        break
    }
  })
  socket.on('close', function () {
    socket.myText += moment().format('hh:mm:ss ') + ' tcp 断开连接!\n'
  })
}).on('error', (err) => {
  throw err
})

server.listen({port: TCP_PORT, host: HOST}, () => {
  console.log('opened tcp server on', server.address())
})

server.LED1 = '0'
server.LED2 = '1'
module.exports = server
