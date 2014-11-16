//
//  searchInsert.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/26/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "searchInsert.h"

int findPos(int A[], int left, int right, int target) {
    if (left > right) return left;
    int mid = (left + right) /2;
    if (target > A[mid]) {
        return findPos(A, mid+1, right, target);
    }
    else if (target < A[mid]) {
        return findPos(A, left, mid-1, target);
    }
    else {
        return mid;
    }
}

int searchInsert(int A[], int n, int target) {
    if (n == 0) return 0;
    return findPos(A, 0, n-1, target);
}

void searchInsertTest() {
    int a[] = {1,3,5,6};
    cout << searchInsert(a, 4, 7) << endl;
}