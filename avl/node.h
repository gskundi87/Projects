#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
class Node
{
private:
    T data;
    Node* left;
    Node* right;
    Node* parent;

public:
    Node();
    Node(const T& data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(const Node<T>& other) {
        data = other.data;
    }

    ~Node() {}

    Node<T>& operator=(const Node<T>&);
    bool operator>(const Node<T>&) const;
    bool operator<(const Node<T>&) const;
    bool operator==(const Node<T>&) const;

    void printNode() const
    {
        std::cout << data << " ";
    };

    template<class U>
    friend std::__1::basic_ostream<char, std::__1::char_traits<char>>& operator<<(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, const Node<U>&);

    template<class U>
    friend std::istream& operator>>(std::istream&, Node<U>&);

    Node<T>* getLeft() const;
    void setLeft(Node<T>* newLeft);
    void resetLeft();
    Node<T>* getRight() const;
    void setRight(Node<T>* newRight);
    void resetRight();
    Node<T> *getParent() const;
    void setParent(Node<T> *newParent);
    void resetParent();

    T getData() const;
};

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& other)
{
    if(this != &other) {
        data = other.data;
    }

    return *this;
}

template<class T>
bool Node<T>::operator>(const Node<T>& other) const
{
    return data > other.data;
}

template<class T>
bool Node<T>::operator<(const Node<T>& other) const
{
    return data < other.data;
}

template<class T>
bool Node<T>::operator==(const Node<T>& other) const
{
    return data == other.data;
}

template<class U>
std::__1::basic_ostream<char, std::__1::char_traits<char>>& operator<<(std::__1::basic_ostream<char, std::__1::char_traits<char>>& out, const Node<U>& obj)
{
    out << obj.data;

    return out;
}

template<class U>
std::istream& operator>>(std::istream& in, Node<U>& obj)
{
    in >> obj.data;

    return in;
}

template<class T>
inline Node<T>* Node<T>::getLeft() const
{
    return left;
}

template<class T>
inline void Node<T>::setLeft(Node<T>* newLeft)
{
    left = newLeft;
}

template<class T>
inline void Node<T>::resetLeft()
{
    setLeft(nullptr); // TODO: Adapt to use your actual default value
}

template<class T>
inline Node<T>* Node<T>::getRight() const
{
    return right;
}

template<class T>
inline void Node<T>::setRight(Node<T>* newRight)
{
    right = newRight;
}

template<class T>
inline void Node<T>::resetRight()
{
    setRight(nullptr); // TODO: Adapt to use your actual default value
}

template<class T>
inline Node<T>* Node<T>::getParent() const
{
    return parent;
}

template<class T>
inline void Node<T>::setParent(Node<T> *newParent)
{
    parent = newParent;
}

template<class T>
inline void Node<T>::resetParent()
{
    setParent(nullptr); // TODO: Adapt to use your actual default value
}

template<class T>
inline T Node<T>::getData() const {
    return data;
}


#endif // NODE_H
