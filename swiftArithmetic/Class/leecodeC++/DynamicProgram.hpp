//
//  DynamicProgram.hpp
//  swiftArithmetic
//
//  Created by admin on 2023/6/28.
//

#ifndef DynamicProgram_hpp
#define DynamicProgram_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "CPlusHeader.h"

using namespace std;
//void print1() {};

template <typename T, typename... Types>
void print1(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
//    print1(args...);
}

class FIB {
    /*
     斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是： F(0) = 0，F(1) = 1 F(n) = F(n - 1) + F(n - 2)，其中 n > 1 给你n ，请计算 F(n) 。

     示例 1：

     输入：2
     输出：1
     解释：F(2) = F(1) + F(0) = 1 + 0 = 1
     示例 2：

     输入：3
     输出：2
     解释：F(3) = F(2) + F(1) = 1 + 1 = 2
     示例 3：

     输入：4
     输出：3
     解释：F(4) = F(3) + F(2) = 2 + 1 = 3
     提示：

     0 <= n <= 30
     */
    
public:
    int fib(int N) {
        if (N <= 1) {
            return N;
        }
        vector<int> dp(N + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i ++) {
            dp[i] = dp[i -1] + dp[i -2];
        }
        return dp[N];
    }
    
    int fibII(int N) {
        if (N <= 1) {
            return N;
        }
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i ++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};


class ClimbStairs {
    
public:
    int climbStairs(int n)  {
        if (n <= 1) {
            return n;
        }
        vector<int>dp(3);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <=n; i ++) {
            int  sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
    /*
     一次可以多个台阶
     */
    int climbStairsII(int n)  {
        if (n <= 1) {
            return n;
        }
        int m =  2; //  代表有多少不可以
        vector<int>dp(n + 1,0);
        dp[0] = 1;
        for (int i = 1; i <=n; i ++) {
            for (int j = 1; i <=m; j ++) {
                if(i - j >= 0) {
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int> &cost){
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 2; i <=cost.size(); i ++) {
            int dpi = min(dp1 + cost[i-1], dp0 + cost[i -2]);
            dp0 = dp1;
            dp1 = dpi;
        }
        return dp1;
    }
};


class UniquePaths {
    /*
     62.不同路径
     力扣题目链接
     一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
     机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
     问总共有多少条不同的路径？
     */
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n);
        for (int i = 0; i <n; i ++) {
            dp[i] = 1;
        }
        for (int j = 1; j <m; j ++) {
            for (int i = 1; i <n; i++) {
                dp[i] += dp[i -1];
            }
        }
        return dp[n-1];
    }
    
    int uniquePathsII(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for (int i = 0; i <m; i ++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i <n; i ++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <m; i ++) {
            for (int j = 1; j <n; j ++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        for (int i = 0; i <m && obstacleGrid[i][0] == 0; i ++)dp[i][0] = 1;
        for (int i = 0; i <n && obstacleGrid[0][i] == 0; i ++)dp[0][i] = 1;
        for (int i = 1; i <m; i ++) {
            for (int j = 1; j <n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class InterBreake {
    /*
     给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
     示例 1:
     输入: 2
     输出: 1
     解释: 2 = 1 + 1, 1 × 1 = 1。
     示例 2:
     
     输入: 10
     输出: 36
     解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
     说明: 你可以假设 n 不小于 2 且不大于 58。
     */
    
public:
    int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[2] = 1;
        for (int i = 3; i <=n; i ++) {
            for (int j = 1; j <= i / 2; j ++) {
                dp[i] = max(dp[i], max((i -j) * j, dp[i-j] *j));
            }
        }
        return dp[n];
    }
    
    int integerBreakII(int n) {
        if(n == 2) {
            return 1;
        } else if(n == 3) {
            return 2;
        }  else if(n == 4) {
            return 4;
        }
        int result = 1;
        while (n > 4) {
            result *= 3;
            n-=3;
        }
        result *= n;
        return result;
    }
};

#endif /* DynamicProgram_hpp */


class Knapsack {
    
public:
    vector<vector<int>> test_2_wei_bag_problem1() {
        vector<int>weight = {1,3,4};
        vector<int> value = {15, 20, 30};
        int bagweight = 4;
        // 初始化
        vector<vector<int>>dp(weight.size(), vector<int>(bagweight +1, 0));
        for (int j= weight[0]; j<= bagweight; ++j) {
            dp[0][j] =  value[0];
        }
        // weight数组的大小 就是物品个数
        for (int i=1; i< weight.size(); ++i) {
            for (int j=0; j<= bagweight; ++j) {
                if (j < weight[i]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
                }
            }
        }
        for (int i=0; i< dp.size(); ++i) {
            cout << "\n -- end" << endl;
            for (int j=0; j< dp[0].size(); ++j) {
                cout << dp[i][j] << endl;
            }
        }
        return dp;
    }
    
    void test_1_wei_bag_problem() {
        vector<int>weight = {1,3,4};
        vector<int>value =  {15,20, 30};
        int bagWeight= 4;
        vector<int>dp(bagWeight +1, 0);
        for (int i = 0; i < weight.size() ; i ++) {
            for (int j = bagWeight; j >= weight[i] ; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << "test_1_wei_bag_problem dp----: " << dp[bagWeight] << endl;
    }
};

class DivideEqualSumSubsets {
    
    /*
     题目难易：中等
     给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
     注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
     示例 1:
     输入: [1, 5, 11, 5]
     输出: true
     解释: 数组可以分割成 [1, 5, 5] 和 [11].
     示例 2:
     输入: [1, 2, 3, 5]
     输出: false
     解释: 数组不能分割成两个元素和相等的子集.
     */
    
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        vector<int>dp(10001,0);
        for (int i=0; i< nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        for (int i = 0; i < nums.size() ; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) {
            return true;
        }
        return false;
    }
    
    
};


class LastStoneWeightII {
    
    /*
     
     1049. 最后一块石头的重量 II

     有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

     每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
     如果 x == y，那么两块石头都会被完全粉碎；
     如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
     最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

     示例 1：
     输入：stones = [2,7,4,1,8,1]
     输出：1
     解释：
     组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
     组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
     组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
     组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
     示例 2：

     输入：stones = [31,26,33,21,40]
     输出：5
     */
    
    
public:
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int weight : stones) {
            sum += weight;
        }
        int target = sum / 2;
        vector<int>dp(1501, 0);
        for (int i = 0; i < stones.size(); i ++) {
            for (int j = target;  j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return (sum - dp[target]) - dp[target];
    }
};

class SumOfZeroOne {
    /*
     给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

     请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

     如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

     示例 1：

     输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3

     输出：4

     解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

     示例 2：

     输入：strs = ["10", "0", "1"], m = 1, n = 1
     输出：2
     解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
     提示：

     1 <= strs.length <= 600
     1 <= strs[i].length <= 100
     strs[i] 仅由 '0' 和 '1' 组成
     1 <= m, n <= 100
     */
    
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m +1, vector<int>(n + 1, 0));
        for(string str: strs) {
            int  oneNum = 0;
            int  zeroNum = 0;
            for(char c: str) {
                if(c == '0') {
                    zeroNum ++;
                } else {
                    oneNum++;
                }
            }
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
            
        }
        return dp[m][n];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (abs(target) >  sum ) return 0;
        cout << "sum  " << sum << endl;
        if ((sum + target )%2 ==1) return 0;
        int bagSize = (sum + target) / 2;
        
        vector<int>dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};


class FindTargetSumWays {
    /*
     给你一个整数数组 nums 和一个整数 target 。

     向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

     例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
     返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

      

     示例 1：

     输入：nums = [1,1,1,1,1], target = 3
     输出：5
     解释：一共有 5 种方法让最终目标和为 3 。
     -1 + 1 + 1 + 1 + 1 = 3
     +1 - 1 + 1 + 1 + 1 = 3
     +1 + 1 - 1 + 1 + 1 = 3
     +1 + 1 + 1 - 1 + 1 = 3
     +1 + 1 + 1 + 1 - 1 = 3
     示例 2：

     输入：nums = [1], target = 1
     输出：1
      
     */
    
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i <nums.size(); i ++) sum += nums[i];
        if (abs(S) > sum || (S + sum) %2 == 1) {
            return 0;
        }
        int bagSize = (S + sum) / 2;
        vector<int>dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <nums.size(); i ++) {
            for (int j =  bagSize; j >=nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
        
    }
    
};


class ChangeCoinII {
    
    /*
     518. 零钱兑换 II
     给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 aamount 表示总金额。

     请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

     假设每一种面额的硬币有无限个。

     题目数据保证结果符合 32 位带符号整数。

      

     示例 1：

     输入：aamount = 5, coins = [1, 2, 5]
     输出：4
     解释：有四种方式可以凑成总金额：
     5=5
     5=2+2+1
     5=2+1+1+1
     5=1+1+1+1+1
     示例 2：

     输入：aamount = 3, coins = [2]
     输出：0
     解释：只用面额 2 的硬币不能凑成总金额 3 。
     示例 3：

     输入：aamount = 10, coins = [10]
     输出：1
     */
public:
    
    int change(int amount, vector<int>&coins) {
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for (int i = 0; i <coins.size(); i ++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
                
            }
        }
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <coins.size(); i ++) {
            for (int j =  coins[i]; j <= amount; j++) {
                if(dp[j - coins[i]] != INT_MAX ) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return  -1;
        }
        return dp[amount];
    }
};


class CombinationSum4 {
    /*
     难度：中等

     给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

     示例:

     nums = [1, 2, 3]
     target = 4
     所有可能的组合为： (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (1, 3) (2, 1, 1) (2, 2) (3, 1)

     请注意，顺序不同的序列被视作不同的组合。

     因此输出为 7。
     */
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+ 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i ++) {
            for (int j = 0; j <nums.size(); j ++) {
                
                if (i - nums[j] >=0 &&  dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return  dp[target];
        
    }
    
};


class NumSquares {
    /*
     279. 完全平方数
     给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
     完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

     示例 1：
     输入：n = 12
     输出：3
     解释：12 = 4 + 4 + 4
     示例 2：

     输入：n = 13
     输出：2
     解释：13 = 4 + 9

     */
    
public:
    
    int numSquares(int n) {
        vector<int>dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <=n; i ++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i - j* j] + 1, dp[i]) ;
            }
        }
        return dp[n];
    }
};

class WorkBreak {
    /*
     139. 单词拆分
     给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

     注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

      

     示例 1：

     输入: s = "leetcode", wordDict = ["leet", "code"]
     输出: true
     解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
     示例 2：

     输入: s = "applepenapple", wordDict = ["apple", "pen"]
     输出: true
     解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
          注意，你可以重复使用字典中的单词。
     示例 3：

     输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
     输出: false
     */
    
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        vector<bool>dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i ++) {
            for (int j = 0; j < i ; j++) {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
