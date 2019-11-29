#ifndef _EIGHT_HPP_
#define _EIGHT_HPP_

#include "Solution.h"

/* #718
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

https ://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
*/
class FindLength : public Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        auto lenA = (int)A.size();
        auto lenB = (int)B.size();
        vector<vector<int>> stats(lenA + 1, vector<int>(lenB + 1, 0));

        int maxMutual = 0;
        for (int i = 1; i <= lenA; i++)
        {
            for (int j = 1; j <= lenB; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    stats[i][j] = stats[i - 1][j - 1] + 1;
                }
                else
                {
                    stats[i][j] = 0;
                }

                if (stats[i][j] > maxMutual)    maxMutual = stats[i][j];
            }
        }

        return maxMutual;
    }

    virtual void Run()
    {
        vector<int> A = { 0, 1, 1, 1, 1 };
        vector<int> B = { 1, 0, 1, 0, 1 };
        cout << findLength(A, B) << endl;
    }
};

#endif