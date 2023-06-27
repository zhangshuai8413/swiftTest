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
    
    // 2 是无覆盖
    // 1 摄像头
    // 0 无覆盖
    int result = 0;
    int traversal(TreeNode* cur) {
        if(cur == nullptr) {
            return 2;
        }
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        
        if (left == 2 && right == 2) {
            return 0;
        }
        if(left == 0 || right == 0) {
            result += 1;
            return 1;
        }
        if(left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};


#endif /* Greedy_hpp */
