#ifndef _OTHERS_HPP_
#define _OTHERS_HPP_

#include "Solution.h"

/*  LCP2
有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？

连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。


输入的cont代表连分数的系数（cont[0]代表上图的a0，以此类推）。返回一个长度为2的数组[n, m]，使得连分数的值等于n / m，且n, m最大公约数为1。

https://leetcode-cn.com/problems/deep-dark-fraction
*/

class Fraction : public Solution
{
public:
    vector<int> fraction(vector<int>& cont) {
        auto len = (int)cont.size();

        if (len == 1)
        {
            return vector<int>{cont.front(), 1};
        }

        int n = 1, m = cont.back();

        for (int i = len - 2; i > 0; i--)
        {
            auto t = m;
            m = cont[i] * m + n;
            n = t;
        }

        n += cont.front() * m;

        auto a = max(n, m);
        auto b = min(n, m);
        while (a % b != 0)
        {
            auto mod = a % b;
            a = b;
            b = mod;
        }

        return vector<int>{n / b, m / b};
    }

    virtual void Run()
    {
        vector<int> cont = { 0, 0, 3 };
        cout << fraction(cont);
    }
};

#endif