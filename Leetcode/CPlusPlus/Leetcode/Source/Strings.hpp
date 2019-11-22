#ifndef _STRINGS_HPP_
#define _STRINGS_HPP_

#include "Solution.h"

/* #438
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.
https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
*/
class FindAnagrams : public Solution
{
public:
    vector<int> findAnagrams(string s, string p) {
        const int lowerLetters = 26;
        auto slen = (int)s.size();
        auto plen = (int)p.size();

        vector<int> res;
        if (plen > slen)
        {
            return res;
        }

        vector<short> target(lowerLetters, 0);
        for (int i = 0; i < plen; i++)
        {
            target[(int)p[i] - 'a']++;
        }

        vector<short> stats(lowerLetters, 0);
        for (int i = 0; i < plen; i++)
        {
            stats[(int)(s[i] - 'a')]++;
        }

        for (int i = 0; i <= slen - plen; i++)
        {
            auto j = 0;
            do
            {
                if (stats[j] != target[j])
                {
                    break;
                }
            } while (++j < lowerLetters);

            if (j == lowerLetters)
            {
                res.push_back(i);
            }

            stats[(int)(s[i] - 'a')]--;

            if (i != slen - plen)
            {
                stats[(int)(s[i + plen] - 'a')]++;
            }
        }

        return res;
    }

    virtual void Run()
    {
        string s = "abab";
        string p = "ab";

        cout << findAnagrams(s, p);
    }
};

/* #537
Given two strings representing two complex numbers.
You need to return a string representing their multiplication.Note i2 = -1 according to the definition.
https ://leetcode-cn.com/problems/complex-number-multiplication
*/
class ComplexNumberMultiply : public Solution
{
public:
    string complexNumberMultiply(string a, string b) {
        int t1 = a.find('+');
        int t2 = b.find('+');
        int _a = std::stoi(a.substr(0, t1));
        int _b = std::stoi(b.substr(0, t2));
        int a_ = std::stoi(a.substr(t1 + 1, a.find('i') - t1));
        int b_ = std::stoi(b.substr(t2 + 1, b.find('i') - t2));
        int _ab = _a * _b - a_ * b_;
        int ab_ = _a * b_ + _b * a_;
        return std::string(std::to_string(_ab) + "+" + std::to_string(ab_) + "i");
    }

    virtual void Run()
    {
        string a = "1+-1i";
        string b = "1+-1i";
        cout << complexNumberMultiply(a, b) << endl;
    }
};

#endif