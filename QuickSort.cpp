#include <iostream>
#include <vector>
#include <string>
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
    std::pair<short, short> partition(std::pair<short, short> partRange) //lower bound, upper bound
    {

        short &lowerBound = std::get<0>(partRange);
        short &upperBound = std::get<1>(partRange);
        short pivotIndex = 2; //get pivot index(between lower bound and upper bound)
        std::vector<short> leftV(dataArray.begin() + lowerBound, dataArray.begin() + pivotIndex - 1);
        std::vector<short> rightV(dataArray.begin() + pivotIndex + 1, dataArray.begin() + upperBound);

        if (!leftV.empty())
        {
            for (auto iL : leftV)
            {
                if (iL > dataArray[pivotIndex])
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
                if (iR < dataArray[pivotIndex])
                {
                    leftV.push_back(iR);
                    rightV.erase(rightV.begin() + iR);
                }
            }
        }
        partition(std::make_pair(lowerBound + 1, pivotIndex - 1));
        partition(return std::make_pair(pivotIndex + 1, upperBound - 1));
    }
    //or
    /* 
    passing information about the indexes of begining, dividing, and ending point in the previous partitioning
    */
    std::tuple<short, short, short>
    partition(std::tuple<short, short, short> idxBeginPivotEnd)
    {
        /*
            TODO : set pivot index
        */
        //short pivotIndex = std::get<1>(beginPivotEnd);
        //vector::end()  is past-the-end iterator
        std::vector<short> leftV(dataArray.begin() + std::get<0>(idxBeginPivotEnd), dataArray.begin() + std::get<1>(idxBeginPivotEnd) - 1);
        std::vector<short> rightV(dataArray.begin() + std::get<1>(idxBeginPivotEnd) + 1, dataArray.begin() + std::get<2>(idxBeginPivotEnd));
        if (!leftV.empty())
        {
            for (auto iL : leftV)
            {
                if (iL > dataArray[std::get<1>(idxBeginPivotEnd)])
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
                if (iR < dataArray[std::get<1>(idxBeginPivotEnd)])
                {
                    leftV.push_back(iR);
                    rightV.erase(rightV.begin() + iR);
                }
            }
        }
        /*
        short beg = 
        short end = 
        return std::maketuple(beg, pivot, end);
        */
    }
};
int main(void)
{
    QuickSort q;
    return 1;
}