//
//  pascal.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/9/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "pascal.h"

void pascalIter(int i, int n, vector<vector<int>> &ret) {
    if (i > n) return;
    vector<int>r;
    r.push_back(1);
    vector<int> t = ret[i-2];
    for (int k = 0; k < i-2; k++) {
        r.push_back(t[k] + t[k+1]);
    }
    r.push_back(1);
    ret.push_back(r);
    pascalIter(i+1, n, ret);
}

vector<vector<int> > generate(int numRows) {
    vector<vector<int>> ret;
    if (numRows < 1) return ret;
    
    ret.push_back({1});
    if (numRows == 1) return ret;
    
    pascalIter(2, numRows, ret);
    return ret;
}

void pascaleTest() {
    vector<vector<int>> ha = generate(5);
    cout << "haha" << endl;
}