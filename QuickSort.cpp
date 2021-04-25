#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <utility>

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

        partition(std::make_pair(0, dataArray.size()));
        print();
    }
    void partition(std::pair<short, short> partRange) //lower bound, upper bound
    {
        short lowerBound = std::get<0>(partRange);
        short upperBound = std::get<1>(partRange);
        short pivotIndex = 2; //get pivot index(between lower bound and upper bound)
        short pivotValue = dataArray[pivotIndex];
        std::vector<short> leftV(dataArray.begin() + lowerBound, dataArray.begin() + pivotIndex - 1);
        std::vector<short> rightV(dataArray.begin() + pivotIndex + 1, dataArray.begin() + upperBound);
        dataArray.clear();
        if (!leftV.empty())
        {
            for (auto iL : leftV)
            {
                if (iL > pivotValue)
                {
                    rightV.push_back(iL);
                    leftV.erase(leftV.begin() + iL);
                }
            }
        }

        if (!leftV.empty())
        {
            for (auto iR : rightV)
            {
                if (iR < pivotValue)
                {
                    leftV.push_back(iR);
                    rightV.erase(rightV.begin() + iR);
                }
            }
        }
        dataArray = leftV;
        dataArray.push_back(pivotValue);
        dataArray.insert(dataArray.end(), rightV.begin(), rightV.end());

        //partition(std::make_pair(lowerBound + 1, pivotIndex - 1));
        //partition(std::make_pair(pivotIndex + 1, upperBound - 1));
    }
    //or
    /* 
    passing information about the indexes of begining, dividing, and ending point in the previous partitioning
    */
};
int main(void)
{
    QuickSort q;
    return 1;
}