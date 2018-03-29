//
//  removeElements.cpp
//  leetcodepro
//
//  Created by drakeDan on 10/22/15.
//  Copyright © 2015 bravo. All rights reserved.
//

#include "removeElements.hpp"
#include <iostream>
#include "common.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

ListNode* removeElements(ListNode* head, int val) {
    ListNode* p = NULL;
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    if (head == NULL) return NULL;
    
    p = head;
    while (p != NULL) {
        if (p->next != NULL && p->next->val == val) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return head;
}


void removeElementsTest() {
    int a[] = {1,2,2,1};
    ListNode *list = buildList(a, 4);
    ListNode *after = removeElements(list, 2);
    cout << "hey" << endl;
}
