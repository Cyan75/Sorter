//#include "TwoDVector.h"
#include <iostream>
class TwoDVector
{
private:
    short x, y;

public:
    TwoDVector(short dftX = 0, short dftY = 0)
    {
        x = dftX;
        y = dftY;
    }
    TwoDVector operator + (TwoDVector const &vec1)
    {
        TwoDVector vec;
        vec.x = x + vec1.x;
        vec.y = y + vec1.y;
        return vec;
    }
    void cout()
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};
int main(void)
{
    TwoDVector v1(2, 4);
    TwoDVector v2(1, 1);
    TwoDVector v3 = v1 + v2;
    v3.cout();
    return 0;
}