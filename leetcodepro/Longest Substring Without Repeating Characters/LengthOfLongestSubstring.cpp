//
//  LengthOfLongestSubstring.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/19/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "LengthOfLongestSubstring.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (!s.size()) return 0;
    int len = 0;
    int max = 0;
    unordered_map<char, int>set;
    
    for (int i = 0; i < s.size(); i++) {
        if (s.size()-i-1 < max) break;
        for (int j = i; j < s.size(); j++) {
            if (set.find(s[j]) == set.end()) {
                len++;
                set[s[j]] = j;
            }
            else {
                i = set[s[j]];
                break;
            }
        }
        if (len > max) {
            max = len;
        }
        set.clear();
        len = 0;
    }
    
    return max;
}

int lengthOfLongestSubstring2(string s) {
    int pt = 0;
    int len = 0;
    int max = 0;
    unordered_map<char, int> map;
    while (pt < s.size()) {
        if (map.find(s[pt]) == map.end()) {
            len++;
            map[s[pt]] = pt;
        }
        else {
            if (len > max) { max = len; }
            len = pt - map[s[pt]];
            map.clear();
            for (int k = map[s[pt]]+1; k <= pt; k++) {
                map[s[k]] = k;
            }
        }
        pt++;
    }
    
    if (len > max) return len;
    return max;
}

int lengthOfLongestSubstring3(string s) {
    int n = (int)s.size();
    if (!n) return 0;
    int len = 1;
    int max = 1;
    int visited[256] = {-1};
    visited[s[0]] = 0;
    
    for (int i = 1; i < n; i++) {
        if (visited[s[i]] == -1 || i - len > visited[s[i]]) {
            len++;
        }
        else {
            if (len > max) { max = len; }
            len = i - visited[s[i]];
        }
        visited[s[i]] = i;
    }
    
    return len > max ? len : max;
}

int lengthOfLongestSubstring4(string s) {
    int n = (int)s.size();
    if (!n) return 0;
    int len = 0, max = 0;
    unordered_map<char, int> map;
    
    for (int i = 0; i < n; i++) {
        if (map.find(s[i]) == map.end() || map[s[i]] < i - len) {
            len++;
        }
        else {
            if (len > max) { max = len; }
            len = i - map[s[i]];
        }
        map[s[i]] = i;
    }
    return len > max ? len : max;
}

void lengthOfLongestSubstringTest() {
    string t = "GEEKSFORGEEKS";
    cout << lengthOfLongestSubstring4(t) << endl;
}