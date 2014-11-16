//
//  minDepth.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/12/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "minDepth.h"
#include "common.h"
using namespace std;

int minDepth(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    
    int leftMin = INT_MAX;
    int rightMin = INT_MAX;
    
    if (root->left)
        leftMin = minDepth(root->left);
    if (root->right)
        rightMin = minDepth(root->right);
    
    return leftMin < rightMin ? leftMin+1 : rightMin+1;
}

void minDepthTest() {
    int raw[] = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,1};
    TreeNode *tree = buildTree(raw, 15);
    cout << minDepth(tree) << endl;
}