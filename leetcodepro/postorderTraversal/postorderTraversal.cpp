//
//  postorderTraversal.cpp
//  leetcodepro
//
//  Created by drakeDan on 5/19/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "postorderTraversal.h"
#include <vector>
#include <iostream>
#include <stack>
#include "common.h"
using namespace std;


void help(TreeNode *node, vector<int>& ret) {
    if (!node) return;
    help(node->left, ret);
    help(node->right, ret);
    ret.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    help(root, ret);
    return ret;
}

vector<int> postorderTraversal2(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> ret;
    if (!root) return ret;
    
    st.push(root);
    return ret;
}

void postorderTraversalTest() {
    int raw[] = {1,-1,2,-1,-1,-1,3};
    TreeNode *tree = buildTree(raw, 7);
    vector<int> ret = postorderTraversal(tree);
    for (int r : ret) {
        cout << r << ",";
    }
}
