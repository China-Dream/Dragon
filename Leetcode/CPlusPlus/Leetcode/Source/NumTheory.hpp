#pragma once

#include "Solution.h"

/*
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

/* #69
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non - negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
https://leetcode-cn.com/problems/sqrtx
*/
class MySqrt : public Solution
{
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int res = 0;
        while (low <= high)
        {
            auto mid = low + (high - low) / 2;
            double t = (double)x / mid;

            if (abs(t - mid) < DBL_EPSILON && mid * mid == x)
            {
                return mid;
            }
            else if (t > mid)
            { 
                low = mid + 1;
                res = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return res;
    }

    virtual void Run()
    {
        cout << mySqrt(9) << endl;
    }
};

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