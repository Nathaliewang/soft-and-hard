/**
 * 文件：bin/tcp-server.js
 * 作者：alwxkxk
 * 修改时间：2018/04/22
 * 描述：TCP服务器，对socket操作
 */
// const HOST = '127.0.0.1'
const HOST = '192.168.1.121' // 要填入自己的内网IP地址

const moment = require('moment')
const net = require('net')
const TCP_PORT = 2424
const server = net.createServer((socket) => {
  socket.write('OK\n', 'ascii')
  // 暂时简单地将socket引出来
  server.mySocket = socket
  socket.myText = moment().format('hh:mm:ss ') + ' tcp 建立连接!\n'
  socket.on('data', function (data) {
    socket.myText += moment().format('hh:mm:ss ') + ' <--' + data + ' \n'
    socket.write('OK \n')
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
