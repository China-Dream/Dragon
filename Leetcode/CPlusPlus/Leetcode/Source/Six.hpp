#ifndef _SIX_HPP_
#define _SIX_HPP_

#include "Solution.h"

/* #526
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
 

 Now given N, how many beautiful arrangements can you construct?
 https://leetcode-cn.com/problems/beautiful-arrangement
*/
class CountArrangement : public Solution
{
public:
    int countArrangement(int N) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            arr[i] = i + 1;
        }

        int n = 0;
        Permute(arr, 0, n);

        return n;
    }

    void Permute(vector<int>& arr, int pos, int& n)
    {
        if (pos == arr.size())
        {
            n++;
        }

        for (int i = pos; i < (int)arr.size(); i++)
        {
            std::swap(arr[pos], arr[i]);
            if (arr[pos] % (pos + 1) == 0 || (pos + 1) % arr[pos] == 0)
            {
                Permute(arr, pos + 1, n);
            }
            std::swap(arr[pos], arr[i]);
        }
    }

    virtual void Run()
    {
        cout << countArrangement(3) << endl;
    }
};

/* #537
Given two strings representing two complex numbers.
You need to return a string representing their multiplication.Note i2 = -1 according to the definition.
https ://leetcode-cn.com/problems/complex-number-multiplication
*/
class ComplexNumberMultiply : public Solution
{
public:
    string complexNumberMultiply(string a, string b) {
        int t1 = a.find('+');
        int t2 = b.find('+');
        int _a = std::stoi(a.substr(0, t1));
        int _b = std::stoi(b.substr(0, t2));
        int a_ = std::stoi(a.substr(t1 + 1, a.find('i') - t1));
        int b_ = std::stoi(b.substr(t2 + 1, b.find('i') - t2));
        int _ab = _a * _b - a_ * b_;
        int ab_ = _a * b_ + _b * a_;
        return std::string(std::to_string(_ab) + "+" + std::to_string(ab_) + "i");
    }

    virtual void Run()
    {
        string a = "1+-1i";
        string b = "1+-1i";
        cout << complexNumberMultiply(a, b) << endl;
    }
};

/* #560
*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*https ://leetcode-cn.com/problems/subarray-sum-equals-k
*/
class SubarraySum : public Solution
{
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty())
        {
            return 0;
        }

        auto size = (int)nums.size();
        vector<int> sums(size);
        sums[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            sums[i] = sums[i - 1] + nums[i];
        }

        int count = 0;
        unordered_multimap<int, int> map;
        for (int i = 0; i < size; i++)
        {
            map.insert(unordered_map<int, int>::value_type(sums[i], i));

            if (k == sums[i])
            {
                count++;
            }
        }

        for (int i = 0; i < size - 1; i++)
        {
            auto range = map.equal_range(sums[i] + k);

            for (auto it = range.first; it != range.second; it++)
            {
                if (it->second > i)
                {
                    count++;
                }
            }
        }

        return count;
    }

    virtual void Run()
    {
        vector<int> nums = { 1, 1, 1 };
        cout << subarraySum(nums, 2) << endl;
    }
};

/* #589
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal
*/
class PreorderN : public Solution
{
public:
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };

    vector<int> preorder(Node* root) {
        vector<int> nums;
        preorder(root, nums);
        return nums;
    }

    void preorder(Node* root, vector<int>& nums)
    {
        if (root == nullptr)
        {
            return;
        }

        nums.push_back(root->val);

        for (auto it = root->children.cbegin(); it != root->children.cend(); it++)
        {
            preorder(*it, nums);
        }
    }

    vector<int> preorder_(Node* root) {
        vector<int> nums;

        if (root == nullptr)
        {
            return nums;
        }

        stack<Node*> ptrs;
        ptrs.push(root);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            ptrs.pop();

            nums.push_back(ptr->val);
            for (auto it = ptr->children.rbegin(); it != ptr->children.rend(); it++)
            {
                if (*it != nullptr)
                {
                    ptrs.push(*it);
                }
            }
        }

        return nums;
    }

    virtual void Run()
    {

    }
};

/* #590
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
*/
class PostorderN : public Solution
{
public:
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };

    vector<int> postorder(Node* root) {
        vector<int> nums;
        postorder(root, nums);
        return nums;
    }

    void postorder(Node* root, vector<int>& nums)
    {
        if (root == nullptr)
        {
            return;
        }

        for (auto it = root->children.cbegin(); it != root->children.cend(); it++)
        {
            postorder(*it, nums);
        }

        nums.push_back(root->val);
    }

    vector<int> postorder_(Node* root) {
        vector<int> nums;

        if (root == nullptr)
        {
            return nums;
        }

        stack<Node*> ptrs;
        ptrs.push(root);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            ptrs.pop();

            nums.push_back(ptr->val);
            for (auto it = ptr->children.begin(); it != ptr->children.end(); it++)
            {
                if (*it != nullptr)
                {
                    ptrs.push(*it);
                }
            }
        }

        std::reverse(nums.begin(), nums.end());
        return nums;
    }

    virtual void Run()
    {

    }
};
#endif