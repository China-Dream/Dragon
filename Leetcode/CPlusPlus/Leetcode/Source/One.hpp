#ifndef _ONE_HPP_
#define _ONE_HPP_

#include "Solution.h"

/* #1
*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*You may assume that each input would have exactly one solution, and you may not use the same element twice.
*https://leetcode-cn.com/problems/two-sum
*/
class TwoSum : public Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> maps;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            maps.insert(std::unordered_map<int, int>::value_type(nums[i], i));
        }

        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (maps.find(target - nums[i]) != maps.end())
            {
                auto ind = maps[target - nums[i]];

                if (i != ind)
                {
                    return vector<int>({ i, ind });
                }
            }
        }

        return vector<int>({ -1, -1 });
    }

    virtual void Run()
    {
        vector<int> vec = { 3, 2, 4 };
        cout << twoSum(vec, 6);
    }
};

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

/* #5
Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
https ://leetcode-cn.com/problems/longest-palindromic-substring
*/
class LongestPalindrome : public Solution
{
public:
    string longestPalindrome(string s) {
        if (s.empty())
        {
            return s;
        }

        int start = 0, end = 0;
        int len = (int)s.size();
        for (int i = 0; i < len; i++)
        {
            auto low = i - 1, high = i + 1;
            while (low >= 0 && high < len && s[low] == s[high])
            {
                low--;
                high++;
            }
            if (high - low - 1 > end - start)
            {
                start = low + 1;
                end = high;
            }

            low = i, high = i + 1;
            while (low >= 0 && high < len && s[low] == s[high])
            {
                low--;
                high++;
            }
            if (high - low - 1 > end - start)
            {
                start = low + 1;
                end = high;
            }
        }

        return s.substr(start, end - start);
    }

    virtual void Run()
    {
        string s("bb");
        cout << longestPalindrome(s) << endl;
    }
};

/* #15
*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
*https ://leetcode-cn.com/problems/3sum
*/
class ThreeSum : public Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if (nums.size() < 3)
        {
            return ret;
        }

        qsort(nums.data(), nums.size(), sizeof(nums[0]),
            [](const void* p1, const void* p2)
        {
            return *(int*)p1 < *(int*)p2 ? -1 : 1;
        });

        for (int i = 0; i < (int)nums.size() - 2 && nums[i] <= 0; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            auto target = 0 - nums[i];

            int low = i + 1, high = (int)nums.size() - 1;
            while (low < high)
            {
                auto sum = nums[low] + nums[high];

                if (sum == target)
                {
                    ret.push_back(vector<int>({ nums[i], nums[low], nums[high] }));

                    while (low < high && nums[low] == nums[low + 1])
                    {
                        low++;
                    }
                    low++;

                    while (low < high && nums[high] == nums[high - 1])
                    {
                        high--;
                    }
                    high--;
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
        }

        return ret;
    }

    virtual void Run()
    {
        vector<int> nums = { -1, 0, 1, 2, -1, -4 };

        auto ret = threeSum(nums);

        for (auto it = ret.cbegin(); it != ret.cend(); it++)
        {
            for (auto it_ = it->cbegin(); it_ != it->cend(); it_++)
            {
                cout << *it_ << " ";
            }
            cout << endl;
        }
    }
};

/* #16
*Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
*https ://leetcode-cn.com/problems/3sum-closest
*/
class ThreeSumClosest : public Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best = target;
        int bestErr = INT_MAX;

        qsort(nums.data(), nums.size(), sizeof(nums[0]),
            [](const void* p1, const void* p2)
        {
            return *(int*)p1 < *(int*)p2 ? -1 : 1;
        });

        for (int i = 0; i < (int)nums.size() - 2 && 3 * nums[i] - target < bestErr; i++)
        {
            auto target_ = target - nums[i];

            int low = i + 1, high = (int)nums.size() - 1;
            while (low < high)
            {
                auto sum = nums[low] + nums[high];

                if (sum == target_)
                {
                    return target;
                }
                else if (sum < target_)
                {
                    low++;
                }
                else
                {
                    high--;
                }

                auto err = abs(sum - target_);
                if (err < bestErr)
                {
                    bestErr = err;
                    best = sum + nums[i];
                }
            }
        }

        return best;
    }

    virtual void Run()
    {
        vector<int> nums = { -1, 1, 2, -4 };
        cout << threeSumClosest(nums, 1) << endl;
    }
};

/* #18
*Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
*https://leetcode-cn.com/problems/4sum
*/
class FourSum : public Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        ret.reserve(16);

        if (nums.size() < 4)
        {
            return ret;
        }

        qsort(nums.data(), nums.size(), sizeof(nums[0]),
            [](const void* p1, const void* p2)
        {
            return *(int*)p1 < *(int*)p2 ? -1 : 1;
        });

        for (int i = 0; i < (int)nums.size() - 3 && nums[i] <= target / 4; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            auto avg = (target - nums[i]) / 3;
            for (int j = i + 1; j < (int)nums.size() - 2 && nums[j] <= avg; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                auto rest = target - nums[i] - nums[j];

                int low = j + 1, high = (int)nums.size() - 1;
                while (low < high)
                {
                    auto sum = nums[low] + nums[high];

                    if (sum == rest)
                    {
                        ret.push_back(vector<int>({ nums[i], nums[j], nums[low], nums[high] }));

                        while (low < high && nums[low] == nums[low + 1])
                        {
                            low++;
                        }
                        low++;

                        while (low < high && nums[high] == nums[high - 1])
                        {
                            high--;
                        }
                        high--;
                    }
                    else if (sum < rest)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }

        return ret;
    }

    virtual void Run()
    {
        vector<int> nums = { -1, -5, -5, -3, 2, 5, 0, 4 };

        auto ret = fourSum(nums, -7);

        for (auto it = ret.cbegin(); it != ret.cend(); it++)
        {
            for (auto it_ = it->cbegin(); it_ != it->cend(); it_++)
            {
                cout << *it_ << " ";
            }
            cout << endl;
        }
    }
};

/* #53
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
https ://leetcode-cn.com/problems/maximum-subarray
*/
class MaxSubArray : public Solution
{
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }

        auto len = (int)nums.size();
        auto maxSum = nums[0];
        auto lastSum = nums[0];

        for (int i = 1; i < len; ++i)
        {
            if (lastSum > 0)
            {
                lastSum += nums[i];
            }
            else
            {
                lastSum = nums[i];
            }

            if (lastSum > maxSum)
            {
                maxSum = lastSum;
            }
        }

        return maxSum;
    }

    virtual void Run()
    {
        vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        cout << maxSubArray(nums) << endl;
    }
};

/* #69
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non - negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
https://leetcode-cn.com/problems/sqrtx
*/
class MySqrt : public Solution
{
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int res = 0;
        while (low <= high)
        {
            auto mid = low + (high - low) / 2;
            double t = (double)x / mid;

            if (abs(t - mid) < DBL_EPSILON && mid * mid == x)
            {
                return mid;
            }
            else if (t > mid)
            {
                low = mid + 1;
                res = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return res;
    }

    virtual void Run()
    {
        cout << mySqrt(9) << endl;
    }
};

/* #94
* Given a binary tree, return the inorder traversal of its nodes' values.
*/
class InorderTraversal : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                if (ptr->right != nullptr)
                {
                    ptrs.push(ptr->right);
                    flags.push(false);
                }
                ptrs.push(ptr);
                flags.push(true);
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

    /*vector<int> inorderTraversal(TreeNode* root) {
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

        vec.push_back(root->val);

        if (root->right != nullptr)
        {
            traverse(root->right, vec);
        }
    }

    virtual void Run()
    {

    }
};

/* #98
*Given a binary tree, determine if it is a valid binary search tree (BST).
*/
class IsValidBST : public Solution
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long min, long max)
    {
        if (root == NULL)
        {
            return true;
        }

        return (root->val > min) && (root->val < max) &&
            isValidBST(root->left, min, root->val) &&
            isValidBST(root->right, root->val, max);
    }

    virtual void Run()
    {

    }
};

#endif