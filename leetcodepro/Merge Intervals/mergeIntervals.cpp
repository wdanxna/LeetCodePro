//
//  mergeIntervals.cpp
//  leetcodepro
//
//  Created by drakeDan on 23/01/2018.
//  Copyright © 2018 bravo. All rights reserved.
//

#include "mergeIntervals.hpp"
#include <vector>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

vector<Interval> merge(vector<Interval>& intervals) {
    
}

void mergeIntervalTest() {
    vector<Interval> r1 = {Interval(0, 1), Interval(2, 4), Interval(3, 5)};
    merge(r1);
//    {Interval(0, 1), Interval(2, 5)};
}
