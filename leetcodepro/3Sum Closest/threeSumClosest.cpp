//
//  threeSumClosest.cpp
//  leetcodepro
//
//  Created by drakeDan on 12/1/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "threeSumClosest.h"
#include <iostream>
#include <vector>
using namespace std;

int closestSearch(vector<int> &num, int left, int right, int target) {
    if (left == right) {
        return num[left];
    }
    int mid = (left + right) / 2;
    if (num[mid] == target) return num[mid];
    if (num[mid] > target) {
        if (mid - 1 < left) {
            return num[left];
        }
        return closestSearch(num, left, mid - 1, target);
    }
    else {
        if (mid + 1 > right) {
            return num[right];
        }
        return closestSearch(num, mid + 1, right, target);
    }
}

int threeSumClosest(vector<int> &num, int target) {
    if (!num.size()) return 0;
    sort(num.begin(), num.end());
    int ret = num[0]+num[1]+num[2];
    int min = abs(num[0]+num[1]+num[2] - target);
    int n = (int)num.size();
    for (int i = 0; i <= n-3; i++) {
        if (i > 0 && num[i] == num[i-1]) { continue; }
        for (int j = i+1; j <= n-2; j++) {
            if (j > i+1 && num[j] == num[j-1]) { continue; }
            int tar = target - num[i] - num[j];
            int c = closestSearch(num, j+1, n-1, tar);
            tar = target - num[i] - num[j] - c;
            if (abs(tar) < min) {
                min = abs(tar);
                ret = num[i] + num[j] + c;
//                cout << num[i] << "," << num[j] << "," << c << endl;
            }
        }
    }
    return ret;
}

void threeSumClosestTest() {
    vector<int> s = {1,2,4,8,16,32,64,128};
    cout << threeSumClosest(s, 82) << endl;
}
