#include <iostream>
#include "node.h"

int main()
{
    node<int> a = node<int>(3);
    node<int> b = node<int>(4);

    std::cout << (b > a) << '\n';

    std::cout << a << " " << b << '\n';

    return 0;
}
