//
//  validParentheses.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/15/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "validParentheses.h"
#include <stack>
#include <map>
#include <assert.h>
using namespace std;

static map<char, char> conterpart;

bool isValid(string s) {
    conterpart['('] = ')';
    conterpart['['] = ']';
    conterpart['{'] = '}';
    
    if (s.empty()) return true;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}'){
            if (st.empty()) return false;
            if ( conterpart[st.top()] != c) {
                return false;
            }
            else {
                st.pop();
            }
        }
    }
    
    if (st.empty()) {
        return true;
    }
    return false;
}

void validParenthesesTest() {
    vector<string> tests = {"","()","()[]{}","(]","([)]","((((((()","((([[{[]}]])))","]"};
    vector<bool> result = {true,true,true,false,false,false,true};
    assert(tests.size() == result.size());
    
    bool ok = true;
    for (int i = 0; i < tests.size(); i++) {
        if (isValid(tests[i]) != result[i]) {
            ok = !ok;
            cout << "failed: " << tests[i] << endl;
        }
    }
    
    if (ok) {
        cout << "all ok!" << endl;
    }
}
