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
//TCP服务器启动
const server = net.createServer((socket) => {
  //TCP客户端连接后，马上以ascii的形式返回字符串 OK 
  socket.write('OK\n', 'ascii')
  // 图了个方便，直接把最新的TCP客户端socket赋值给server.mySocket。
  server.mySocket = socket
  socket.myText = moment().format('hh:mm:ss ') + ' tcp 建立连接!\n'
  // TCP客户端发来数据时执行代码：
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
  //TCP客户端断开连接时：
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
