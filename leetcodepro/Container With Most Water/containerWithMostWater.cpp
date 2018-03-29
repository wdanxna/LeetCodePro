//
//  containerWithMostWater.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/26/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "containerWithMostWater.h"
#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int> &height) {
    int max = 0;
    int n = (int)height.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int min = height[i] > height[j] ? height[j] : height[i];
            int area = (j - i) * min;
            if (area > max) {
                max = area;
            }
        }
    }
    return max;
}

int maxArea2(vector<int> &height) {
    int n = (int)height.size();
    int max = 0, curr = 0;
    int left = 0, right = n - 1;
    
    while (left < right) {
        int h = height[left] > height[right] ? height[right] : height[left];
        int w = right - left;
        curr = w * h;
        if (curr > max) {
            max = curr;
        }
        
        if (height[left] > height[right]) {
            right--;
        }
        else {
            left ++;
        }
    }
    
    return max;
}

void containerWithMostWaterTest() {
    vector<int> t = {2,3,5,1};
    int area = maxArea2(t);
    cout << area << endl;
}
