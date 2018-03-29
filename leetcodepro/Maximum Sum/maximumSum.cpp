//
//  maximunSum.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/13/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "maximumSum.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//[−2,1,−3,4,−1,2,1,−5,4]
//[4,−1,2,1] = 6
int maxSubArray_brute(int A[], int n) {
    int max = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum += A[j];
            max = std::max(sum, max);
        }
        sum = 0;
    }
    return max;
}

void maximumSumTest() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray_brute(a, 9) << endl;
}
