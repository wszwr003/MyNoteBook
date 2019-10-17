# [your first electrion exe](https://electronjs.org/docs/tutorial/first-app#trying-this-example)
## new project:
```
mkdir your-app
type nul> main.js
type nul> index.html
```
```
npm init //generate package.json
npm install --save-dev electrion 
```
```
git init 
type node_modules>.gitignore
```
## 基本目录：
```
your-app/
├── .git
├── .gitignore
├── node_modules     
├── package.json 
├── package-lock.json  
├── main.js //如果 main 字段没有在 package.json 中出现，那么 Electron 将会尝试加载 index.js 文件
└── index.html   
```
## [electron官网最小运行代码示例](https://electronjs.org/docs/tutorial/first-app#trying-this-example)
## [查看example](https://github.com/electron/electron-quick-start)
## [npm i时卡在electron太慢](https://blog.csdn.net/qq_33699981/article/details/78516618)
## [electron-builder 卡在nsis-resource](https://segmentfault.com/q/1010000011726124/a-1020000011912627)
## [用electron-build或者electron-builder添加serialport依赖时windows下出现如下问题！！](https://github.com/chjj/pty.js/issues/60)
err:  
MSBUILD : error MSB4132: The tools version "2.0" is unrecognized. Available tools versions are "4.0".
解决：  
open up a new cmd as administrator and run this command:  
`npm install --global --production windows-build-tools`  
then  
`npm config set msvs_version 2017 --global`    //just wait  
close all instances of shell/cmd, reopen a cmd (regular this time, non-administrator) return to your directory where you are trying to run npm install and run it again

## [添加了windows-build-tools后又出现了MSB8020err](https://github.com/brianmcd/contextify/issues/210)
err:  
error MSB8020: The builds tools for v140 (Platform Toolset = 'v140') cannot be found.  
解决：  
I finally realized that if I execute `npm install` while inside of `the Developer Command Prompt for VS2015` that I'd have no issues finding the right build tools. When executing inside that context everything works perfectly.