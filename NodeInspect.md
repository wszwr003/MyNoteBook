# [Nodejs 入门、Inspect调试](https://www.imooc.com/learn/1093)
## 1-1 inspector intruduce
命令行使用方法：`node --inspect xxx.js`  
优势：本质是断点调试，可以查看上下文变量、可以查看函数调用堆栈、不需要侵入代码、暂停状态下可以执行指定代码
Inspector原理：
* 启动时会启动一个WebSocket服务（监听命令）
* Inspect protocol
* Http Server(获取metadata)   http://localhost:port/json
## 1-2 激活调试
如何激活调试： 命令行加上--inspect参数
## 1-3 1-4 1-5 调试客户端 Node.js Inspector
### Chrome DevTools 55+  
* 打开chrome://inspect
* 打开访问metadata中的 devtoolsFrontendUrl
* 点击开发工具的绿色按钮  
    #### 调试窗口：  
    profile：用于性能调试，响应慢  
    Memory：用于内存调试，内存泄漏
### VS Code
* 启动方式： F5
* 配置launch.json
  * const arg = process.argv;
  * 自动附加：auto attach
* 调试动作： step in/step out
* 数据展现： 本地、全局变量
* Log Point
* REPL：read eval print loop
## [1-6 nodejs调试命令行参数](https://nodejs.org/en/docs/guides/debugging-getting-started/)
* --inspect-brk  //直到attach上再运行程序，防止程序过快停止无法调试。
* inspect //命令行调试

# [Node.js debugging in VSCode 'launch.json'](https://code.visualstudio.com/docs/nodejs/nodejs-debugging)
launch.json各种参数的定义

