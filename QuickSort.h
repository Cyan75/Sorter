#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
/* #include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <random>
 */
namespace qs
{
    template <typename T>
    class QuickSort
    {
    private:
        std::vector<T> dataArray;
        short rng(short lower, short upper);
        void print(std::vector<T> &vec);

    public:
        QuickSort();
        void sort(std::vector<T> &vec, const short &lower, const short &upper);
    };
}
#endif //QUICKSORT_HPP