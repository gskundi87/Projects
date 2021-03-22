#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include "node.h"

template <typename T>
class myDoubleLinkedList
{
public:
    myDoubleLinkedList() : head{nullptr}, tail{nullptr}{}
    myDoubleLinkedList(T);
    ~myDoubleLinkedList();


private:
  node<T>* head;
  node<T>* tail;
};

template <typename T>
myDoubleLinkedList<T>::myDoubleLinkedList(T d)
{
    node<T> temp(d);
    head = &temp;
    tail = &temp;
}

#endif // MYDOUBLELINKEDLIST_H
