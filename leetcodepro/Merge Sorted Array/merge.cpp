//
//  merge.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/9/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "merge.h"

void merge(int A[], int m, int B[], int n) {
    int aux[m+n];
    int i = 0, j = 0;
    for (int k = 0; k < m+n; k++) {
             if (i >= m) { aux[k] = B[j++]; }
        else if (j >= n) { aux[k] = A[i++]; }
        else if (A[i] < B[j]) {
            aux[k] = A[i++];
        } else {
            aux[k] = B[j++];
        }
    }
    
    for (int k = 0; k < m+n; k++) {
        A[k] = aux[k];
    }
}

void mergeTest() {
    int *A = (int *)malloc(sizeof(int) * 9);
    A[0] = 1;
    A[1] = 5;
    A[2] = 6;
    A[3] = 8;
    A[4] = 9;
    
    int B[] = {2,3,4,7};
    merge(A, 5, B, 4);
    for (int i = 0; i < 9; i++) {
        cout << A[i] << " ";
    }
}
