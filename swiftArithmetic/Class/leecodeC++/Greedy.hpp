//
//  Greedy.hpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/6/12.
//

#ifndef Greedy_hpp
#define Greedy_hpp

#include <stdio.h>
#include "CPlusHeader.h"
class DynmicProfit {
    int maxProfit(vector<int>& prices);
    int maxProfit1(vector<int>& prices);
    
};
using namespace std;

class MinCameraCover {
    /*
     https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0968.%E7%9B%91%E6%8E%A7%E4%BA%8C%E5%8F%89%E6%A0%91.md
     
     给定一个二叉树，我们在树的节点上安装摄像头。
     节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
     计算监控树的所有节点所需的最小摄像头数量。

     示例 1：
     输入：[0,0,null,0,0]
     输出：1
     解释：如图所示，一台摄像头足以监控所有节点。
     
     
     示例 2：
     输入：[0,0,null,0,null,0,null,null,0]
     输出：2
     解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
     提示：
     给定树的节点数的范围是 [1, 1000]。
     每个节点的值都是 0。
     
     */
    
private:
    
//    0：该节点无覆盖
//    1：本节点有摄像头
//    2：本节点有覆盖
    int result = 0;
    int traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return 2;
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        
        if (left == 2 && right == 2) return 0;
        else if (left == 0 || right == 0) {
            result++;
            return 1;
        } else return 2;
    }
    
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};

class CanCompleteCircuit {
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
    
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        int flag = (int)strNum.size(), size = (int)strNum.size();
        
        for (int i = size;i >=0; i--) {
            if (strNum[i -1] > strNum[i]) {
                flag = i;
                strNum[i-1]--;
            }
        }
        for(int i = flag; i < size; i ++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};

class MergeInterval {
    
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i< intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1]< L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
#endif /* Greedy_hpp */
