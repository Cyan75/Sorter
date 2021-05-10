#ifndef TWODVECTOR_H
#define TWODVECTOR_H
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <random>

namespace MyNamespace
{
    class TwoDVector
    {
    public:
        short x;
        short y;
        TwoDVector();
        void printThis();
    };
}

#endif //TWODVECTOR_H