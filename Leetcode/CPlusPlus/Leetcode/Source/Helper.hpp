#pragma once

#include <vector>

using namespace std;

template<typename T>
void Swap(vector<T>& vec, int ind1, int ind2)
{
    T bp = vec[ind1];
    vec[ind1] = vec[ind2];
    vec[ind2] = bp;
}

template<typename T>
int Partition(vector<T>& vec, int start, int tail)
{
    if (start >= tail)
    {
        return start;
    }

    auto low = start + 1;
    auto high = tail;
    while (low <= high)
    {
        while (low <= high && vec[low] <= vec[start])
        {
            low++;
        }

        while (high > start && vec[high] >= vec[start])
        {
            high--;
        }

        if (low < high)
        {
            Swap(vec, low, high);
        }
    }

    Swap(vec, start, low - 1);

    return low - 1;
}

template<typename T>
void QuickSort(vector<T>& vec, int start, int tail)
{
    if (start >= tail)
    {
        return;
    }

    auto ind = Partition(vec, start, tail);
    QuickSort(vec, start, ind - 1);
    QuickSort(vec, ind + 1, tail);
}
