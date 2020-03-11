# [322.零钱兑换](https://leetcode-cn.com/problems/coin-change/)

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
