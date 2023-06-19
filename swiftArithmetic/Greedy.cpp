//
//  Greedy.cpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/6/12.
//

#include "Greedy.hpp"

/* 分发 饼干

 g  胃口
 s 饼干尺寸
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int index = (int)s.size() - 1;
    int result = 0;
    for (int i= (int)g.size(); i > 0 ; i--) {
        if(index > 0 && g[i] > s[index]) {
            result++;
            index--;
        }
    }
    return result;
    
}

int maxSubArray(vector<int>& nums) {
    int result = INT32_MIN;
    int count = 0;
    for (int i=0; i< nums.size(); ++i) {
        count += nums[i];
        result = max(result, count);
        count = max(0, count);
    }
    return result;
    
}

int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() <=1) {
        return (int)nums.size();
    }
    int result = 1;
    int curDiff = 0;
    int preDiff = 0;
    for (int i=0; i< nums.size() - 1; ++i) {
        curDiff = nums[i +1] - nums[i];
        if ((preDiff <=0 && curDiff > 0) || (preDiff >=0 && curDiff < 0)) {
            result++;
            preDiff = curDiff;
        }
    }
    return result;
}

class WiggleMax {

public:
    int dp[1005][2];
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 1;
        for (int i= 1; i< nums.size() ; ++i) {
            dp[i][0] = dp[i][1] = 1;
            for (int j=0; j< i; ++j) {
                if (nums[j] > nums[i]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            for (int j=0; j< i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
    
};
int maxProfit(vector<int>&price) {
    int result = 0;
    for (int i=1; i< price.size(); ++i) {
        result += max(price[i] - price[i -1], 0);
    }
    return result;

}



    

int DynmicProfit:: maxProfit(vector<int>& prices) {
    int n = (int)prices.size();
    vector<vector<int>>dp(n, vector<int>(2,0));
    dp[0][0] -= prices[0]; // 持有股票
    // dp[i][1]  第i天持有最多的现金
    // dp[i][0] 第i天持有股票最多的现金
    for (int i=1; i< n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    }
    return max(dp[n -1][0], dp[n-1][1]);
}


class Solution {
    
    
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    
    int largestSumAfterKNegations(vector<int>&A, int k) {
        sort(A.begin(), A.end());
        int result = 0;
        for (int i=0; i< A.size(); ++i) {
            if(A[i] < 0 && k >0) {
                A[i] *= -1;
                 k--;
            }
        }
        
        if(k % 2 == 1) A[A.size() -1] *= -1;        
        for(int a: A) result += a;
        return result;
    }
};
