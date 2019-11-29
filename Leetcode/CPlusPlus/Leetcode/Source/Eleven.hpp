#ifndef _ELEVEN_HPP_
#define _ELEVEN_HPP_

#include "Solution.h"

/* #1017
Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).
The returned string must have no leading zeroes, unless the string is "0".
https://leetcode-cn.com/problems/convert-to-base-2
*/
class BaseNeg2 : public Solution
{
public:
    string baseNeg2(int N) {
        if (N == 0)
        {
            return "0";
        }

        stringstream ss;
        bool flag = true;
        while (N != 0)
        {
            auto mod = N % 2;
            N = flag ? (N - mod) >> 1 : (N + mod) >> 1;
            flag = !flag;
            ss << mod;
        }

        auto str = ss.str();
        std::reverse(str.begin(), str.end());
        return str;
    }

    virtual void Run()
    {
        cout << baseNeg2(11) << endl;
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

#endif