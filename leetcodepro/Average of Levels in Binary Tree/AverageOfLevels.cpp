//
//  AverageOfLevels.cpp
//  leetcodepro
//
//  Created by drakeDan on 20/07/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#include "AverageOfLevels.hpp"
#include <iostream>

void dfsIter(TreeNode *root, int level, vector<vector<double>*>& rets) {
    if (root == nullptr) return;
    
    vector<double> *l;
    if (rets.size() <= level) {
        l = new vector<double>();
        rets.push_back(l);
    } else {
        l = rets.at(level);
    }
    
    l->push_back(root->val);
    dfsIter(root->right, level+1, rets);
    dfsIter(root->left, level+1, rets);
}

vector<double> AverageOfLevels::averageOfLevels(TreeNode *root) {
    vector<vector<double>*> levels;
    vector<double> result;
    dfsIter(root, 0, levels);
    for (auto level : levels) {
        int sum = 0;
        for (int n : *level) {
            sum += n;
        }
        result.push_back((double)sum / (double)level->size());
    }
    
    return result;
}



void AverageOfLevels::testAverageOfLevels() {
    using namespace std;
    int l[] = {3,9,20, -1,-1,15,7};
    TreeNode *root = buildTree(l, 7);
    averageOfLevels(root);
    cout << "hello" << endl;
}
