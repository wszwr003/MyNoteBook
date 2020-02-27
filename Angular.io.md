# [Introduction to the Angular Docs](https://angular.io/docs)
## 1 Getting Started
* 名词解释 
  * 组件:被@component装饰器修饰的ts文件为一个组件,紧随其后的那个类就是组件类,否则就是一个普通类.
  * 模板:HTML模板文件
  * 样式:CSS样式文件
  * 组件的元数据:  
    * selector:一旦在模板中找到对应的标签,就创建并插入该组件的一个实例.
    * templateUrl:HTML模板文件路径,也可使用内联模板写在ts文件内.
    * styleUrls:CSS样式文件路径,也可使用内联样式写在ts文件内.
    ```ts
    //模板文件和样式文件
    import { Component, OnInit } from '@angular/core';
    @Component({
    selector: 'app-heroes',
    templateUrl: './heroes.component.html',
    styleUrls: ['./heroes.component.css']
    })
    export class HeroesComponent implements OnInit {
    constructor() { }
    ngOnInit() { }
    }
    ```
    * template:内联模板
    * styles:内联样式
    ```ts
    //内联模板和内联样式
    import { Component, OnInit } from '@angular/core';
    @Component({
    selector: 'app-root',
    template: `
        <h1>Tour of Heroes</h1>
        <app-hero-main [hero]="hero"></app-hero-main>
    `,
    styles: ['h1 { font-weight: normal; }']
    })
    export class HeroAppComponent {
    /* . . . */
    }
    ```
    * providers:服务提供商
### 1.1 *ngFor  
* Template File(.html)
```html
<div *ngFor="let product of products">
    <h3>
        {{product.name}}
    </h3>
</div>
```
### 1.2 *ngIf  
* Template File(.html)
```html
<p *ngIf="product.description"> //TOSOLVE:判断条件的细节和语法学习    
</p>
<p *ngIf="product.price > 700">	
</p>
```
### 1.3 InterPolation: {{ }} 
差值符:花括号纸巾通常是组件的属性(.ts文件)的名字.默认情况下
```html
<p>
    title:{{ title }}
</p>
<div>
    <img src="{{ itemImageUrl }}">
</div>
```
### 1.4 Property binding: [property]="statement" 
```html
<img [src]="itemImageUrl">
```
### 1.5 Event binding: (event)="statement/MostTimeIsFunction"  
```html
<button (click)="share()">
    button_name
</button>
```
### 1.6 Input
* Input组件(子组件?)
```ts
//需要input属性的组件
import { Component, OnInit } from '@angular/core';
import { Input } from "@angular/core"
@Component({
selector: 'app-product-title',
template: `
    <h1>{{ product.name }}</h1>
`
})
export class ProductTitleComponent {
    @Input() product;
    constructor() {}
    ngOnInit() {}
}
```  
* 源组件(TOSOLVE:父组件?)
```ts
//定义属性的组件
import { Component, OnInit } from '@angular/core';
@Component({
selector: 'app-product',
template: `
    <app-product-title [product]="product">  
	</app-product-title>
`
})
export class ProductComponent {
    product = "product1";
}
```
### 1.7 Output
* Output组件(子组件)
```ts
import { Component, OnInit } from "@angular/core";
import { Output, EventEmitter } from "@angular/core";
@Component({
  selector: "app-product-alerts",
  template: `
    <button (click)="notify.emit()">Notify</button>
`
})
export class ProductAlertsComponent implements OnInit {
  @Output() notify = new EventEmitter();
}
```
* 接收组件(TOSOLVE:父组件?)
```ts
import { Component, OnInit } from "@angular/core";
@Component({
  selector: "app-product-alerts",
  template: `
	<app-product-alerts (notify)="onNotify()">
	</app-product-alerts>
`
})
export class ProductAlertsComponent implements OnInit {
  onNotify() {
    window.alert("this is an alert!!");
  }
}
```
### 

