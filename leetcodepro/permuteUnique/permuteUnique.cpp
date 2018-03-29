//
//  permuteUnique.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/27/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "permuteUnique.h"
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void swap2(vector<int> &num, int i, int j) {
    int t = num[i];
    num[i] = num[j];
    num[j] = t;
}

void permuteIter2(vector<int> &num, int start, vector<vector<int>> &ret) {
    if (start >= num.size()) {
        ret.push_back(num);
    }
    
    unordered_set<int> set;
    for (int i = start; i < num.size(); i++) {
        if (i > start && set.find(num[i])!= set.end()) {
            continue;
        }
        set.insert(num[i]);
        swap2(num, start, i);
        permuteIter2(num, start + 1, ret);
        swap2(num, start, i);
    }
}

vector<vector<int>> permuteUnique(vector<int> &num) {
    vector<vector<int>> ret;
    sort(num.begin(), num.end());
    permuteIter2(num, 0, ret);
    return ret;
}

void permutationUniqueTest(){
    vector<int> num = {1,1,2};
    vector<vector<int>> ret = permuteUnique(num);
    cout << "" <<endl;
}
