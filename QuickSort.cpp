#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>
/*
    MODULISATION PLAN
    √• reader(constructor) : reads vector of shorts
    √• maxNumCounter : gets the size of any (sub-)vector
    √• pivotCandidate Number setter :  sets the number of potential elements one of which will be a pivot.
    √• RNG : random number generator
    ∆• swapSwitch(virtual): determines wheater the two elements which are being investigated should be changed
    x• pivot selector : picks some (one?,three?) elements randomly and set the most neutral value as the pivot
    x• sorter(main?) : while the size of the all the remant vector is one.

    ¡¡¡¡¡¡ As the base class has the most generic form of the hierarchy, it has to available for any vector of any type!!!!!!
*/

class QuickSort
{
public:
    QuickSort(std::string fileName)
    {
        sizeOfVec = 0;
        pivotCandNum = 1; //the number of candidates one of them can be the pivot
        itP = vec.begin() + getPivotIndex();
        std::ifstream unsorted(fileName);
        if (unsorted.is_open())
        {
            std::string line;
            while (std::getline(unsorted, line))
            {
                vec.push_back(stoi(line));
                sizeOfVec++;
            }
            unsorted.close();
            //sizeOfVec is the number of elments of the file
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

private:
    std::vector<short> vec;
    std::vector<short>::iterator itP;
    unsigned short sizeOfVec;
    unsigned short pivotCandNum;

    void setPivotCandNum(short pivotCandNum)
    {
        this->pivotCandNum = pivotCandNum;
    }

    short ranNumGen(void)
    {
        std::srand(std::time(nullptr));
        if (std::rand() < 0)
        {
            return ((-std::rand()) % pivotCandNum);
        }
        else
        {
            return ((std::rand()) % pivotCandNum);
        }
    }
    /*
    • pivot candidates are randomly selected
    */
    short getPivotIndex(void)
    {
        std::vector<short> candidatesIndices;
        for (short index = 0; index < pivotCandNum; ++index)
        {
            short *random = new short;
            *random = ranNumGen();
            candidatesIndices.push_back(*random);
            delete random;
        }
        /*
        choose the random()-th element
        random is 
        */
        return *(candidatesIndices.begin() + ranNumGen());
    }
    void partition(std::vector<short> vec)
    {

        /* code */

        std::vector<short>::iterator iP = vec.begin() + getPivotIndex();
        std::vector<short> vecL(vec.begin(), iP - 1);
        std::vector<short> vecR(iP + 1, vec.end() - 1);
        if (!vecL.empty() && !vecR.empty())
        {

            std::vector<short> *leftBuffer = new std::vector<short>;
            //short leftMinSize;
            //hort rightMinSize;
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

            delete leftBuffer;
            this->vec.clear();
            this->vec = vecL;
            this->vec.push_back(*iP);
            this->vec.insert(this->vec.end(), vecR.begin(), vecR.end());
            partition(vecL);
            partition(vecR);
        }
        else //either or both vecL, vecR is/are empty
        {
        }
    }
    void sort(void)
    {
        partition(this->vec);
        //iteration regulator needed
    }
};