#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    virtual void Run() = 0;
};

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& vec)
{
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
    {
        out << *it << endl;
    }

    return out;
}

#endif