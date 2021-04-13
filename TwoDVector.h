#ifndef TWODVECTOR_H
#define TWODVECTOR_H
#include <iostream>
class TwoDVector
{
private:
    short x, y;

public:
    TwoDVector(short dftX, short dftY) : x(dftX), y(dftY){};
    ~TwoDVector();
};

#endif //TWODVECTOR_H