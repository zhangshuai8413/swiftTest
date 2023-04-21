//
//  FLList.h
//  suanfaC++
//
//  Created by 张帅 on 2023/4/21.
//

#import <Foundation/Foundation.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode * _Nullable next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * _Nullable next) : val(x), next(next) {}
};


NS_ASSUME_NONNULL_BEGIN

@interface FLList : NSObject

ListNode * addTwo(ListNode *list1, ListNode *list2);

ListNode * reverse(ListNode *head);
std::vector<int> twoSum(std::vector<int>& nums, int target);

@end

NS_ASSUME_NONNULL_END
