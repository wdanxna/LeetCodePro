//
//  isPalindrome.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/8/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "isPalindrome.h"
bool isAlphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isPalindrome(string s) {
    int i = 0 ,j = (int)s.length()-1;
    while (i <= j) {
        if (!isAlphanumeric(s[i])) {
            i++;
            continue;
        }
        if (!isAlphanumeric(s[j])) {
            j--;
            continue;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void isPalindromeTest() {
    string s = "1a2";
    cout << isPalindrome(s) << endl;
}
