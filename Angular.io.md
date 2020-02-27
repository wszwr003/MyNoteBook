# [Introduction to the Angular Docs](https://angular.io/docs)
## 1 Getting Started  
### 1.1 *ngFor  
* Template File(.html):
    ```html
    <div *ngFor="let product of products">
        <h3>
            {{product.name}}
        </h3>
    </div>
    ```
### 1.2 *ngIf  
* Template File(.html):
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
### 1.6 Routing
