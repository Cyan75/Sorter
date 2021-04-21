#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class QuickSort
{
private:
    short pivotIndex;
    std::vector<short> dataArray;

public:
    QuickSort()
    {
        pivotIndex = 2;
        dataArray = {5, 4, 3, 2, 1};
    }
    void partition(std::vector<short> &vec)
    {
        while (vec.size() > 1)
        {
            std::vector<short> leftV(vec.begin(), vec.begin() + pivotIndex - 1);
            std::vector<short> rightV(vec.begin() + pivotIndex + 1, vec.end());
            std::vector<short> buffer;
            for (short i = 0; i < pivotIndex; ++i)
            {
                if (vec[i] > vec[pivotIndex])
                {
                }
            }
            partition(vec);
        }
    }
};