# [**npm-package.json**](https://docs.npmjs.com/files/package.json)

## 新建一个 package.json 文件

`$ mkdir myapp`  
`$ cd myapp`  
`$ npm init`

## 安装包的技巧

`$ npm install --save` //--save -S 是为了把安装信息加到 package.json 文件 ,运行时依赖 `$ npm install --save-dev`  
//--save-dev -D 是为了把安装信息加到 package.json 文件 ,开发时依赖  
//package-lock.json 文件是为了锁定所有依赖的版本，防止下次重新安装包时版本不一致  
`$ npm i` //下次直接 npm i（npm install） 直接就可以安装所有包

## 查看

`npm ls -g` //查看所有全局安装的模块  
`npm config ls` //查看 npm 默认设置（部分）  
`npm config ls -l` //查看 npm 默认设置（全部）  
`npm list --depth=0 -global`

## Packages List

- `@angular/flex-layout`<sup>[光维]</sup>  
  实现响应式布局，安装：`npm i -s @angular/flex-layout @angular/cdk`
- `@angular/material`<sup>[光维]</sup>  
  angular 官方前端组件，安装：`ng add @angular/material`
- `angular-2-local-storage`<sup>[光维]</sup>  
  实现本机缓存，分为`localStorage`和`sessionStorage`
- `angular2-baidu-map`<sup>[光维]</sup> 百度地图
- `@amap/amap-jsapi-loader`<sup>[光维]</sup>  
  angular 实现高德地图
- `d3`<sup>[光维]</sup>
- `xlsx`<sup>[irest]</sup>  
  简单 xlsx 导入导出无法设置样式
- `exceljs`<sup>[irest]</sup>（结合`file-saver`一起使用）  
  可以设置复杂的 xlsx 格式、样式
- `highcharts`<sup>[光维],[杭钢]</sup>  
  图表
- `material-icons`<sup>[光维]</sup>  
  实现本地 material icon（google 网站不稳定有时网页无法显示 icons）
- `ngx-spinner`<sup>[光维]</sup>  
  网页初始化载入等待动画
- `ezuikit-js`<sup>[杭钢]</sup>  
  萤石摄像头驱动包
- `particle-wave`<sup>[杭钢]</sup>  
  粒子波动背景
- `@capacitor/{..}`<sup>[irest]</sup>  
  实现 angular web 应用=>android\ios
- `electron` `electron-builder` `electron-packager`<sup>[irest]</sup>  
  实现 angular web 应用=>desktop exe/dmg
