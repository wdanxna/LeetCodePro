//
//  selfProduct.cpp
//  leetcodepro
//
//  Created by drakeDan on 9/20/15.
//  Copyright (c) 2015 bravo. All rights reserved.
//

#include "selfProduct.h"

char s[] = {
    'v',
    'o',
    'i',
    'd',
    ' ',
    's',
    'e',
    'l',
    'f',
    'P',
    'r',
    'o',
    'd',
    'u',
    'c',
    't',
    '(',
    ')',
    ' ',
    '{',
    '\n',
    '\t',
    'i',
    'n',
    't',
    ' ',
    'i',
    ';',
    '\n',
    '\t',
    'p',
    'r',
    'i',
    'n',
    't',
    'f',
    '(',
    '"',
    'c',
    'h',
    'a',
    'r',
    ' ',
    's',
    '[',
    ']',
    ' ',
    '=',
    ' ',
    '{',
    '\\',
    'n',
    '"',
    ')',
    ';',
    '\n',
    '\t',
    'f',
    'o',
    'r', ' ',
    '(',
    'i',
    ' ',
    '=',
    ' ',
    '0',
    ';',
    's',
    '[',
    'i',
    ']',
    ';',
    'i',
    '+',
    '+',
    ')',
    '\n',
    '\t',
    '\t',
    'p',
    'r',
    'i',
    'n',
    't',
    'f',
    '(',
    '"',
    '%',
    'd',
    ',',
    ' ',
    '\\',
    'n',
    '"',
    ',',
    's',
    '[',
    'i',
    ']',
    ')',
    ';',
    '\n',
    '\t',
    'p',
    'r',
    'i',
    'n',
    't',
    'f',
    '(',
    '"',
    '}',
    ';',
    '\\',
    'n',
    '%',
    's',
    ',',
    's',
    ')',
    ';',
    '\n',
    '}',
    0
};
void selfProduct() {
    int i;
    printf("char s[] = {\n");
    for (i = 0; s[i]; i++)
        printf("\t%d, \n", s[i]);
    printf("};\n%s", s);
}