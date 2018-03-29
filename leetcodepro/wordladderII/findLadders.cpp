//
//  findLadders.cpp
//  leetcodepro
//
//  Created by drakeDan on 5/3/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "findLadders.h"
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string>> ladders;
    
    queue<vector<string>> q, t;
    unordered_set<string> set;
    vector<string> route;
    bool found = false;
    
    q.push(vector<string>(1,start));
    
    while (!q.empty()) {
        vector<string> top = q.front();
        q.pop();
        
        string topWord = top[top.size()-1];
        for (int i = 0; i < top[top.size()-1].length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string newWord = topWord;
                newWord.replace(i, 1, string(1, c));
                
                if (newWord == end) {
                    vector<string> n = top;
                    n.push_back(newWord);
                    ladders.push_back(n);
                    found = true;
                    break;
                }
                
                if (newWord != topWord && dict.find(newWord) != dict.end()) {
                    vector<string> p = top;
                    p.push_back(newWord);
                    t.push(p);
                    set.insert(newWord);
                }
            }
        }
        
        if (q.empty()) {
            if (found) {
                break;
            }
            swap(t, q);
        }
    }
    
    return ladders;
}


void help(string start, string end, unordered_set<string>& d, unordered_set<string> have, vector<string> now, int len, int* min, vector<vector<string>>& ret) {
    if (start == end) {
        if (len + 1 <= *min) {
            ret.push_back(now);
            *min = len + 1;
        }
        return;
    }
    
    for (int i = 0; i < start.length(); ++i) {
        string newWord = start;
        for (char c = 'a'; c <= 'z'; ++c) {
            swap(newWord[i], c);
            if (d.find(newWord) != d.end() && have.find(newWord) == have.end()) {
                now.push_back(newWord);
                have.insert(newWord);
                help(newWord, end, d, have, now, len + 1, min, ret);
            }
        }
    }
}

vector<vector<string>> findLadders2(string start, string end, unordered_set<string> &dict) {
    vector<vector<string>> ret;
    int minLen = 1000000;
    unordered_set<string> have = {start};
    help(start, end, dict, have, vector<string>(1, start), 1, &minLen,  ret);
    return ret;
}


void findLaddersTest() {
//    string start = "hit";
//    string end = "cog";
//    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    
    string start = "red";
    string end = "tax";
    unordered_set<string> dict = {"ted","tex","red","tax","tad","den","rex","pee"};
    
//    string start = "hot";
//    string end = "dog";
//    unordered_set<string> dict = {"hot", "dog"};

    
    findLadders2(start, end, dict);
}