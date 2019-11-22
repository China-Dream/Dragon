#pragma once

#include "Solution.h"

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

/* #975
You are given an integer array A.From some starting index, you can make a series of jumps.The(1st, 3rd, 5th, ...) jumps in the series are called odd numbered jumps, and the(2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.
You may from index i jump forward to index j (with i < j) in the following way :
During odd numbered jumps(ie.jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.If there are multiple such indexes j, you can only jump to the smallest such index j.
During even numbered jumps(ie.jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.If there are multiple such indexes j, you can only jump to the smallest such index j.
(It may be the case that for some index i, there are no legal jumps.)
A starting index is good if, starting from that index, you can reach the end of the array(index A.length - 1) by jumping some number of times(possibly 0 or more than once.)
Return the number of good starting indexes.
https ://leetcode-cn.com/problems/odd-even-jump
*/
class OddEvenJumps : public Solution
{
public:
    int oddEvenJumps(vector<int>& A) {
        auto len = (int)A.size();
        if (len <= 1)
        {
            return len;
        }

        map<int, int> dataMap;
        vector<bool> oddReached(len, false);
        vector<bool> evenReached(len, false);
        dataMap.insert(map<int, int>::value_type(A.back(), len - 1));
        oddReached[len - 1] = evenReached[len - 1] = true;

        for (int i = len - 2; i >= 0; --i)
        {
            auto it = dataMap.find(A[i]);
            if (it != dataMap.end())
            {
                oddReached[i] = evenReached[it->second];
                evenReached[i] = oddReached[it->second];
                it->second = i;
            }
            else
            {
                auto it1 = dataMap.lower_bound(A[i]);

                if (it1 != dataMap.end())
                {
                    oddReached[i] = evenReached[it1->second];
                }

                if (it1 != dataMap.begin())
                {
                    --it1;
                    evenReached[i] = oddReached[it1->second];
                }

                dataMap.insert(map<int, int>::value_type(A[i], i));
            }
        }

        auto sum = 0;
        for (auto it = oddReached.cbegin(); it != oddReached.cend(); ++it)
        {
            if (*it)
            {
                ++sum;
            }
        }

        return sum;
    }

    /*int oddEvenJumps(vector<int>& A) {
        if (A.empty())
        {
            return 0;
        }

        auto len = (int)A.size();
        vector<int> oddNext(len, -1);
        vector<int> evenNext(len, -1);

        auto monotoneStack = [&A, &len](vector<int>& vec, bool ascend){
            stack<int> monoStack;
            for (int i = 0; i < len; ++i)
            {
                if (monoStack.empty() || (ascend && A[monoStack.top()] < A[i]) || (!ascend && A[monoStack.top()] > A[i]))
                {
                    monoStack.push(i);
                }
                else
                {
                    stack<int> tmpStack;
                    while (!monoStack.empty() && ((ascend && A[monoStack.top()] >= A[i]) || (!ascend && A[monoStack.top()] <= A[i])))
                    {
                        auto ind = monoStack.top();
                        tmpStack.push(ind);
                        monoStack.pop();

                        if (vec[ind] != -1 && ((ascend && A[vec[ind]] >= A[i]) || (!ascend && A[vec[ind]] <= A[i])))
                        {
                            ;
                        }
                        else
                        {
                            vec[ind] = i;
                        }
                    }

                    monoStack.push(i);
                    while (!tmpStack.empty())
                    {
                        monoStack.push(tmpStack.top());
                        tmpStack.pop();
                    }
                }
            }
        };

        monotoneStack(oddNext, false);
        monotoneStack(evenNext, true);

        vector<bool> oddReached(len, false);
        vector<bool> evenReached(len, false);
        oddReached[len - 1] = evenReached[len - 1] = true;
        for (int i = len - 2; i >= 0; --i)
        {
            if (oddNext[i] != -1)
            {
                oddReached[i] = evenReached[oddNext[i]];
            }

            if (evenNext[i] != -1)
            {
                evenReached[i] = oddReached[evenNext[i]];
            }
        }

        auto sum = 0;
        for (auto it = oddReached.cbegin(); it != oddReached.cend(); ++it)
        {
            if (*it)
            {
                ++sum;
            }
        }

        return sum;
    }*/

    virtual void Run()
    {
        vector<int> A = { 2, 3, 1, 1, 4 };
        cout << oddEvenJumps(A) << endl;
    }
};

/* #983
In a country popular for train travel, you have planned some train travelling one year in advance.The days of the year that you will travel is given as an array days.Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways :

a 1 - day pass is sold for costs[0] dollars;
a 7 - day pass is sold for costs[1] dollars;
a 30 - day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.For example, if we get a 7 - day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

https ://leetcode-cn.com/problems/minimum-cost-for-tickets
*/
class MinCostTickets : public Solution
{
public:
    // Bottom to top
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> sumCosts(days.back() + 1, 0);

        int ind = 0;
        for (int i = days[ind]; i <= days.back() && ind < (int)days.size(); i++)
        {
            if (i == days[ind])
            {
                sumCosts[i] = min((i - 1 >= 0 ? sumCosts[i - 1] : 0) + costs[0],
                    min((i - 7 >= 0 ? sumCosts[i - 7] : 0) + costs[1], (i - 30 >= 0 ? sumCosts[i - 30] : 0) + costs[2]));
                ind++;
            }
            else if (i < days[ind])
            {
                sumCosts[i] = sumCosts[days[ind - 1]];
            }
        }

        return sumCosts.back();
    }

    // Top to bottom
    /*int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> sumCosts(days.back() + 1, 0);
        return mincostTickets(days, costs, sumCosts, days.back());
    }*/

    int mincostTickets(vector<int>& days, vector<int>& costs, vector<int>& sumCosts, int day)
    {
        if (day < days.front())
        {
            return 0;
        }

        if (sumCosts[day] != 0)
        {
            return sumCosts[day];
        }

        for (auto it = days.crbegin(); it != days.crend(); it++)
        {
            if (*it == day)
            {
                sumCosts[day] = min(mincostTickets(days, costs, sumCosts, day - 30) + costs[2],
                    min(mincostTickets(days, costs, sumCosts, day - 7) + costs[1], mincostTickets(days, costs, sumCosts, day - 1) + costs[0]));
                break;
            }
            else if (*it < day)
            {
                sumCosts[day] = mincostTickets(days, costs, sumCosts, *it);
                break;
            }
        }

        return sumCosts[day];
    }

    virtual void Run()
    {
        vector<int> days = { 1, 4, 6, 7, 8, 20 };
        //vector<int> days = { 1, 3, 4, 5 };
        vector<int> costs = { 2, 7, 15 };

        cout << mincostTickets(days, costs) << endl;
    }
};

/* #1143
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not).A common subsequence of two strings is a subsequence that is common to both strings.
If there is no common subsequence, return 0.
https ://leetcode-cn.com/problems/longest-common-subsequence
*/
class LongestCommonSubsequence : public Solution
{
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto len1 = (int)text1.size();
        auto len2 = (int)text2.size();
        vector<vector<int>> buff(len1 + 1, vector<int>(len2 + 1, 0));

        for (int k = 2; k <= len1 + len2; k++)
        {
            for (int i = max(1, k - len2); i <= min(len1, k - 1); i++)
            {
                auto j = k - i;
                if (text1[i - 1] == text2[j - 1])
                {
                    buff[i][j] = buff[i - 1][j - 1] + 1;
                }
                else
                {
                    buff[i][j] = max(buff[i - 1][j], buff[i][j - 1]);
                }
            }
        }

        return buff[len1][len2];
    }

    virtual void Run()
    {
        string text1 = "abcde";
        string text2 = "acd";
        cout << longestCommonSubsequence(text1, text2) << endl;
    }
};