//
//  pathSum2.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/12/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "pathSum2.h"
#include "common.h"
using namespace std;

void pathSum2Iter(TreeNode *node, int sum, vector<int> t, vector<vector<int>> &ret) {
    if (!node) return;
    int val = sum - node->val;
    t.push_back(node->val);
    if (val == 0 && (!node->left && !node->right)) {
        ret.push_back(t);
        return;
    }
    pathSum2Iter(node->left, val, t, ret);
    pathSum2Iter(node->right, val, t, ret);
}

vector<vector<int> > pathSum2(TreeNode *root, int sum) {
    vector<vector<int>> ret;
    vector<int> t;
    pathSum2Iter(root, sum, t, ret);
    return ret;
}

void pathSum2Test() {
    int raw[] = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,5,1};
    TreeNode *tree = buildTree(raw, 15);
    vector<vector<int>> haha = pathSum2(tree, 22);
}
