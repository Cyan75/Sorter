#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <ctime>
#include <utility>
#include <algorithm>
template <typename T>
class QuickSort
{
private:
    std::vector<T> dataArray;
    void print(std::vector<T> &vec)
    {
        for (auto i : vec)
        {
            std::cout << i << ", ";
        }
    }
    short rng(short &lower, short &upper)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> random(lower, upper);
        return random(mt);
    }

public:
    QuickSort()
    {
        dataArray = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        /*
        TODO:
        */
        print(dataArray);
    }

    void sort(std::vector<T> &vec, const short &lower, const short &upper)
    {
        if (upper <= lower)
        {
            return;
        }
        else // upper > lower
        {
            short left = lower + 1;
            short right = upper;
            std::swap(vec[lower], vec[rng(lower, upper)]);
            short current = lower;
            bool focusedOnRignt = true;
            do
            {
                if (focusedOnRignt)
                {
                    /* code */
                }
            }
        }
    }
};
int main(void)
{
    //QuickSort q;
    return 1;
}