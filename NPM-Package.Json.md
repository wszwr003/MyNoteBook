# [__npm-package.json__](https://docs.npmjs.com/files/package.json)
## 新建一个package.json文件 
`$ mkdir myapp`  
`$ cd myapp`  
`$ npm init`
## 安装包的技巧
`$ npm install --save`   //--save -S 是为了把安装信息加到package.json文件 ,运行时依赖 
`$ npm install --save-dev`   
//--save-dev -D 是为了把安装信息加到package.json文件 ,开发时依赖   
//package-lock.json 文件是为了锁定所有依赖的版本，防止下次重新安装包时版本不一致  
`$ npm i`  //下次直接npm i（npm install） 直接就可以安装所有包
## 查看
`npm ls -g` //查看所有全局安装的模块   
`npm config ls`  //查看npm默认设置（部分）  
`npm config ls -l`  //查看npm默认设置（全部）   