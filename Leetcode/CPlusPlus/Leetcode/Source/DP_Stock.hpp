#pragma once 

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