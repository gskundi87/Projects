#include "avl.h"
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

template<class T>
void printTree(const Node<T>&);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

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

    cout << "\nENDING TESTING NODE CLASS\n";

    cout << "\nSTARTING TESTING AVL CLASS\n";

    AVL<int> tree{};

    for(int i = 0; i < 10; ++i)
    {
        tree.insert(arc4random() % 100 + 1);
    }

    printTree<int>(*tree.getRoot());

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
