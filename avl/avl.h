#ifndef AVL_H
#define AVL_H

#include "node.h"

template<typename T>
class AVL
{
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

    private:
        bool isImbalanced(Node<T>*) const;
        void rebalance(Node<T>*);
        void rotateLeftLeft(Node<T>*);
        void rotateLeftRight(Node<T>*);
        void rotateRightLeft(Node<T>*);
        void rotateRightRight(Node<T>*);

        Node<T>* root;
};

template<typename T>
bool AVL<T>::insert(const T& data)
{
    Node<T>* tempNode;
    Node<T>* insertNode = new Node<T>(data);

    if(((tempNode = find(data, root)) != nullptr) && (*tempNode == *insertNode))
    {
        std::cout << "Value already inserted\n";
        return false;
    }
    else if(tempNode == nullptr)
    {
        root = new Node<T>(data);
    }
    else if(*insertNode < *tempNode)
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
bool AVL<T>::remove(const T& data)
{

}

template<typename T>
Node<T>* AVL<T>::getRoot() const
{
    return root;
}

template<typename T>
Node<T>* AVL<T>::find(const T& value, Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    Node<T>* findNode = new Node<T>(value);

    while(*findNode != *node)
    {
        if(*findNode < *node)
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
        else
        {
            if(node->getRight() != nullptr)
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

template<typename T>
Node<T>* AVL<T>::previous(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    if(node->getLeft() != nullptr)
    {
        return max(node->getLeft());
    }

    Node<T>* tempParent = node->getParent();

    while(tempParent != nullptr && node == tempParent->getLeft())
    {
        node = tempParent;
        tempParent = node->getParent();
    }

    return tempParent;
}

template<typename T>
Node<T>* AVL<T>::next(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    if(node->getRight() != nullptr)
    {
        return min(node->getRight());
    }

    Node<T>* tempParent = node->getParent();

    while(tempParent != nullptr && node == tempParent->getRight())
    {
        node = tempParent;
        tempParent = node->getParent();
    }

    return tempParent;
}

template<typename T>
Node<T>* AVL<T>::min(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    while(node->getLeft())
    {
        node = node->getLeft();
    }

    return node;
}

template<typename T>
Node<T>* AVL<T>::max(Node<T>* node) const
{
    if(node == nullptr)
    {
        return nullptr;
    }

    while(node->getRight())
    {
        node = node->getRight();
    }

    return node;
}

template<typename T>
int AVL<T>::getHeight(Node<T>* node)
{
    if(node == nullptr || (node->getLeft() == nullptr && node->getRight() == nullptr))
    {
        return 0;
    }

    return 1 + std::max(AVL<T>::getHeight(node->getLeft()), AVL<T>::getHeight(node->getRight()));
}



#endif // AVL_H
