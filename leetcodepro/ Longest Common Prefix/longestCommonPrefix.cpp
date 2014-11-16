//
//  longestCommonPrefix.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/24/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "longestCommonPrefix.h"

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return string();
    if (strs.size() == 1) return strs[0];
    char *ptrs[strs.size()];
    for (int i = 0; i < strs.size(); i++) {
        ptrs[i] = &(strs[i][0]);
    }
    
    bool failed = false;
    int bias = 0;
    int i;
    string res;
    while (!failed){
        for (i = 1; i < strs.size(); i++) {
            if ((bias >= strs[i].size() || bias >= strs[i-1].size()) || *(ptrs[i]+bias) != *(ptrs[i-1]+bias)){
                failed = true;
                break;
            }
        }
        if (!failed){
            res += strs[0][bias];
            bias++;
        }
    }
    
    return res;
}

void longestCommonPrefixTest() {
    vector<string> strs = {"",""};
    string prefix = longestCommonPrefix(strs);
    cout << prefix << endl;
}
