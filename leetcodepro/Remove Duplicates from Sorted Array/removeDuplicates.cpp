//
//  removeDuplicates.cpp
//  leetcodepro
//
//  Created by drakeDan on 12/11/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "removeDuplicates.h"
#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
    if (n <= 0 ) return 0;
    int curdel = 0;
    int prev = A[0];
    int len = n;
    for (int i = 1; i < n; i++) {
        int cur = A[i];
        if (cur == prev) {
            len--;
            curdel++;
        }else {
            if (curdel > 0) {
                A[i-curdel] = A[i];
            }
        }
        prev = cur;
    }
    return len;
}

void removeDuplicatesTest() {
    int a[] = {1,1,2,3,3,4,5};
    int n = removeDuplicates(a, 7);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout <<endl;
    
}
