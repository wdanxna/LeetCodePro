//
//  strstr.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/19/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "strstr.h"
#include <iostream>
using namespace std;

int mystrstr(string haystack, string needle) {
    int hlen = (int)haystack.length();
    int nlen = (int)needle.length();
    if (hlen < nlen) {
        // nothing to be found
        return -1;
    }
    int i = 0, p = 0;
    while (p <= hlen - nlen) {
        while (i < nlen && haystack[p+i] == needle[i]) {
            i++;
        }
        if (i == nlen) {
            return p;
        }
        i = 0;
        p++;
    }
    return -1;
}


void strstrTest() {
    cout << mystrstr("", "") << endl;
}