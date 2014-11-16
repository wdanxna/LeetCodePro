//
//  plusOne.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/13/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "plusOne.h"
#include <stack>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int t = 0;
    for (int i = 0; i < digits.size(); i++) {
        if (t > INT_MAX / 10) {
            t = INT_MAX - 1;
            break;
        }
        t = t * 10 + digits[i];
    }
    t += 1;

    vector<int> ret;
    stack<int> s;
    while (t) {
        s.push(t % 10);
        t /= 10;
    }
    
    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }
    
    return ret;
}

vector<int> plusOne2(vector<int> &digits) {
    int carry = 1;
    int ptr = (int)digits.size() - 1;
    vector<int> ret;
    if (ptr < 0) return ret;
    stack<int> s;
    for (int i = ptr; i >= 0; i--) {
        int val = digits[i] + carry;
        carry = val / 10;
        val = val % 10;
        s.push(val);
    }
    if (carry) {
        s.push(1);
    }
    
    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }
    
    return ret;
}

void plusOneTest() {
    vector<int> digits = {9,9,9};
    vector<int> result = plusOne2(digits);
    cout << " " << endl;
}
