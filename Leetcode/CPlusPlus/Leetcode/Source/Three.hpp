#ifndef _THREE_HPP_
#define _THREE_HPP_

#include "Solution.h"

/* #288
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
https://leetcode-cn.com/problems/ugly-number
*/
class IsUgly : public Solution
{
public:
    bool isUgly(int num) {
        while (num > 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else if (num % 3 == 0)
            {
                num /= 3;
            }
            else if (num % 5 == 0)
            {
                num /= 5;
            }
            else
            {
                return false;
            }
        }

        return num == 1;
    }

    virtual void Run()
    {
        cout << isUgly(14) << endl;
    }
};

#endif