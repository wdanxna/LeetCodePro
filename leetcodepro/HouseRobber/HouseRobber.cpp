//
//  HouseRobber.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/1/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "HouseRobber.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int robIter(vector<int> &num, int head) {
    if (head == num.size() - 1) {
        return num[head];
    }
    if (head > num.size() - 1) {
        return 0;
    }
    
    int maxSum = num[head];
    for (int i = head + 2; i < num.size(); i++) {
        maxSum = max(robIter(num, i) + num[head], maxSum);
    }
    return maxSum;
}

int rob(vector<int> &num) {
    if (num.empty()) return 0;
    int maxSum = 0;
    for (int i = 0; i < num.size(); i++) {
        maxSum = max(maxSum, robIter(num, i));
    }
    return maxSum;
}


int rob2(vector<int> &num) {
    if (num.empty()) return 0;
    int prev = 1;
    vector<int> f(num.size()+1, 0);
    f[1] = num[0];
    
    for (int i = 2; i < num.size() + 1; i++) {
        
        // if the previous one was choosen
        if (i - prev  == 1) {
            if (f[prev - 1] + num[i-1] > f[prev]) {
                f[i] = f[prev - 1] + num[i - 1];
                prev = i;
            } else {
                f[i] = f[prev];
            }
        } else {
            f[i] = f[i - 1] + num[i - 1];
            prev = i;
        }
    }
    
    return f[num.size()];
}

void houseRobberTest() {
    //2,1,1,2
    //2,3,2
    //1,2,1,2,1
    vector<int> a = {2,3,2};//4
    vector<int> b = {2,1,1,2};//4
    vector<int> c = {1,2,1,2,1};//4
    vector<int> d = {1};//1
    vector<int> e = {1,2};//2
    vector<int> f = {2, 1};//2
    vector<int> g = {6,3,10,8,2,10,3,5,10,5,3};//39
    vector<int> h = {};
    cout << rob2(h) << endl;
}

