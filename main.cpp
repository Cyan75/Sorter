#include <iostream>
#include <vector>
#include <iterator>
//using namespace MyNamespace;
int main(void)
{
    std::vector<short> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<short>::iterator i = vec.begin() + 3;
    std::cout << *i << std::endl;
    vec.erase(i);
    std::cout << *i << std::endl;

    return 0;
}
