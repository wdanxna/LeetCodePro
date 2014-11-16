//
//  longestConsecutive.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/24/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "longestConsecutive.h"

int longestConsecutive_kidding(vector<int> &num) {
    int max = 0;
    for (int i=0; i<num.size(); i++) {
        if (max < num[i]) max = num[i];
    }
    vector<int> pos(max);
    
    for (int i = 0; i < max; i++) {
        pos[i] = 0;
    }
    
    for (int i = 0; i < num.size(); i++) {
        pos[num[i]] = 1;
    }
    
    int j = 0, l = 0;
    for (int i = 0; i < max; i++) {
        if (pos[i] == 1) {
            j++;
            if (j > l) l = j;
        }
        else {
            j = 0;
        }
    }
    
    return l;
}

int consecutive(unordered_set<int>& set, int value, bool asc) {
    int cnt = 0;
    while (set.find(value) != set.end()) {
        cnt++;
        set.erase(value);
        if (asc) {
            value++;
        }else {
            value--;
        }
    }
    return cnt;
}

int longestConsecutive(vector<int> &num) {
    int max = 0;
    unordered_set<int> set;
    for (int n: num) {
        set.insert(n);
    }
    for (int i = 0; i < num.size(); i++) {
        int value = num[i];
        int seq = consecutive(set, value, true) + consecutive(set, value-1, false);
        if (seq > max) max = seq;
    }
    return max;
}


void longestConsecutiveTest() {
    vector<int> num = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(num) << endl;
}
