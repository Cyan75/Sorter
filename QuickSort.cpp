#include <iostream>
#include <vector>
#include <iterator>
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
        dataArray = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        /*
        TODO:
        */

        partition();
        print();
    }
    void partition() //lower bound, upper bound
    {
        //vector
        short lowerBound = 0;
        short upperBound = this->dataArray.size();
        short pivotIndexValue = 5; //get pivot index(between lower bound and upper bound)

        std::vector<short>::iterator pivot = dataArray.begin();
        advance(pivot, pivotIndexValue - 1);

        std::cout << "begin : " << *dataArray.begin() << std::endl;
        //std::cout << "end : " << *dataArray.end() << std::endl;//0
        std::cout << "pivot : " << *pivot << std::endl;
        std::cout << "dataArray size: " << dataArray.size() << std::endl;

        std::vector<short> leftV(dataArray.begin(), pivot);
        std::cout << "leftV before part : ";
        for (auto i : leftV)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;

        std::vector<short> rightV(pivot + 1, dataArray.end());
        std::cout << "rightV before part : ";
        for (auto i : rightV)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;

        //partition---------------------------------------------------
        //this->dataArray.clear();
        if (!leftV.empty())
        {
            std::vector<short>::iterator iL = leftV.begin();
            for (auto i : leftV)
            {
                std::cout << "*iL = " << *iL << std::endl;
                if (*iL > *pivot)
                {
                    rightV.push_back(*iL);
                    leftV.erase(iL);
                }
                else
                {
                    ++iL;
                }
            }
        }
        else
        {
            std::cout << "leftV is empty : " << std::endl;
        }
        if (!rightV.empty())
        {
            std::vector<short>::iterator iR = rightV.begin();
            for (auto i : rightV)
            {
                std::cout << "*iR = " << *iR << std::endl;
                if (*iR < *pivot)
                {
                    leftV.push_back(*iR);
                    rightV.erase(iR);
                }
                else
                {
                    ++iR;
                }
            }
        }
        else
        {
            std::cout << "rightV is empty " << std::endl;
        }
        std::cout << "leftV after part : ";
        for (auto i : leftV)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
        std::cout << "rightV after part : ";
        for (auto i : rightV)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;

        /* this->dataArray = leftV;
        this->dataArray.push_back(pivotValue);
        this->dataArray.insert(dataArray.end(), rightV.begin(), rightV.end());
 */
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