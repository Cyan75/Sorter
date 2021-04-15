#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>
#include "TwoDVector.hpp"
int main(void)
{
    TwoDVector v1(2, 4);
    //TwoDVector v2(-1, -1);
    //TwoDVector v3 = v1 + v2;
    v1.cout();
    v1.printThis();
    return 0;
}