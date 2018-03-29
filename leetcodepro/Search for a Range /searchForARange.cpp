//
//  searchForARange.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/30/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "searchForARange.h"
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int binarySearch(int num[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (num[mid] == target) return mid;
    if (num[mid] > target) {
        return binarySearch(num, left, mid - 1, target);
    }
    else {
        return binarySearch(num, mid + 1, right, target);
    }
}

vector<int> searchRange(int A[], int n, int target) {
    vector<int> ret = {-1, -1};
    if (n <= 0) return ret;
    
    int start, end;
    int hit = binarySearch(A, 0, n-1, target);
    if (hit < 0) return ret;
    start = hit - 1;
    end = hit + 1;
    while (start >= 0 && A[start] == target) { start--; }
    while (end < n && A[end] == target) { end++; }
    ret = {start + 1, end - 1};
    return ret;
}

void searchForARangeTest() {
    int a[] = {0,0,2,3,4,4,4,5};
    vector<int> ret = searchRange(a, 8, 5);
    cout << "haha" << endl;
}