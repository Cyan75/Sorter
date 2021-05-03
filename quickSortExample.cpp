/* 
    AS SUCCINT AS POSSIBBLE
 */
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());

template <typename T>
void quickSort(vector<T> &vec, const int &left, const int &right)
{
    if (right <= left)
    {
        return;
    }
    //rignt > left
    uniform_int_distribution<int> randInt(left, right);
    int leftArrow = left + 1;
    int rightArrow = right;
    swap(vec[left], vec[randInt(mt)]);
    int current = left;
    bool focusedOnRight = true;
    do
    {
        if (focusedOnRight)
        {
            if (vec[current] >= vec[rightArrow])
            {
                swap(vec[current], vec[rightArrow]);
                current = rightArrow;
                focusedOnRight = !focusedOnRight;
            }
            --rightArrow;
        }
        else
        {
            if (vec[current] <= vec[leftArrow])
            {
                swap(vec[current], vec[leftArrow]);
                current = leftArrow;
                focusedOnRight = !focusedOnRight;
            }
            ++leftArrow;
        }
    } while (rightArrow >= leftArrow);
    quickSort(vec, left, current - 1);
    quickSort(vec, current + 1, right);
}
