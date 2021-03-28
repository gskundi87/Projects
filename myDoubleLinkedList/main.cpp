#include <iostream>
#include "myDoubleLinkedList.h"

int main()
{
    node<int> a = node<int>(3);
    node<int> b = node<int>(4);

    std::cout << (b > a) << '\n';

    std::cout << a << " " << b << '\n';

    myDoubleLinkedList<int> A = myDoubleLinkedList<int>(0);

    for (int i = 1; i < 10; ++i)
    {
        A.push_front(i);
    }

    std::cout << A;

    std::cout << '\n';


    myDoubleLinkedList<int> B = myDoubleLinkedList<int>(9);

    for (int i = 8; i >= 0; --i)
    {
        B.push_back(i);
    }

    std::cout << B;

    std::cout << '\n';

    for (int i = 4; i >= 0; --i)
    {
        B.pop_back();
    }

    std::cout << B;

    std::cout << '\n';

    myDoubleLinkedList<int>::iterator itr1 = B.begin();

    myDoubleLinkedList<int>::iterator itr2 = A.end();

    std::cout << *itr1 << '\n';

    std::cout << *itr2 << '\n';

    itr1++;

    --itr2;

    std::cout << *itr1 << '\n';

    std::cout << *itr2 << '\n';

    return 0;
}
