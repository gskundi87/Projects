#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include "node.h"

template <typename T>
class myDoubleLinkedList
{
public:
    myDoubleLinkedList() : head{nullptr}, tail{nullptr}{}
    myDoubleLinkedList(T);
    myDoubleLinkedList(const myDoubleLinkedList<T>&);
    ~myDoubleLinkedList();
    myDoubleLinkedList<T>& operator=(const myDoubleLinkedList<T>&);




private:
  node<T>* head;
  node<T>* tail;
  size_t _size;

  void copy(const myDoubleLinkedList<T>&);
  void del();
};

template <typename T>
myDoubleLinkedList<T>::myDoubleLinkedList(T d)
{
    head = new node<T>(d);
    tail = head;
    ++_size;
}

template <typename T>
myDoubleLinkedList<T>::myDoubleLinkedList(const myDoubleLinkedList<T>& other)
{
    copy(other);
}

template <typename T>
myDoubleLinkedList<T>& myDoubleLinkedList<T>::operator=(const myDoubleLinkedList<T>& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename T>
void myDoubleLinkedList<T>::copy(const myDoubleLinkedList<T>& other)
{

}

template <typename T>
void myDoubleLinkedList<T>::del()
{

}

#endif // MYDOUBLELINKEDLIST_H
