//
//  quickSort.cpp
//  leetcodepro
//
//  Created by drakeDan on 9/28/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "quickSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

int easyPartition(vector<int> &num, int left, int right) {
    if (left == right) return left;
    int i = left + 1;
    int j = right;
    
    while (i <= j) {
        if (num[i] > num[left]) {
            swap(num[i], num[j]);
            j--;
        } else {
            i++;
        }
    }
    swap(num[left], num[i - 1]);
    return i - 1;
}

void quickSortIter(vector<int> &num, int left, int right) {
    if (left >= right) return;
    int mid = easyPartition(num, left, right);
    quickSortIter(num, left, mid);
    quickSortIter(num, mid + 1, right);
}

void quickSort(vector<int> &num) {
    random_shuffle(num.begin(), num.end());
    quickSortIter(num, 0, (int)num.size() - 1);
}

void quickSortTest() {
    vector<int> num = {5,4,2,1,3};
    quickSort(num);
    for (auto i : num) {
        cout << i << " ";
    }
}