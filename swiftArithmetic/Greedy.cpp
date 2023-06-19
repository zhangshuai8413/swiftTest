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
