#pragma once

#include "Solution.h"

/* #2
You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
https ://leetcode-cn.com/problems/add-two-numbers
*/
class AddTwoNumbers {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        auto p = head;
        int bit = 0;

        while (l1 != nullptr || l2 != nullptr || bit != 0)
        {
            int sum = bit;
            if (l1 != nullptr)
            {
                sum += l1->val;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
            }

            bit = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;
            if (l1 != nullptr)  l1 = l1->next;
            if (l2 != nullptr)  l2 = l2->next;
        }

        p = head->next;
        delete head;
        return p;
    }

    virtual void Run()
    {
    }
};