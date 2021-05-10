#include "QuickSort.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <random>
template <typename T>

void qs::QuickSort::print(std::vector<T> &vec)
{
    for (auto i : vec)
    {
        std::cout << i << ", ";
    }
}
/*
    generate a random number between lower and upeer
    */
short qs::QuickSort::rng(short lower, short upper)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<T> random(lower, upper);
    return random(mt);
}

qs::QuickSort::QuickSort()
{
    dataArray = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(dataArray, 0, dataArray.size() - 1);
    print(dataArray);
}

void qs::sort(std::vector<T> &vec, const short &lower, const short &upper)
{
    if (upper <= lower)
    {
        return;
    }
    short left = lower + 1;
    short right = upper;
    //?
    std::swap(vec[lower], vec[rng(lower, upper)]);
    //pivot is vec[rng(lower, upper)]
    short pivot = lower;
    bool focusedOnRignt = true;
    do
    {
        if (focusedOnRignt)
        {
            if (vec[pivot] >= vec[right])
            {
                std::swap(vec[pivot], vec[right]);
                pivot = right;
                focusedOnRignt = !focusedOnRignt;
            }
            --right;
        }
        else
        {
            if (vec[pivot] <= vec[left])
            {
                std::swap(vec[pivot], vec[left]);
                pivot = left;
                focusedOnRignt = !focusedOnRignt;
            }
            ++left;
        }
    } while (right >= left);
    sort(vec, lower, pivot - 1);
    sort(vec, pivot + 1, upper);
}
