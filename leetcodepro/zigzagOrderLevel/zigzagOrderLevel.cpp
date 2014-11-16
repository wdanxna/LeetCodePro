//
//  zigzagOrderLevel.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/24/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "zigzagOrderLevel.h"

//{3,9,20,#,#,15,7}
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//caution: val cannot > 255
TreeNode* buildTree(const char *list, int i,  int len) {
    if (i > len) return NULL;
    if (list[i] == '#') return NULL;
    
    TreeNode *root = (TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = (int)list[i];
    root->left = buildTree(list, 2*i+1, len);
    root->right = buildTree(list, 2*i+2, len);
    return root;
}

//[
//   [3],
//   [20,9],
//   [15,7]
//]
vector<vector<int>> zigzagLevelOrder(TreeNode *root){
    vector<vector<int>> res;
    if (!root) return res;
    vector<int> t;
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;
    stack<TreeNode*> *sp;
    
    sp = &leftStack;
    bool left = true;
    sp->push(root);
    
    while (!sp->empty()) {
        TreeNode* top = sp->top();
        t.push_back(top->val);
        if (left) {
            if (top->left)
                rightStack.push(top->left);
            if (top->right)
                rightStack.push(top->right);
        }
        else {
            if (top->right)
                leftStack.push(top->right);
            if (top->left)
                leftStack.push(top->left);
        }
        sp->pop();
        if (sp->empty()) {
            res.push_back(t);
            t.clear();
            sp = left? &rightStack : &leftStack;
            left = !left;
        }
    }
    return res;
}

void zigzagLevelOrderTest() {
    char list[] = {3,9,20,'#','#',15,7};
    TreeNode* root = buildTree(list, 0, 7);
    vector<vector<int>> hey = zigzagLevelOrder(root);
}