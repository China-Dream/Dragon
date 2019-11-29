#ifndef _FIVE_HPP_
#define _THREE_HPP_

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

/* #455
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.
https://leetcode-cn.com/problems/assign-cookies
*/
class FindContentChildren : public Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        auto content = 0;
        auto lenG = (int)g.size();
        auto lenS = (int)s.size();
        int i = 0, j = 0;
        while (i < lenG && j < lenS)
        {
            if (g[i] <= s[j])
            {
                content++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return content;
    }

    virtual void Run()
    {
        vector<int> g = { 1, 2 };
        vector<int> s = { 1, 2, 3 };
        cout << findContentChildren(g, s) << endl;
    }
};

#endif