//
//  maximumGap.cpp
//  leetcodepro
//
//  Created by drakeDan on 6/5/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "maximumGap.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
using namespace std;

int partition_a(vector<int> &nums, int pivot) {
    int i = 1, j = i;
    swap(nums[0], nums[pivot]);
    for (i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[0]) {
            swap(nums[i], nums[j++]);
        }
    }
    swap(nums[0], nums[j-1]);
    return j-1;
}

int partition_b(vector<int> &nums, int pivot) {
    int i = 0, j = i;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] <= pivot) {
            swap(nums[i], nums[j++]);
        }
    }
    return j-1;
}

int gapIter(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;
    if (right - left == 1) {
        return abs(nums[right] - nums[left]);
    }
    // find maximum and minimum
    int max = INT_MIN, min = INT_MAX;
    for (int i = left; i <= right; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    if (max == min) {
        return 0;
    }
    int mid = (max + min) / 2;
    
    //partition by mid
    int pivot = partition_b(nums, mid);
    
    //[0, pivot] < mid, (pivot, n-1] > mid
    // find max on the left side, and min on the right side
    int leftmax = min, rightmin = max;
    for (int i = 0; i <= pivot; i++) {
        if (nums[i] > leftmax) {
            leftmax = nums[i];
        }
    }
    
    for (int i = pivot + 1; i <= right; i++) {
        if (nums[i] < rightmin) {
            rightmin = nums[i];
        }
    }
    
    int leftGap = gapIter(nums, 0, pivot);
    int rightGap = gapIter(nums, pivot+1, right);
    int crossGap = rightmin - leftmax;
    
    
    
    return leftGap > rightGap ? (leftGap > crossGap ? leftGap : crossGap) : (rightGap > crossGap ? rightGap : crossGap);
}

int maximumGap(vector<int>& nums) {
    int ret = gapIter(nums, 0, (int)nums.size()-1);
    cout << ret << endl;
    return ret;
}


void maximumGapTest() {
//    vector<int> nums = {1,4,2,5};
//    vector<int> nums = {1};
//    vector<int>nums = {1,1,1,1,1};
    vector<int> nums = {1,1,1,1,1,5,5,5,5,5};
    maximumGap(nums);
    
//    cout << partition_b(nums, 3) << endl;
//    for (int i : nums) {
//        cout << i << ",";
//    }
    
    
}

