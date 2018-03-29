//
//  permute.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/26/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "permute.h"
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void permuteIter(vector<int> tmp, vector<int> &num, int start, vector<vector<int>> &ret) {
    if (start >= num.size()) {
        ret.push_back(tmp);
        return;
    }
    
    for (int i = start; i < num.size(); i++) {
        swap(num, start, i);
        tmp.push_back(num[start]);
        permuteIter(tmp, num, start+1, ret);
        swap(num, start, i);
        tmp.pop_back();
    }

}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> ret;
    vector<int> tmp;
    permuteIter(tmp, num, 0, ret);
    return ret;
}

void permuteTest() {
    vector<int> num = {1,2,3};
    vector<vector<int>> r = permute(num);
    cout << "haha";
}
