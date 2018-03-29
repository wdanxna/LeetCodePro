//
//  3Sum.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/30/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "ThreeSum.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &num) {
    vector<vector<int>> ret;
    if (!num.size()) return ret;
    sort(num.begin(), num.end());
    vector<int> t;
    int n = (int)num.size();
    for (int i = 0; i <= n - 3; i++) {
        if (i > 0 && num[i] == num[i-1]) continue;
        for (int j = i + 1; j <= n - 2; j++) {
            if (j > i + 1 && num[j] == num[j-1]) continue;
            int tar = - (num[i] + num[j]);
            if (num[j+1] > tar || num[n-1] < tar) continue;
            if (binary_search(num.begin()+j+1, num.end(), tar)) {
                t.push_back(num[i]);
                t.push_back(num[j]);
                t.push_back(tar);
                ret.push_back(t);
                t.clear();
            }
        }
    }
    return ret;
}

void ThreeSumTest() {
    vector<int> a = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> b = {0,0,0};
    vector<vector<int>> ret = threeSum(b);
    cout << "hi" << endl;
}
