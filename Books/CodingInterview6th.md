# Coding interview 6TH

## Chapter 6 大 O

- 一个算法的时间复杂度:
  - 最好情况通常为 O(1),因此没有意义.
  - 期望情况和最坏情况通常相等,但有例外.
- 大 O 仅仅描述了增长趋势,O(N)很有可能比 O(1)快;大 O 更多的表现了运行时间的规模,O(N)并不总是比 O(N<sup>2</sup>)快.
- 复杂度加法和乘法:
  - 如果算法是“做这个,结束之后做那个”则复杂度相加;
  - 如果算法是“对这个每个元素,做那个”则复杂度相乘.
  ```c++
  //O(A + B)
  for(int a : arrA){
    print(a);
  }
  for(int b : arrB){
    print(b);
  }
  //O(A*B)
  for(int a : arrA){
    for(int b : arrB){
      print(a + "," + b);
    }
  }
  ```

### 6.8 二分 LogN

如果元素个数每次减半,它的运行时间很有可能是: `O(LogN)`,如二分查找、平衡二叉搜索树.

### 6.9 递归 2<sup>N</sup>

当出现递归函数时,它的运行时间往往是(偶尔不是): **O(分支数<sup>深度</sup>)**

## 9.1 数组与字符串

### 9.1.1 散列表(哈希表、Hash Table)

哈希表（Hash table，也叫散列表），是根据关键码值(Key)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做`散列函数`，存放记录的数组叫做散列表。

- step1:通过哈希码函数计算哈希码 `hash code = hash(key);` `散列值 = 散列函数(键)` 常见的散列函数:MD5、SHA-1
- step2:数组地址映射
  - 取模散列法
  - 平方散列散列法
  - 斐波那契乘数散列法
- step3:散列冲突,即两个不同的 key,hash code 相同!再好的算法都无法解决因为 key 无限,hash code 有限!
  - 直接使用链表数组解决!
  - 开放寻址法:线性探测、二次方探测、多重散列法.

### 9.1.2 ArrayList\可变长数组、动态数组

本质是一个可变长的对象数组,可以存放不同对象.

### 9.1.3 StringBuilder

本质是一个可变长字符数组,通过 toString 方法返回一个 string

### 题目

## 9.2 链表

链表中的某些问题可以通过递归来解决,但是递归的时间复杂度至少为 O(n),其实所有的递归可以转化为迭代来实现,但实现起来复杂的多.

```java
//java 链表实现
class Node{
  Node next = null;
  int data;
  public Node(int data){
    this.data = data;
  }
  public appendToTail(int data){
    Node nodeNew = new Node(data);//不会销毁?
    Node curr = this;  //this is link head
    while(curr.next != null){
      curr = curr.next;
    }
    curr.next = end;
  }
}
```

```c
//c链表实现,通过测试.
#include <stdio.h>  //print
#include <stdlib.h>  //malloc

struct node{
  int data;
  struct node* next;
};
void appendToTail(struct node* head,int data){
  struct node* curr = head;
  struct node* nodeNew = (struct node*)malloc(sizeof(struct node));
  nodeNew->data = data;
  nodeNew->next = NULL;
  while(curr->next!=NULL){
    curr = curr->next;
  }
  curr->next = nodeNew;
}
void traverseList(struct node* head){
  struct node* p = head->next;
  while(p != NULL){
    printf("%d\n",p->data);
    p = p->next;
  }
}
int main(){
  struct node* head=(struct node*)malloc(sizeof(struct node));//FAO:为什么需要分配空间?
  head->data = 0;
  head->next = NULL;
  appendToTail(head,1);
  appendToTail(head,2);
  traverseList(head);
}
```

## 9.3 栈与队列

### 9.3.1 栈(LIFO)

操作系统中的堆栈和数据结构中的堆栈是完全不同的两个概念!

### 9.3.2 队列(FIFO)

## 9.4 树与图

### 9.4.1 树

树定义:

- 编程中每棵树都有一个根节点.
- 根节点有 0 个或多个子节点.
- 子节点有 0 个或多个子节点. 分类:
- 二叉树:每个节点至多有两个子节点的树.
- 二叉搜索树:任意节点的左子节点`小于等于`<sup>TBS:等于?</sup>当前节点,右子节点`大于`当前节点.
- 平衡二叉树:
  - AVL 树: 1.本身首先是一棵二叉搜索树。 2.带有平衡条件：每个结点的左右子树的高度之差的绝对值（平衡因子）最多为 1。
  - 红黑树:
- 完整二叉树: 除了最后一层外所有节点都有两个子节点,并且最后一层节点从左到右依次填充.
- 满二叉树: 每个节点都有 0 或 2 个子节点.
- 完美二叉树: 除了最后一层外所有节点都有两个子节点(并且最后一层所有节点都没有子节点)
