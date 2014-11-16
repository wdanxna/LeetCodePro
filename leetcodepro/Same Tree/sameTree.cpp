//
//  sameTree.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/13/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "sameTree.h"
#include "common.h"
using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!(p && q)) return false;
    if (p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}

void sameTreeTest() {
    int raw1[] = {1,2,2,3,3,4,4};
    int raw2[] = {1,2,2,3,3,5,4};
    TreeNode *p = buildTree(raw1, 7);
    TreeNode *q = buildTree(raw2, 7);
    cout << isSameTree(p, q) << endl;
}