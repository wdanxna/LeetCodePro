//
//  addDigits.cpp
//  leetcodepro
//
//  Created by drakeDan on 27/06/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#include <iostream>
#include "addDigits.hpp"

int addDigits(int num) {
    int t = num;
    while (t >= 10) {
        int tt = t;
        int perDigitSum = 0;
        while (tt > 0) {
            int d = tt % 10;
            perDigitSum += d;
            tt /= 10;
        }
        t = perDigitSum;
    }
    
    return t;
}

int addDigits2(int num) {
    if (num == 0) return 0;
    return num % 9 == 0 ? 9 : num % 9;
}


void addDigitsTest() {
    using namespace std;
//    cout << "10: "<< addDigits(10) << endl;
//    cout << "123: "<< addDigits(123) << endl;
//    cout << "456: " << addDigits(456) << endl;
//    cout << "789: " << addDigits(789) << endl;
    int n = 100;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << addDigits(i) << " vs " << addDigits2(i) << endl;
    }
}
