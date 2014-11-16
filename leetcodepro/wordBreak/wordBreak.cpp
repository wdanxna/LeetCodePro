//
//  wordBreak.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/2/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "wordBreak.h"

bool wbIter(string s, int left, int right, unordered_set<string> &dict) {
    if (left > right) return true;
    for (string ele:dict) {
        string t = s.substr(left, ele.size());
        if (t.compare(ele) == 0) {
            if (wbIter(s, (int)(left+ele.size()), right, dict)) return true;
        }
    }
    
    return false;
}


bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.size() == 0) return false;
    return wbIter(s, 0, (int)s.size()-1, dict);
}

void wordBreakTest() {
    string s = "";
    unordered_set<string> dict = {"leet", "code"};
    cout << wordBreak(s, dict) << endl;
}
