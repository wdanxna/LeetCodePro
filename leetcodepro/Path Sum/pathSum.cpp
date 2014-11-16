//
//  pathSum.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/9/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "pathSum.h"
#include "common.h"

bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    int val = sum - root->val;
    if (val == 0) {
        if (!root->left && !root->right)
            return true;
    }

    return hasPathSum(root->left, val) || hasPathSum(root->right, val);
}

void pathSumTest() {
    int raw[] = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,1};
    TreeNode *tree = buildTree(raw, 15);
    cout << hasPathSum(tree, 22) << endl;
}
