# [npm-package.json](https://docs.npmjs.com/files/package.json)
## 新建一个package.json文件 
`$ mkdir myapp`  
`$ cd myapp`  
`$ npm init`
## 安装包的技巧
`$ npm install --save`   //--save 是为了把安装信息加到package.json文件  
//package-lock.json 文件是为了锁定所有依赖的版本，防止下次重新安装包时版本不一致  
`$ npm i`  //下次直接npm i（npm install） 直接就可以安装所有包