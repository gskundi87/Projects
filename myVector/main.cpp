#include <iostream>
#include <string>
#include <myvector.h>

using namespace std;

int main()
{
    myVector<int> a;

    for(int i = 0; i < 50; ++i)
        a.push_back(i);

    for(size_t i = 0; i < a._size(); ++i)
        cout << a[i] << " ";

    cout << '\n';

    a.resize(257, 'o');

    for(size_t i = 0; i < a._size(); ++i)
        cout << a[i] << " ";

    cout << '\n';

    cout << a[24] << endl;
    cout << a.at(24) << endl;
    a[24] = 255;

    for(size_t i = 0; i < a._size(); ++i)
        cout << a[i] << " ";

    cout << '\n';

    a.resize(10);

    a.pop_back();

    for(size_t i = 0; i < a._size(); ++i)
        cout << a[i] << " ";

    cout << '\n';

    cout << a[9] << endl;

    return 0;
}
