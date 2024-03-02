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
            int sum = dp[1] + dp[2];
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
            for (int j = 1; j <=m; j ++) {
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
        for (int i = 0; i < weight.size(); i ++) {
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
    
    /*
     给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

     返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
     
     提示：

     数组非空，且长度不会超过 20 。
     初始的数组的和不会超过 1000 。
     保证返回的最终结果能被 32 位整数存下。
     */
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
            for (int j = bagSize; j >=nums[i]; j--) {
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
    /*
     给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

     你可以认为每种硬币的数量是无限的。

     示例 1：

     输入：coins = [1, 2, 5], amount = 11
     输出：3
     解释：11 = 5 + 5 + 1
     示例 2：

     输入：coins = [2], amount = 3
     输出：-1
     示例 3：

     输入：coins = [1], amount = 0
     输出：0
     示例 4：

     输入：coins = [1], amount = 1
     输出：1
     示例 5：

     输入：coins = [1], amount = 2
     输出：2
     提示：

     1 <= coins.length <= 12
     1 <= coins[i] <= 2^31 - 1
     0 <= amount <= 10^4

     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <coins.size(); i ++) {  // 遍历物品
            for (int j = coins[i]; j <= amount; j++) {   // 遍历背包
                if(dp[j - coins[i]] != INT_MAX ) {  // 如果dp[j - coins[i]]是初始值则跳过
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
                if (i - nums[j] >=0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
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
        for (int i = 1; i <= s.size(); i ++) {   // 遍历背包
            for (int j = 0; j < i ; j++) {       // 遍历物品
                string word = s.substr(j, i - j);  //substr(起始位置，截取的个数)
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
    
    void test_multi_pack() {
        vector<int>weight  = {1,3,4};
        vector<int> value = {15,20, 30};
        vector<int> nums = {2,3,2};
        int bagWeight = 10;
        vector<int>dp(bagWeight + 1, 0);
        for (int i = 0; i < weight.size() ; i ++) {
            for (int j = bagWeight; j >= weight[i]; j--) {
                for (int k = 1; k <= nums[i] && (j - k* weight[i] >= 0); k++) {
                    dp[j] = max(dp[j], dp[j - k*weight[i]] + value[i] * k);
                }
            }
        }
        cout << dp[bagWeight] << endl;
    }
};


class Rob {
    /*
     198.打家劫舍
     力扣题目链接

     你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

     给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

     示例 1：
     输入：[1,2,3,1]
     输出：4
     解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。   偷窃到的最高金额 = 1 + 3 = 4 。

     示例 2：
     输入：[2,7,9,3,1]
     输出：12 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。   偷窃到的最高金额 = 2 + 9 + 1 = 12 。
     提示：

     0 <= nums.length <= 100
     0 <= nums[i] <= 400
     */
    
public:
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 0; i < nums.size(); i ++) {
            dp[i] = max(dp[i -2] + nums[i], dp[i -1]);
        }
        return dp[nums.size() - 1];
    }
};

class RobII {
    /*
     力扣题目链接

     你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

     给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

     示例 1：

     输入：nums = [2,3,2]

     输出：3

     解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

     示例 2：

     输入：nums = [1,2,3,1]

     输出：4

     解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。偷窃到的最高金额 = 1 + 3 = 4 。

     示例 3：

     输入：nums = [0]

     输出：0

     提示：

     1 <= nums.length <= 100
     0 <= nums[i] <= 1000
     */
    
public:
    
    int robRange(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        vector<int>dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i= start + 2; i<= end; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            
        }
        return dp[end];
    }
    
    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int result1 = robRange(nums, 0, (int)nums.size() -2);
        int result2 = robRange(nums, 1, (int)nums.size() -1);
        return max(result1, result2);
    }
    
};

class RobIII {
    /**
     
     337.打家劫舍 III
     力扣题目链接
     
     在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
     
     计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
     
     337.打家劫舍III
     
     */
    
    int rob(TreeNode *root) {
        vector<int>result = robTree(root);
        return max(result[0], result[1]);
    }
    
    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode* cur) {
        if(cur == nullptr) {
            return vector<int>{0,0};
        }
        vector<int>left = robTree(cur ->left);
        vector<int>right = robTree(cur ->right);
        int val1 = cur->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {val2, val1};
    }
    
};

class LengthOFLIS {
    /*
     给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

     子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

     示例 1：

     输入：nums = [10,9,2,5,3,7,101,18]
     输出：4
     解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
     示例 2：

     输入：nums = [0,1,0,3,2,3]
     输出：4
     示例 3：

     输入：nums = [7,7,7,7,7,7,7]
     输出：1
     提示：

     1 <= nums.length <= 2500
     -10^4 <= nums[i] <= 104
     */
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return (int)nums.size();
        vector<int>dp(nums.size() + 1, 1);
        int result = 0;
        for (int i = 1; i < nums.size() ; i ++) {
            for (int j = 0; j < i ; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
    /*
     给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

     连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

     示例 1：

     输入：nums = [1,3,5,4,7]
     输出：3
     解释：最长连续递增序列是 [1,3,5], 长度为3。尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
     示例 2：

     输入：nums = [2,2,2,2,2]
     输出：1
     解释：最长连续递增序列是 [2], 长度为1。
     提示：

     0 <= nums.length <= 10^4
     -10^9 <= nums[i] <= 10^9
     */
    int findLengthOfLCIS(vector<int>& nums) {
        
        if (nums.size() <= 1) {
            return (int)nums.size();
        }
        int result = 0;
        vector<int>dp(nums.size() + 1, 1);
        for (int i = 1; i < nums.size() ; i ++) {
            if(nums[i]> nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }
        return result;
    }
    /*
     给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

     一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

     例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

     若这两个字符串没有公共子序列，则返回 0。

     示例 1:

     输入：text1 = "abcde", text2 = "ace"
     输出：3
     解释：最长公共子序列是 "ace"，它的长度为 3。
     示例 2:

     输入：text1 = "abc", text2 = "abc"
     输出：3
     解释：最长公共子序列是 "abc"，它的长度为 3。
     示例 3:

     输入：text1 = "abc", text2 = "def"
     输出：0
     解释：两个字符串没有公共子序列，返回 0。
     提示:

     1 <= text1.length <= 1000
     1 <= text2.length <= 1000 输入的字符串只含有小写英文字符。

     */
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size() + 1,vector<int>(text2.size() +1, 1));
        for (int i = 1; i <= text1.size(); i ++) {
            for (int j = 1; j <= text2.size(); j ++) {
                if(text1[i -1] == text2[j -1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i -1][j], dp[i][j -1] );
                }
            }
        }
        return dp[text1.size()][text2.size()];
        
    }
    // 一维数组
    int longestCommonSubsequenceII(string text1, string text2) {
        int n1 = (int)text1.size();
        int n2 = (int)text2.size();
        vector<int>dp(n2 +1);
        for (int i=1; i<= n1; ++i) {
            int pre = dp[0];
            for (int j = 1; j <= n2; j++) {
                int cur = dp[j];
                if(text1[ i- 1] == text2[j -1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j -1]);
                }
                pre = cur;
            }
        }
        return dp[n2];
    }
};


class Subsequence {
    /*
     给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

     字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

     示例 1：
     输入：s = "abc", t = "ahbgdc"
     输出：true

     示例 2：
     输入：s = "axc", t = "ahbgdc"
     输出：false

     提示：

     0 <= s.length <= 100
     0 <= t.length <= 10^4
     两个字符串都只由小写字符组成
     */
    
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return (int)nums.size();
        }
        vector<int>dp(nums.size(), 1);
        int result = 0;
        for (int i = 0; i< nums.size(); ++i) {
            for (int j = 0; j< i; ++j) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }




    
    /*
     
     给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

     题目数据保证答案符合 32 位带符号整数范围。

      

     示例 1：

     输入：s = "rabbbit", t = "rabbit"
     输出：3
     解释：
     如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
     rabbbit
     rabbbit
     rabbbit
     示例 2：

     输入：s = "babgbag", t = "bag"
     输出：5
     解释：
     如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
     babgbag
     babgbag
     babgbag
     babgbag
     babgbag

     
     每次当初始化的时候，都要回顾一下dp[i][j]的定义，不要凭感觉初始化。

     dp[i][0]表示什么呢？

     dp[i][0] 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。

     那么dp[i][0]一定都是1，因为也就是把以i-1为结尾的s，删除所有元素，出现空字符串的个数就是1。

     再来看dp[0][j]，dp[0][j]：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。

     那么dp[0][j]一定都是0，s如论如何也变成不了t。

     最后就要看一个特殊位置了，即：dp[0][0] 应该是多少。

     dp[0][0]应该是1，空字符串s，可以删除0个元素，变成空字符串t。


     
     来源：力扣（LeetCode）
     链接：https://leetcode.cn/problems/distinct-subsequences
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    
    
    long long numDistinct(string s, string t) {
        int n1 = (int)s.size();
        int n2 = (int)t.size();
        vector<vector<uint64_t>>dp(n1 + 1,vector<uint64_t>(n2 + 1));
        for (int i = 0; i <=n1; i ++) {
            dp[i][0] = 1;
        }
        for ( int j = 1; j <=n2; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <=n1; i ++) {
            for (int j = 1; j <=n2;  j++) {
                if(s[i-1] == t[j -1]) {
                    dp[i][j] = dp[i -1][j -1] + dp[i -1][j];
                } else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }
        return dp[n1][n2];
    }
};

class FindLength {
    /*
     给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

     示例：

     输入：

     A: [1,2,3,2,1]
     B: [3,2,1,4,7]
     输出：3
     解释：长度最长的公共子数组是 [3, 2, 1] 。
     提示：

     1 <= len(A), len(B) <= 1000
     0 <= A[i], B[i] < 100
     718. 最长重复子数组

     */
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size() + 1, vector<int>(nums2.size() + 1,0));
        int result = 0;
        for (int i = 1; i <= nums1.size() ; i ++) {
            for (int j = 1; j <= nums2.size() ; j ++) {
                if (nums1[i -1] == nums2[j -1]) {
                    dp[i][j] = dp[i -1][j -1] + 1;
                }
                
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};

class LoggesttSubStrings {
    
    /*
     673.最长递增子序列的个数
     力扣题目链接

     给定一个未排序的整数数组，找到最长递增子序列的个数。

     示例 1:

     输入: [1,3,5,4,7]
     输出: 2
     解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
     示例 2:

     输入: [2,2,2,2,2]
     输出: 5
     解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

     */
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return (int)nums.size();
        vector<int> dp(nums.size(), 1);
        vector<int>count(nums.size(), 1);
        int maxCount = 0;
        for (int i = 1; i < nums.size() ; i ++) {
            for (int j = 0; j < i ; j ++) {
                if (nums[i] > nums[j]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
                maxCount = max(maxCount, dp[i]);
            }
        }
        int result = 0;
        for (int i = 0; i < nums.size() ; i ++) {
            if (maxCount == dp[i]) result += count[i];
        }
        return result;
    }
};


class MaxUncrossedLines {
    /*
     1035.不相交的线
     力扣题目链接

     我们在两条独立的水平线上按给定的顺序写下 A 和 B 中的整数。

     现在，我们可以绘制一些连接两个数字 A[i] 和 B[j] 的直线，只要 A[i] == B[j]，且我们绘制的直线不与任何其他连线（非水平线）相交。

     以这种方法绘制线条，并返回我们可以绘制的最大连线数。
     */
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size() + 1, vector<int>(nums2.size() + 1,0));
        for (int i = 1; i <= nums1.size() ; i ++) {
            for (int j=1; j<= nums2.size(); ++j) {
                if(nums1[i -1] == nums2[j -1]) {
                    dp[i][j] = dp[i -1][j -1] + 1;
                } else {
                    dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
    
    
    
    /*
     给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

     示例:

     输入: [-2,1,-3,4,-1,2,1,-5,4]
     输出: 6
     解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
     */
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int>dp(nums.size()+ 1);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i=1; i< nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

class MinDistance {
    /*
     583. 两个字符串的删除操作
     力扣题目链接

     给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

     示例：

     输入: "sea", "eat"
     输出: 2
     解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
     */
    
    
     /*
      注意点
        开始下表 
      */
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size() +1));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j ++) {
                if(word1[i -1] == word2[j -1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

class MinDistanceII {
    /*
     给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

     你可以对一个单词进行如下三种操作：

     插入一个字符

     删除一个字符

     替换一个字符

     示例 1：

     输入：word1 = "horse", word2 = "ros"

     输出：3

     解释： horse -> rorse (将 'h' 替换为 'r') rorse -> rose (删除 'r') rose -> ros (删除 'e')

     示例 2：

     输入：word1 = "intention", word2 = "execution"

     输出：5

     解释： intention -> inention (删除 't') inention -> enention (将 'i' 替换为 'e') enention -> exention (将 'n' 替换为 'x') exention -> exection (将 'n' 替换为 'c') exection -> execution (插入 'u')

     提示：

     0 <= word1.length, word2.length <= 500
     word1 和 word2 由小写英文字母组成
     */
    
public:
    
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i ++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j ++) {
            dp[0][j] = j;
            
        }
        for (int i = 1; i <= word1.size(); i ++) {
            for (int j = 1; j <=word2.size(); j ++) {
                if (word1[i -1] == word2[j -1]) {
                    dp[i][j] = dp[i -1][j -1];
                } else {
                    dp[i][j] = min({dp[i -1][j], dp[i][j-1], dp[i-1][j-1]})  + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};


class CountSubstrings {
    /*
     647. 回文子串
     力扣题目链接

     给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

     具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

     示例 1：

     输入："abc"
     输出：3
     解释：三个回文子串: "a", "b", "c"
     示例 2：

     输入："aaa"
     输出：6
     解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
     提示：输入的字符串长度不会超过 1000 。
     */
    
public:
    int countSubstrings(string s) {
        if(s.size() <= 1) return (int)s.size();
        vector<vector<bool>>dp(s.size(), vector<bool>(s.size(),false));
        int result = 0;
        for (int i = (int)s.size(); i >=0 ; i--) {
            for (int j = i; j <s.size(); j ++) {
                if(s[i] == s[j] && ((j -i) <= 1 || dp[i+1][j -1])) {
                    result += 1;
                    dp[i][j]= true;
                }
            }
        }
        return result;
    }
};


class LongestPalindromeSubseq {
    /*
     给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

     示例 1: 输入: "bbbab" 输出: 4 一个可能的最长回文子序列为 "bbbb"。

     示例 2: 输入:"cbbd" 输出: 2 一个可能的最长回文子序列为 "bb"。

     提示：


     
     */
    
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for (int i = 0; i < s.size() ; i ++) {
            dp[i][i] = 1;
        }
        for (int i = (int)s.size() - 1; i >= 0 ; i--) {
            for (int j = i + 1; j < s.size() ; j ++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j -1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j -1]);
                }
            }
        }
        return dp[0][s.size() -1];
    }
    
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int L=2; L<= n; L++) {
            for (int i=0; i< n; i++) {
                int j = L + i - 1;
                if (j >=n) {
                    break;;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j -i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

class NextGreaterElement {
    /*
     496.下一个更大元素 I
     给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

     请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

     nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

     示例 1:

     输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
     输出: [-1,3,-1]
     解释:
     对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
     对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
     对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

     示例 2:
     输入: nums1 = [2,4], nums2 = [1,2,3,4].
     输出: [3,-1]
     解释:
     对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
     对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出-1 。

     提示：

     1 <= nums1.length <= nums2.length <= 1000
     0 <= nums1[i], nums2[i] <= 10^4
     nums1和nums2中所有整数 互不相同
     nums1 中的所有整数同样出现在 nums2 中
     */
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int>result(nums1.size(), -1);
        unordered_map<int, int>umap;
        for (int i=0; i< nums1.size(); ++i) {
            umap[nums1[i]] = i;
        }
        stack<int>st;
        st.push(0);
        for (int i=1; i< nums2.size(); ++i) {
            while (!st.empty() && nums2[i]> nums2[st.top()]) {
                if (umap.count(nums2[st.top()])) {
                    int index = umap[nums2[st.top()]];
                    result[index] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    
};


class LargestRectangleArea {
    
public:
    
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() < 1) {
            return 0;
        }
        int result = 0;
        stack<int>st;
        st.push(0);
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i=0; i< heights.size(); ++i) {
            while (!st.empty() &&heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int width = i - st.top() - 1;
                int height = heights[mid];
                result = max(result, width * height);
            }
            st.push(i);
        }
        return result;
       }
    
};

class MinimumTotal {
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};


class LongestCommonSubString {
    
    
    /*
     
     string string1 = "abcdef";
     string string2 = "bcd";
     int commonLength = longestCommonSubString(string1, string2);
     cout << "Longest Common Substring Length: " << commonLength << endl;
     
     */
    int longestCommonSub(string string1, string string2) {
        long length1 = string1.size();
        long length2 = string2.size();
        if (length1 == 0 || length2 == 0) {
            return 0;
        }
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= length1; ++i) {
            for (int j = 1; j <= length2; ++j) {
                if (string1[i - 1] == string2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
    
};


class MaxProduct {
    /*
     给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
     测试用例的答案是一个 32-位 整数。
     子数组 是数组的连续子序列。
     示例 1:
     输入: nums = [2,3,-2,4]
     输出: 6
     解释: 子数组 [2,3] 有最大乘积 6。
     示例 2:

     输入: nums = [-2,0,-1]
     输出: 0
     解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

    */
    
public:
    
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i -1] * nums[i], max(nums[i], minF[i-1] * nums[i]));
            minF[i] = min(minF[i -1] * nums[i], min(nums[i], maxF[i-1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
    
    
    /*
     
     
     */
    
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int factorial = 1;
        string result = "";
        for (int i=0; i< n; ++i) {
            nums[i] = i + 1;
            factorial *= (i +1);
        }
        --k;
        for (int i=0; i< n; ++i) {
            factorial /= (n -i);
            int index = k / factorial;

            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k -= index * factorial;
 
            
        }
        return result;
    }
    
};

class MinPathSum {

public:
    int minPathSum(vector<vector<int>>& grid) {
           if(grid.size() == 0 || grid[0].size() == 0) {
               return 0;
           }
           int rows = (int)grid.size(), colums = (int)grid[0].size();
           auto dp = vector<vector<int>>(rows, vector<int>(colums));
           dp[0][0] = grid[0][0];
           for (int i=1; i< rows; ++i) {
               dp[i][0] = dp[i-1][0] + grid[i][0];
           }
           for (int j=1; j< colums; ++j) {
               dp[0][j] = dp[0][j -1] + grid[0][j];
           }
           for (int i=1; i< rows; ++i) {
               for (int j=1; j< colums; ++j) {
                   dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
               }
           }
           return dp[rows-1][colums-1];
       }
};
