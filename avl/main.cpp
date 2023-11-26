#include "node.h"
#include <string>

using namespace std;

template<class T>
void printTree(const Node<T>&);

int main()
{
    cout << "Hello World!" << endl;

    cout << "TESTING NODE CLASS" << '\n';

    Node<string> x("5");
    Node<string> y("6");
    Node<string> z("7");

    y.setLeft(&x);
    x.setParent(&y);
    y.setRight(&z);
    z.setParent(&y);

    x.printNode();

    cout << x << endl;

    printTree<string>(y);

    cout << "\nENDING TESTING NODE CLASS" << '\n';

    return 0;
}

template<class T>
void printTree(const Node<T>& node)
{
    if(node.getLeft())
    {
        printTree<T>(*node.getLeft());
    }

    cout << node;

    cout << " ";

    if(node.getRight())
    {
        printTree<T>(*node.getRight());
    }
}
