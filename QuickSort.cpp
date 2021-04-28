#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <time.h>
#include <utility>
#include <algorithm>

class QuickSort
{
private:
    std::vector<short> dataArray;
    void print(std::vector<short> &vec)
    {
        for (auto i : vec)
        {
            std::cout << i << ", ";
        }
    }
    /*
    make and return the vector consists of levf + pivot + right
    */
    std::vector<short> reAssociate(std::vector<short> &leftV, short pivot, std::vector<short> &rightV)
    {
        //this->dataArray.clear();
        std::vector<short> vec;
        vec.insert(vec.end(), leftV.begin(), leftV.end());
        vec.push_back(pivot);
        vec.insert(vec.end(), rightV.begin(), rightV.end());
        return vec;
    }
    std::vector<short> makeUnitVector(short l, short p, short r)
    {
        std::vector<short> uVec;
        uVec.push_back(l);
        uVec.push_back(p);
        uVec.push_back(r);
        return uVec;
    }

public:
    QuickSort()
    {
        dataArray = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        /*
        TODO:
        */

        partition(dataArray);
        print(dataArray);
    }

    void partition(std::vector<short> &vec)
    {
        short lowerBound = 0;
        short upperBound = vec.size();
        short pivotIndexValue = upperBound / 2; //get pivot index(between lower bound and upper bound)

        std::vector<short>::iterator pivot = vec.begin();
        advance(pivot, pivotIndexValue - 1);

        //std::cout << "begin : " << *dataArray.begin() << std::endl;
        //std::cout << "end : " << *dataArray.end() << std::endl;//0
        std::cout << "pivot : " << *pivot << std::endl;
        //std::cout << "dataArray size: " << dataArray.size() << std::endl;

        std::vector<short> leftV(vec.begin(), pivot);
        std::vector<short> rightV(pivot + 1, vec.end());

        if (!leftV.empty())
        {
            std::vector<short>::iterator iL = leftV.begin();
            for (auto i : leftV)
            {
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
            std::cout << "leftV is empty!" << std::endl;
        }
        if (!rightV.empty())
        {
            std::vector<short>::iterator iR = rightV.begin();
            for (auto i : rightV)
            {
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
            std::cout << "rightV is empty" << std::endl;
        }

        //iteration regulation
        short l;
        short r;
        if (leftV.size() > 1 && rightV.size() > 1)
        {
            partition(leftV);
            partition(rightV);
        }
        else if (leftV.size() > 1 && !rightV.size() > 1)
        {
            partition(leftV);
            r = *rightV.begin();
        }
        else if (!leftV.size() > 1 && rightV.size() > 1)
        {
            l = *leftV.begin();
            partition(rightV);
        }
        else
        {
            makeUnitVector(l, *pivot, r);
        }
        vec.clear();
        vec = reAssociate(leftV, *pivot, rightV);
    }
};
int main(void)
{
    QuickSort q;
    return 1;
}