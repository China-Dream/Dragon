#pragma once

#include "Solution.h"

class AddTwoNumbers : public Solution
{
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        auto p = head;
        auto p1 = l1;
        auto p2 = l2;

        int advanced = 0;
        while (p1 != nullptr && p2 != nullptr)
        {
            auto val = p1->val + p2->val + advanced;
            auto node = new ListNode(val % 10);
            advanced = val / 10;

            p->next = node;
            p = node;

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 == nullptr)
        {
            for (auto q = p2; q != nullptr; q = q->next)
            {
                auto val = q->val + advanced;
                auto node = new ListNode(val % 10);
                advanced = val / 10;

                p->next = node;
                p = node;
            }
        }

        if (p2 == nullptr)
        {
            for (auto q = p1; q != nullptr; q = q->next)
            {
                auto val = q->val + advanced;
                auto node = new ListNode(val % 10);
                advanced = val / 10;

                p->next = node;
                p = node;
            }
        }

        if (advanced != 0)
        {
            p->next = new ListNode(advanced);
        }

        p = head;
        head = head->next;
        delete p;

        return head;
    }

    virtual void Test()
    {
        ListNode* p1 = new ListNode(2); ListNode* p2 = new ListNode(4); ListNode* p3 = new ListNode(3);
        ListNode* q1 = new ListNode(5); ListNode* q2 = new ListNode(6); ListNode* q3 = new ListNode(4);
        p1->next = p2; p2->next = p3;
        q1->next = q2; q2->next = q3;

        auto r = addTwoNumbers(p1, q1);
        for (auto p = r; p != nullptr; p = p->next)
        {
            cout << p->val << " ";
        }
        cout << std::endl;
    }
};