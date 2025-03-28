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

ListNode *addTwoNumbers1(ListNode *l1,ListNode *l2) {
    int carray = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 != nullptr || l2 != nullptr || carray != 0) {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2 ->val : 0;
        int sum = a + b + carray;
        tail->next = new  ListNode(sum % 10);
        carray = sum / 10;
        
        if (l1){
            l1 = l1->next;
        }
        if (l2){
            l2 = l2->next;
        }
    }
    return  dummy->next;
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

class ReverseListII {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        // 递归调用，翻转第二个节点开始往后的链表
        ListNode *last = reverseList(head->next);
        // 翻转头节点与第二个节点的指向
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head->next = NULL;
        return last;
    }

};

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


ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> visited;
    while (head != nullptr) {
        if (visited.count(head)) {
            return head;
        }
        visited.insert(head);
        head = head->next;
    }
    return nullptr;
    
}

#endif /* ListNode_hpp */

class SolutionDeleteDuplicatesII {
    /*
     
     给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

     环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

     子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

      

     示例 1：

     输入：nums = [1,-2,3,-2]
     输出：3
     解释：从子数组 [3] 得到最大和 3
     示例 2：

     输入：nums = [5,-3,5]
     输出：10
     解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
     示例 3：

     输入：nums = [3,-2,2,-3]
     输出：3
     解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
      
     
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/solutions/678122/shan-chu-pai-xu-lian-biao-zhong-de-zhong-oayn/
     
     给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
     输入：head = [1,2,3,3,4,4,5]
     输出：[1,2,5]
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<>> q;
    for (const auto &num: nums) {
        if (q.size() < k) {
            q.push(num);
        } else if (q.top() < num) {
            q.pop();
            q.push(num);
        }
    }
    return q.top();
}

class SolutionReconstructQueue {
public:
  
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};



class SolutionMergeKLists {
    
    /*
     合并排序链表
     */
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };
    
    priority_queue <Status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

class DeleteNode {
    
public:
    void deleteNode(ListNode* node, int target) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


class ReverseList {
    
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        for (int i = 0; i< left - 1 ; i ++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i< right - left; i ++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            
        }
        return dummyNode->next;
    }
};


class GenerateTrees {
    
public:
    
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        if (start > end) {
            return { nullptr };
        }
        for (int i = start; i <= end; i ++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            for (auto &left: leftTrees) {
                for (auto &right : rightTrees) {
                    TreeNode *currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.emplace_back(currentTree);
                }
            }
            
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};

class NumTrees {
    // 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
    
    /*
    示例 1：
    输入：n = 3
    输出：5
    示例 2：

    输入：n = 1
    输出：1
*/
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;  // 空树的数量为1
        dp[1] = 1;  // 只有一个节点的树的数量为1
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};


class SortList {
    
public:
    
    ListNode* getMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        
        return dummyHead->next;
    }
  
    ListNode* sortList(ListNode* head) {
   
        if (!head || !head->next) {
            return head;
        }
        ListNode *mid = getMiddle(head);
        ListNode *right = mid->next;
        mid->next = nullptr;
        
        ListNode * leftSort = sortList(head);
        ListNode * rightSort = sortList(right);
        return merge(leftSort, rightSort);
        
    }
};
