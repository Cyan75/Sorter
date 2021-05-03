#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <time.h>
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
    }
};
int main(void)
{
    //QuickSort q;
    return 1;
}