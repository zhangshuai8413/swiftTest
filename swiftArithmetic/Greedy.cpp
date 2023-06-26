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

class MAXProfit {
    
    
public:
    //  只操作一天
    int maxProfit(vector<int>&price) {
        int result = 0;
        for (int i=1; i< price.size(); ++i) {
            result += max(price[i] - price[i -1], 0);
        }
        return result;
        
    }
    
    //  只操作一天
    int maxProfitDym(vector<int>&prices) {
        int result = 0;
        for (int i=1; i< prices.size(); ++i) {
            result += max(prices[i] - prices[i -1], 0);
        }
        return result;
        
    }
    
    
};


// 可以多日操作
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

int canCompleteCircuit(vector<int>&gas, vector<int>cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size() ;i ++) {
        curSum += gas[i] - cost[i];
        totalSum += gas[i] - cost[i];
        if (curSum < 0) {
            start  = i + 1;
            curSum = 0;
        }
    }
    if (totalSum < 0) {
        return  -1;
    }
    return start;
}


int candy(vector<int>& ratings) {
    int result = 0;
    vector<int>candyVec(ratings.size(), 1);
    for (int i = 1 ; i < (int)ratings.size(); i++) {
        if (ratings[i] > ratings[i -1]) {
            candyVec[i] = candyVec[i -1] + 1;
        }
    }
    for (int i = (int)ratings.size() - 1; i > 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
    }
    
    for (int i = 0; i < candyVec.size(); i ++) {
        result += candyVec[i];
    }
    return result;
}


bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for( int bill :  bills) {
        if(bill == 5) five ++;
        if (bill == 10) {
            if (five <= 0) {
                return false;
            }
            ten++;
            five--;
        }
        if (bill == 20) {
            if (five> 0 &&  ten >0) {
                five--;
                ten--;
            } else if(five >=3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

class  SortHeight {
    
public:
    static  bool com(const vector<int> &a, const vector<int>&b) {
        if (a[0]== b[0]) {
            return a[1] < b[1];
        }
        return a[0]> b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> & people) {
        sort(people.begin(), people.end(), com);
        vector<vector<int>> que;
        for (int i = 0; i <people.size(); i ++) {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
            
        }
        return que;
    }
};


class  SortHeightII {
    //    根据身高重建队列
    // https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%A0%B9%E6%8D%AE%E8%BA%AB%E9%AB%98%E9%87%8D%E5%BB%BA%E9%98%9F%E5%88%97%EF%BC%88vector%E5%8E%9F%E7%90%86%E8%AE%B2%E8%A7%A3%EF%BC%89.md
    
    
public:
    static bool com(const vector<int> &a, const vector<int>&b) {
        if (a[0]== b[0]) {
            return a[1] < b[1];
        }
        return a[0]> b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> & people) {
        sort(people.begin(), people.end(), com);
        list<vector<int>> que;
        for (int i = 0; i <people.size(); i ++) {
            int position = people[i][1];
            list<vector<int>> :: iterator it = que.begin();
            while (position--) {
                it++;
            }
            que.insert(it, people[i]);
            
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};

class MinArrowShots {
    /*
     有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
     
     一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
     
     给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
     */
    
public:
    
    static bool cmp(const vector<int> &a, const vector<int>&b) {
        return a[0] < b[0];
    }
    
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int result = 1;
        for (int i = 0; i <points.size(); i ++) {
            if (points[i][0] > points[i -1][1]) {
                result++;
            } else {
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return result;

    }
};
