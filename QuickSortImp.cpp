#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>
//#include "QuickSort.h"
/*
    MODULISATION PLAN
    √• reader(constructor) : reads vector of shorts
    √• maxNumCounter : gets the size of any (sub-)vector
    √• pivotCandidate Number setter :  sets the number of potential elements one of which will be a pivot.
    √• RNG : random number generator
    ∆• swapSwitch(virtual): determines wheater the two elements which are being investigated should be changed
    x• pivot selector : picks   e some (one?,three?) elements randomly and set the most neutral value as the pivot
    x• sorter(main?) : while the size of the all the remant vector is one.

    ¡¡¡¡¡¡ As the base class has the most generic form of the hierarchy, it has to available for any vector of any type!!!!!!
*/

class QuickSort
{
public:
    QuickSort(std::string &fileName)
    {
        pivotCandNum = 1; //the number of candidates one of them can be the pivot
        itP = vec.begin() + getPivotIndex();
        std::ifstream unsorted(fileName);
        if (unsorted.is_open())
        {
            std::string line;
            while (std::getline(unsorted, line))
            {
                vec.push_back(stoi(line));
            }
            unsorted.close();
            //sizeOfVec is the number of elments of the file
            sort();
            printVec(this->vec);
        }
        else
        {
            std::cout << "¡Oops!" << std::endl;
        }
    }
    virtual bool letItBe(short a, short b)
    {
        /** this is the part that specifies a rule for sort using pivot **/
        if (a < b)
        {
            return true;
        }
        else //a>=b?
        {
            return false;
        }
    }
    void sort(void)
    {
        partition(this->vec);
    }

private:
    std::vector<short> vec;
    std::vector<short>::iterator itP;
    unsigned short pivotCandNum;

    void setPivotCandNum(short &pivotCandNum)
    {
        this->pivotCandNum = pivotCandNum;
    }

    unsigned short randNumGen(void)
    {
        std::srand(std::time(nullptr));
        return std::rand();
    }
    /*
    • pivot candidates are randomly selected
    */
    unsigned short getPivotIndex(void)
    {
        std::vector<short> candidatesIndices;
        short theNumOfCandidates = (randNumGen() % (this->pivotCandNum));
        setPivotCandNum(theNumOfCandidates);
        for (short index = 0; index < this->pivotCandNum; ++index)
        {
            short *random = new short;
            *random = randNumGen();
            candidatesIndices.push_back(*random);
            delete random;
        }
        /*
        choose the random()-th element
        random is 
        */
        return *(candidatesIndices.begin() + randNumGen());
    }
    void partition(std::vector<short> &vec)
    {
        bool endPartitioning = false;
        if (!endPartitioning)
        {
            std::vector<short>::iterator iP = vec.begin() + getPivotIndex();
            std::vector<short> vecL(vec.begin(), iP - 1);
            std::vector<short> vecR(iP + 1, vec.end() - 1);
            std::vector<short> *leftBuffer = new std::vector<short>;
            //short leftMinSize;
            //short rightMinSize;
            if (!vecL.empty())
            {
                /*
            //left-half partition option1   
            for (std::vector<short>::iterator iL = vecL.begin(); iL != vecL.end(); ++iL)
            {
                if (!letItBe(*iL, *iP))
                {
                    leftBuffer->push_back(*iL);
                    vecL.erase(iL);
                }
            }
            */
                //left-half partition option2
                std::vector<short>::iterator iL = vecL.begin();
                do
                {
                    if (!letItBe(*iL, *iP))
                    {
                        leftBuffer->push_back(*iL);
                        vecL.erase(iL);
                    }
                    ++iL;
                } while (iL != vecL.end());
            }
            else
            {
                if (vecL.empty())
                {
                    endPartitioning = true;
                }
            }
            if (!vecR.empty())
            {
                /*
        //right-half partition option1
        for (std::vector<short>::iterator iR = vecR.begin(); iR != vecR.end(); ++iR)
        {
            if (!letItBe(*iP, *iR))
            {
                vecL.push_back(*iR);
                vecR.erase(iR);
                vecR.insert(vecR.end(), leftBuffer->begin(), leftBuffer->end());
            }
        }
        */
                //right-half partition option2
                std::vector<short>::iterator iR = vecR.begin();
                do
                {
                    if (!letItBe(*iP, *iR))
                    {
                        vecL.push_back(*iR);
                        vecR.erase(iR);
                        vecR.insert(vecR.end(), leftBuffer->begin(), leftBuffer->end());
                        leftBuffer->clear();
                    }
                    --iR;
                } while (iR != vecR.end());
            }
            delete leftBuffer;
            this->vec.clear();
            this->vec = vecL;
            this->vec.push_back(*iP);
            this->vec.insert(this->vec.end(), vecR.begin(), vecR.end());
            partition(vecL);
            partition(vecR);
        }
    }
    void printVec(std::vector<short> &vec)
    {
        for (auto it : vec)
        {
            std::cout << it << std::endl;
        }
    }
};
int main(void)
{
    //QuickSort *sortNumbers = new QuickSort("numbers.txt");
    //elete sortNumbers;
    std::string file = "numbers.txt";
    QuickSort sorter(file);
}