#pragma once

#include "Solution.h"

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
        vector<int> nums = {1, 2, 5, 3, 4};
        cout << findLengthOfLCIS(nums) << endl;
    }
};

/*  #875
Koko loves to eat bananas.There are N piles of bananas, the i - th pile has piles[i] bananas.The guards have gone and will come back in H hours.
Koko can decide her bananas - per - hour eating speed of K.Each hour, she chooses some pile of bananas, and eats K bananas from that pile.If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
Return the minimum integer K such that she can eat all the bananas within H hours.
https ://leetcode-cn.com/problems/koko-eating-bananas
*/
class MinEatingSpeed : public Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        double sum = 0;
        auto maxPile = 0;
        for (auto it = piles.begin(); it != piles.end(); it++)
        {
            sum += (double)*it / H;

            if (maxPile < *it)  maxPile = *it;
        }

        int low = (int)std::ceil(sum);
        int high = (int)std::ceil(maxPile / ((double)H / piles.size()));
        int minK = INT_MAX;
        while (low <= high)
        {
            auto K = (low + high) / 2;
            auto H_ = 0;
            for (auto it = piles.begin(); it != piles.end(); it++)
            {
                H_ += (int)std::ceil((double)*it / K);
            }

            if (H_ < H)
            {
                high = K - 1;
            }
            else if (H_ > H)
            {
                low = K + 1;
            }
            else
            {
                high = K - 1;

                if (minK > K)   minK = K;
            }
        }

        return minK == INT_MAX ? low : minK;
    }

    virtual void Run()
    {
        vector<int> piles = { 332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
        auto H = 823855818;
        cout << minEatingSpeed(piles, H) << endl;
    }
};

/* #1094
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
https://leetcode-cn.com/problems/car-pooling
*/
class CarPooling : public Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> buff(1000, 0);

        for (auto it = trips.cbegin(); it != trips.cend(); it++)
        {
            buff[(*it)[1]] -= (*it)[0];
            buff[(*it)[2]] += (*it)[0];
        }

        auto c = capacity;
        for (auto it = buff.cbegin(); it != buff.cend(); it++)
        {
            c += *it;

            if (c < 0)
            {
                return false;
            }
        }

        return true;
    }

    virtual void Run()
    {
        vector<vector<int>> trips = { { 2, 1, 5 }, { 3, 5, 7 } };
        int capacity = 3;
        cout << carPooling(trips, capacity) << endl;
    }
};