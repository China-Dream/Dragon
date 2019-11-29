#ifndef _SIX_HPP_
#define _SIX_HPP_

#include "Solution.h"

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

#endif