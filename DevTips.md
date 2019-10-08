*  ORM:对象关系映射(Object Relational Mapping)
*  JDBC ORMs:  
    dbutils: 是对jdbc进行了相对简单的包装, 需要在代码中写sql语句  
    Mybatis: 进一步封装 jdbc,Sql语句写在配置文件中,面向对象操作,有一二级缓存功能  
    Hibernate: 对jdbc封装得最彻底的框架,纯面向对象,可以不用写SQL   
*  [Node ORM: sequelize ](https://www.cnblogs.com/y-yxh/p/6005729.html)
*  SSR:SERVER SIDE RENDER
*  Node.js REPL(Read Eval Print Loop:交互式解释器) 表示一个电脑的环境，类似 Window 系统的终端或 Unix/Linux shell，我们可以在终端中输入命令，并接收系统的响应。
Node 自带了交互式解释器，可以执行以下任务：
读取 - 读取用户输入，解析输入了Javascript 数据结构并存储在内存中。
执行 - 执行输入的数据结构
打印 - 输出结果
循环 - 循环操作以上步骤直到用户两次按下 ctrl-c 按钮退出。
Node 的交互式解释器可以很好的调试 Javascript 代码。
*  HTTPS(Hyper Text Transfer Protocol over Secure Socket Layer)
*  SSL(Secure Socket Layer)
*  [angular2-chartjs use github](https://github.com/emn178/angular2-chartjs)
    1. `npm install --save angular2-chartjs`
    2.   
        ```
            import { ChartModule } from 'angular2-chartjs';
            @NgModule({
                imports: [ ChartModule ]
                // ...
            })
            export class AppModule {
            }
        ```
    3.  ```javascript
        //javascript
        type = 'line';
        data = {
        labels: ["January", "February", "March", "April", "May", "June", "July"],
        datasets: [
            {
            label: "My First dataset",
            data: [65, 59, 80, 81, 56, 55, 40]
            }
        ]
        };
        options = {
        responsive: true,
        maintainAspectRatio: false
        };
        ```
        ```html
        //html
        <chart [type]="type" [data]="data" [options]="options"></chart>
        ```
