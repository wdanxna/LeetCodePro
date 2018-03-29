//
//  HappyNumber.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/9/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "HappyNumber.h"
#include <unordered_set>
#include <iostream>
using namespace std;

bool isHappy(int n) {
    if (n < 0) return false;
    unordered_set<int> loop;
    while (true) {
        if (n == 1) return true;
        int t = n;
        int round = 0;
        while (t > 0) {
            int p = t % 10;
            round += p * p;
            t /= 10;
        }
        
        if (loop.find(round) != loop.end()) return false;
        else loop.insert(round);
        n = round;
    }
    return true;
}

void HappyNumberTest() {
    cout << isHappy(13) << endl;
}
