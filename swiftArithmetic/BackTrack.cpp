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
    
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>&nums, int start) {
        result.push_back(path);
        for (int i=start; i< nums.size() ; ++i) {
            unordered_set<int> set;
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
