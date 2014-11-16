//
//  pascale2.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/9/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "pascale2.h"

void getRowIter(int index, int n, vector<int> &aux) {
    if (index > n) return;
    vector<int> t;
    
    t.push_back(1);
    for (int k = 0; k < index-1; k++) {
        t.push_back(aux[k]+aux[k+1]);
    }
    t.push_back(1);
    aux = t;
    getRowIter(index+1, n, aux);
}


vector<int> getRow(int rowIndex) {
    vector<int> aux;
    if (rowIndex < 0) return aux;
    aux = {1};
    if (rowIndex == 0) return aux;
    getRowIter(1,rowIndex, aux);
    return aux;
}

void pascale2Test() {
    vector<int> ret = getRow(3);
    cout << "hi" << endl;
}