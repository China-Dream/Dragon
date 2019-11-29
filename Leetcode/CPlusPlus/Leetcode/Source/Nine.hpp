#ifndef _NINE_HPP_
#define _NINE_HPP_

#include "Solution.h"

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
        vector<int> piles = { 332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184 };
        auto H = 823855818;
        cout << minEatingSpeed(piles, H) << endl;
    }
};

#endif