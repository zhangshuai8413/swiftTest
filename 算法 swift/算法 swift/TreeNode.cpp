//
//  TreeNode.cpp
//  C++
//
//  Created by 张帅 on 2023/5/17.
//

#include "TreeNode.hpp"


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
};


