#ifndef _FOUR_HPP_
#define _FOUR_HPP_

#include "Solution.h"

/* #309
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
*/
class MaxProfitIV : public Solution
{
public:
    enum Action
    {
        Buy = 0,
        Sell,
        Quiet,
        Count
    };

    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }

        const int CoolDays = 1;
        vector<vector<int>> stats(prices.size(), vector<int>(Action::Count, 0));
        stats[0][Buy] = -prices[0];
        auto maxBuy = stats[0][Buy];

        for (int i = 1; i < (int)prices.size(); i++)
        {
            stats[i][Buy] = max(i >= CoolDays + 1 ? stats[i - CoolDays - 1][Sell] : 0, stats[i - 1][Quiet]) - prices[i];
            stats[i][Sell] = maxBuy + prices[i];
            stats[i][Quiet] = max(stats[i - 1][Quiet], stats[i - 1][Sell]);

            if (maxBuy < stats[i][Buy])   maxBuy = stats[i][Buy];
        }

        return *std::max_element(stats.back().begin(), stats.back().end());
    }

    virtual void Run()
    {
        vector<int> prices = { 1, 2, 3, 0, 2 };
        cout << maxProfit(prices) << endl;
    }
};

/* #322
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
https://leetcode-cn.com/problems/coin-change
*/
class CoinChange : public Solution
{
public:
    // Bottom to top
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount < 0)
        {
            return -1;
        }

        vector<int> vec(amount + 1, -1);
        vec[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            auto num = INT_MAX;
            for (int j = 0; j < (int)coins.size(); j++)
            {
                if (i < coins[j])
                {
                    continue;
                }
                else if (vec[i - coins[j]] != -1 && vec[i - coins[j]] + 1 < num)
                {
                    num = vec[i - coins[j]] + 1;
                }
            }

            vec[i] = num == INT_MAX ? -1 : num;
        }

        return vec[amount];
    }

    // Top to bottom
    /*int coinChange(vector<int>& coins, int amount) {
    vector<int> vec(amount + 1, -1);
    vec[0] = 0;
    return coinChange(coins, amount, vec);
    }*/

    int coinChange(vector<int>& coins, int amount, vector<int>& vec)
    {
        if (amount == 0)    return 0;
        if (amount < 0)     return -1;
        if (vec[amount] != -1)  return vec[amount];

        auto num = INT_MAX;
        for (int i = 0; i < (int)coins.size(); i++)
        {
            auto res = coinChange(coins, amount - coins[i], vec);
            if (res != -1 && res + 1 < num)
            {
                num = res + 1;
            }
        }
        vec[amount] = num == INT_MAX ? -1 : num;

        return vec[amount];
    }

    virtual void Run()
    {
        vector<int> coins = { 1, 2, 5 };
        cout << coinChange(coins, 11);
    }
};

/* #349
Given two arrays, write a function to compute their intersection.
*/
class Intersection : public Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> s1, s2;

        for (auto it = nums1.cbegin(); it != nums1.cend(); it++)
        {
            s1.insert(*it);
        }

        for (auto it = nums2.cbegin(); it != nums2.cend(); it++)
        {
            s2.insert(*it);
        }

        vector<int> v;
        auto it1 = s1.cbegin(), it2 = s2.cbegin();
        while (it1 != s1.cend() && it2 != s2.cend())
        {
            if (*it1 == *it2)
            {
                v.push_back(*it1);
                it1++;
                it2++;
            }
            else if (*it1 < *it2)
            {
                it1++;
            }
            else
            {
                it2++;
            }
        }

        return v;
    }

    virtual void Run()
    {
        vector<int> n1 = { 1, 2, 2, 1 };
        vector<int> n2 = { 2, 2 };
        cout << intersection(n1, n2) << endl;
    }
};

/* #367
Given a positive integer num, write a function which returns True if num is a perfect square else False.
https://leetcode-cn.com/problems/valid-perfect-square
*/
class IsPerfectSquare : public Solution
{
public:
    /*bool isPerfectSquare(int num) {
    if (num < 0)
    {
    return false;
    }

    if (num <= 1)
    {
    return true;
    }

    auto low = 2;
    auto high = num / 2;
    while (low <= high)
    {
    long long mid = (high + low) / 2;
    long long m = mid * mid;

    if (m == num)
    {
    return true;
    }
    else if (m > num)
    {
    high = mid - 1;
    }
    else
    {
    low = mid + 1;
    }
    }

    return false;
    }*/

    bool isPerfectSquare(int num)
    {
        if (num < 0)    return false;
        if (num <= 1)   return true;

        auto i = (long long)(num / 2);
        while (i * i > num)
        {
            i = (i + num / i) / 2;
        }

        return i * i == num;
    }

    virtual void Run()
    {
        int num = 2147395600;
        cout << isPerfectSquare(num) << endl;
    }
};

/* #396
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.
https://leetcode-cn.com/problems/rotate-function
*/
class MaxRotateFunction {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sum = 0;
        long long total = 0;
        long long size = (long long)A.size();

        for (int i = 0; i < size; i++)
        {
            sum += i * A[i];
            total += A[i];
        }

        auto lastInd = size - 1;
        auto maxSum = sum;
        for (int i = 1; i < (int)A.size(); i++)
        {
            sum += total - size * A[lastInd];
            lastInd--;

            if (maxSum < sum)   maxSum = sum;
        }

        return (int)maxSum;
    }

    virtual void Run()
    {
        vector<int> A = { 2147483647, 2147483647 };
        cout << maxRotateFunction(A) << endl;
    }
};

#endif