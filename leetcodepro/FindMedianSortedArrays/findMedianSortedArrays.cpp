//
//  findMedianSortedArrays.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/22/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "findMedianSortedArrays.h"
#include <iostream>
#include <vector>
using namespace std;

double findKth(vector<int> &nums1, vector<int> &nums2, int k) {
    int lena = (int)nums1.size();
    int lenb = (int)nums2.size();
    int i = 0, j = 0, n = 0;
    while (i < lena && j < lenb) {
        if (nums1[i] < nums2[j]) {
            if (n == k) {
                return nums1[i];
            }
            i++;
        } else if (nums1[i] > nums2[j]) {
            if (n == k){
                return nums2[j];
            }
            j++;
        }
        n++;
    }
    return i >= lena ? nums2[j + k-n] : nums1[i + k-n];
}

double findKth2(vector<int> &num1, vector<int> &num2, int k){
    int lena = (int)num1.size();
    int lenb = (int)num2.size();
    
    if (lena > lenb) {
        return findKth2(num2, num1, k);
    }
    if (lena == 0) {
        return num2[max(0,k-1)];
    }
    if (lenb == 0) {
        return num1[max(0,k-1)];
    }
    if (k <= 1){
        return min(num1[0], num2[0]);
    }
    
    int pa = min(lena, k/2);
    int pb = k - pa;
    
    if (num1[pa-1] < num2[pb-1]) {
        vector<int> v(num1.begin() + pa, num1.end());
        return findKth2(v, num2, k - pa);
    } else {
        vector<int> v(num2.begin() + pb, num2.end());
        return findKth2(num1, v, k - pb);
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = (int)(nums1.size() + nums2.size());
    return (len & 1) == 1 ? findKth2(nums1, nums2, len/2+1):
    (findKth2(nums1, nums2, len/2) + findKth2(nums1, nums2, len/2+1)) * 0.5;
    
}

void findMedianOfTwoSortedArraysTest() {
    vector<int> a = {};
    vector<int> b = {1,2,3,4,5};
    cout << findMedianSortedArrays(a, b) << endl;
}
