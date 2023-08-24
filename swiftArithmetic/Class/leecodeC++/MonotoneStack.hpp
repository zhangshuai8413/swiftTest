//
//  MonotoneStack.hpp
//  swiftArithmetic
//
//  Created by admin on 2023/7/26.
//

#ifndef MonotoneStack_hpp
#define MonotoneStack_hpp

#include <stdio.h>

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

class Trap {
    /*
     给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

     示例 1：
     输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
     输出：6
     解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
     示例 2：

     输入：height = [4,2,0,3,2,5]
     输出：9

     */
    
public:
    
    int trap(vector<int>& height) {
        stack<int>st;
        st.push(0);
        int sum = 0;
        for (int i = 0; i <height.size(); i ++) {
            while (!st.empty() && height[i] > st.top()) {
                int mid = st.top();
                st.pop();
                if(!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }
    
    int trapII(vector<int>& height) {
        if(height.size() < 2) return 0;
        vector<int>maxLeft(height.size(), 0);
        vector<int>maxRight(height.size(), 0);
        int size = (int)height.size();
        maxLeft[0] = 0;
        for (int i = 1; i <size; i ++) {
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }
        maxRight[size -1] = height[size -1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i +1]);
        }
        int sum = 0;
        for (int i = 0; i <size; i ++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            sum += count;
        }
        return sum;
    }
};

/*
 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

  

 示例 1：

 输入：s = "(()"
 输出：2
 解释：最长有效括号子串是 "()"
 示例 2：

 输入：s = ")()())"
 输出：4
 解释：最长有效括号子串是 "()()"
 示例 3：

 输入：s = ""
 输出：0
 */

int longestValidParentheses(string s) {
    
    int maxans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxans = max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
    
}
#endif /* MonotoneStack_hpp */
