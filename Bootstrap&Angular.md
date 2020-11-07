# [angular 项目中引入 bootstrap](https://codeburst.io/getting-started-with-angular-7-and-bootstrap-4-styling-6011b206080)

## step1:

```
npm install --save jquery popper bootstrap
```

## step2:

```
//angular.json
"styles": [
  "src/styles.scss",
  "node_modules/bootstrap/dist/css/bootstrap.min.css"
],
"scripts": [
  "./node_modules/jquery/dist/jquery.min.js",
  "./node_modules/bootstrap/dist/js/bootstrap.min.js"
],
```

## [Step3:遇到了一个 dropdown 无法使用的 bug 目前通过引入 ng-bootstrap 解决](https://www.techiediaries.com/angular-bootstrap-ui/)

```shell
npm install --save @ng-bootstrap/ng-bootstrap
```

```javascript
// app.module
import { NgbModule } from "@ng-bootstrap/ng-bootstrap";
@NgModule({
  // [...]
  imports: [NgbModule /* [...] */],
  // [...]
})
export class AppModule {}
```
