//
//  common.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/27/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "common.h"


/* buildTree ======================================*/
TreeNode *buildTreeIter(int *list, int i, int len) {
    if (i >= len) return NULL;
    if (list[i] < 0) return NULL;
    TreeNode *node = new TreeNode(list[i]);
    node->left = buildTreeIter(list, 2*i+1, len);
    node->right = buildTreeIter(list, 2*i+2, len);
    return node;
}

TreeNode *buildTree(int *list, int len) {
    return buildTreeIter(list, 0, len);
}

/* buildTree END =================================*/

/* buildList =====================================*/
ListNode *buildListIter(int *list, int i, int len) {
    if (i > len-1) return NULL;
    ListNode *node = new ListNode(list[i]);
    node->next = buildListIter(list, i+1, len);
    return node;
}
ListNode *buildList(int *list, int len) {
    return buildListIter(list, 0, len);
}
/* buildList END =================================*/


