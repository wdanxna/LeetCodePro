//
//  getSum.cpp
//  leetcodepro
//
//  Created by drakeDan on 29/06/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#include "getSum.hpp"
#include <iostream>
using namespace std;

int getSum(int a, int b) {
    cout << a << " + " << b << " = ";
    int base = a | b;
    int carry = a & b;
//    cout << "base: " << base << " carry: " << carry << endl;
    while (carry > 0) {
        int mask = 1;
        while (mask != 0) {
            
            int tm = base & mask;
            int bb = tm ^ mask;
            base &= ~mask;
            base |= bb;
            mask = tm;
            mask = mask << 1;
        }
        --carry;
    }
    return base;
}

void getSumTest() {
    cout << getSum(15, 20) << endl;;
}
