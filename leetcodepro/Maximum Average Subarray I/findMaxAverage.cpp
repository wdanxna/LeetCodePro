//
//  findMaxAverage.cpp
//  leetcodepro
//
//  Created by drakeDan on 20/07/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#include "findMaxAverage.hpp"
#include <iostream>

double FindMaxAverage::findMaxAverage(vector<int> &nums, int k) {
    int start;
    start = 0;
    double maxAvg = -9999.;
    while (start + k - 1 < nums.size()) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums.at(start + i);
        }
        double avg = sum / k;
        if (avg > maxAvg) maxAvg = avg;
        
        start++;
    }
    return maxAvg;
}
double FindMaxAverage::findMaxAverage2(vector<int>& nums, int k) {
    vector<int> cache{0};
    int acc = 0;
    for (int i = 0; i < nums.size(); i++) {
        acc += nums[i];
        cache.push_back(acc);
    }
    
    int start = 0;
    int maxSum = INT_MIN;
    while (start + k - 1 < nums.size()) {
        int sum = cache.at(start + k) - cache.at(start);
        if (sum > maxSum) maxSum = sum;
        start++;
    }
    return ((double)maxSum / (double)k);
}

void FindMaxAverage::testFindMaxAverage() {
    using namespace std;
    vector<int> nums{1,12,-5,-6,50,3};
    cout << findMaxAverage2(nums, 4) << endl;
}


