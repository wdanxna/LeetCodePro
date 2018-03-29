//
//  maxSubArray.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/25/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "maxSubArray.h"
#include <iostream>
#include <vector>
using namespace std;

int help(vector<int> &nums, int left, int right) {
    int max = nums[left];
    if (nums.empty()) {
        return -1;
    }
    if (left >= right) {
        return nums[left];
    }
    
    // ==left < right
    int mid = (left + right) / 2;
    int leftMax = help(nums, left, mid);
    max = leftMax > max ? leftMax : max;
    int rightMax = help(nums, mid+1, right);
    max = rightMax > max ? rightMax : max;
    
    int sum = 0, j = mid, k = mid+1;
    int max_tail = nums[j];
    while (j >= left) {
        sum += nums[j--];
        max_tail = sum > max_tail ? sum : max_tail;
    }
    sum = 0;
    int max_head = nums[k];
    while (k <= right) {
        sum += nums[k++];
        max_head = sum > max_head ? sum : max_head;
    }
    
    sum = max_head + max_tail;
    return max > sum ? max : sum;
}

int maxSubArray(vector<int> &nums) {
    return help(nums, 0, (int)nums.size()-1);
}


void maxSubArrayTest() {
    vector<int> num1 = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> num2 = {-1,-1,-1,-1,-1};
    vector<int> num3 = {-1};
    vector<int> num4 = {8,-19,5,-4,20};
    cout << maxSubArray(num4) << endl;
}
