//
//  DynamicProgram.hpp
//  swiftArithmetic
//
//  Created by admin on 2023/6/28.
//

#ifndef DynamicProgram_hpp
#define DynamicProgram_hpp

#include <stdio.h>
#include "CPlusHeader.h"

using namespace std;

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
};

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
#endif /* DynamicProgram_hpp */
