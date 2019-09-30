#pragma once

#include "Solution.h"
#include "Helper.hpp"

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

        for (int i = 0; i < (int)nums.size() - 2 && 3 * nums[i] - target < bestErr ; i++)
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