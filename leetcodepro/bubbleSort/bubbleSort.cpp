//
//  bubbleSort.cpp
//  leetcodepro
//
//  Created by drakeDan on 9/28/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "bubbleSort.h"
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < num.size() - 1; j++) {
            if (num[j] > num[j+1]) swap(num[j], num[j+1]);
        }
    }
}

void bubbleSortTest() {
    vector<int> num = {1,2,4,3,5};
    bubbleSort(num);
    for (auto i: num) {
        cout << i << " ";
    }
}
