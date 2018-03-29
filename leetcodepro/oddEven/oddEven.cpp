//
//  oddEven.cpp
//  leetcodepro
//
//  Created by drakeDan on 9/6/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "oddEven.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isOdd(int n) {
    return n == 2 || n == 3 || n % 2 != 0;
}

vector<int> oddEven(vector<int>& num) {
    if (num.size() <= 1) return num;
    int i = 0;
    int j = 0;
    int k = (unsigned)num.size() - 1;
    while (i < num.size() && isOdd(num[i])) i++;
    while (k > 0 && !isOdd(num[k])) k--;
    j = i + 1;
    while (i + 1 < k) {
        if (!isOdd(num[j])) {
            if (j == num.size() - 1) break;
            swap(num[i], num[j]);
            j++;
        } else {
            swap(num[i], num[j]);
            i++;
            j = i + 1;
        }
    }
    return num;
}




void oddEvenTest() {
//    vector<int> a = {1,2,1,2,1,2};
    vector<int> a = {1,3,5,4,6,7,8};
//    vector<int> a = {4,6,1,5,8,10};
    oddEven(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}