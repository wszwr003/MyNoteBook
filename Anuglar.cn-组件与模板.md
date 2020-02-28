# [ANGULAR LEARNING](https://www.angular.cn)
## [架构](https://www.angular.cn/guide/architecture)
### [架构概览](https://www.angular.cn/guide/architecture)
* **模块module：** Angular 是一个用 HTML 和 TypeScript 构建客户端应用的平台与框架。Angular 的基本构造块是 `NgModule`，它为`component`提供了编译的上下文环境。每个 Angular 应用都有一个`root module`，通常命名为`AppModule`。  
像 JavaScript 模块一样，`NgModule` 也可以从其它 `NgModule` 中导入功能，并允许导出它们自己的功能供其它 `NgModule` 使用。 比如，要在你的应用中使用`Router`服务，就要导入 `Router` 这个 `NgModule`。
* **组件component：** 每个 Angular 应用都至少有一个组件，也就是`root component` ，它会把组件树和页面中的 DOM 连接起来。 每个组件都会定义一个类，其中包含应用的数据和逻辑，并与一个 `HTML template`相关联，该模板定义了一个供目标环境下显示的视图。  
`@Component()` 装饰器表明紧随它的那个类是一个组件，并提供模板和该组件专属的元数据。 
* **服务与依赖注入service & dependency injection：** 对于与特定视图无关并希望跨组件共享的数据或逻辑，可以创建服务类。 服务类的定义通常紧跟在 “@Injectable()” 装饰器之后。
依赖注入（DI）让你可以保持组件类的精简和高效。有了 DI，组件就不用从服务器获取数据、验证用户输入或直接把日志写到控制台，而是会把这些任务委托给服务。
* **Routing：** 路由器会把类似浏览器 URL 的路径映射到视图而不是页面。 当用户执行一个动作时（比如点击链接），本应该在浏览器中加载一个新页面，但是路由器拦截了浏览器的这个行为，并显示或隐藏一个视图层次结构。
* **OverView:**
![Angular overview!](./src/angularoverview.png)
### [模块简介](https://www.angular.cn/guide/architecture-modules)
*  **@NgModule 元数据:** 小型的应用可能只有一个 NgModule，不过大多数应用都会有很多特性模块。应用的根模块之所以叫根模块，是因为它可以包含任意深度的层次化子模块。
@NgModule metadata：
    * declarations（可声明对象表） —— 那些属于本 NgModule 的组件、指令、管道。
    * exports（导出表） —— 那些能在其它模块的组件模板中使用的可声明对象的子集。
    * imports（导入表） —— 那些导出了本模块中的组件模板所需的类的其它模块。
    * providers —— 本模块向全局服务中贡献的那些服务的创建器。 这些服务能被本应用中的任何部分使用。（你也可以在组件级别指定服务提供商，这通常是首选方式。）
    * bootstrap —— 应用的主视图，称为根组件。它是应用中所有其它视图的宿主。只有根模块才应该设置这个 bootstrap 属性。    
  
    ```typescript
    import { NgModule }      from '@angular/core';
    import { BrowserModule } from '@angular/platform-browser';
    @NgModule({
    imports:      [ BrowserModule ],
    providers:    [ Logger ],
    declarations: [ AppComponent ],
    exports:      [ AppComponent ],
    bootstrap:    [ AppComponent ]
    })
    export class AppModule { }
    ```
*  **NgModule 和 JavaScript 的模块:** NgModule 系统与 JavaScript 对象的模块系统不同，而且也没有直接关联。 这两种模块系统不同但互补。你可以使用它们来共同编写你的应用。
*  **Angular 自带的库:** Angular 会作为一组 JavaScript 模块进行加载，你可以把它们看成库模块。每个 Angular 库的名称都带有` @angular `前缀。 使用 npm 包管理器安装 Angular 的库，并使用 JavaScript 的 import 语句导入其中的各个部分。
### [组件简介](https://www.angular.cn/guide/architecture-components)
*  @Component metadata：
   * selector：是一个选择器，它会告诉 Angular，一旦在模板 HTML 中找到了这个选择器对应的标签，就创建并插入该组件的一个实例。 
   * templateUrl：该组件的 HTML 模板文件相对于这个组件文件的地址。  
   * template 属性的值来提供内联的 HTML 模板。 这个模板定义了该组件的宿主视图。  
   * styleUrls: 样式模板本件地址。
   * providers：当前组件所需的服务提供商的一个数组。在这个例子中，它告诉 Angular 该如何提供一个 HeroService 实例，以获取要显示的英雄列表。  
    ```typescript
    @Component({
        selector:    'app-hero-list',
        templateUrl: './hero-list.component.html',
        providers:  [ HeroService ]
    })
    export class HeroListComponent implements OnInit {
    /* . . . */
    }
    ```
* 模板与视图  
![compont tree](./src/component-tree.png)
### [服务与依赖注入简介](https://www.angular.cn/guide/architecture-services)
Angular 把组件和服务区分开，以提高模块性和复用性。 通过把组件中和视图有关的功能与其他类型的处理分离开，你可以让组件类更加精简、高效。  
理想情况下，组件的工作只管用户体验。 它应该提供用于数据绑定的属性和方法，以便作为视图（由模板渲染）和应用逻辑（通常包含一些模型的概念）的中介者。  
组件应该把诸如`从服务器获取数据`、`验证用户输入`或`直接往控制台中写日志`等工作委托给各种服务。通过把各种处理任务定义到可注入的服务类中，你可以让它被任何组件使用。 通过在不同的环境中注入同一种服务的不同提供商，你还可以让你的应用更具适应性。  
Angular 不会强迫你遵循这些原则。Angular 只会通过依赖注入来帮你更容易地将应用逻辑分解为服务，并让这些服务可用于各个组件中。
#### [服务范例](https://www.angular.cn/guide/architecture-services#service-examples)
#### 服务级别
* 默认情况下，Angular CLI 的 ng generate service 命令会在 @Injectable() 装饰器中提供元数据来把它注册到根注入器中。
* 当你使用特定的 NgModule 注册提供商时，该服务的同一个实例将会对该 NgModule 中的所有组件可用。要想在这一层注册，请用 @NgModule() 装饰器中的 providers 属性。
* 当你在组件级注册提供商时，你会为该组件的每一个新实例提供该服务的一个新实例。 要在组件级注册，就要在 @Component() 元数据的 providers 属性中注册服务提供商。
## 模板与组件
### [显示数据](https://www.angular.cn/guide/displaying-data)
* 插值表达式 (interpolation) ：{{}}
* 变量赋值的方式初始化属性，也可以使用构造函数来声明和初始化属性。
* ngFor显示组件：
    ```typescript
    template:   `
                <h1>{{title}}</h1>
                <h2>My favorite hero is: {{myHero}}</h2>
                <p>Heroes:</p>
                <ul>
                    <li *ngFor="let hero of heroes">
                    {{ hero }}
                    </li>
                </ul>
                `
    export class AppComponent {
    title = 'Tour of Heroes';
    heroes = ['Windstorm', 'Bombasto', 'Magneta', 'Tornado'];
    myHero = this.heroes[0];
    }
    ```
* 创建一个实体类：`ng generate class hero`
  ```typescript
  export class Hero {
    constructor(
        public id: number,
        public name: string) { }
    }   
  ```
* ngIf条件显示：
    ```html
    <p *ngIf="heroes.length > 3">There are many heroes!</p>
    ```
### [模板语法](https://www.angular.cn/guide/template-syntax)
从模型-视图-控制器 (MVC) 或模型-视图-视图模型 (MVVM) 的经验中，很多人都熟悉了组件和模板这两个概念。 在 Angular 中，组件扮演着控制器或视图模型的角色，模板则扮演视图的角色。
* **插值表达式 {{...}}:** 所谓 "插值" 是指将表达式嵌入到标记文本中。  
  *  在{{}}之间的“素材”，通常是组件属性的名字。Angular 会用组件中相应属性的字符串值，替换这个名字。  
        ```html
        <p>{{title}}</p>
        <div><img src="{{itemImageUrl}}"></div>
        ```
  * 括号间的素材是一个`模板表达式`，Angular 先对它求值，再把它转换成字符串，表达式可以调用宿主组件的方法。
    ```html
    <p>The sum of 1 + 1 is not {{1 + 1 + getVal()}}.</p>
    ```
* **表达式上下文:** 
典型的表达式上下文就是组件实例，它是各种绑定值的来源。 在下面的代码片段中，双花括号中的 recommended  和引号中的 itemImageUrl2  所引用的都是 AppComponent 中的属性。
    ```html
    <h4>{{recommended}}</h4>
    <img [src]="itemImageUrl2">
    ```
  * `表达式的上下文变量`可以包括组件之外的对象。 比如`模板输入变量` (let customer )和`模板引用变量`(#customerInput)就是备选的上下文对象之一。
      ```html
      <ul>
      <li *ngFor="let customer of customers">{{customer.name}}</li>
      </ul>
      ```
      ```html
      <input #customerInput>{{customerInput.value}}</label>
      ```
  * `表达式的上下文变量`是由模板变量、__指令的上下文变量__（如果有）和组件的成员叠加而成的。
* **模板语句:** Template statements： (event)="statement"  
模板语句有副作用。 这是事件处理的关键。因为你要根据用户的输入更新应用状态。  
和模板表达式一样，模板语句使用的语言也像 JavaScript。 模板语句解析器和模板表达式解析器有所不同，特别之处在于它支持基本赋值 (=) 和表达式链 (; 和 ,)。
* **绑定语法：**

    | 数据方向 | 语法 | 绑定类型 |
    | - | - | - |
    | view-to-source | `(target)="statement"`<br>`on-target="statement"` | 事件 |
    | source-to-view | `{{expression}}`<br>`[target]="expression"`<br>`bind-target="expression"` | 插值<br>属性<br>Attribute<br>CSS<br>类样式 |
    | 双向 | `[(target)]="expression"`<br>`bindon-target="expression"` | 双向 |

------

 **HTML attribute 与 DOM property 的对比:**
attribute 初始化 DOM property，然后它们的任务就完成了。property 的值可以改变；attribute 的值不能改变。   
添加或删除 disabled 这个 attribute 会禁用或启用这个按钮。但 attribute 的值无关紧要，这就是你为什么没法通过 `<button disabled="false">仍被禁用</button>` 这种写法来启用按钮。  
设置按钮的 disabled 这个 property（如，通过 Angular 绑定）可以禁用或启用这个按钮。 这就是 property 的价值。  
就算名字相同，HTML attribute 和 DOM property 也不是同一样东西。
`在 Angular 的世界中，attribute 唯一的作用是用来初始化元素和指令的状态。 当进行数据绑定时，只是在与元素和指令的 property 和事件打交道，而 attribute 就完全靠边站了。`   

------

* [**绑定目标：**](https://angular.cn/guide/template-syntax#binding-targets)
    | 绑定类型 | 目标 | 范例 |
    | - | - | - |
    | Property | 元素的 property<br>组件的 property<br>指令的 property | <img [src]="heroImageUrl"><br><app-hero-detail [hero]="currentHero"></app-hero-detail><br><div [ngClass]="{'special': isSpecial}"></div> |
    | 事件 | 元素的事件<br>组件的事件<br>指令的事件 | <button (click)="onSave()">Save</button><br><app-hero-detail (deleteRequest)="deleteHero()"></app-hero-detail><br><div (myClick)="clicked=$event" clickable>click me</div> |
    | 双向 | 事件与 property | <input [(ngModel)]="name"> |
    | Attribute | attribute（例外情况） | <button [attr.aria-label]="help">help</button> |
    | CSS 类 | class property | <div [class.special]="isSpecial">Special</div> |
    | 样式 | style property | <button [style.color]="isSpecial ? 'red' : 'green'">|    
* **属性绑定:**  
元素属性可能是最常见的绑定目标，但 Angular 会先去看这个名字是否是某个已知指令的属性名，就像下面的例子中一样：
```html
<div [ngClass]="classes">[ngClass] binding to the classes property</div>
```
模板表达式应该返回目标属性所需类型的值。 如果目标属性想要个字符串，就返回字符串。 如果目标属性想要个数字，就返回数字。 如果目标属性想要个对象，就返回对象。设置自定义组件的模型属性（这是父子组件之间通讯的重要途径）：
```html
<app-hero-detail [hero]="currentHero"></app-hero-detail>
```
* **attribution,class,style绑定：**
```
<!-- create and set an aria attribute for assistive technology -->
<button [attr.aria-label]="actionName">{{actionName}} with Aria</button>
<!-- reset/override all class names with a binding  -->
<div class="bad curly special" [class]="badCurly">Bad curly</div>
<!-- class toggle the "special" class on/off with a property -->
<!-- class.name的时候比较特殊表达式是true/false来判断是否添加该类型 -->
<div [class.special]="isSpecial">The class binding is special</div>
<!-- styles -->
<button [style.color]="isSpecial ? 'red': 'green'">Red</button>
<button [style.background-color]="canSave ? 'cyan': 'grey'" >Save</button>
<button [style.font-size.em]="isSpecial ? 3 : 1" >Big</button>
<button [style.font-size.%]="!isSpecial ? 150 : 50" >Small</button>
```
* **事件绑定：**
*    
## 生命周期钩子 
## 组件交互（父子）
* 通过`@input`装饰器把数据从父组件传到子组件。
  parent.html-->child.html
* 通过 setter 截听输入属性值的变化
  parent.html-->child.ts-->child.html
    ```typescript
    _allowDay: boolean;
    get allowDay(): boolean {
        return this._allowDay;
    }

    @Input('allowDay')
    set allowDay(value: boolean) {
        this._allowDay = value;
        this.updatePeriodTypes();
    }
    ```
* 通过ngOnChanges()来截听输入属性值的变化
  parent.html-->child.ts-->child.html
    ```typescript    
    export class VersionChildComponent implements OnChanges {
        @Input() major: number;
        @Input() minor: number;
        changeLog: string[] = [];
        
        ngOnChanges(changes: {[propKey: string]: SimpleChange}) {
            let log: string[] = [];
            for (let propName in changes) {
            let changedProp = changes[propName];
            let to = JSON.stringify(changedProp.currentValue);
            if (changedProp.isFirstChange()) {
                log.push(`Initial value of ${propName} set to ${to}`);
            } else {
                let from = JSON.stringify(changedProp.previousValue);
                log.push(`${propName} changed from ${from} to ${to}`);
            }
            }
            this.changeLog.push(log.join(', '));
        }
    }
    ```
* 父组件监听子组件的事件@output EventEmitter
  child.html-->parent.ts-->parent.html
* 父组件与子组件通过本地变量互动
  child.html-->#var-->parent.html
  父组件不能使用数据绑定来读取子组件的属性或调用子组件的方法。但可以在父组件模板里，新建一个本地变量来代表子组件，然后利用这个变量来读取子组件的属性和调用子组件的方法
  把本地变量(#timer)放到(<countdown-timer>)标签中，用来代表子组件。这样父组件的模板就得到了子组件的引用，于是可以在父组件的模板中访问子组件的所有属性和方法。
* 父组件调用@ViewChild()
  这个本地变量方法是个简单便利的方法。但是它也有局限性，因为父组件-子组件的连接必须全部在父组件的模板中进行。父组件本身的代码对子组件没有访问权。
* 父组件和子组件通过服务来通讯
## 属性型指令
* **指令概览:**
指令分为三类，组件，属性指令和结构性指令
组件（Component directive）：UI组件，继承于Directive；  
属性指令（Attribute directive）：改变组件的样式；  
结构指令（Structural directive）：改变DOM布局；  
属性指令例如 ngClass  ngStyle  
结构性指令 *ngIf\*ngFor\*ngSwitch  

