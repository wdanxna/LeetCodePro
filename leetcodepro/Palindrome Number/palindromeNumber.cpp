//
//  palindromeNumber.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/16/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "palindromeNumber.h"
#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    int t = x;
    int v = 0;
    while (t) {
        if (v / 10 > INT_MAX) return false;
        v = v * 10 + (t % 10);
        t /= 10;
    }
    
    if (v == x) return true;
    return false;
}

void palindromNumberTest() {
    cout << isPalindrome(-2147447412) << endl;
}
