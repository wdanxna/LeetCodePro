//
//  climbstairs.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/26/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "climbstairs.h"


int climbstairs_TLE(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbstairs_TLE(n-1) + climbstairs_TLE(n-2);
}

void iter(int acc, int n, vector<int> &table) {
    if (acc < 0) return;
    if (acc == n+1) return;
    int a = acc-1 < 0? 0 : acc-1;
    int b = acc-2 <0? 0 : acc-2;
    table.push_back(table[a] + table[b]);
    iter(acc+1, n, table);
}

int climbStairs(int n) {
    vector<int> table;
    table.push_back(0);
    table.push_back(1);
    table.push_back(2);
    if (n < 3) return table[n];
    iter(3, n,table);
    return table[n];
}

void climbstairsTest() {
    cout << climbStairs(5) << endl;
}
