#include <iostream>
#include <cstdlib>
#include <time.h>
#include "bst.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int x;


    bst<int> a, c;

    for(int i = 0; i < 50; ++i)
    {
        x = rand() % 50;
        a.insert(x);
        cout << x << " ";
    }

    cout << '\n';

    a.print(a._root(), cout);
    cout << "a nodecount: " << a.nodecount() << "; a datacount: " << a.datacount() << '\n';

    bst<int> b(a);

    cout << '\n';

    b.print(b._root(), cout);
    cout << "b nodecount: " << b.nodecount() << "; b datacount: " << b.datacount() << '\n';

    cout << '\n';

    for(int i = 0; i < 25; ++i)
    {
        x = rand() % 50;
        b.insert(x);
        cout << x << " ";
    }

    c = b;

    cout << '\n';

    a.print(a._root(), cout);
    cout << "a nodecount: " << a.nodecount() << "; a datacount: " << a.datacount() << '\n';

    cout << '\n';

    b.print(b._root(), cout);
    cout << "b nodecount: " << b.nodecount() << "; b datacount: " << b.datacount() << '\n';

    cout << '\n';

    c.print(c._root(), cout);
    cout << "c nodecount: " << c.nodecount() << "; c datacount: " << c.datacount() << '\n';

    cout << '\n';

    return 0;
}
