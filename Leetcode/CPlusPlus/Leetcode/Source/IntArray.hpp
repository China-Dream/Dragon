#pragma once

#include "Solution.h"

// Sort the array, and set front/back index
// Compare sum of front/back elements to target, and move front/back index

class TwoSum : public Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        for (size_t i = 0u; i < nums.size(); i++)
        {
            pairs.push_back(make_pair(i, nums[i]));
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.second < p2.second; });

        int i = 0, j = pairs.size() - 1;
        while (i < j)
        {
            auto sum = pairs[i].second + pairs[j].second;
            if (sum > target)
            {
                j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                break;
            }
        }

        vector<int> res;
        if (i < j)
        {
            res.push_back(min(pairs[i].first, pairs[j].first));
            res.push_back(max(pairs[i].first, pairs[j].first));
        }

        return res;
    }

    virtual void Test()
    {
        vector<int> vec = { 2, 7, 11, 15 };
        auto res = twoSum(vec, 9);
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << " ";
        }
        cout << std::endl << res[0] << " " << res[1] << endl;

        cout << std::endl;
        vector<int> vec1 = { 3, 2, 4 };
        auto res1 = twoSum(vec1, 6);
        for (auto it = vec1.begin(); it != vec1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << std::endl << res1[0] << " " << res1[1] << endl;
    }
};

class FindMedianSortedArrays : public Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto m = nums1.size();
        auto n = nums2.size();


    }

    virtual void Test()
    {

    }
};