//
//  TreeNode.cpp
//  C++
//
//  Created by 张帅 on 2023/5/17.
//

#include "TreeNode.hpp"
#include <string>


class TreeNodeTraversal {
    
    
public:
    
    // 前序遍历
    void traversal(TreeNode* cur, vector<int>& vec) {
          if (cur == NULL) return;
          vec.push_back(cur->val);    // 中
          traversal(cur->left, vec);  // 左
          traversal(cur->right, vec); // 右
      }
    
    
    // 中序遍历：
    void traversalII(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        traversal(cur->right, vec); // 右
    }
    
//    后序遍历：
    void traversalIII(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }
};

class TreeNodeIteration {
    
    
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> result;
         stack<TreeNode*> st;
         TreeNode* cur = root;
         while (cur != NULL || !st.empty()) {
             if (cur != NULL) { // 指针来访问节点，访问到最底层
                 st.push(cur); // 将访问的节点放进栈
                 cur = cur->left;                // 左
             } else {
                 cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                 st.pop();
                 result.push_back(cur->val);     // 中
                 cur = cur->right;               // 右
             }
         }
         return result;
     }
    
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;    //  中 右 左
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> que;
    if (root != NULL) {
        que.push(root);
    }
    while (!que.empty()) {
        long size = que.size();
        vector<int>  vec;
        for(int i = 0; i< size; i++) {
            TreeNode *node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        }
        result.push_back(vec);
    }
    return result;
}


TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

bool compare(TreeNode* left, TreeNode* right) {
    if (left != NULL && right == nullptr ) {
        return false;
    } else if (left == NULL && right != NULL) {
        return false;
    } else if (left == NULL && right == NULL) {
        return true;
    } else if (left->val != right->val ) {
        return false;
    }
    bool outSide = compare(left->left, right->right);
    bool inSide = compare(left->right, right->left);
    return outSide && inSide;
}

bool compareII(TreeNode *left, TreeNode* right) {
    if (left!= nullptr && right == nullptr) {
        return false;
    } else if (left == nullptr && right != nullptr) {
        return false;
    } if (left->val != right->val) {
        return  false;
    }
    return compareII(left->left, right->right) && compareII(left->right, right->left);;
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return compare(root->left, root->right);
}

bool isSymmetriciteration(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    queue<TreeNode*>que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        TreeNode *left = que.front();
        que.pop();
        TreeNode *right = que.front();
        que.pop();
        if (!left && !right) {
            continue;
        }
        
        if (!left || !right || left->val != right->val) {
            return false;
        }
        que.push(left->left);
        que.push(right->right);
        que.push(left->right);
        que.push(right->left);
    }
    return true;
}


int getdepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(getdepth(root->left), getdepth(root->right)) + 1;
}

int getdepthIteration(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(getdepth(root->left), getdepth(root->right)) + 1;
}


class solution {
    
public:
    int result;
    void getdepth(TreeNode* node, int depth) {
        result = max(result, depth);
        if(node->left == nullptr && node->right == nullptr) {
            return;
        }
        if (node->left) {
             depth++;
            getdepth(node->left,depth);
            depth--;
        }
        if (node->right) {
            depth++;
            getdepth(node->right,depth);
            depth--;
        }
    }
    int maxDepth(TreeNode* root) {
         result = 0;
         if (root == NULL) return 0;
         getdepth(root, 1);
         return result;
     }
    
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        if (node->left == NULL && node->right != nullptr) {
            return  1 + rightDepth;
        }

        if (node->right == NULL && node->left != nullptr) {
            return  1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }
    
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
    
    int miniterationDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            depth ++;
            long size = que.size();
            for (int i=0; i< size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left){
                    que.push(node->left);
                }
                if (node->right){
                    que.push(node->right);
                }
                if (!node->left && !node->right) {
                    return depth;
                }
            }
        }
        return depth;
    }
};

/*
 完全二叉树
 以上方法都是按照普通二叉树来做的，对于完全二叉树特性不了解的同学可以看这篇 关于二叉树，你该了解这些！，这篇详细介绍了各种二叉树的特性。

 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^(h-1)  个节点。

 大家要自己看完全二叉树的定义，很多同学对完全二叉树其实不是真正的懂了。

 我来举一个典型的例子如题：
 */
int countNodes(TreeNode* root) {
    if(root == nullptr) return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth = 0;
    int rightDepth = 0;
    while (left) {
        left = left->left;
        leftDepth ++;
    }
    while (right) {
        right = right->right;
        rightDepth ++;
    }
    
    if (leftDepth == rightDepth) {
        return (2 << leftDepth ) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
    }
    return countNodes(left) + countNodes(right) + 1;
}


int getHeight(TreeNode* node) {
    if(node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1) return -1;
    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    return getHeight(root) == -1 ? false : true;
}

int getDepth(TreeNode* cur) {
    stack<TreeNode*>st;
    if (cur == nullptr) {
        st.push(cur);
    }
    int result = 0;
    int depth = 0;
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node);  // 中
            st.push(nullptr);
            depth ++;
            if (node->right) {
                st.push(node->right);   // 右
            }
            if (node->left) {
                st.push(node->left);     // 左
            }
        } else {
            st.pop();
            node = st.top();
            st.pop();
            depth--;
        }
        result = max(depth, result);
    }
    return result;
}

bool isBalancedIteration(TreeNode* root) {
    stack<TreeNode*>st;
    if (root == nullptr) {
        return  true;
    }
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        if (abs(getdepth(node->left) - getdepth(node->right)) > 1) {
            return false;
        }
        if (node->right) st.push(node->right);           // 右（空节点不入栈）
        if (node->left) st.push(node->left);
    }
    return true;
}


void traversal(TreeNode * cur,vector<int> &path, vector<string> &result) {
    path.push_back(cur->val);
    if (cur->left == nullptr && cur->right == nullptr) {
        string sPath;
        for (int i=0; i< path.size() -1; ++i) {
            sPath += to_string(path[i]);
            sPath += "->";
        }
        sPath += to_string(path[path.size() -1]);
        result.push_back(sPath);
        return;
    }
    if (cur ->left) {
        traversal(cur->left, path, result);
        path.pop_back();
    }
    
    if (cur->right) {
        traversal(cur->right, path, result);
        path.pop_back();
    }
}
 

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    vector<int> path;
    if(root == nullptr) return result ;
    traversal(root, path, result);
    return result;
}

vector<string> binaryTreePathsIteration(TreeNode* root) {
    vector<string> result;
    stack<TreeNode*> treeStack;
    stack<string> pathStack;
    if (root == nullptr) {
        return result;
    }
    treeStack.push(root);
    pathStack.push(to_string(root->val));
    while (!treeStack.empty()) {
        TreeNode *node = treeStack.top(); treeStack.pop();
        string path = pathStack.top(); pathStack.pop();
        if(node->left == nullptr && node->right == nullptr){
            result.push_back(path);
        }
        if(node->left) {
            treeStack.push(node->left);
            pathStack.push(path + "->" + to_string(node->left->val));
        }
        if(node->right) {
            treeStack.push(node->right);
            pathStack.push(path + "->" + to_string(node->right->val));
        }
    }
    return result;
}

int leftNodeSum(TreeNode *root) {
    int result = 0;
    queue<TreeNode*> que;
    if(root == NULL) return result;
    que.push(root);
    while (!que.empty()) {
        TreeNode *node = que.front();que.pop();
        if (node->left !=nullptr &&node->left->left == nullptr&&node->left->right == nullptr ) {
            result += node->left->val;
        }
        if (node->left) {
            que.push(node->left);
        }
        if (node->right) {
            que.push(node->right);
        }
    }
    return result;
}


class LeftNodeSolution {
//    给定一个二叉树，在树的最后一行找到最左边的值。
public:
    int maxDepth = INT_MIN;
    int result = 0;
    void traversal(TreeNode* root, int depth) {
        if(root->left == NULL && root->right == nullptr) {
            if(depth > maxDepth) {
                maxDepth = depth;
                result = root-> val;
            }
            return;
        }
        if (root->left) {
            traversal(root->left, depth +1);
        }
        if (root->right) {
            traversal(root->right, depth + 1);
        }
    }
    
    int findBottomleftValue(TreeNode*root) {
        traversal(root, 0);
        return result;
    }
    
    int findBottomleftValueIteration(TreeNode*root) {
        queue<TreeNode*> que;
        if (root != NULL) {
            que.push(root);
        }
        int result = 0;
        while (!que.empty()) {
            long size = que.size();
            for (int i=0; i< size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (i== 0) {
                    result = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return result;
    }
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right && sum == root->val) {
        return true;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}


bool hasPathSumIteration(TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    stack<pair<TreeNode*, int>> st;
    pair<TreeNode *, int>  node = st.top();
    st.pop();
    if (!node.first->left && !node.first->right && sum == node.second)  return true;
    if(node.first->right) {
        st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
    }
    
    if(node.first->left) {
        st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
    }
    return false;
}


TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
    
    if (postorder.size() == 0) {
        return NULL;
    }
    int rootValue = postorder[postorder.size() -1];
    TreeNode *root =  new TreeNode(rootValue);
    if (postorder.size() == 1) {
        return root;
    }
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size() ; delimiterIndex ++) {
        if (inorder[delimiterIndex] == rootValue) {
            break;
        }
    }
    
    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
    
    postorder.resize(postorder.size()-1);
    
    vector<int>leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
    
    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() ==0 || postorder.size() == 0) {
        return NULL;
    }
    return traversal(inorder, postorder);
}


TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
    
    if(preorderBegin == preorderEnd) {
        return NULL;
    }
    int rootValue = preorder[preorderBegin];
    TreeNode *root = new TreeNode(rootValue);
    if (preorderEnd - preorderBegin == 1) {
        return root;
    }
    
    int delimiterIndex;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; ++delimiterIndex) {
        if(inorder[delimiterIndex] == rootValue) break;
    }

    int leftInoderBegin = inorderBegin;
    int leftInoderEnd = delimiterIndex;
    int rightInorderBegin = delimiterIndex + 1;
    int rightInorderEnd = inorderEnd;
    
    
    // 切割前序数组
    int leftPreorderBegin = preorderBegin + 1;
    int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
    
    int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
    int rightPreorderEnd = preorderEnd;
 
    root->left = traversal(inorder, leftInoderBegin, leftInoderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
    root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, preorder, rightInorderBegin, rightInorderEnd);
    
    return root;
}

TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
    if (inorder.size() == 0 || preorder.size() == 0) {
        return NULL;
    }
    
    return traversal(inorder, 0, (int)inorder.size(), preorder, 0, (int)preorder.size());
  
}


class Solution2 {

private:
    unordered_map<int, int> indexMap;
public:
    TreeNode *buideTree(const vector<int> preorder, const vector<int> &inorder,int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        int preorder_root = preorder_left;
        int inorder_root = indexMap[preorder[preorder_root]];
        
        TreeNode *root = new TreeNode(preorder[preorder_root]);
      
        int size_left_subtree = inorder_root - inorder_left;
        
        root->left = buideTree(preorder, inorder, preorder_left +1, preorder_left +size_left_subtree, inorder_left, inorder_root -1);
        
        root->right = buideTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    
    TreeNode *buildTree(vector<int>& preorder,vector<int>& inorder) {
        int n = (int)preorder.size();
        for (int i=0; i< n; ++i) {
            indexMap[inorder[i]] = i;
        }
        return buideTree(preorder, inorder, 0, n -1, 0, n -1);
    }
};


TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL) return root2;
    if (root2 == NULL) {
        return root1;
    }
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    if(root->val > val) return searchBST(root->left, val);
    if(root->val < val) return searchBST(root->right, val);
    return nullptr;
 
}

class SearchBST {
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if(root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return nullptr;
    }
    
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool left = isValidBST(root->left);
        if (pre != nullptr  && pre->val >= root->val) return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    while (cur != nullptr || !st.empty()) {
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            if(pre != nullptr && pre->val >= cur->val) return false;
            pre = cur;
            cur = cur->right;
        }
    }
    return true;
}



class SolutionSearchBSTMin {
private: vector<int> vec;
    
public:
    void traversal(TreeNode *root) {
        if(root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
    
    int getMinNumDifferce(TreeNode *root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i=1; i< vec.size(); ++i) {
            result = min(result, vec[i] -vec[i-1]);
        }
        return result;
    }
};


class SolutionSearchBSTMin1 {

public:
    int result = INT_MAX;
    TreeNode *pre = nullptr;
    
    void traversal(TreeNode *root) {
        if(root == nullptr) return;
        traversal(root->left);   // 左
        if(pre != nullptr) {
            result = min(result, root->val - pre->val);
        }
        pre = root;
        traversal(root->right);
    }
    int getMinNumDifferce(TreeNode *root) {
        traversal(root);
        return result;
    }

//    -------------------------------
    void searchBST(TreeNode *current, unordered_map<int, int> &map) {
        if(current == nullptr)  return;
        map[current->val] ++;
        searchBST(current->left, map);
        searchBST(current->right, map);
    }
    bool static cmp(const pair<int, int>&a, const pair<int, int> &b){
        return a.second > b.second;
    }
    
    vector<int> findMode(TreeNode *root) {
        /*
         给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

         假定 BST 有如下定义：

         结点左子树中所含结点的值小于等于当前结点的值
         结点右子树中所含结点的值大于等于当前结点的值
         左子树和右子树都是二叉搜索树
         
         给定 BST [1,null,2,2],

         501. 二叉搜索树中的众数

         返回[2].
         */
        unordered_map<int, int> map;
        vector<int> result;
        if(root == nullptr) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        result.push_back(vec[0].first);
        for (int i=1; i< vec.size(); ++i) {
            if(vec[i].second ==  vec[0].second) {
                result.push_back(vec[i].first);
            }
        }
        return result;
    }
};



class SearchBSTMode {
  
private:
   int maxCount = 0;
    int count = 0;
    TreeNode *pre = nullptr;
    vector<int> result;
    
public:
    void searchBST(TreeNode *current) {
        if(current == nullptr) return;
        searchBST(current->left);
        
        if (pre == nullptr || pre-> val != current->val) {
            count = 1;
        } else {
            count ++;
        }
        pre = current;
        if(count == maxCount) {
            result.push_back(current->val);
        }
        if(count >maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(current->val);
        }
        searchBST(current->right);
    }
    
    vector<int> findMode(TreeNode *root) {
        count = 0;
        maxCount = 0;
        pre = nullptr;
        result.clear();
        searchBST(root);
        return result;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val ) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
        
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left != nullptr && right != nullptr) return root;
    if(left == nullptr) return right;
    return left;
}


class LowestCommonAncestorBST {
    
private:
    TreeNode *result;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if(root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val){
                root = root->right;
            } else {break;}
        }
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val)  {
        if(root == nullptr) {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};


class SolutionBSTInsert {
    
public:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) {
        if(cur == nullptr) {
            TreeNode *node = new TreeNode(val);
            if(val > parent->val) {
                parent->right = node;
            } else  {
                parent->left = node;
            }
            return;
        }
        parent = cur;
        if(cur->val >val)  traversal(cur->left, val);
        if (cur->val < val) traversal(cur->right, val);
        return;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent = new TreeNode(0);
        if (root == nullptr) {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
    
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr) {
        return new TreeNode(val);
    }
    TreeNode *current = root;
    TreeNode *parent = root;
    if(current !=nullptr) {
        parent = current;
        if(current->val > val) current = current->left;
        if(current->val < val) current = current->right;
    }
    TreeNode *node = new TreeNode(val);
    if(parent->val > val) {
        parent->left = node;
    }
    if (parent->val < val) {
        parent->right = node;
    }
    return node;
    
}


TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if(root->val == key) {
        if(root->left == nullptr && root->right == nullptr) {
            delete  root;
            return nullptr;
        } else if (root->left == nullptr) {
            TreeNode *right = root->right;
            delete root;
            return right;
        }  else if (root->right == nullptr) {
            TreeNode *left = root->left;
            delete root;
            return left;
        } else {
            TreeNode *current = root->right;
            while (current->left != nullptr) {
                current = current->left;
            }
            
            current->left = root->left;
            TreeNode *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
    }
    
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    
    return root;
}

class SortedArrayToBST {
    
    
public:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if(left> right) {
            return nullptr;
        }
        int mid = left + ((right -left) >> 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid-1);
        root->right = traversal(nums, mid + 1, right);
        return root;
        
    }
    
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *root = traversal(nums, 0, (int32_t)nums.size()-1);
        return root;
    }
};

class ZuHE {
//    给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
/*
 输入: n = 4, k = 2
 输出:
 [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
 ]
 
 输入: n = 1, k = 1
 输出: [[1]]
 */
     
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i= startIndex; i <= n -(k - path.size()) + 1; ++i) {
            path.push_back(i);
            backtracking(n, k, i +1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

class Combining {
    /*
     找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

     说明：

     所有数字都是正整数。
     解集不能包含重复的组合。
     示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]

     示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]


     */
public:
    vector<vector<int>>reslut;
    vector<int> path;
    
    void backtracking(int target,int k, int sum, int startIndx) {
       
        if(sum > target) {
            return;
        }
        if(path.size() == k) {
            if(sum == target) {
                reslut.push_back(path);
            }
            return;
        }
        for (int i=startIndx; i< 9-(k -path.size()) + 1; ++i) {
            sum += i;
            path.push_back(i);
            backtracking(target,k, sum,i +1);
            sum -=i;
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        reslut.clear();
        path.clear();
        backtracking(n,k, 0, 1);
        return reslut;
    }
};


class PhoneNumber {
private:
  
public:
    
    const string letterMap[10] = {
        "",
        "",
        "abc", //2
        "def", //3
        "ghi", //
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;
    string s;
    void backtracking(const string &digits, int index) {
        if(index == digits.size()) {
            result.push_back(s);
            return;
        }
        
        int digit = digits[index] - '0';
        string lettters = letterMap[digit];
        for(char ch: lettters) {
            s.push_back(ch);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if(digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};


class SolutionComBine {
    
    
public:
    
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i= startIndex; i< candidates.size() &&  sum + candidates[i] <= target; ++i) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
    
};

class Palindrome {
    
    
public:
    vector<vector<string>> result;
    vector<string> path; // 放已经回文的子串
    vector<vector<bool>> palindromes; // 放事先计算好的是否回文子串的结果
    
    bool isPalindrome(const string& s, int start, int end) {
        for (int i= start, j = end; i< j;  ++i, --j) {
            if (s[start] != s[end]) {
                return false;
            }
        }
        return true;
    }
    
    void backtracking(const string &s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i= startIndex; i< s.size(); ++i) {
            if(palindromes[startIndex][i]) {
                string str = s.substr(startIndex, i- startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }
            backtracking(s, i +1);
            path.pop_back();
            
        }
    }
    
    void computePalindrome(const string &s) {
        palindromes.resize(s.size(), vector<bool>(s.size(),false));
        for (int i= (int)s.size()-1; i >=0 ; i--) {
            for (int j = i; j < s.size(); j++) {
                if (j == i) {
                    palindromes[i][j] = true;
                } else if (j -i == 1) {
                    palindromes[i][j]  = (s[i] == s[j]);
                } else {
                    palindromes[i][j]  = (s[i] == s[j] && palindromes[i+1][j-1]);
                }
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        computePalindrome(s);
        backtracking(s, 0);
        return result;
    }
    
};


class IPRe {
    
public:
    vector<string> result;
    bool isValid(const string &s, int start, int end) {
        if(start > end) {
            return false;
        }
        if(s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i=start; i< end; ++i) {
            if(s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num *10 + (s[i] - '0');
            if(num > 255) {
                return false;
            }
        }
        return true;
    }
    
    void backtracking(string &s, int start, int pointNum) {
        if(pointNum == 3) {
            if (isValid(s, start, (int)s.size() -1)) {
                result.push_back(s);
            }
            return;
        }
        
        for (int i=start; i< s.size(); ++i) {
            if (isValid(s, start, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum --;
                s.erase(s.begin() + i + 1);
            } else break;;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};

