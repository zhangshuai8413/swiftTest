//
//  MonotoneStack.hpp
//  swiftArithmetic
//
//  Created by admin on 2023/7/26.
//

#ifndef MonotoneStack_hpp
#define MonotoneStack_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "CPlusHeader.h"


class DailyTemperatures {
    /*
     请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

     例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

     提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
     */
    
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size(),0);
        stack<int>st;
        for (int i = 0; i <temperatures.size(); i ++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

class NextGreatNum {
    /*
     力扣题目链接

     给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

     示例 1:

     输入: [1,2,1]
     输出: [2,-1,2]
     解释: 第一个 1 的下一个更大的数是 2；数字 2 找不到下一个更大的数；第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
     提示:

     1 <= nums.length <= 10^4
     -10^9 <= nums[i] <= 10^9
     */
    
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>result(nums.size(), -1);
        stack<int>st;
        st.push(0);
        for (int i = 0; i <nums.size() * 2; i ++) {
            while (!st.empty() && nums[i % nums.size()]> nums[st.top()]) {
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return result;
    }
};
#endif /* MonotoneStack_hpp */
