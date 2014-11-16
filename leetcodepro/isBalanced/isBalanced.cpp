//
//  isBalanced.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/27/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "isBalanced.h"

int depth(TreeNode *node) {
    if (!node) return 0;
    if (!node->left) {
        return 1 + depth(node->right);
    }
    else if (!node->right) {
        return 1 + depth(node->left);
    }
    return 1+max(depth(node->left), depth(node->right));
}

bool isBalanced(TreeNode *root) {
    if (!root) return true;
    int val = depth(root->left) - depth(root->right);
    if (abs(val) <= 1) {
        return isBalanced(root->left) && isBalanced(root->right);
    }
    return false;
}

void isBalancedTest() {
    int treeData[] = {1,2};
    TreeNode *tree = buildTree(treeData, 2);
    cout << isBalanced(tree) << endl;
}
