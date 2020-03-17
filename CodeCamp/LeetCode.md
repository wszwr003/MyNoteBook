# [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)
## 方法一、迭代(自写)
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * list1 = l1;
    struct ListNode * list2 = l2;
    struct ListNode * list3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list3->val = 0; 
    list3->next = NULL;
    int up=0; //进位
    struct ListNode * currPos=list3;
    while(list1!=NULL||list2!=NULL){
        int temp1 = (list1 == NULL) ? 0:(list1->val);
        int temp2 = (list2 == NULL) ? 0:(list2->val);
        int tempSum = (temp1+temp2+up)%10;
        up= (temp1+temp2+up)/10;
        struct ListNode * tempNode3 = (struct ListNode *)malloc(sizeof(struct ListNode));
        tempNode3->val = tempSum;
        tempNode3->next = NULL;
        currPos->next = tempNode3;
        list1 = (list1 == NULL)  ? NULL:(list1->next); //FAO
        list2 = (list2 == NULL)  ? NULL:(list2->next); //FAO
        currPos = tempNode3; //FAO list3当前位置更新
    }
    if(up){  //判断最后有没有进位
        struct ListNode * tempNode3 = (struct ListNode *)malloc(sizeof(struct ListNode));
        tempNode3->val = up;
        tempNode3->next = NULL;
        currPos->next = tempNode3;  
    }
    return list3->next;
}
```
# [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
## 方法一、滑动窗口
```cpp
int lengthOfLongestSubstring(char * s){
    int start = 0 ;
    int end = 0;
    int length = 0;
    int result = 0;
    int strLength = strlen(s);
    while(end<strLength){
        char tmpChar = s[end];
        for (int index = start; index < end; index++)
        {
            if (tmpChar == s[index])
            {
                start = index + 1;
                length = end - start;
                break;
            }
        }
        end++;
        length++;
        result = length>result?length:result;
    }
    return result;
}
```
# [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)
## 方法一、中心扩散法
```cpp
#include <string.h>
char * longestPalindrome(char * s){
    int N = strlen(s), start = 0, len = 0;  // N 字符串长度， start 子串起始位置， len 子串长度
    for (int i = 0; i < N; i++) {   // 奇数长度的回文子串
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < N && s[left] == s[right]){
            left--; right++;            // 以 i 为中心，向两侧延伸，直到不再满足回文
        }                               // left+1 ~ right-1 则为以i为中心的最大回文子串
        if (right - left - 1 > len) {   // 若更长，则保存该子串信息
            start = left + 1;
            len = right - left - 1;
        }
    }
    for (int i = 0; i < N; i++) {   // 偶数长度的回文子串
        int left = i, right = i + 1;    // 以 i+0.5 为中心，向两侧延伸
        while (left >=0 && right < N && s[left] == s[right]) {
            left--, right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
    }
    char *temp = malloc(sizeof(char) * len+1);
    for(int i=0;i<len;i++){
        temp[i] = s[start + i];
    }
    temp[len]='\0';
    return temp;
}
```
# [43. 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)
## 方法一:竖式乘法
思想:利用竖式相乘方法
# [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
## 方法一、迭代(自写)
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* reverseHead = head;  //reverse以后链表头
    struct ListNode* prevReverse = NULL;  //第一个交换节点的前一个
    struct ListNode* currReverse = head;  //第一个交换节点
    struct ListNode* prev = NULL;         //当前节点的前一个节点
    struct ListNode* curr = NULL;         //当前节点

    if(m==n)
        return head;
    for(int i=0;i<m-1;i++){               //循环到交换节点
        prevReverse = currReverse;
        currReverse = currReverse->next;
    }
    curr = currReverse;                   
    for(int i=0;i<n-m+1;i++){
        struct ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp; //FAO curr = temp->next;
    }
    if(m==1)
        reverseHead = prev;
    else
        prevReverse->next = prev;
    currReverse->next = curr;
    return  reverseHead;
}
```
## 方法二、递归
# [121. 买卖股票最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
## 方法一、暴力法
```cpp
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int maxProfit(int* prices, int pricesSize){
    int maxPrice = 0;
    for(int i=0;i<pricesSize-1;i++){
        for(int j=i+1;j<pricesSize;j++){
            maxPrice = max(maxPrice,prices[j]-prices[i]);
        }
    }
    return maxPrice;
}
```
## 方法二、动态规划
# [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)
## 方法一、冒泡排序
```cpp
//FAO 超出时间限制
int majorityElement(int* nums, int numsSize){
    int n2=numsSize/2;
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-1-i;j++){  //注意冒泡写法
            if(nums[j]>nums[j+1]){
                int tmp = nums[j+1];
                nums[j+1]=nums[j];
                nums[j]=tmp;
            }
        }
    }
    return nums[numsSize/2];
}
```
## 方法二、
```cpp
int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i] == key)
            count++;
        else
            count--;
        
        if(count <= 0)
        {
            key = nums[i+1];
        }
        
    }
    return key;
}
```
## 方法三、哈希
## 方法四、随机数
## 方法五、位运算
## 方法六、Moore投票
# [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
## 方法一、深度优先搜索
# [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
## 方法一、迭代(自写)
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while(curr != NULL){
        struct ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
```
## 方法二、递归
# [222. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)
## 方法一:暴力遍历
# [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

## 题目

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回  -1。  
**示例  1:**  
输入: coins = [1, 2, 5], amount = 11  
输出: 3  
解释: 11 = 5 + 5 + 1  
**示例 2:**  
输入: coins = [2], amount = 3  
输出: -1

## 知识点

递归就是自我调用，经常作为一种编程的实现方式.
DFS(深度优先搜索)、动态规划、回溯法都可以用递归来实现，当然也可以用非递归来实现。
当回溯用于树的时候，就是深度优先搜索,几乎所有可以用回溯解决的问题都可以表示为树,那么这俩在这里就几乎同义了。回溯 ≈ 深度优先搜索

## 方法一、搜索回溯 [超出时间限制]

许多情况下,回溯算法相当于穷举搜索的巧妙实现,但性能一般不理想;很多时候每一步的处理都是一致的，这时候用递归来实现就很自然。

```JAVA
public class Solution{
    public int changeCoins(int[] coins,int amount){
        return changeCoins(0,coins,amount);
    }
    private int changeCoins(int idxCoin,int[] coins,int amount){
        if(amount == 0){
            return 0;
        }
        //FAO遍历coins数组直到最后//amount>0是否有必要写?
        if(idxCoin < coins.length && amount > 0){
            //计算当前硬币的最大可能值
            int maxValue = amount/coins[idxCoin];
            //最少硬币数量,初始化为最大整数
            int minCoins = Integer.MAX_VALUE;
            //FAO从0开始?
            for(int x=0;x<maxValue;x++){
                if(x*coins[idxCoin]<=amount)
                    int res = changeCoins(idxCoin+1,coins,amount-x*coins[idxCoin]);
                    if(res != -1)
                        minCoins = Math.min(minCost, res + x);
            }
            return (minCoins == Integer.MaxValue)? -1: minCoins;
        }
        return -1
    }
}
```

## 动态规划-自上而下 [通过]
## 动态规划-自下而上 [通过]
# [394. 字符串解码](https://leetcode-cn.com/problems/decode-string/)
## 方法一、辅助栈
## 方法二、递归
```cpp

```
# [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)
## 方法一、深度优先算法.
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans=1;
int depth(struct TreeNode * node){
    if(node == NULL)
        return 0;
    int L = depth(node->left);
    int R = depth(node->right);
    ans = max(ans,L+R+1);
    return max(L,R)+1;
}
int max(int a,int b){
    if(a>=b)
        return a;
    else
        return b;
};
int diameterOfBinaryTree(struct TreeNode* root){    
    ans = 1;   //FAO 为什么这里不初始化1,空树用例测试错误
    depth(root);
    return ans - 1;
}
```
# [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)
## 方法一、深度优先搜索
```cpp
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int area(int** grid,int gridSize,int*gridColSize,int i,int j){
    int x[4]={1,0,-1,0};
    int y[4]={0,1,0,-1};
    int areaAdd = 1; //FAO 初始化值!!!!;
    //FAO 不加i,j判断,会造成在递归的时候越界!!!!!!!!!!
    if(i < 0 || j < 0 || i == gridSize || j == *gridColSize || grid[i][j]==0) 
        return 0;
    grid[i][j]=0;
    for(int k=0;k<4;k++){
        areaAdd += area(grid,gridSize,gridColSize,i+x[k],j+y[k]);
    }
    return areaAdd;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int maxArea = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            maxArea = max(maxArea,area(grid,gridSize,gridColSize,i,j));
        }
    }
    return maxArea;
}
```
# [820. 单词的压缩编码](https://leetcode-cn.com/problems/short-encoding-of-words/)
## 方法一、排序+查找
## 方法二、字典树
# [1013. 将数组分成和相等的三个部分](https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/)
## 题目
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。  
形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。  
**示例 1：**  
输出：[0,2,1,-6,6,-7,9,1,2,0,1]  
输出：true  
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1  
**示例 2：**  
输入：[0,2,1,-6,6,7,9,-1,2,0,1]  
输出：false  
**示例 3：**  
输入：[3,3,6,5,-2,2,5,1,-9,4]  
输出：true  
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4  
**提示：**  
3 <= A.length <= 50000  
-10^4 <= A[i] <= 10^4 
## 方法一：寻找切分点
```cpp
bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0,avg=0;
    bool s1=false,s2=false;
    for(int i=0;i<ASize;i++){  //计算和
        sum += A[i];
    }
    if(sum%3!=0)    //如果和不能被3整除则 false
        return false;
    else            //否则计算avg
        avg = sum/3;
    sum = 0;
    for(int i=0;i<ASize-1;i++){ //FAO:首先不需要考虑3*avg|其次s2一定要在s1之后发生|进入s1后不再进入判断,否则为零的情况会把S2吃掉.
        sum += A[i];
        if(s1==false&&sum == avg)
            s1 = true;
        else if(s1 == true&&sum == 2*avg)
            s2 = true;
    }
    if(s2)
        return true;
    return false;
}
```
1
# [1103. 分糖果](https://leetcode-cn.com/problems/distribute-candies-to-people/)
## 方法一、
```cpp
int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}
int* distributeCandies(int candies, int num_people, int* returnSize){
    int candy = 0;
    int *candiesPerson = malloc(sizeof(int) * num_people);
    for (int i = 0; i < num_people; i++) {
        candiesPerson[i] = 0;
    }
    while(candies>0){
        candy++;
        candiesPerson[(candy-1)%num_people] += min(candy,candies);
        //FAO ERROR candiesPerson[candy%num_people-1] += min(candy,candies);
        candies -=candy;
    }
    *returnSize = num_people;
    return candiesPerson;
}
```
# [1109. 航班预定系统](https://leetcode-cn.com/problems/corporate-flight-bookings/)
## 方法一、遍历(61/63超时)
```cpp
//FAO 超时!
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){ 
    if (n == 0) {
        *returnSize = 0;
        return NULL; 
    }
    int* bookArray;
    if ((bookings == NULL) || (bookingsSize == 0) || (bookingsColSize == NULL) || (*bookingsColSize == 0)) {
        bookArray = (int *)malloc(n * sizeof(int));
        memset(bookArray, 0, n * sizeof(int));
        *returnSize = n;
        return bookArray;
    }
    bookArray = (int *)malloc(n * sizeof(int));
    memset(bookArray, 0, n * sizeof(int));
    *returnSize = n;
    for(int i = 0; i < bookingsSize; i++){
        int start = bookings[i][0]; 
        int end = bookings[i][1]; 
        int val = bookings[i][2];

        for(int j = start-1 ;j < end;j++){
            bookArray[j]+=val;
        }
    }
    return bookArray;
}
```
# [面试题 10.01. 合并排序的数组](https://leetcode-cn.com/problems/sorted-merge-lcci/)
## 方法一、冒泡排序
```cpp
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i,j;
    for(i=0;i<n;i++){
        A[m+i]=B[i];
    }
    for(i = 0;i < n+m-1;i++){  //冒泡排序
        for(j = 0;j < m+n-1-i;j++)
        {
            int tmp = 0;
            if(A[j] > A[j+1])
            {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}
```