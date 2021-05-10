#include "TwoDVector.hpp"
#include <iostream>
//using namespace MyNamespace;

MyNamespace::TwoDVector::TwoDVector() : x(0), y(0)
{
    std::cin >> x;
    std::cin >> y;
    MyNamespace::TwoDVector::printThis();
}
void MyNamespace::TwoDVector::printThis()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
