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

class QuickSortAlgorithm
{
public:
    QuickSortAlgorithm(std::string fileName)
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
        std::vector<short> candidates;
        for (short index = 0; index < pivotCandNum; ++index)
        {
            short *random = new short;
            *random = ranNumGen();
            candidates.push_back(*random);
            delete random;
        }
        /*
        choose the random()-th element
        random is 
        */
        return *(candidates.begin() + ranNumGen());
    }
    void partition(std::vector<short> vec)
    {
        std::vector<short>::iterator iP = vec.begin() + getPivotIndex();
        std::vector<short> vecL(vec.begin(), iP - 1);
        //std::vector<short>::iterator iL = vecL.begin();
        std::vector<short> vecR(iP + 1, vec.end() - 1);
        //std::vector<short>::iterator iR = vecR.begin();
        std::vector<short> *leftBuffer = new std::vector<short>;
        for (std::vector<short>::iterator iL = vecL.begin(); iL != vecL.end(); ++iL)
        {
            if (!letItBe(*iL, *iP))
            {
                leftBuffer->push_back(*iL);
                vecL.erase(iL);
            }
        }
        for (std::vector<short>::iterator iR = vecL.begin(); iR != vecL.end(); ++iR)
        {
            if (!letItBe(*iP, *iR))
            {
                vecL.push_back(*iR);
                vecR.erase(iR);
                vecR.insert(vecR.end(), leftBuffer->begin(), leftBuffer->end());
            }
        }
        delete leftBuffer;
        this->vec.empty();
        this->vec = vecL;
        this->vec.push_back(*iP);
        this->vec.insert(this->vec.end(), vecR.begin(), vecR.end());
        partition(vecL);
        partition(vecR);
    }
    void sort(void)
    {
        partition(this->vec);
        //iteration regulator needed
    }
};