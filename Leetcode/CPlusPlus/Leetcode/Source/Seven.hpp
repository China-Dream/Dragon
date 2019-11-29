#ifndef _SEVEN_HPP_
#define _SEVEN_HPP_

#include "Solution.h"

/* #622
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
https://leetcode-cn.com/problems/design-circular-queue
*/
class MyCircularQueue : public Solution
{
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        buff.resize(k + 1);
        head = tail = 0;
        size = k + 1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (head == (tail + 1) % size)
        {
            return false;
        }

        buff[tail] = value;
        tail = ++tail % size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (head == tail)
        {
            return false;
        }

        head = ++head % size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return head != tail ? buff[head] : -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        return head != tail ? buff[(tail - 1 + size) % size] : -1;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head == (tail + 1) % size;
    }

    std::vector<int> buff;
    int head;
    int tail;
    int size;

    MyCircularQueue() = default;

    virtual void Run()
    {
        int k = 3;
        buff.resize(k + 1);
        head = tail = 0;
        size = k + 1;


        cout << enQueue(1) << endl;
        cout << enQueue(2) << endl;
        cout << enQueue(3) << endl;
        cout << enQueue(4) << endl;
        cout << Rear() << endl;
        cout << isFull() << endl;
        cout << deQueue() << endl;
        cout << enQueue(4) << endl;
        cout << Rear() << endl;
    }
};

/*  #653
*Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
*https ://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
*/
class TwoSumIV : public Solution
{
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)
        {
            return false;
        }

        std::set<int> nums;
        std::stack<TreeNode*> stack;

        stack.push(root);
        while (!stack.empty())
        {
            auto p = stack.top();
            if (nums.find(k - p->val) != nums.end())
            {
                return true;
            }
            else
            {
                nums.insert(p->val);
            }

            stack.pop();
            if (p->right != nullptr)
            {
                stack.push(p->right);
            }
            if (p->left != nullptr)
            {
                stack.push(p->left);
            }
        }

        return false;
    }

    /*bool findTarget(TreeNode* root, int k) {
    std::unordered_set<int> nums;
    return traverse(root, k, nums);
    }*/

    bool traverse(TreeNode* root, int k, std::unordered_set<int>& nums) {
        if (root == nullptr)
        {
            return false;
        }

        if (nums.find(k - root->val) != nums.end())
        {
            return true;
        }

        nums.insert(root->val);

        return traverse(root->left, k, nums) || traverse(root->right, k, nums);
    }

    virtual void Run()
    {
        cout << findTarget(nullptr, 0);
    }
};

/* #674
Given an unsorted array of integers, find the length of longest continuous increasing subsequence(subarray).
https ://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
*/
class FindLengthOfLCIS : public Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 0;
        int start = 0;
        int total = (int)nums.size();

        for (int i = 1; i < total; ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                if (i - start > maxLength)
                {
                    maxLength = i - start;
                }

                if (start + maxLength >= total)
                {
                    break;
                }

                start = i;
            }
        }

        return max(maxLength, total - start);
    }

    virtual void Run()
    {
        vector<int> nums = { 1, 2, 5, 3, 4 };
        cout << findLengthOfLCIS(nums) << endl;
    }
};
#endif