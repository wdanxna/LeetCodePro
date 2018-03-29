//
//  JudgeSquareSum.cpp
//  leetcodepro
//
//  Created by drakeDan on 20/07/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#include "JudgeSquareSum.hpp"
#include <iostream>

bool JudgeSquareSum::judgeSquareSum(int c) {
    int d = c / 2;
    for (int a = 0; a*a <= d && a*a >= 0; a++) {
        int bs = c - a*a;
        for (int b = 0; b*b <= bs && b*b >= 0; b++) {
            if (a*a + b*b == c) return true;
        }
    }
    return false;
}


long bsIter(long s, long e, long target) {
    if (s > e) {
        return -1;
    }
    long mid = (s + e)/2;
    long mids = mid * mid;
    if (mids == target) return mid;
    if (mids > target) return bsIter(s, mid - 1, target);
                       return bsIter(mid + 1, e, target);
}

bool JudgeSquareSum::judgeSquareSum2(int c) {
    for (long a = 0; a*a <= c; a++) {
        long bs = c - (a*a);
        //determin if bs is a perfect square
        long b = bsIter(0, bs, bs);
        if (b != -1) return true;
    }
    return false;
}

void JudgeSquareSum::testJudgeSquareSum() {
    using namespace std;
//    cout << judgeSquareSum2(2147482647) << endl;
    cout << judgeSquareSum2(0) << endl;
//    cout << judgeSquareSum2(5) << endl;
}
