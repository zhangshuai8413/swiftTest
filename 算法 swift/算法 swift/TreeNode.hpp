//
//  TreeNode.hpp
//  C++
//
//  Created by 张帅 on 2023/5/17.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right) {}
};


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
                st.push(node->right);
            }
            if(node->left){
               st.push(node->left);
            }
            st.push(node);
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
                st.push(node->right);
            }
            st.push(node);
            st.push(NULL);
            if(node->left){
               st.push(node->left);
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
    stack<TreeNode*>st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        if(node->left){
            st.push(node->left);
        }
        if(node->right){
            st.push(node->right);
        }
        result.insert(result.begin(), node->val);
    }
  
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
            st.push(node);
            st.push(NULL);
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
               st.push(node->left);
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

vector<vector<int>> levelOrder(TreeNode* root);

#endif /* TreeNode_hpp */
