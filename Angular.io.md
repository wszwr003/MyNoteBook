# [Introduction to the Angular Docs](https://angular.io/docs)

# [1 Getting Started](https://angular.io/start)

- 名词解释
  - 组件:被@component 装饰器修饰的 ts 文件为一个组件,紧随其后的那个类就是组件类,否则就是一个普通类.
  - 模板:HTML 模板文件
  - 样式:CSS 样式文件
  - 组件的元数据:
    - selector:一旦在模板中找到对应的标签,就创建并插入该组件的一个实例.
    - templateUrl:HTML 模板文件路径,也可使用内联模板写在 ts 文件内.
    - styleUrls:CSS 样式文件路径,也可使用内联样式写在 ts 文件内.
    ```ts
    //模板文件和样式文件
    import { Component, OnInit } from "@angular/core";
    @Component({
      selector: "app-heroes",
      templateUrl: "./heroes.component.html",
      styleUrls: ["./heroes.component.css"]
    })
    export class HeroesComponent implements OnInit {
      constructor() {}
      ngOnInit() {}
    }
    ```
    - template:内联模板
    - styles:内联样式
    ```ts
    //内联模板和内联样式
    import { Component, OnInit } from "@angular/core";
    @Component({
      selector: "app-root",
      template: `
        <h1>Tour of Heroes</h1>
        <app-hero-main [hero]="hero"></app-hero-main>
      `,
      styles: ["h1 { font-weight: normal; }"]
    })
    export class HeroAppComponent {
      /* . . . */
    }
    ```
    - providers:服务提供商

## 1.1 \*ngFor

- Template File(.html)

```html
<div *ngFor="let product of products">
  <h3>
    {{product.name}}
  </h3>
</div>
```

## 1.2 \*ngIf

- Template File(.html)

```html
<p *ngIf="product.description">//TOSOLVE:判断条件的细节和语法学习</p>
<p *ngIf="product.price > 700"></p>
```

## 1.3 Interpolation: {{ statement }}

插值符:花括号纸巾通常是组件的属性(.ts 文件)的名字.默认情况下

```html
<p>
  title:{{ title }}
</p>
<div>
  <img src="{{ itemImageUrl }}" />
</div>
```

## 1.4 Property binding: [property]="statement"

```html
<img [src]="itemImageUrl" />
```

## 1.5 Event binding: (event)="statement/MostTimeIsFunction"

```html
<button (click)="share()">
  button_name
</button>
```

## 1.6 Input

**inpute 数据流转:** fatherComponent(.ts)->fatherTemplate(html)->childComponent->childTemplate  
**编程最佳流程:** fatherComponent->childComponent->childTemplate->fatherTemplate

- Input 组件(子组件?)

```ts
//需要input属性的组件
import { Component, OnInit } from "@angular/core";
import { Input } from "@angular/core"; //input component
@Component({
  selector: "app-title",
  template: `
    <h1>{{ product.name }}</h1>
    <!--input template-->
  `
})
export class TitleComponent {
  @Input() product; //input component
}
```

- 源组件(TOSOLVE:父组件?)

```ts
//定义属性的组件
import { Component, OnInit } from "@angular/core";
@Component({
  selector: "app-product",
  template: `
  <app-title [product]="product"></app--title>            <!--father template-->
`
})
export class ProductComponent {
  product = "product1"; //father component
}
```

## 1.7 Output

**Outpute 数据流转:** childTemplate->childComponent->fatherTemplate->fatherComponent  
**编程最佳流程(?TOSOLVE):**

- Output 组件(子组件)

```ts
import { Component, OnInit } from "@angular/core";
import { Output, EventEmitter } from "@angular/core"; //output component
@Component({
  selector: "app-alerts",
  template: `
    <button (click)="notify.emit()">Notify</button> //emit(value?: T)
    <!--output template-->
  `
})
export class AlertsComponent implements OnInit {
  @Output() notify = new EventEmitter(); //output component
}
```

- 接收组件(TOSOLVE:父组件?)

```ts
import { Component, OnInit } from "@angular/core";
@Component({
  selector: "app-product",
  template: `
    <app-alerts (notify)="onNotify()"></app-alerts>
    <!--father template-->
  `
})
export class ProductComponent implements OnInit {
  onNotify() {
    //father component
    window.alert("this is an alert!!");
  }
}
```

## 1.8 Routing(顺带 Material topBar)

- 路由模块

```ts
//app-routing.module.ts//路由模块代码
import { NgModule } from "@angular/core";
import { Routes, RouterModule } from "@angular/router";

const routes: Routes = [
  //localhost:port
  { path: "", component: ProductListComponent },
  //localhost:port/products/productId
  { path: "products/:productId", component: ProductDetailsComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule {}
```

- 根模块

```ts
//app.module.ts//导入路由模块的根模块
import { NgModule } from "@angular/core";
import { BrowserModule } from "@angular/platform-browser";
import { AppRoutingModule } from "./app-routing.module";

import { AppComponent } from "./app.component";
import { TopBarComponent } from "./top-bar/top-bar.component";
@NgModule({
  declarations: [
    AppComponent, //declare AppComponent
    TopBarComponent //declare TopBarComponent
  ],
  imports: [BrowserModule, AppRoutingModule],
  providers: [],
  bootstrap: [AppComponent] //set AppComponent as root component
})
export class AppModule {}
```

- 根组件

```ts
//app.component.ts
import { Component } from "@angular/core";
@Component({
  selector: "app-root",
  templateUrl: "./app.component.html",
  styleUrls: ["./app.component.css"]
})
export class AppComponent {}
```

```html
<!--app.component.html--><!--具有路由功能和topBar功能的根模板-->
<app-top-bar></app-top-bar>
<!--top bar-->
<div class="container">
  <router-outlet></router-outlet>
  <!--routing-->
</div>
```

- fatherTemplate of Routing

```html
<!--product-list.component.html-->
<!--父路由模板写法-->
<div *ngFor="let product of products; index as productId">
  <h3>
    <a
      [title]="product.name + ' details'"
      [routerLink]="['/products', productId]"
    >
      {{ product.name }}
    </a>
  </h3>
</div>
```

- topBar 组件

```ts
//top-bar.component.ts
import { Component, OnInit } from "@angular/core";
@Component({
  selector: "app-top-bar",
  templateUrl: "./top-bar.component.html",
  styleUrls: ["./top-bar.component.css"]
})
export class TopBarComponent implements OnInit {
  constructor() {}
  ngOnInit() {}
}
```

```html
<!--top-bar.component.html-->
<a [routerLink]="['/']">
  <h1>My Store</h1>
</a>
<a [routerLink]="['/cart']" class="button fancy-button">
  <i class="material-icons">shopping_cart</i>
  Checkout
</a>
```

- ProductDetailComponent  
  childRoutesComponent 的复用(针对相似的页面如不同商品的详情页面).通过导入 ActivatedRoute 模块并注入此模块,订阅其 paraMap 服务以获取当前路由的相关数据.  
  The ActivatedRoute is specific to each routed component that the Angular Router loads. It contains information about the route, its parameters, and additional data associated with the route.

```ts
//product-details.component.ts
import { Component, OnInit } from "@angular/core";
import { ActivatedRoute } from "@angular/router";
import { products } from "../products";

export class ProductDetailsComponent implements OnInit {
  product;
  constructor(private route: ActivatedRoute) {}
  ngOnInit() {
    this.route.paramMap.subscribe(params => {
      this.product = products[+params.get("productId")];
    });
  }
}
```

```html
<!--product-details.component.html-->
<h2>Product Details</h2>
<div *ngIf="product">
  <h3>{{ product.name }}</h3>
  <h4>{{ product.price | currency }}</h4>
  <p>{{ product.description }}</p>
</div>
```

## 1.9 Managing Data

## 1.10 Forms

## 1.11 Deployment

# [2 Click and Enter Event](https://angular.io/guide/user-input)

- button click event with no parametre

```ts
import { Component } from "@angular/core";

@Component({
  selector: "app-click-me",
  template: `
    <button (click)="onClickMe()">Click me!</button>
    {{ clickMessage }}
  `
})
export class ClickMeComponent {
  clickMessage = "";

  onClickMe() {
    this.clickMessage = "You are my hero!";
  }
}
```

- input keyup event with parametre \$event

```ts
import { Component } from "@angular/core";

@Component({
  selector: "app-key-up",
  template: `
    <input (keyup)="onKey($event)" />
    <p>{{ values }}</p>
  `
})
export class KeyUpComponent {
  values = "";
  /*
  onKey(event: any) { // without type info //不好!编程时不能获得参数提示
    this.values += event.target.value + ' | ';
  }
  */
  onKey(event: KeyboardEvent) {
    // with type info //好!编程时可以获得参数提示
    this.values += (event.target as HTMLInputElement).value + " | ";
  }
}
```

- input keyup event with template reference variable(模板引用变量)

```ts
@Component({
  selector: "app-loop-back",
  //只有应用程序发生了异步事件,Angular才会更新绑定(UI)
  //本代码将0绑定到keyup事件,虽然什么也没做但是满足了Angular要求,所以会更新UI.
  template: `
    <input #box (keyup)="(0)" />
    <p>{{ box.value }}</p>
  `
})
export class LoopbackComponent {}
```

```ts
@Component({
  selector: "app-key-up",
  //模板引用变量作为事件参数.
  template: `
    <input #box (keyup)="onKey(box.value)" />
    <p>{{ values }}</p>
  `
})
export class KeyUpComponent {
  values = "";
  onKey(value: string) {
    this.values += value + " | ";
  }
}
```

- 按键事件过滤/失去焦点事件

```ts
@Component({
  selector: "app-key-up",
  //仅仅绑定回车键/blur为失去焦点事件
  template: `
    <input #box (keyup.enter)="update(box.value)" (blur)="update(box.value)" />

    <p>{{ value }}</p>
  `
})
export class KeyUpComponent {
  value = "";
  update(value: string) {
    this.value = value;
  }
}
```

# 3 指令(Directive)

- 在 Angular 中有三种指令:
  1. 组件 - 拥有模板的指令.
  2. 属性型指令 - 改变元素和组件或其他指令的外观和行为的指令.(NgStyle)
  3. 结构型指令 - 通过添加和移除 DOM 元素来改变 DOM 布局的指令.(NgFor、NgIf)

## [3.1 属性型指令](https://angular.cn/guide/attribute-directives)

```ts
//mouse-enter-setble.directive.ts
import { Directive, ElementRef, HostListener, Input } from "@angular/core";
@Directive({
  //注意中括号
  selector: "[appMouseEnterSetble]"
})
export class MouseEnterSetbleDirective {
  //el: ElementRef; //[1]
  //TBS:此处@Input时,赋初值为什么不行?
  //此处设置了backgroundColor的别名与指令名称相同,可以简化调用方式
  @Input("appMouseEnterSetble") backgroundColor: string;
  @HostListener("mouseenter") onMouseEnter() {
    //如果没有设置则赋初始值'#DCDCFF'
    this.el.nativeElement.style.backgroundColor =
      this.backgroundColor || "#DCDCFF";
  }
  @HostListener("mouseleave") onMouseLeave() {
    this.el.nativeElement.style.backgroundColor = null;
  }
  //TBS:此处添加private修饰后,无需再声明全局变量[1]和赋值[2],why?
  constructor(private el: ElementRef) {
    //this.el = el; //[2]
    this.backgroundColor = "green";
  }
}
```

```html
<!--xxxx.component.html-->
<!--推荐!使用不带参数的属性指令,或者使用默认参数-->
<p appMouseEnterSetble >Highlight me!</p>
<!--不推荐!使用不带参数的属性指令,或者使用默认参数-->
<p [appMouseEnterSetble] >Highlight me!</p>
<!--不推荐!不使用别名设置参数方法,不加中括号:双引号里面为值!!!-->
<p appMouseEnterSetble backgroundColor="red">Highlight me!</p>
<!--推荐!不使用别名设置参数方法,加中括号:双引号里面为表达式!!!-->
<p appMouseEnterSetble [backgroundColor]="'red'">Highlight me!</p>
<!--不推荐!使用别名,不加中括号:双引号里面为值!!!-->
<p appMouseEnterSetble = "red" >Highlight me!</p>
<!--推荐!使用别名,加中括号:双引号里面为表达式!!!-->
<p [appMouseEnterSetble] = "'red'" >Highlight me!</p>
<!--FAO:通过测试发现@Input时也可以不加中括号!-->
```

## [3.2 结构型指令](https://angular.cn/guide/structural-directives)
```html


```
# 4 管道(Pipe)

是一种把从后端获取的数据**转换格式**后显示到界面的途径.
# [5 可观察对象(Observable)与RxJS](https://angular.cn/guide/observables)
## [5.1 可观察对象(Observable)]
## [5.3 Angular中的可观察对象]
* EventEmitter 类派生自 Observable。
* HTTP 模块使用可观察对象来处理 AJAX 请求和响应。
* 路由器和表单模块使用可观察对象来监听对用户输入事件的响应。

