//
//  wordLadder.cpp
//  leetcodepro
//
//  Created by drakeDan on 5/2/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "wordLadder.h"
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int ladder(string beginWord, string endWord, unordered_set<string>& wordDict) {
    int length = 0;
    
    if (beginWord == endWord) {
        return length;
    }
    
    for (int i = 0; i < beginWord.length(); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            string newWord = beginWord.replace(i, 1, string(1, c));
            
        }
    }
    
    return length;
}


int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    int length = 1;
    if (beginWord == endWord) {
        return length;
    }
    queue<string> q;
    queue<string> t;
    unordered_set<string> checked;
    q.push(beginWord);
    
    while (!q.empty()) {
        string topWord = q.front();
        q.pop();
        
        for (int i = 0; i < topWord.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string newWord = topWord;
                newWord.replace(i, 1, string(1, c));
                if (newWord == endWord) {
                    return length + 1;
                }
                if (checked.find(newWord) == checked.end() && wordDict.find(newWord) != wordDict.end()) {
                    t.push(newWord);
                    checked.insert(newWord);
                }
            }
        }
        
        if (q.empty()) {
            length++;
            swap(q, t);
        }
    }
    
    return 0;
}

void ladderLengthTest() {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    cout << ladderLength(beginWord, endWord, dict) << endl;
    
//    string b1 = "hot";
//    string e1 = "dog";
//    unordered_set<string> d1 = {"hot", "dog"};
//    cout << ladderLength(b1, e1, d1) << endl;
    
//    string b1 = "hot";
//    string e1 = "hot";
//    unordered_set<string> d1 = {"hot", "dog"};
//    cout << ladderLength(b1, e1, d1) << endl;
}
