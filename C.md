# c语言程序设计book
## 5.5.3 字符串与字符数组
字符串是一种以“\0”结尾的字符数组。
### 字符数组的初始化:
c语言没有字符串变量，字符串常量不能直接赋初值给字符数组（只能在定义时，见上）。
```c++
char ch[10] = {'1','2','3','4','5'}; //其他位自动补\0，等同字符串
char ch[5] = {'1','2','3','4','5'}; //不补\0，不是字符串
char ch[] = "12345"; //自动补一个\0 Error 非法: char ch[5]; st="12345";/st[]="12345";
```
## 5.6.1 字符串指针
字符数组有很多弊端：1.定长。2.初始化后只能逐个赋值。
使用字符串指针一定要初始化:1.字符串常量赋值。2.其他字符串指针赋值。3.malloc和calloc函数。
## 6.4.1 返回指针值的函数
返回的指针必须是该函数调用结束后不被释放的内存地址。
## 6.4.2 函数指针
返回类型 (*函数指针变量名)（参数类型）;
int (*p) (void);

```c++
#include <stdio.h>
int add(int a,int b);
void main(){
    int (*p) (int,int);
    p=add;
    printf("%d",(*p)(1,2));
}
int add(int a,int b){
    return a+b;
}
```
## 7.1 宏定义
```c++
#define A 
#define PI 3.14
#define C(r) = 2*PI*r
#undef C

#ifdef A
//#else
#endif

#ifndef A
//#else
#endif

#if 1
//#else
#endif
```