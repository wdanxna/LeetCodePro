//
//  reverseWords.cpp
//  leetcodepro
//
//  Created by drakeDan on 9/6/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class ReverseWords_Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        string t;
        int j = 0;
        
        for (int i = 0; i < s.length(); i++) {
            //if (s[i] == ' '){}
            cout << s[i];
        }
        cout << endl;
    }
    
    static int main() {
        cout << "haha";
        return 0;
    }
};