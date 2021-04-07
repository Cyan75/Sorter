#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

#include "QuickSort.h"
int main(void)
{
    QuickSort *sortNumbers = new QuickSort("numbers.txt");
    delete sortNumbers;
}