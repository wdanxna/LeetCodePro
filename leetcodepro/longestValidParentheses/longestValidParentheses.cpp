//
//  longestValidParentheses.cpp
//  leetcodepro
//
//  Created by drakeDan on 4/24/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "longestValidParentheses.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    int max = 0;
    stack<int> st;
    int mark[s.size()];
    for (int i=0; i<s.size(); i++) {
        mark[i] = 0;
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if (st.size() > 0) {
            for (int j=st.top(); j<= i; j++) {
                mark[j] = 1;
            }
            st.pop();
        }
    }
    
    int j = 0;
    for (int i=0; i<s.size(); i++) {
        if (mark[i] == 1) {
            j++;
            if (j > max) max = j;
        }
        else {
            j = 0;
        }
    }
    
    return max;
}

int longestValidParentheses2(string s) {
    stack<int> st;
    int result = 0;
    int last = -1;
    for (int i = 0; i < s.length(); i++) {
        char t = s[i];
        if(t == '('){
            st.push(i);
        }
        else if (t == ')') {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    result = max(result, i - last);
                } else {
                    result = max(result, i - st.top());
                }
            } else {
                last = i;
            }
        }
    }
    return result;
}

int longestValidParentheses3(string s) {
    return 0;
}

void longestValidParenthesesTest() {
    string a = ")()())";//4
    string b = "()((()";//2
    string c = "(()())";//6
    string d = "()(())";//6
    string e = "(()";//2
    cout << longestValidParentheses2(e) << endl;
}


