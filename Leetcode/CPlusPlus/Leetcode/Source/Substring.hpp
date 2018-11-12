#pragma once

#include "Solution.h"

class LongestSubstring : public Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> subSet(0xFF, -1);

        int longestLength = 0;
        int start = 0;
        int end = start + 1;
        subSet[(int)s[start]] = 0;

        while (start < s.length())
        {
            while (end < s.length() && subSet[(int)s[end]] == -1)
            {
                subSet[(int)s[end]] = end;
                end++;
            }

            if (longestLength < end - start)
            {
                longestLength = end - start;
            }

            if (end == s.length())
            {
                break;
            }
            else
            {
                for (auto j = start; j < subSet[(int)s[end]]; j++)
                {
                    subSet[(int)s[j]] = -1;
                }

                start = subSet[(int)s[end]] + 1;
                subSet[(int)s[end]] = end;
                end++;
            }
        }

        return longestLength;
    }

    virtual void Test()
    {
        /*string str1 = "abcabcbb";
        cout << str1 << endl << lengthOfLongestSubstring(str1) << endl << endl;*/

        string str2 = "dvdf";
        cout << str2 << endl << lengthOfLongestSubstring(str2) << endl << endl;

        /*string str3 = "pwwkew";
        cout << str3 << endl << lengthOfLongestSubstring(str3) << endl << endl;*/
    }
};