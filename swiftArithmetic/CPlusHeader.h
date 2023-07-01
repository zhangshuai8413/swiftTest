//
//  CPlusHeader.h
//  swiftArithmetic
//
//  Created by 张帅 on 2023/6/12.
//

#ifndef CPlusHeader_h
#define CPlusHeader_h

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_set>
#include <list>

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right) {}
};


using namespace std;



#endif /* CPlusHeader_h */
