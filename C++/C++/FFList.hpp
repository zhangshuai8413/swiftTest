//
//  FFList.hpp
//  suanfaC++
//
//  Created by 张帅 on 2023/5/1.
//

#ifndef FFList_hpp
#define FFList_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode * _Nullable next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * _Nullable next) : val(x), next(next) {}
};

string longestPalindrome(string s);
ListNode * _Nullable _Nullable addTwo(ListNode * _Nullable list1, ListNode * _Nullable list2);
ListNode * _Nullable reverse(ListNode * _Nullable head);
vector<int> twoSum(vector<int>& nums, int target);

#endif /* FFList_hpp */
