//
//  flattenBinaryTree.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/7/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "flattenBinaryTree.h"

TreeNode *flattenIter(TreeNode *node) {
    if (!node) return NULL;
    if (!node->left && !node->right) {
        return node;
    }

    TreeNode *leftTail = flattenIter(node->left);
    TreeNode *rightTail = flattenIter(node->right);
    
    if (leftTail && node->right) {
        leftTail->right = node->right;
        node->right = node->left;
        node->left = NULL;
        return rightTail;
    }
    else if (leftTail) {
        node->right = node->left;
        node->left = NULL;
        return leftTail;
    }
    return rightTail;
}

void flatten(TreeNode *root) {
    flattenIter(root);
}

void flattenTest() {
    int raw[] = {1,-1,2};
    TreeNode *tree = buildTree(raw, 3);
    flatten(tree);
    cout << "hi" << endl;
}