//
//  removeElement.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/16/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "removeElement.h"
#include <iostream>
#include <vector>
using namespace std;

int removeElement(int A[], int n, int elem) {
    int ex = -1;
    int len = n;
    for (int i = 0; i < n; i++) {
        if (A[i] == elem) {
            len--;
            if (ex < 0)
                ex = i;
        }
        else if (ex >= 0) {
            A[ex] = A[i];
            ex++;
        }
    }
    return len;
}

int removeElement2(int A[], int n, int elem) {
    int len = n;
    int aux[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == elem) {
            len--;
        }
        else {
            aux[k++] = A[i];
        }
    }
    
    for (int i = 0; i < len; i++) {
        A[i] = aux[i];
    }
    return len;
}

int removeElement3(int A[], int n, int elem) {
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == elem) {
            l++;
        }
        else if (l > 0){
            A[i-l] = A[i];
        }
    }
    return n-l;
}

void removeElementTest() {
    int a[] = {3,1,2,3,4,5};
    cout << removeElement3(a,6,3) << endl;
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
