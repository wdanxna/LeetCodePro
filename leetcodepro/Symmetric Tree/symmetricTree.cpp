//
//  symmetricTree.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/13/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "symmetricTree.h"
#include "common.h"
using namespace std;

bool symmetricIter(TreeNode *left, TreeNode *right) {
    if (!left && !right) return true;
    if (!(left && right)) return false;
    if (left->val == right->val) {
        return symmetricIter(left->left, right->right) && symmetricIter(left->right, right->left);
    }
    return false;
}

bool isSymmetric(TreeNode *root) {
    return symmetricIter(root->left, root->right);
}

void symmetricTreeTest() {
    int raw[] = {1,2,2,-1,3,-1,3};
    TreeNode *tree = buildTree(raw, 7);
    cout << isSymmetric(tree) << endl;
}