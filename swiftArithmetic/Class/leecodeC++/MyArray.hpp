//
//  MyArray.hpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/8/12.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <stdio.h>
#include "CPlusHeader.h"

class MergeTwoSortArray {
    
    
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int k = m + n - 1;
        while (p >= 0 && q >=0) {
            nums1[k--] = nums1[p] > nums2[q] ? nums1[p--] : nums2[q--];
        }
        while (q >= 0) {
            nums1[k--] = nums2[q--];
        }
    }
};

class FLQuickSort {
    
public:
    int paritition1(int A[], int low, int high) {
        int pivot = A[low];
        while (low < high) {
            while (low < high && A[high] >= pivot) {
                --high;
            }
            A[low] = A[high];
            while (low < high && A[low] <= pivot) {
                ++low;
            }
            A[high] = A[low];
        }
        A[low] = pivot;
        return low;
    }
    
    void quickSort(int A[], int low, int high) {
        if (low < high) {
            int pivot = paritition1(A, low, high);
            quickSort(A, low, pivot - 1);
            quickSort(A, pivot + 1, high);
        }
    }
    
    void quicksort(vector<int>& v, int begin, int end){
        if(end - begin<=1) return;
        int pivot = v[end-1], less_end = begin;
        
        for(int i=begin; i<end-1; i++)
            if(v[i]<pivot) swap(v[i], v[less_end++]);
        
        swap(v[end-1], v[less_end]);
        quicksort(v, begin, less_end);
        quicksort(v, less_end + 1, end);
    }
};

class ThreeSum {
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
    
    // 耗时
    
    vector<vector<int>> threeSumIII(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = (int)nums.size();
        for (int i=0; i< n; i++) {
            int a = nums[i];
            if (a > 0) {
                break;
            }
            if (i > 0 && a == nums[i -1]) {
                continue;
            }
            
            unordered_set<int> set = {};
            for (int j= i + 1; j< n; j++) {
                if (j > i + 2 &&  nums[j] == nums[j-1] && nums[j -1] == nums[j-2] ) {
                    continue;
                }
                
                int b = nums[j];
                int c = -(a + b);
                if (set.find(c) != set.end()) {
                    result.push_back({a,b,c});
                    set.erase(c);
                } else {
                    set.insert(b);
                }
            }
        }
        return result;
    }
};


class MedianSortedArray {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() >  nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int left = 0;
        int right = m;
        int median1 = 0, median2 = 0;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i = (i == m? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j = (j == n? INT_MAX : nums2[j]);
            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
    
};


class SolutionBinarySearch {
    /*
     统计一个数字在排序数组中出现的次数。
     示例 1:

     输入: nums = [5,7,7,8,8,10], target = 8
     输出: 2
     示例 2:

     输入: nums = [5,7,7,8,8,10], target = 6
     输出: 0

     */
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
    
    int searchII(vector<int>& nums, int target) {
        return upper_bound(begin(nums), end(nums), target) - lower_bound(begin(nums), end(nums), target);
    }
};


class RotateArray {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};



//    func threeSum(_ nums: [Int]) -> [[Int]] {
//         var result: [[Int]] = []
//        let nums: [Int] = nums.sorted(by: <)
//        for (i,a) in nums.enumerated() {
//            if a > 0  {
//                break
//            }
//            if i > 0 && a == nums[i - 1] {
//                continue
//            }
//            var set: Set<Int> = Set()
//            for j in i + 1..<nums.count {
//                if j > i + 2 && nums[j] == nums[j-1] && nums[j - 1] == nums[j - 2]{
//                    continue
//                }
//                let b: Int = nums[j]
//                let c = 0 - (a + b)
//                if set.contains(c) {
//                    result.append([a,b,c])
//                    set.remove(c)
//                } else {
//                    set.insert(b)
//                }
//
//            }
//        }
//        return result
//    }
#endif /* MyArray_hpp */
