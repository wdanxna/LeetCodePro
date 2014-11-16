//
//  validBST.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/15/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "validBST.h"
#include <iostream>
#include <vector>
#include "common.h"
using namespace std;

bool validIter(TreeNode *node, TreeNode *left, TreeNode *right) {
    if (!node) return true;
    bool validLeft = true;
    bool validRight = true;
    if (node->left) {
        validLeft = (node->val > node->left->val);
        if (left) {
            validLeft = validLeft && (node->left->val > left->val);
        }
    }
    
    if (node->right) {
        validRight = (node->val < node->right->val);
        if (right) {
            validRight = validRight && (node->right->val < right->val);
        }
    }
    
    if (validLeft && validRight) {
        return validIter(node->left, left, node) && validIter(node->right, node, right);
    }
    return false;
}

bool isValidBST(TreeNode *root) {
    return validIter(root, NULL, NULL);
}

void midOrderTraversal(TreeNode *node, vector<int> &s) {
    if (!node) return;
    midOrderTraversal(node->left, s);
    s.push_back(node->val);
    midOrderTraversal(node->right, s);
}

bool newValid(TreeNode *root) {
    if (!root) return true;
    vector<int> s;
    midOrderTraversal(root, s);
    
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[i-1] || s[i] == s[i-1]) {
            return false;
        }
    }
    return true;
}

void validBSTTest() {
    int raw[] = {3,2,-1,1,-2147483648};
    TreeNode *bst = buildTree(raw, 5);
    bst->left->right = new TreeNode(-2147483648);
    cout << newValid(bst) << endl;
}
