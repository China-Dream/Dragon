#ifndef _TWO_HPP_
#define _TWO_HPP_

#include "Solution.h"

/* #121
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
*/
class MaxProfit : public Solution
{
public:
    int maxProfit(vector<int>& prices) {
        auto profit = 0;
        auto minPrice = INT_MAX;
        auto len = (int)prices.size();
        for (int i = 0; i < len; ++i)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }

            auto p = prices[i] - minPrice;
            if (p > profit)
            {
                profit = p;
            }
        }

        return profit;
    }

    virtual void Run()
    {
        vector<int> prices = { 7, 1, 5, 3, 6, 4 };
        cout << maxProfit(prices) << endl;
    }
};

/* #122
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
*/
class MaxProfitII : public Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

    virtual void Run()
    {
        vector<int> prices = { 7, 1, 5, 3, 6, 4 };
        cout << maxProfit(prices) << endl;
    }
};

/* #123
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
*/
class MaxProfitIII : public Solution
{
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;

        for (int i = 1; i< (int)prices.size(); ++i) {
            s1 = max(s1, -prices[i]); //买入价格更低的股
            s2 = max(s2, s1 + prices[i]); //卖出当前股，或者不操作
            s3 = max(s3, s2 - prices[i]); //第二次买入，或者不操作
            s4 = max(s4, s3 + prices[i]); //第二次卖出，或者不操作
        }
        return max(0, s4);
    }

    virtual void Run()
    {
        vector<int> prices = { 7, 1, 5, 3, 6, 4 };
        cout << maxProfit(prices) << endl;
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

/* #144
Given a binary tree, return the preorder traversal of its nodes' values.
*/
class PreorderTraversal : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        stack<TreeNode*> ptrs;
        ptrs.push(root);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            ptrs.pop();

            vec.push_back(ptr->val);
            if (ptr->right != nullptr)
            {
                ptrs.push(ptr->right);
            }
            if (ptr->left != nullptr)
            {
                ptrs.push(ptr->left);
            }
        }

        return vec;
    }

    /*vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;

    if (root == nullptr)
    {
    return vec;
    }

    traverse(root, vec);
    return vec;
    }*/

    void traverse(TreeNode* root, vector<int>& vec)
    {
        vec.push_back(root->val);

        if (root->left != nullptr)
        {
            traverse(root->left, vec);
        }

        if (root->right != nullptr)
        {
            traverse(root->right, vec);
        }
    }

    virtual void Run()
    {

    }
};

/* #145
Given a binary tree, return the postorder traversal of its nodes' values.
*/
class PostorderTraversal : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;

        if (root == nullptr)
        {
            return vec;
        }

        stack<TreeNode*> ptrs;
        stack<bool> flags;
        ptrs.push(root);
        flags.push(false);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            auto flag = flags.top();
            ptrs.pop();
            flags.pop();

            if (!flag)
            {
                ptrs.push(ptr);
                flags.push(true);
                if (ptr->right != nullptr)
                {
                    ptrs.push(ptr->right);
                    flags.push(false);
                }
                if (ptr->left != nullptr)
                {
                    ptrs.push(ptr->left);
                    flags.push(false);
                }
            }
            else
            {
                vec.push_back(ptr->val);
            }
        }

        return vec;
    }

    /*vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;

    if (root == nullptr)
    {
    return vec;
    }

    traverse(root, vec);
    return vec;
    }*/

    void traverse(TreeNode* root, vector<int>& vec)
    {
        if (root->left != nullptr)
        {
            traverse(root->left, vec);
        }

        if (root->right != nullptr)
        {
            traverse(root->right, vec);
        }

        vec.push_back(root->val);
    }

    virtual void Run()
    {

    }
};

/* #167
*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
*The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
*https ://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
*/
class TwoSumII : public Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = (int)numbers.size() - 1;

        while (low < high)
        {
            auto sum = numbers[low] + numbers[high];

            if (sum == target)
            {
                return vector<int>({ low + 1, high + 1 });
            }
            else if (sum < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return vector<int>({ 0, 0 });
    }

    virtual void Run()
    {
        vector<int> vec = { 2, 7, 11, 15 };
        cout << twoSum(vec, 9);
    }
};

#endif