//
//  regularExpressionMatch.cpp
//  leetcodepro
//
//  Created by drakeDan on 17/01/2018.
//  Copyright © 2018 bravo. All rights reserved.
//

#include "regularExpressionMatch.hpp"
#include <string>
#include <iostream>
using namespace std;

bool matchIter(string &s, int s_begin, int s_end, string &p, int p_begin, int p_end) {
    if (s_begin > s_end && p_begin > p_end) return true;
    if (s_begin < s_end && p_begin > p_end) return false;
    bool isHeadMatch = (s_begin <= s_end) && (s[s_begin] == p[p_begin] || p[p_begin] == '.');
    if (p_begin+1 <= p_end && p[p_begin+1] == '*') {
        bool result = matchIter(s, s_begin, s_end, p, p_begin+2, p_end);
        if (isHeadMatch) {
            return (
            result = result ||
            matchIter(s, s_begin+1, s_end, p, p_begin, p_end));
        }
        return result;
    } else {
        return isHeadMatch & matchIter(s, s_begin+1, s_end, p, p_begin+1, p_end);
    }
}

bool isMatch(string s, string p) {
    return matchIter(s, 0, s.length()-1, p, 0, p.length()-1);
}

void regularMatchingTest() {
    std::cout << isMatch("aaaab", "a*b") << std::endl;
}
