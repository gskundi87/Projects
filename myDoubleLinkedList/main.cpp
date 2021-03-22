#include <iostream>
#include "node.h"

int main()
{
    node<int> a = node<int>(3);
    node<int> b = node<int>(4);

    std::cout << (b > a) << '\n';

    return 0;
}
