# 光维上位机软件全栈构架

本文件夹主要为web\desktop\mobile\server全栈软件构架说明。

## __web__
WEB frontend部分通过angular实现！
1. angular
   * bootstrap
## __desktop__
桌面端应用程序(win/mac/linux)，通过angular前端，封装到electron实现，通过rebuild，electron自带的nodejs库来实现本地硬件驱动。
1. angular
   * bootstrap
2. electron
   * serialport
   * sqlite
## __mobile__
Android和IOS客户端APP，通过ionic框架实现，native功能通过cordova实现。
1. ionic(基于angular)
2. cordova
   * BLE
   * sqlite
   * camera
## __server__
BackendServer,主要用于数据的CRUD，通过nodejs服务器实现。
需要实现：1.服务器的高可用，高并发（负载均衡）1.数据库的高可用、高并发（服务器集群技术、负载均衡、分片技术）。    
1. node.js
   * mysql/redis
   * mongodb     