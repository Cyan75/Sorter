#include "TwoDVector.hpp"
#include <iostream>
using namespace MyNamespace;

TwoDVector::TwoDVector() : x(0), y(0)
{
    std::cin >> x;
}
void TwoDVector::printThis()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
