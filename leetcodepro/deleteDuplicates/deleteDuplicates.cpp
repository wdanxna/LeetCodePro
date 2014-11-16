//
//  deleteDuplicates.cpp
//  leetcodepro
//
//  Created by drakeDan on 11/9/14.
//  Copyright (c) 2014 bravo. All rights reserved.
//

#include "deleteDuplicates.h"
#include "common.h"

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return NULL;
    
    ListNode *stick = head, *cursor = head->next;
    while (cursor) {
        if (cursor->val == stick->val) {
            cursor = cursor->next;
            continue;
        }
        else {
            stick->next = cursor;
            stick = cursor;
        }
        cursor = cursor->next;
    }
    stick->next = NULL;
    return head;
}

void deleteDuplicatesTest() {
    int raw[] = {1,1,2,3,3};
    ListNode *list = buildList(raw, 5);
    ListNode *hah = deleteDuplicates(list);
    cout << "ha" << endl;
}
