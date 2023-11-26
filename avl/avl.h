#ifndef AVL_H
#define AVL_H

#include "node.h"
#include <cassert>

template<typename T>
class AVL
{
private:
    Node<T>* root;

    bool isImbalanced(Node<T>*) const;
    void rebalance(Node<T>*);
    void rotateLeftLeft(Node<T>*);
    void rotateLeftRight(Node<T>*);
    void rotateRightLeft(Node<T>*);
    void rotateRightRight(Node<T>*);

public:
    AVL() : root(nullptr) {}

    bool insert(const T&);
    bool remove(const T&);

    Node<T>* getRoot() const;
    Node<T>* find(const T&, Node<T>*) const;
    Node<T>* previous(Node<T>*) const;
    Node<T>* next(Node<T>*) const;
    Node<T>* min(Node<T>*) const;
    Node<T>* max(Node<T>*) const;

    static int getHeight(Node<T>*);

};

template<typename T>
bool AVL<T>::insert(const T& data)
{
    Node<T>* tempNode;
    Node<T>* insertNode = new Node<T>(data);

    if((tempNode = find(data, root)) == insertNode)
    {
        std::cout << "Value already inserted\n";
        return false;
    }
    else if(tempNode == nullptr)
    {
        root = new Node<T>(data);
    }
    else if(tempNode < insertNode)
    {
        tempNode->setLeft(insertNode);
        insertNode->setParent(tempNode);
    }
    else
    {
        tempNode->setRight(insertNode);
        insertNode->setParent(tempNode);
    }

    return true;
}

template<typename T>
bool remove(const T& data)
{

}

template<typename T>
Node<T>* AVL<T>::getRoot() const {
    return root;
}

template<typename T>
Node<T>* find(const T& value, Node<T>* node)
{
    if(value != nullptr || node != nullptr)
    {
        return nullptr;
    }

    Node<T>* tempNode = new Node<T>(value);

    while(tempNode != node)
    {
        if(tempNode < node)
        {
            if(node->getLeft() != nullptr)
            {
                node = node->getLeft();
            }
            else
            {
                break;
            }

        }
        else if(tempNode > node)
        {
            if(node->getRight())
            {
                node = node->getRight();
            }
            else
            {
                break;
            }
        }
    }

    return node;
}

#endif // AVL_H
