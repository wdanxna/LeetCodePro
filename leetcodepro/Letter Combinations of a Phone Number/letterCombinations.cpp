//
//  letterCombinations.cpp
//  leetcodepro
//
//  Created by drakeDan on 12/6/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "letterCombinations.h"
#include <iostream>
#include <vector>
using namespace std;

void comboIter(string digits, int i, vector<string> &domains, string cur, vector<string> &result) {
    if (i >= digits.size()) {
        result.push_back(cur);
        return;
    }
    char t = digits.at(i);
    string domain = domains[t-'0'];
    string old = cur;
    for (char ele : domain) {
        cur += ele;
        comboIter(digits, i+1, domains, cur ,result);
        cur = old;
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (!digits.size()) return {""};
    vector<string> domain = {"0","1","abc","def","ghi","jkl","mno","pqr","stu","vwxyz"};
    comboIter(digits,0,domain,"",ret);
    return ret;
}

void letterCombinationsTest() {
    vector<string> ret = letterCombinations("");
    cout << "haha" << endl;
}
