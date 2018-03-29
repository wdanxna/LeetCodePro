//
//  longestPalindrome.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/24/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "longestPalindrome.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string longestPalindrome(string s) {
    if (!s.size()) return "";
    int len = 0, max = 1;
    int left, right;
    int n = (int)s.size();
    int start = 0;
    
    for (int i = 0; i < n; i++) {
        //hadle odd
        left = i-1;
        right = i+1;
        while (left >=0 && right < n && s[left] == s[right]) {
            left--;
            right++;
            len++;
        }
        if (len * 2 + 1 > max) {
            max = len * 2 + 1;
            start = i - len;
        }
        len = 0;
        
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
            len++;
        }
        if (len * 2 > max) {
            max = len * 2;
            start = i - len + 1;
        }
        len = 0;
    }
    return s.substr(start, max);
}


string longestPalindrome2(string s) {
    string ret;
    if (s.empty()) return ret;
    
    int back, forth, start = 0, maxLen = 0;
    bool odd;
    for (int i = 0; i < s.length(); i++){
        // for odd
        back = i - 1;
        forth = i + 1;
        while (back >= 0 && forth < s.length() && s[back] == s[forth]) {
            back--;
            forth++;
        }
        if (forth - back - 1 > maxLen) {
            odd = true;
            start = back + 1;
            maxLen = forth - back - 1;
        }
        
        // for even
        back = i;
        forth = i + 1;
        while (back >= 0 && forth < s.length() && s[back] == s[forth]) {
            odd = false;
            back--;
            forth++;
        }
        if (forth - back - 1 > maxLen) {
            start = back + 1;
            maxLen = forth - back - 1;
        }
        
    }
    
    return s.substr(start, maxLen);
}


void longestPalindormTest() {
    string tt = "bb";
    string t = "abckeegffgeekfgh";
    string t2 = "yegeekfkeegs";
    string s = longestPalindrome2(t2);
    cout << s << endl;
}
