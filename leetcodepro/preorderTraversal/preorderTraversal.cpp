//
//  preorderTraversal.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/7/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "preorderTraversal.h"

void preorderIter(TreeNode *node, vector<int> &ret) {
    if (!node) return;
    ret.push_back(node->val);
    cout << node->val <<endl;
    preorderIter(node->left, ret);
    preorderIter(node->right, ret);
}

void preorderIter2(TreeNode *node, stack<TreeNode*>&st, vector<int>&ret) {
    while (!st.empty()) {
        TreeNode *top = st.top();
        st.pop();
        
        ret.push_back(top->val);
        if (top->right) st.push(top->right);
        if (top->left) st.push(top->left);
    }
}

vector<int> preorderTraversal(TreeNode *root){
    vector<int> ret;
    if (!root) return ret;
    stack<TreeNode *> st;
    st.push(root);
    preorderIter2(root, st, ret);
    return ret;
}

void preorderTraversalTest() {
    int raw[] = {1,2};
    TreeNode *tree = buildTree(raw, 2);
    vector<int> result = preorderTraversal(tree);
//    for (int i : result) cout << i << " ";
}