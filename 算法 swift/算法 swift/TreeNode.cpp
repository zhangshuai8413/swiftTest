//
//  TreeNode.cpp
//  C++
//
//  Created by 张帅 on 2023/5/17.
//

#include "TreeNode.hpp"
#include <string>

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
        return (2 << leftDepth )-1;
    }
    return countNodes(left) + countNodes(right);
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
        if (node == NULL) {
            st.pop();
            st.push(node);
            st.push(nullptr);
            depth ++;
        } else {
            st.pop();
            node = st.top();
            st.pop();
            depth--;
        }
        result = max(depth, result);
    }
    return 0;
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
