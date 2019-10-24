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
*  busybox
*  正向代理和反向代理
正向代理：是一个位于客户端和原始服务器(origin server)之间的服务器，为了从原始服务器取得内容，客户端向代理发送一个请求并指定目标(原始服务器)，然后代理向原始服务器转交请求并将获得的内容返回给客户端。客户端必须要进行一些特别的设置才能使用正向代理。
正向代理的用途：
   （1）访问原来无法访问的资源，如google
   （2）可以做缓存，加速访问资源
   （3）对客户端访问授权，上网进行认证
   （4）代理可以记录用户访问记录（上网行为管理），对外隐藏用户信息
反向代理：初次接触反向代理的感觉是，客户端是无感知代理的存在的，反向代理对外都是透明的，访问者者并不知道自己访问的是一个代理。因为客户端不需要任何配置就可以访问。
反向代理（Reverse Proxy）实际运行方式是指以代理服务器来接受internet上的连接请求，然后将请求转发给内部网络上的服务器，并将从服务器上得到的结果返回给internet上请求连接的客户端，此时代理服务器对外就表现为一个服务器。
反向代理的作用：
   （1）保证内网的安全，可以使用反向代理提供WAF功能，阻止web攻击大型网站，通常将反向代理作为公网访问地址，Web服务器是内网。
   （2）负载均衡，通过反向代理服务器来优化网站的负载