//
//  BackTrack.cpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/6/6.
//

#include "BackTrack.hpp"

class SubSet {
    
    
public:
    
    vector<vector<int>>result;
    vector<int>path;
    
    void backtraking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if (startIndex > nums.size()) {
            return;
        }
        for (int i=startIndex; i< nums.size(); ++i) {
            path.push_back(nums[i]);
            backtraking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> & nums) {
        result.clear();
        path.clear();
        backtraking(nums, 0);
        return result;
        
    }
};


class SubSetII {
    /*
     给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

     说明：解集不能包含重复的子集。

     示例:

     输入: [1,2,2]
     输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]

     */
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>&nums, int start) {
        result.push_back(path);
        unordered_set<int> set;
        for (int i=start; i< nums.size() ; ++i) {
            if (set.find(nums[i]) != set.end()) {
                continue;
            }
            set.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>>subsetsWithDup(vector<int>&nums){
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
    
};

 // 递增子序列
class IncreaseSubSet {
    /*
     给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

     示例:

     输入: [4, 6, 7, 7]
     输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
     说明:

     给定数组的长度不会超过15。
     数组中的整数范围是 [-100,100]。
     给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
     */
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>&nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        unordered_set<int> set;
        for (int i=startIndex; i< nums.size(); ++i) {
            if ((!path.empty()  && nums[i] < path.back()) || set.find(nums[i]) != set.end()) {
                continue;
            }
            set.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }

    }
    vector<vector<int>>findSubsequences(vector<int>&nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};


class Arrange {
    /*
     给定一个 没有重复 数字的序列，返回其所有可能的全排列。

     示例:

     输入: [1,2,3]
     输出: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
     */
public:
    vector<vector<int>> result;
    vector<int>path;
    void backtraing(vector<int>&nums, vector<bool>used) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i=0; i< nums.size(); ++i) {
            if (used[i] == true) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtraing(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>>permute(vector<int>&nums) {
        result.clear();
        path.clear();
        vector<bool>used(nums.size(), false);
        backtraing(nums, used);
        return result;
    }
};


class RangeII {
    /*
     给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

     示例 1：

     输入：nums = [1,1,2]
     输出： [[1,1,2], [1,2,1], [2,1,1]]
     示例 2：

     输入：nums = [1,2,3]
     输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
     提示：

     1 <= nums.length <= 8
     -10 <= nums[i] <= 10
     */
    
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>&nums, vector<bool>used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i=0; i< nums.size(); ++i) {
            if (i> 0&& nums[i] == nums[i -1] && used[i -1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
                
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool>used(nums.size(),false);
        backtracking(nums, used);
        return result;
    }
    
};
