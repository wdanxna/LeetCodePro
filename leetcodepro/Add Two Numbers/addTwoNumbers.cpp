//
//  addTwoNumbers.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/24/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "addTwoNumbers.h"
#include <iostream>
#include "common.h"
using namespace std;

void addIter(ListNode *l1, ListNode *l2, ListNode *prev, int carry) {
    if (!l1 && !l2 && carry == 0) return;
    ListNode *node;
    int val = 0;
    if (l1) {
        val += l1->val;
    }
    if (l2) {
        val += l2->val;
    }
    val += carry;
    carry = val / 10;
    val = val % 10;
    
    node = new ListNode(val);
    if (prev) {
        prev->next = node;
    }
    
    addIter(l1 ? l1->next : NULL, l2 ? l2->next : NULL, node, carry);
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = new ListNode(0);
    addIter(l1, l2, ret, 0);
    return ret->next;
}


void addTwoNumbersTest() {
    int raw1[] = {2,4,3};
    int raw2[] = {5,6};
    ListNode *l1 = buildList(raw1, 3);
    ListNode *l2 = buildList(raw2, 2);
    ListNode *result = addTwoNumbers(l1, l2);
    cout << "yeah" << endl;
}
