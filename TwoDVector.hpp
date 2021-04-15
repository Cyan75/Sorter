#ifndef TWODVECTOR_H
#define TWODVECTOR_H
class TwoDVector
{
public:
    short x, y;
    TwoDVector(short dftX, short dftY);
    TwoDVector operator+(TwoDVector const &vec1);
    void printThis();
    void cout();
};
#endif //TWODVECTOR_H