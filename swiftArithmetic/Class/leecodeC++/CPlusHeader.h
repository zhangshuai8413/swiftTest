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
#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <set>
#include <map>
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;


#endif /* CPlusHeader_h */
