#pragma once

#include "Solution.h"

/* #322
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
https://leetcode-cn.com/problems/coin-change
*/
class CoinChange : public Solution
{
public:
    int coinChange(vector<int>& coins, int amount) {
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