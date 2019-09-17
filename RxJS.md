# [RXJS 基本](https://rxjs.dev/guide/overview)
* **RXJS是用可观察序列组成异步和基于事件的程序的库。**
## 基本概念：
    1. 可观察对象（observable）：表示一组在未来可以调用的值和事件的集合。
    2. 观察者（observer）：表示一组监听可观察对象传递的值的回调。
    3. 订阅（subscription）：表示一个可观察对象的执行。
    4. 操作符（operator）：用来操作可观察对象的功能性函数。
    5. 调度程序（Schedulers）：为了控制并发而进行的集中收发。
## Observable
### Pull versus Push  
\ | SINGLE | MULTIPLE
- | - | -
PULL | Funtcion | Iterator
PUSH | Promise  | Observable

\ | PRODUCER | CONSUMER
- | - | -
PULL | Passive: produces data when requested. | Active: decides when data is requested.
PUSH | Active: produces data at its own pace.  | Passive: reacts to received data.
### example
```typescript
import { Observable } from 'rxjs';

const observable = new Observable(subscriber => {
  try {
    subscriber.next(1);
    subscriber.next(2);
    subscriber.next(3);
    setTimeout(() => {
        subscriber.next(4);
        subscriber.complete();
    }, 1000);
  } catch (err) {
    subscriber.error(err); // delivers an error if it caught one
  }
});

console.log('just before subscribe');
observable.subscribe({
  next(x) { console.log('got value ' + x); },
  error(err) { console.error('something wrong occurred: ' + err); },
  complete() { console.log('done'); }
});
console.log('just after subscribe');
```
```cmd
just before subscribe
got value 1
got value 2
got value 3
just after subscribe
got value 4
done
```