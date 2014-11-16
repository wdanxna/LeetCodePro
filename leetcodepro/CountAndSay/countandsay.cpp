//
//  countandsay.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/25/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "countandsay.h"

void iter(string &s, int i, int n) {
    if (i > n) {
        return;
    }
    string t;
    int cnt = 1;
    char c = s[0];
    for (int i = 1; i <= s.size(); i++) {
        if (s[i] != c || i >= s.size()) {
            char cnt_char = cnt+'0';
            t += cnt_char;
            t += c;
            c = s[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    s = t;
    iter(s, i+1, n);
}

string countAndSay(int n) {
    string s = "1";
    iter(s,1,n-1);
    return s;
}

void countAndSayTest() {
    cout << countAndSay(5) << endl;
}