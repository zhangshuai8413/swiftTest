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

int DynmicProfit:: maxProfit1(vector<int>& prices) {
    int n = (int)prices.size();
    vector<vector<int>>dp(2, vector<int>(2));
    dp[0][0] -= prices[0]; // 持有股票
    dp[0][1] = 0;
    for (int i=1; i< n; ++i) {
        dp[i % 2][0] = max(dp[(i-1) %2][0], -prices[i]);
        dp[i % 2][1] = max(dp[(i-1) %2][1], dp[(i-1)%2][0] + prices[i]);
    }
    return dp[(n -1) %2][1];
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


bool canJump(vector<int>& nums) {
    
    int cover = 0;
    if (nums.size() == 1) {
        return  true;
    }
    for(int i =0; i <= cover;  i++) {
        cover = max(i + nums[i], cover);
        if (cover >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

int jump(vector<int>& nums) {
    int  curDistance = 0;
    int ans = 0;
    int nextDistance = 0;
    for(int i = 0; i < nums.size() -1 ; i ++) {
        nextDistance = max(i + nums[i], nextDistance);
        if (curDistance == i) {
            curDistance = nextDistance;
            ans++;
        }
    }
    return ans;
}


class MaxProfitIII {
    
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<int>dp(5,0);
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        for (int i=1; i< prices.size(); ++i) {
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
            
        }
        return dp[4];
    }
};
