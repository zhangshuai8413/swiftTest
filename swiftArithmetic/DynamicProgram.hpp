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
#endif /* DynamicProgram_hpp */
