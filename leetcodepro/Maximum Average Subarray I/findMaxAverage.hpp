//
//  findMaxAverage.hpp
//  leetcodepro
//
//  Created by drakeDan on 20/07/2017.
//  Copyright © 2017 bravo. All rights reserved.
//

#ifndef findMaxAverage_hpp
#define findMaxAverage_hpp

#include <stdio.h>
#include <vector>
using std::vector;

class FindMaxAverage {
    public:
    double findMaxAverage(vector<int>& nums, int k);
    double findMaxAverage2(vector<int>& nums, int k);
    void testFindMaxAverage();
};


#endif /* findMaxAverage_hpp */
