//
//  zigzagOrderLevel.h
//  leetcodepro
//
//  Created by drakeDan on 10/24/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#ifndef __leetcodepro__zigzagOrderLevel__
#define __leetcodepro__zigzagOrderLevel__

#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stack>
#include "common.h"
using namespace std;

TreeNode* buildTree(const char *list, int i, int len);
vector<vector<int>> zigzagLevelOrder(TreeNode *root);

#endif /* defined(__leetcodepro__zigzagOrderLevel__) */
