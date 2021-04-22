#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class QuickSort
{
private:
    std::vector<short> dataArray;
    void print(void)
    {
        for (auto i : dataArray)
        {
            std::cout << i << ", ";
        }
    }

public:
    QuickSort()
    {
        dataArray = {5, 4, 3, 2, 1};
        /*
        TODO:
        */
        print();
    }
    /* 
    passing information about the previous index and returns 
    */
    short partition(short &previousPivotIndex)
    {
        /*
            TODO : set pivot index
            */
        short pivotIndex = 2;
        std::vector<short> leftV(vec.begin(), vec.begin() + pivotIndex - 1);
        std::vector<short> rightV(vec.begin() + pivotIndex + 1, vec.end());
        if (!leftV.empty())
        {
            for (auto iL : leftV)
            {
                if (iL > vec[pivotIndex])
                {
                    rightV.push_back(iL);
                    leftV.erase(leftV.begin() + iL);
                }
            }
        }
        if (!rightV.empty())
        {

            for (auto iR : rightV)
            {
                if (iR < vec[pivotIndex])
                {
                    leftV.push_back(iR);
                    rightV.erase(rightV.begin() + iR);
                }
            }
        }
    }
};
int main(void)
{
    QuickSort q;
    return 1;
}