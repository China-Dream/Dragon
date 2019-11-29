#ifndef _TEN_HPP_
#define _TEN_HPP_

#include "Solution.h"

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

#endif