//
//  solveEquation.cpp
//  leetcodepro
//
//  Created by drakeDan on 19/01/2018.
//  Copyright © 2018 bravo. All rights reserved.
//

#include "solveEquation.hpp"
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int parseNum(string s, int start, int end, int* i){
#define ISNUM(x) (x >= '0' && x <= '9')
    assert(ISNUM(s[start]));
    int j = start;
    int result = 0;
    while (j < end && ISNUM(s[j])) {
        result = (result * 10) + s[j] - '0';
        j++;
    }
    *i = j;
    return result;
#undef ISNUM
}

string process(string s, int begin, int end) {
    int x_cnt = 0;
    int num_cnt = 0;
    int i = begin;
    int isLeft = 1;
    int coeff = 1;
    while (i < end) {
        auto c = s[i];
        if (c == '=') {
            isLeft = -1;
            i++;
            c = s[i];
        }
        
        int sign = 1;
        if (c == '+' || c == '-') {
            sign *= (c == '-') ? -1 : 1;
            i++;
            c = s[i];
        }
        
        if (c == 'x') {
            x_cnt += isLeft * sign * coeff;
            coeff = 1;
        }
        else {
            int stop = 0;
            int num = parseNum(s, i, end, &stop);
            if (stop < end && s[stop] == 'x') {
                coeff = sign * num;
            } else {
                num_cnt += isLeft * sign * num;
            }
            i = stop - 1;
        }
        i++;
    }
    if (x_cnt == 0) {
        if (num_cnt == 0) {
            return "Infinite solutions";
        }
        else {
            return "No solution";
        }
    } else {
        return "x=" + std::to_string((-num_cnt)/x_cnt);
    }
}

string solveEquation(string equation) {
    return process(equation, 0, (int)equation.size());
}


void solveEquationTest() {
//    solveEquation("x+5-3+x=6+x-2");
//    solveEquation("x=x");
//    solveEquation("2x=x");
    std::cout << solveEquation("2x+3x-6x=x+2") << std::endl;
//    std::cout << solveEquation("2-x+x+3x=2x-x+x+3") << std::endl;
}
