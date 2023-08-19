//
//  ListNode.hpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/5/21.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>
#include "CPlusHeader.h"

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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


class SolutionDeleteDuplicates {
    
    /*
     
     输入：head = [1,1,2]
     输出：[1,2]
     
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-list/solutions/680357/shan-chu-pai-xu-lian-biao-zhong-de-zhong-49v5/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
};


/*
 作者：力扣官方题解
 链接：https://leetcode.cn/problems/3u1WK4/solutions/1037741/liang-ge-lian-biao-de-di-yi-ge-zhong-he-0msfg/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == nullptr || headB == nullptr) {
          return nullptr;
      }
      ListNode *pA = headA, *pB = headB;
      while (pA != pB) {
          pA = pA == nullptr ? headB : pA->next;
          pB = pB == nullptr ? headA : pB->next;
      }
      return pA;
  }

/*
 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

 返回删除后的链表的头节点。

 注意：此题对比原题有改动

 示例 1:

 输入: head = [4,5,1,9], val = 5
 输出: [4,1,9]
 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
 示例 2:

 输入: head = [4,5,1,9], val = 1
 输出: [4,5,9]
 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 */
ListNode* deleteNode(ListNode* head, int val) {

    if (!head) {
        return head;
    }
    if (head->val == val) {
        return head->next;
    }
    ListNode* p = head;
    while (p->next) {
        if (p->next->val == val) {
            p->next = p->next->next;
            return head;
        }
        p = p->next;
    }
    return head;
    
    
}

/*
 
 输入：head = [1,2,3,4,5], n = 2
 输出：[1,2,3,5]
 示例 2：

 输入：head = [1], n = 1
 输出：[]
 示例 3：

 输入：head = [1,2], n = 1
 输出：[1]

 作者：力扣官方题解
 链接：https://leetcode.cn/problems/SLwz0R/solutions/1417848/shan-chu-lian-biao-de-dao-shu-di-n-ge-ji-ydte/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0, head);
      ListNode* first = head;
      ListNode* second = dummy;
      for (int i = 0; i < n; ++i) {
          first = first->next;
      }
      while (first) {
          first = first->next;
          second = second->next;
      }
      second->next = second->next->next;
      ListNode* ans = dummy->next;
      delete dummy;
      return ans;
  }

/*
 作者：力扣官方题解
 链接：https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/solutions/1398788/he-bing-liang-ge-pai-xu-de-lian-biao-by-g3z6g/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     if (l1 == nullptr) {
         return l2;
     } else if (l2 == nullptr) {
         return l1;
     } else if (l1->val < l2->val) {
         l1->next = mergeTwoLists(l1->next, l2);
         return l1;
     } else {
         l2->next = mergeTwoLists(l1, l2->next);
         return l2;
     }
 }

ListNode* mergeTwoListsII(ListNode* l1, ListNode* l2) {
    ListNode* preHead = new ListNode(-1);
    
    ListNode* prev = preHead;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    prev->next = l1 == nullptr ? l2 : l1;
    
    return preHead->next;
}

/*
 
 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
  

 示例 1：


 输入：head = [1,2,6,3,4,5,6], val = 6
 输出：[1,2,3,4,5]
 示例 2：

 输入：head = [], val = 1
 输出：[]
 示例 3：

 输入：head = [7,7,7,7], val = 7
 输出：[]
  
 作者：力扣官方题解
 链接：https://leetcode.cn/problems/remove-linked-list-elements/solutions/813358/yi-chu-lian-biao-yuan-su-by-leetcode-sol-654m/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

ListNode* removeElements(ListNode* head, int val) {
      if (head == nullptr) {
          return head;
      }
      head->next = removeElements(head->next, val);
      return head->val == val ? head->next : head;
  }



ListNode* removeElementsII(ListNode* head, int val) {
      struct ListNode* dummyHead = new ListNode(0, head);
      struct ListNode* temp = dummyHead;
      while (temp->next != NULL) {
          if (temp->next->val == val) {
              temp->next = temp->next->next;
          } else {
              temp = temp->next;
          }
      }
      return dummyHead->next;
  }


ListNode* reverseList(ListNode* head) {
    ListNode* temp; // 保存cur的下一个节点
    ListNode* cur = head;
    ListNode* pre = NULL;
    while(cur) {
        temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
        cur->next = pre; // 翻转操作
        // 更新pre 和 cur指针
        pre = cur;
        cur = temp;
    }
    return pre;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
    dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
    ListNode* cur = dummyHead;
    while(cur->next != nullptr && cur->next->next != nullptr) {
        ListNode* tmp = cur->next; // 记录临时节点
        ListNode* tmp1 = cur->next->next->next; // 记录临时节点
        
        cur->next = cur->next->next;    // 步骤一
        cur->next->next = tmp;          // 步骤二
        cur->next->next->next = tmp1;   // 步骤三
        
        cur = cur->next->next; // cur移动两位，准备下一轮交换
    }
    return dummyHead->next;
}
#endif /* ListNode_hpp */
