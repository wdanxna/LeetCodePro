//
//  minDistance.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/26/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "minDistance.h"
#include <iostream>
using namespace std;


//doesn't work out
int minDistance(string word1, string word2) {
    if (word1.length() < word2.length()) {
        return minDistance(word2, word1);
    }
    
    //word1 > word2
    int min = (int)word1.length();
    for (int i = 0; i < word1.length(); i++) {
        int k = i, j = 0, step = 0;
        step += k - j;
        while (k < word1.length() && j < word2.length()) {
            if (word1[k] != word2[j]) {
                step++;
            }
            k++;
            j++;
        }
        step += word1.length() - k;
        step += word2.length() - j;
        min = step < min ? step : min;
    }
    return min;
}

int min3(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
int minDistance2(string word1, string word2) {
    int dp[word1.length()+1][word2.length()+1];
    for (int i = 0; i < word1.length()+1; i++) {
        dp[i][0] = i;
    }
    
    for (int i = 0; i < word2.length()+1; i++) {
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= word1.length(); i++) {
        for (int j = 1; j <= word2.length(); j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min3(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[word1.length()][word2.length()];
}

void minDistanceTest() {
//    cout << minDistance2("abcd", "efg") << endl;
//    cout << minDistance2("acdef", "abcd") << endl;
//    cout << minDistance2("abcd", "bcd") << endl;
//    cout << minDistance2("abcd", "a") << endl;
//    cout << minDistance2("", "") << endl;
//    cout << minDistance2("sea","eat") << endl;
//    cout << minDistance2("horse","ros") << endl;
//    cout << minDistance2("aebc", "abc") << endl;
    cout << minDistance2("a", "b");
}
