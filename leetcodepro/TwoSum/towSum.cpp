//
//  towSum.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/25/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "towSum.h"

vector<int> twoSum_TLE(vector<int> &numbers, int target) {
    vector<int> ret;
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target) {
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
            }
        }
    }
    
    return ret;
    
}

int bfind(vector<int> &numbers, int left, int right, int target, int exclu) {
    if (left > right) return -1;
    int mid = (left + right)/2;
    if (target > numbers[mid]) {
        return bfind(numbers, mid + 1, right, target, exclu);
    }
    else if (target < numbers[mid]) {
        return bfind(numbers, left, mid - 1, target, exclu);
    }
    else {
        if (mid != exclu) {
            return numbers[mid];
        }
        return -1;
    }
}

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ret;
    vector<int> aux = numbers;
    sort(numbers.begin(), numbers.end()); // O(nlogn)
    for (int i = 0; i < aux.size(); i++) {
        int j = bfind(numbers,0, (int)numbers.size()-1, target-numbers[i], i);
        if (j >= 0) {
            for (int k = 0; k < aux.size(); k++) {
                if (aux[k] == numbers[i]) {
                    ret.push_back(k+1);
                }
                else if (aux[k] == j) {
                    ret.push_back(k+1);
                }
            }
            return ret;
        }
    }
    return ret;
}

void twoSumTest() {
    vector<int> num = {0,4,3,0};
    vector<int> indexs = twoSum(num, 0);
    cout << indexs[0] << "," << indexs[1] << endl;
}
