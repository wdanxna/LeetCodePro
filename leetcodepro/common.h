//
//  common.h
//  leetcodepro
//
//  Created by drakeDan on 10/27/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#ifndef leetcodepro_common_h
#define leetcodepro_common_h
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*build positive integer tree, negtive value as null node. */
TreeNode *buildTree(int *list, int len);

/*build a integer single-linked list out of list*/
ListNode *buildList(int *list, int len);
#endif
