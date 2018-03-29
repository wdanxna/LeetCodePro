//
//  IntegerReplacement.cpp
//  leetcodepro
//
//  Created by drakeDan on 27/06/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#include "IntegerReplacement.hpp"
#include <vector>
#include <iostream>

//https://leetcode.com/problems/integer-replacement/#/description
using namespace std;
void replaceIter(int &level, vector<vector<int> *> &all) {
    vector<int> *k = all.at(level % 2);
    if (k->size() == 0) {
        return;
    }
    
    while (k->size() != 0) {
        
        int n = k->back();
        if (n == 1) return;
        k->pop_back();
        bool even = (n % 2 == 0);
        bool pOverflow = false;
        bool mOverflow = false;
        
        int over2 = n / 2;
        int plus1 = n + 1;
        int minus1 = n - 1;
        
        if (n > 0 && plus1 < 0) pOverflow = true;
        if (n < 0 && minus1 >= 0) mOverflow = true;
        
        vector<int> *nk = all.at((level + 1) % 2);
        if (even) {
            if (over2 == 0) nk->push_back(1);
            else nk->push_back(over2);
        } else {
            if (!pOverflow) nk->push_back(plus1);
            if (!mOverflow) nk->push_back(minus1);
        }
    }
    
    level++;
    replaceIter(level, all);
}

int integerReplacement(int n) {
    int level = 0;
    vector<int> k = {n};
    vector<int> nk;
    vector<vector<int> *> all = {&k, &nk};
    replaceIter(level, all);
    return level;
}



void integerReplacementTest() {
    using namespace std;
    cout << integerReplacement(64) << endl;
}
