//
//  atoi.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/2/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "atoi.h"
bool isNum(char c) {
    if ( c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
static unsigned maxmount = 2147483647;
static unsigned minmount = 2147483648;
int my_atoi(const char *str) {
    unsigned cur = 0;
    bool negtive =false;
    unsigned result = 0;
    int ret = 0;
    
    while (str[cur] == ' ') cur++;
    if (str[cur] == '\0') return 0;//all whitespaces
    
    if (!isNum(str[cur])) {
        if (str[cur] == '-') negtive = true;
        else if (str[cur] != '+') return 0;
        cur++;
    }
    
    while (str[cur] != '\0' && isNum(str[cur])) {
        if (INT_MAX/10 < result || ((INT_MAX/10 == result) && INT_MAX%10 < (str[cur]-'0')))
        {
            if (negtive) return INT_MIN;
            return INT_MAX;
        }
        result = result * 10 + str[cur]-'0';
        cur++;
    }

    if (negtive) {
        if (result > minmount) {//neg of
            ret = INT_MIN;
        }
        else
            ret = - result;
    }
    else {
        if (result > maxmount) {//pos of
            ret = INT_MAX;
        }
        else
            ret = result;
    }
    
    return ret;
}

void atoiTest() {
    cout << my_atoi("    10522545459") << endl;
//    vector<string> tests = {"001","*&02","12345","xxx","    3","+4","00-5","6","2147483648","-2147483649","   ","23ignored"};
//    for (string s : tests) {
//        cout << s << " -> " << my_atoi(s.c_str()) << endl;
//    }
}
