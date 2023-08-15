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
