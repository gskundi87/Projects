#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include <cstddef>
#include <iostream>
#include "node.h"

template <typename T>
class myDoubleLinkedList
{
public:
    myDoubleLinkedList() : head{nullptr}, tail{nullptr}{}
    myDoubleLinkedList(const T&);
    myDoubleLinkedList(const myDoubleLinkedList<T>&);
    ~myDoubleLinkedList();
    myDoubleLinkedList<T>& operator=(const myDoubleLinkedList<T>&);

    bool is_empty() const;
    size_t get_size() const;
    const node<T>& get_head() const;
    const node<T>& get_tail() const;

    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();

private:
  node<T>* head;
  node<T>* tail;
  size_t _size = 0;

  void copy(const myDoubleLinkedList<T>&);
  void del();

  template <typename T2>
  friend std::ostream& operator<<(std::ostream&, const myDoubleLinkedList<T2>&);

  class iterator
  {
      friend class myDoubleLinkedList;

  public:

  private:
      node<T>* nodePtr;

  };
};

template <typename T>
myDoubleLinkedList<T>::~myDoubleLinkedList()
{
    del();
}

template <typename T>
myDoubleLinkedList<T>::myDoubleLinkedList(const T& d)
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
bool myDoubleLinkedList<T>::is_empty() const
{
    return !_size;
}

template <typename T>
size_t myDoubleLinkedList<T>::get_size() const
{
    return _size;
}

template <typename T>
const node<T>& myDoubleLinkedList<T>::get_head() const
{
    return this->head;
}

template <typename T>
const node<T>& myDoubleLinkedList<T>::get_tail() const
{
    return this->tail;
}

template <typename T>
void myDoubleLinkedList<T>::push_front(const T&d)
{
    if(!is_empty())
    {
        head = new node<T>(d, head, nullptr);
        head->next->previous = head;
    }
    else
    {
        head = tail = new node<T>(d);
    }

    ++_size;
}

template <typename T>
void myDoubleLinkedList<T>::push_back(const T&d)
{
    if(!is_empty())
    {
        tail = new node<T>(d, nullptr, tail);
        tail->previous->next = tail;
    }
    else
    {
        head = tail = new node<T>(d);
    }

    ++_size;
}

template <typename T>
void myDoubleLinkedList<T>::pop_front()
{
    if(!is_empty())
    {
        if(_size == 1)
        {
            delete head;
            head = tail = nullptr;
            --_size;
        }
        else
        {
            head = head->next;
            delete head->previous;
            head->previous = nullptr;
            --_size;
        }
    }
}

template <typename T>
void myDoubleLinkedList<T>::pop_back()
{
    if(!is_empty())
    {
        if(_size == 1)
        {
            delete tail;
            head = tail = nullptr;
            --_size;
        }
        else
        {
            tail = tail->previous;
            delete tail->next;
            tail->next = nullptr;
            --_size;
        }
    }
}

template <typename T>
void myDoubleLinkedList<T>::copy(const myDoubleLinkedList<T>& other)
{

}

template <typename T>
void myDoubleLinkedList<T>::del()
{
    node<T>* temp;

    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    head = tail = nullptr;
    _size = 0;
}

template <typename T2>
std::ostream& operator<<(std::ostream& out, const myDoubleLinkedList<T2>& list)
{
    node<T2>* temp = list.head;

    while(temp)
    {
        out << *temp << " ";

        temp = temp->next;
    }

    return out;
}

#endif // MYDOUBLELINKEDLIST_H
