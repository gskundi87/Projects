#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstdlib>

enum myVectorError {OUT_OF_BOUNDS, EMPTY_VECTOR, INVALID_SIZE};

template <class T>
class myVector
{
public:
    myVector(const T& initalValue = T(), const int& s = 0);
    ~myVector();
    myVector(const myVector<T>&);
    const myVector& operator=(const myVector<T>&);
    const int& _size() const;
    bool empty() const;
    bool full() const;
    void push_back(const T&);
    void pop_back();
    void resize(const int&, const T& value = T());
    const T& at(const int&) const;
    void clear();
    T& operator[](const int &);

private:
    T* vectorArray;
    int size;
    int capacity{256};
    void copy(const myVector<T>&);
    void reallocate(const int &);
};

template <class T>
myVector<T>::myVector(const T& initialValue, const int &s)
{
    try
    {
        if(s < 0)
            throw(0);
    }
    catch (int error)
    {
        switch(error)
        {
        case 0:
            exit(INVALID_SIZE);
            break;
        default:
            break;
        }
    }

    size = s;

    if(size > capacity)
        capacity = size * 2;

    vectorArray = new T[capacity];

    for(int i{0}; i < size; ++i)
        vectorArray[i] = initialValue;

    for(int i{size}; i < capacity; ++i)
    {
        vectorArray[i] = T();
    }
}

template<class T>
myVector<T>::~myVector()
{
    clear();

    delete [] vectorArray;
}

template<class T>
myVector<T>::myVector(const myVector<T>& other)
{
    copy(other);
}

template <class T>
const myVector<T>& myVector<T>::operator=(const myVector<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

template <class T>
const int &myVector<T>::_size() const
{
    return size;
}

template <class T>
bool myVector<T>::empty() const
{
    return !size;
}

template <class T>
bool myVector<T>::full() const
{
    return size == capacity;
}

template <class T>
void myVector<T>::push_back(const T& value)
{
    if(full())
        reallocate(capacity * 2);

    vectorArray[size++] = value;
}

template <class T>
void myVector<T>::pop_back()
{
    try
    {
        if(empty())
            throw(0);
    }
    catch (int error)
    {
        switch(error)
        {
        case 0:
            exit(EMPTY_VECTOR);
            break;
        default:
            break;
        }
    }

    vectorArray[size--] = T();

    if(capacity > 256 && (capacity / 4) > size)
        reallocate(capacity / 2);
}

template <class T>
void myVector<T>::resize(const int &newsize, const T& value)
{
    try
    {
        if(newsize < 0)
            throw(0);
    }
    catch (int error)
    {
        switch(error)
        {
        case 0:
            exit(INVALID_SIZE);
            break;
        default:
            break;
        }
    }

    if(newsize > capacity)
        reallocate(newsize * 2);

    if(newsize > size)
        for(int i{size}; i < newsize; ++i)
            vectorArray[i] = value;
    else
        for(int i{newsize}; i < size; ++i)
            vectorArray[i] = T();

    size = newsize;
}

template <class T>
const T& myVector<T>::at(const int &index) const
{
    return vectorArray[index];
}

template <class T>
T& myVector<T>::operator[](const int& index)
{
    try
    {
        if(index >= size)
            throw(0);
    }
    catch(int error)
    {
        switch(error)
        {
        case 0:
            exit(OUT_OF_BOUNDS);
            break;
        default:
            break;
        }
    }

    return vectorArray[index];
}

template <class T>
void myVector<T>::clear()
{
    for(int i{0}; i < size; ++i)
        vectorArray[i] = T();

    size = 0;
}

template <class T>
void myVector<T>::copy(const myVector<T>& other)
{
    size = other.size;
    capacity = other.capacity;

    vectorArray = new T[capacity];

    for(int i{0}; i < capacity; ++i)
        vectorArray[i] = other.vectorArray[i];
}

template <class T>
void myVector<T>::reallocate(const int& allocation)
{
    capacity = allocation;

    T* temp {new T[capacity]};

    for(int i{0}; i < size; ++i)
    {
        temp[i] = vectorArray[i];
        vectorArray[i] = T();
    }

    for(int i{size}; i < capacity; ++i)
        temp[i] = T();

    delete [] vectorArray;

    vectorArray = temp;
}

#endif // MYVECTOR_H


