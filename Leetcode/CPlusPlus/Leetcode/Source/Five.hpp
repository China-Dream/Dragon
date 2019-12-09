#ifndef _FIVE_HPP_
#define _THREE_HPP_

#include "Solution.h"

/* #429
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
*/
class LevelOrder : public Solution{
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };

public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> data;
        if (root == nullptr)
        {
            return data;
        }

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> v;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            if (p != nullptr)
            {
                v.push_back(p->val);

                for (auto it = p->children.cbegin(); it != p->children.cend(); it++)
                {
                    q.push(*it);
                }
            }
            else
            {
                if (!q.empty())
                {
                    q.push(nullptr);
                }

                data.push_back(v);
                v.clear();
            }
        }

        return data;
    }

    virtual void Run()
    {

    }
};

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

/* #497
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:
An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.

https://leetcode-cn.com/problems/random-point-in-non-overlapping-rectangles
*/
class RandomPointInRects {
public:
    vector<vector<int>> rects;
    vector<int> psum;
    int tot = 0;
    //c++11 random integer generation
    mt19937 rng{ random_device{}() };
    uniform_int_distribution<int> uni;

    RandomPointInRects(vector<vector<int>>& rects) 
    {
        this->rects = rects;
        for (auto& x : rects) {
            tot += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int>{0, tot - 1};
    }

    vector<int> pick() {
        int targ = uni(rng);

        int lo = 0;
        int hi = rects.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid]) lo = mid + 1;
            else hi = mid;
        }

        auto& x = rects[lo];
        int width = x[2] - x[0] + 1;
        int height = x[3] - x[1] + 1;
        int base = psum[lo] - width * height;
        return{ x[0] + (targ - base) % width, x[1] + (targ - base) / width };
    }

    RandomPointInRects()
    {

    }

    virtual void Run()
    {

    }
};

#endif