#include "TwoDVector.hpp"
#include <iostream>
TwoDVector::TwoDVector(short dftX, short dftY) : x(dftX), y(dftY) {};
TwoDVector::TwoDVector operator+(TwoDVector const &vec1)
{
    TwoDVector vec(0,0);
    vec.x = x + vec1.x;
    vec.y = y + vec1.y;
    return vec;
}
void TwoDVector::printThis()
{
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}
void TwoDVector::cout()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
