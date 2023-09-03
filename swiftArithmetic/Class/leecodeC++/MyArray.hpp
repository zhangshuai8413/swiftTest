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


class RemoveDuplicates{
    /*
     80. 删除有序数组中的重复项 II
     中等
     851
     相关企业
     给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

     不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

      

     说明：

     为什么返回数值是整数，但输出的答案是数组呢？

     请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

     你可以想象内部操作如下:

     // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
     int len = removeDuplicates(nums);

     // 在函数里修改输入数组对于调用者是可见的。
     // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
     for (int i = 0; i < len; i++) {
         print(nums[i]);
     }
      

     示例 1：

     输入：nums = [1,1,1,2,2,3]
     输出：5, nums = [1,1,2,2,3]
     解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。
     示例 2：

     输入：nums = [0,0,1,1,1,1,2,3,3]
     输出：7, nums = [0,0,1,1,2,3,3]
     解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 不需要考虑数组中超出新长度后面的元素。
      
     */

public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    };
};

class searchII {
    /*
     整数数组 nums 按升序排列，数组中的值 互不相同 。
     
     在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
     
     给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
     
     你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
     
     
     
     示例 1：
     
     输入：nums = [4,5,6,7,0,1,2], target = 0
     输出：4
     示例 2：
     
     输入：nums = [4,5,6,7,0,1,2], target = 3
     输出：-1
     示例 3：
     
     输入：nums = [1], target = 0
     输出：-1
     
     */
    
public:
    
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

class MaxArea {
    /*
     给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

     找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

     返回容器可以储存的最大水量。

     说明：你不能倾斜容器。
     */
    
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int ans = 0;
        while (l <= r) {
            int are = min(height[l], height[r]) * (r - l);
            ans = max(ans, are);
            if (height[l]<= height[r]) {
                ++l;
            }else {
                --r;
            }
        }
        return ans;
    }
    
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
//                    reverse(nums.begin() + i + 1, nums.end());
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        // 到这里了说明整个数组都是倒序了，反转一下便可
//        reverse(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
    }
};


class SpiralOrder {
    
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        
        int rows = (int)matrix.size(), columns = (int)matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};


class PlusOne {
    
public:
    /*
     
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/plus-one/solutions/1057162/jia-yi-by-leetcode-solution-2hor/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        
        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};



#endif /* MyArray_hpp */
