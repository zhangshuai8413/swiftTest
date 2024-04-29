//
//  TreeNode.hpp
//  C++
//
//  Created by 张帅 on 2023/5/17.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp
#include "CPlusHeader.h"

using namespace std;

// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right) {}
//};


void traversal(TreeNode *root, vector<int> &vec) {
    if (root == NULL) {
        return;
    }
    vec.push_back(root->val);
    traversal(root->left, vec);
    traversal(root->right, vec);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    traversal(root, result);
    return result;
}

class TreeNodeIterationII {
    //  二叉树 统一迭代
    
public:
    
    vector<int> preorderTraversal1(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int> result;
        st.push(root);
        while(!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            result.push_back(top->val);
            if (top->right) {
                st.push(top->right);
            }
            if (top->left) {
                st.push(top->left);
            }
        }
        return result;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        if(root != NULL)
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node) {
                st.pop();
                if(node->right){
                    st.push(node->right);  // 右边
                }
                if(node->left){
                   st.push(node->left);  // 左
                }
                st.push(node);  // 中
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
      
        return result;
    }



    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*>st;
        TreeNode *current = root;
        while (current != NULL || !st.empty()) {
            if (current != NULL) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                result.push_back(current->val);
                current = current->right;
            }
            
        }
        return result;

    }

    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        if(root != NULL)
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node) {
                st.pop();
                if(node->right){
                    st.push(node->right);  // 右边
                }
                st.push(node);
                st.push(NULL);   // 中
                if(node->left){
                   st.push(node->left);  //  左
                }
               
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;    // 中  右 左   - reverse   左 右 中
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }

    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>st;
        if(root != NULL)
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node) {
                st.pop();
                st.push(node);  // 中
                st.push(NULL);
                if(node->right){
                    st.push(node->right); // 右边
                }
                if(node->left){
                   st.push(node->left);   // 左
                }
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
      
        return result;
    }

};

vector<vector<int>> levelOrder(TreeNode* root);


class NodeMaxDepth {
    
public:
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        int depth = 0; // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左
                
            } else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
        
    }
    
    
    int maxDepthII(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
       
       stack<pair<TreeNode*, int>> s;
       s.push(make_pair(root, 1));
       int depth = 0;
       
       while (!s.empty()) {
           TreeNode* node = s.top().first;
           int currDepth = s.top().second;
           s.pop();
           
           if (node->left == NULL && node->right == NULL) {
               depth = max(depth, currDepth);
           }
           
           if (node->left != NULL) {
               s.push(make_pair(node->left, currDepth + 1));
           }
           
           if (node->right != NULL) {
               s.push(make_pair(node->right, currDepth + 1));
           }
       }
       
       return depth;
       }
};



//  LFU
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};

class DictLFUCache {
    
    
public:
    
    // 缓存的节点信息
    struct Node {
        int key, val, freq;
        Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
    };
    
    class LFUCache {
        int minfreq, capacity;
        unordered_map<int, list<Node>::iterator> key_table;
        unordered_map<int, list<Node>> freq_table;
    public:
        LFUCache(int _capacity) {
            minfreq = 0;
            capacity = _capacity;
            key_table.clear();
            freq_table.clear();
        }
        
        int get(int key) {
            if (capacity == 0) return -1;
            auto it = key_table.find(key);
            if (it == key_table.end()) return -1;
            list<Node>::iterator node = it -> second;
            int val = node -> val, freq = node -> freq;
            freq_table[freq].erase(node);
            // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            // 插入到 freq + 1 中
            freq_table[freq + 1].push_front(Node(key, val, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
            return val;
        }
        
        void put(int key, int value) {
            if (capacity == 0) return;
            auto it = key_table.find(key);
            if (it == key_table.end()) {
                // 缓存已满，需要进行删除操作
                if (key_table.size() == capacity) {
                    // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                    auto it2 = freq_table[minfreq].back();
                    key_table.erase(it2.key);
                    freq_table[minfreq].pop_back();
                    if (freq_table[minfreq].size() == 0) {
                        freq_table.erase(minfreq);
                    }
                }
                freq_table[1].push_front(Node(key, value, 1));
                key_table[key] = freq_table[1].begin();
                minfreq = 1;
            } else {
                // 与 get 操作基本一致，除了需要更新缓存的值
                list<Node>::iterator node = it -> second;
                int freq = node -> freq;
                freq_table[freq].erase(node);
                if (freq_table[freq].size() == 0) {
                    freq_table.erase(freq);
                    if (minfreq == freq) minfreq += 1;
                }
                freq_table[freq + 1].push_front(Node(key, value, freq + 1));
                key_table[key] = freq_table[freq + 1].begin();
            }
        }
    };

};


class SolutionSymmetric {
    /*
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/symmetric-tree/solutions/268109/dui-cheng-er-cha-shu-by-leetcode-solution/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     
     */
    
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

class SolutionMaxGain {
    /*
     
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/jC7MId/solutions/1398949/jie-dian-zhi-he-zui-da-de-lu-jing-by-lee-u5q7/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};


class ZigzagLevelOrder {
    
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        bool isleftRoRight = true;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = (int)queue.size();
            vector<int>level(size);
            for (int i= 0; i< size; ++i) {
                TreeNode *topNode = queue.front();
                queue.pop();
                int index = isleftRoRight ? i : (size - 1 - i);
                level[index] = topNode->val;
                if (topNode->left != nullptr) {
                    queue.push(topNode->left);
                }
                if (topNode->right != nullptr) {
                    queue.push(topNode->right);
                }
            }
            result.push_back(level);
            isleftRoRight = !isleftRoRight;
        }
        return result;
    }

};


class LevelOrderBottom {
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto levelOder = vector<vector<int>>();
        if (root == nullptr) {
            return levelOder;
        }
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            auto level = vector<int>();
            int size = (int)q.size();
            for (int i=0; i< size; ++i) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            levelOder.push_back(level);
        }
        reverse(levelOder.begin(), levelOder.end());
        return levelOder;
    }
    
public:
    
};

// 有序链表 转换搜索二叉树
class SortedListToBST {
    
    int getLength(ListNode * head) {
        int ret = 0;
        while (head != nullptr) {
            ret++;
            head = head->next;
        }
        return ret;
    }
    
    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode *root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
    
public:
    
};
#endif /* TreeNode_hpp */
