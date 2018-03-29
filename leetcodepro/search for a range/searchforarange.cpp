//
//  searchforarange.cpp
//  leetcodepro
//
//  Created by drakeDan on 03/01/2018.
//  Copyright © 2018 bravo. All rights reserved.
//

#include "searchforarange.hpp"
#include <vector>
#include <iostream>
using std::vector;

int b_search(vector<int>&nums, int begin, int end, int target) {
    if (begin > end) return -1;
    int mid_id = (begin + end) / 2;
    int mid = nums[mid_id];
    if (mid == target) {
        return mid_id;
    }
    else if (mid > target) {
        return b_search(nums, begin, mid_id-1, target);
    }
    else /*if (mid < target)*/ {
        return b_search(nums, mid_id+1, end, target);
    }
}

int searchIter(vector<int>&nums, int begin, int end, int target, bool isleft) {
    if (begin > end) return -1;
    int pos = b_search(nums, begin, end, target);
    if (pos == -1) {
        return -1;
    }
    
    int left = searchIter(nums, begin, pos-1, target, isleft);
    int right = searchIter(nums, pos+1, end, target, isleft);
    if (left == -1) left = pos;
    if (right == -1) right = pos;
    
    if (isleft) {
        return left;
    } else {
        return right;
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range{-1, -1};
    int pos = b_search(nums, 0, (int)nums.size()-1, target);
    if (pos == -1) {
        return range;
    }
    
    int left = searchIter(nums, 0, pos-1, target, true);
    int right = searchIter(nums, pos+1, (int)nums.size()-1, target, false);
    if (left == -1) left = pos;
    if (right == -1) right = pos;
    range[0] = left;
    range[1] = right;
    return range;
}

void search_for_a_range_test() {
    vector<int> r{1,2,3,3,4};
    auto range = searchRange(r, 2);
    std::cout << "hello";
}
