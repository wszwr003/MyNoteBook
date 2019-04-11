# [VSCode](https://code.visualstudio.com/docs)
## interface overview
* explorer资源管理器     `Ctrl+Shift+E`
* GIT                   `Ctrl+Shift+G`
* search                `Ctrl+Shift+S`
* Debug                 `Ctrl+Shift+D`
* extension             `Ctrl+Shift+X`
* errors&warning    `Ctrl+Shift+M`
* terminal  Ctrl+`
## Editor ShortCut
### Muti-Cursor Editing
* box select  
`Ctrl+Shift+Alt+Down`  
`Ctrl+Shift+Alt+Up`  
`Ctrl+Shift+Alt+Right`  
`Ctrl+Shift+Alt+Left`  
`Shift+Alt+mouse`
* Muti-Curors  
`Ctrl+Alt+Up`  
`Ctrl+Alt+Down`  
`Alt+Click`  
* Create cursors on all occurrences of a string  
`Step1:select a string`  
`Step2:Ctrl+Shift+L`  
* IntelliSense
`Ctrl+k L`  
* copy a line
`Shift+Alt+down/up`
* move a line
`Alt+down/up`
* delete a line 
`Ctrl+Shift+K`
* rename object
`F2`
* rename all occure place
`Ctrl+F2`
* Firnatting 代码整理  
all doc:`Shift+Alt+F`   
selected:`Ctrl+k Ctrl+F`  
* Fold&unFold  
`Ctrl+Shift+[`  
`Ctrl+Shift+]`
## Extension
* ESLint before use  
`npm install -g eslint `   
`eslint --init `  
`Disable ESLint`  
* Markdown All in One
PreView：`Ctrl+K V`
## Debug
**调试工具功能:**   
典型的调试器通常能够在程序运行时拥有以下这些功能，例如单步运行（single-stepping）、利用中断点（breakpoint）使程序遇到各种种类的事件（event）时停止（breaking）（一般用于使程序停止在想要检查的状态）、以及追踪某些变量的变化。有些调试器也有能力在想要调试的程序在运行状态时，去改变它的状态，而不仅仅只是用来观察而己。  
软件要能够（或经常）运行在不同的调试器下进行测试，是非常重要的。不过由于调试器出现将做对软件程序的内部时间的不可避免的变动。所以，即使是一个几近完美的调试器，在多任务环境或分布式系统下，它也会更难去测试到运行时（runtime）的问题。  
**编译器：**   
是一种计算机程序，它会将用某种编程语言写成的源代码（高级语言），转换成另一种编程语言（机器语言、汇编语言）。  
**一个现代编译器的主要工作流程如下：**  
源代码（source code）→ 预处理器（preprocessor）→ 编译器（compiler）→ 汇编程序（assembler）→ 目标代码（object code）→ 链接器（Linker）→ 可执行文件（executables）
**为什么node.js不需要编译就能运行？**  
编程语言分为`编译型语言`和`解释型语言`两类，编译型语言在执行之前要先进行完全编译，而解释型语言一边编译一边执行，很明显解释型语言的执行速度是慢于编译型语言的，而JavaScript就是一种解释型脚本语言，支持动态类型、弱类型、基于原型的语言，内置支持类型。鉴于JavaScript都是在前端执行，而且需要及时响应用户，这就要求JavaScript可以快速的解析及执行。[**见=>WebKit渲染引擎和V8Javascript引擎详解**](https://blog.csdn.net/swimming_in_it_/article/details/78869549)

