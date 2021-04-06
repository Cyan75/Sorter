#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<vector>
#include<string>

class QuickSort
{
private:
    std::vector<short> vec;
    std::vector<short>::iterator itP;
    unsigned short sizeOfVec;
    unsigned short pivotCandNum;
    void setPivotCandNum(short pivotCandNum);
    short randNumGen(void);
    short getPivotIndex(void);
    void partition(std::vector<short> vec);

public:
    QuickSort(std::string fileName);
    virtual bool letItBe(short a, short b);
    void sort(void);
    
};

#endif QUICKSORT_H