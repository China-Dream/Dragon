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

/* #138
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
https ://leetcode-cn.com/problems/copy-list-with-random-pointer
*/
class CopyRandomList : public Solution
{
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node() {}

        Node(int _val, Node* _next, Node* _random) {
            val = _val;
            next = _next;
            random = _random;
        }
    };

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        {
            return head;
        }

        map<Node*, Node*> nodeMap;
        auto p = head;
        auto q = new Node();
        auto head_ = q;
        while (p != nullptr)
        {
            q->next = new Node();
            q = q->next;
            q->val = p->val;
            q->next = nullptr;

            nodeMap[p] = q;
            p = p->next;
        }

        p = head;
        q = head_->next;
        while (p != nullptr)
        {
            if (p->random == nullptr)
            {
                q->random = nullptr;
            }
            else
            {
                q->random = nodeMap[p->random];
            }

            p = p->next;
            q = q->next;
        }

        q = head_->next;
        delete head_;
        return q;
    }

    virtual void Run()
    {

    }
};