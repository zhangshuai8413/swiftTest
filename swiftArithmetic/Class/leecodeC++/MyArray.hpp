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
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int m = (int)nums1.size(), n = (int)nums2.size();
        int left = 0, right = m, median1 = 0, median2 = 0;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            int leftAMax = (i == 0 ? INT_MIN : nums1[i - 1]);
            int rightAMin = (i == m ? INT_MAX : nums1[i]);
            int leftBMax = (j == 0 ? INT_MIN : nums2[j - 1]);
            int rightBMin = (j == n ? INT_MAX : nums2[j]);

            if (leftAMax <= rightBMin) {
                median1 = max(leftAMax, leftBMax);
                median2 = min(rightAMin, rightBMin);
                left = i + 1;  // 继续二分查找
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
    
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                swap(nums[slowIndex++], nums[fastIndex]);
            }
        }

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



class FirstMissingPositive {
    
    /*
     给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

     请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
      

     示例 1：

     输入：nums = [1,2,0]
     输出：3
     示例 2：

     输入：nums = [3,4,-1,1]
     输出：2
     示例 3：

     输入：nums = [7,8,9,11,12]
     输出：1
      
     */
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
        
    }
};

class SolutionInsertIntervals {
    /*
     
     给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

     在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

      

     示例 1：

     输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
     输出：[[1,5],[6,9]]
     示例 2：

     输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
     输出：[[1,2],[3,10],[12,16]]
     解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
     示例 3：

     输入：intervals = [], newInterval = [5,7]
     输出：[[5,7]]
     示例 4：

     输入：intervals = [[1,5]], newInterval = [2,3]
     输出：[[1,5]]
     示例 5：

     输入：intervals = [[1,5]], newInterval = [2,7]
     输出：[[1,7]]

     作者：力扣官方题解
     链接：https://leetcode.cn/problems/insert-interval/solutions/472151/cha-ru-qu-jian-by-leetcode-solution/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

     */
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
    
    
    /*
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/search-a-2d-matrix/solutions/688117/sou-suo-er-wei-ju-zhen-by-leetcode-solut-vxui/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
    }


};

class SearchWordIII {
    /*
     作者：脱碳苯酚
     链接：https://leetcode.cn/problems/word-search/solutions/2413793/shen-sou-hui-su-by-gracious-6reiderd1f-6f51/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m =(int)board.size();
        int n = (int)board[0].size();
        int len = (int)word.length();
        if (word.length() > m * n) return false;//先判断一下
        vector<vector<bool>>visited(m,vector<bool>(n));
        function<bool(int, int,int)>dfs = [&](int x, int y, int pos) -> bool {
            if (x < 0 || x >=m || y < 0 || visited[x][y] || board[x][y] != word[pos] ) {
                return false;
            }
            visited[x][y] = true;
            if(pos==len-1&&board[x][y]==word[pos]) return true;
            if(dfs(x,y+1,pos+1)||dfs(x+1,y,pos+1)||dfs(x,y-1,pos+1)||dfs(x-1,y,pos+1)) {
                return true;//后面有一条可以则正确
            }
            visited[x][y] = false;
            return false;
        };
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == word[0]){//剪去一部分枝
                    if(dfs(i,j,0)) return true;
                }
            }
        }
        return false;
    }
};


class MinWindow {
    unordered_map<char, int> ori, cnt;
    
  
    string minWindow(string s, string t) {
        
        auto isValid = [&]() {
            for (const auto &p : ori) {
                if (cnt[p.first] < p.second) {
                    return false;
                }
            }
            return true;
        };
        
        for (const auto &c:t) {
            ++ori[c];
        }
        int len = INT_MAX, l = 0,r = -1, ansL = -1;
        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()){
                ++cnt[s[r]];
            }
            while (isValid() && l <= r) {
                if(r -l +1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
    
};

class yangHuiSanjiao {
    /*
     输入: numRows = 5
     输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
     示例 2:

     输入: numRows = 1
     输出: [[1]]
      
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;

    }
    
    int maximalSquare(vector<vector<char>>& matrix) {


              if (matrix.size() == 0 || matrix[0].size() == 0) {
               return 0;
           }
           int maxSide = 0;
           int rows = (int)matrix.size(), columns = (int)matrix[0].size();
           vector<vector<int>> dp(rows, vector<int>(columns));
           for (int i = 0; i < rows; i++) {
               for (int j = 0; j < columns; j++) {
                   if (matrix[i][j] == '1') {
                       if (i == 0 || j == 0) {
                           dp[i][j] = 1;
                       } else {
                     
                           dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                       }
                       maxSide = max(maxSide, dp[i][j]);
                   }
               }
           }
           int maxSquare = maxSide * maxSide;
           return maxSquare;
       }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), []( auto a , auto b) {
            return  a[0] < b[0];
        });
        int count = 0; // 注意这里从0开始，因为是记录重叠区间
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end)  end = intervals[i][1]; // 无重叠的情况
            else { // 重叠情况
                end = min(end, intervals[i][1]);
                count++;
            }
        }
        return count;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        bool isDoubleNumber = nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
        return isDoubleNumber;
    }
    
    // https://leetcode.cn/problems/spiral-matrix-ii/description/
    /*
     
     代码
     测试用例
     测试结果
     测试结果
     59. 螺旋矩阵 II
     已解答
     中等
     相关标签
     相关企业
     给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
     */
    
    vector<vector<int>> generateMatrix(int n) {
          int maxNum = n * n;
          int curNum = 1;
          vector<vector<int>> matrix(n, vector<int>(n));
          int row = 0, column = 0;
          vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
          int directionIndex = 0;
          while (curNum <= maxNum) {
              matrix[row][column] = curNum;
              curNum++;
              int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
              if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
                  directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
              }
              row = row + directions[directionIndex][0];
              column = column + directions[directionIndex][1];
          }
          return matrix;
      }
};


class MyTuple {
    tuple<int, double> myFunction() {
        return make_tuple(10, 3.14);
    }
public:
    void test() {
        auto result = myFunction();
        int age =  get<0>(result);
        double height = get<1>(result);
        cout << "age:" <<age << " height" << height << endl;
        
    }
};

class RemoveElement {
    
    public :
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int i = 0; i < nums.size() -1; i ++) {
            if (val != nums[i]) {
                nums[left++] = nums[i];
            }
        }
        return left;
    }
    
    
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        int left = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i - 1]) {
                nums[left++] = nums[i];
            }
        }
        return left;
    }
    
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            if (ret > INT_MAX / 10 || ret < INT_MIN / 10) {
                return 0;
            } else {
                ret = ret + x % 10;
                x = x / 10;
            }
        }
        return ret;
    }
    
    vector<int> sortedSquares(vector<int>& nums) {
          int size = (int)nums.size();
          int k = size - 1;
          vector<int>result(size,0);
          int i = 0;
          int j = k;
          while (i <= j) {
              if (nums[i] * nums[i] < nums[j] *nums[j]) {
                  result[k--] = nums[j] * nums[j];
                  j --;
              } else {
                  result[k--] = nums[i] * nums[i];
                  i++;
              }
          }
          return result;
      }
    
   int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sublength = 0;
        int size = (int)nums.size();
        int sum = 0;
        int i = 0;
        for (int j = 0; j < size; j ++) {
            sum += nums[j];
            while (sum >= target) {
                sublength = (j - i + 1);
                result = min(sublength, result);
                sum -= nums[i++];
            }
           
        }
        return result == INT32_MAX ? 0 : result;
    }
};
#endif /* MyArray_hpp */
