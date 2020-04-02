# 常用模块功能

| NgModule            | from                      | usage                                   |
| ------------------- | ------------------------- | --------------------------------------- |
| BrowserModule       | @angular/platform-browser | 想要在浏览器运行时                      |
| CommonModule        | @angular/common           | 使用 NgIf 和 NgFor 时                   |
| FormsModule         | @angular/forms            | 构建模板驱动表单时(含 NgModel 双向绑定) |
| ReactiveFormsModule | @angular/forms            | 构建响应式表单                          |
| RouterModule        | @angular/router           | 使用路由功能                            |
| HttpClientModule    | @angular/common/http      | 和服务器对话时                          |

# [A deep dive on Angular decorators](https://ultimatecourses.com/blog/angular-decorators)

## Decorators Angular Offers:

- Class decorators, e.g. `@component` and `@NgModule`
- Property decorators, e.g. `@Input` and `@Output`
- Method decorators, e.g. `@HostListener`
- Parameter decorators for parameters inside class constructors, e.g. `@Inject`

## Decorators are actually just functions, its as simple as that, and are called with whatever they are decorating.
