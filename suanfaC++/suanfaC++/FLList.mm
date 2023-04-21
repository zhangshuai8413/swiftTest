//
//  FLList.m
//  suanfaC++
//
//  Created by 张帅 on 2023/4/21.
//

#import "FLList.h"

@implementation FLList

ListNode * addTwo(ListNode *l1, ListNode *l2) {
    int carray = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 != nullptr || l2 != nullptr || carray != 0) {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a + b + carray;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        carray = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    return dummy->next;
}

ListNode *reverse(ListNode *head) {
    if (head == nullptr ){
        return  head;
    }
    ListNode *pre = nullptr;
    ListNode *temp = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }
    return pre;
}

vector<int> twoSum(vector<int> & nums, int target) {
    unordered_map<int, int> map;
    for (int i=0; i< nums.size(); ++i) {
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            return {it-> second, i};
        }
    }
    return {};
}

@end
