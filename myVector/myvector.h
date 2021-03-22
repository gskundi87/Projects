#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstdlib>

enum myVectorError {OUT_OF_BOUNDS};

template <class T>
class myVector
{
public:
    myVector(const T& initalValue = T(), const size_t& s = 0);
    ~myVector();
    myVector(const myVector<T>&);
    const myVector& operator=(const myVector<T>&);
    const size_t& _size() const;
    bool empty() const;
    bool full() const;
    void push_back(const T&);
    void pop_back();
    void resize(const size_t&, const T& value = T());
    const T& at(const size_t&) const;
    void clear();
    T& operator[](const size_t&);

private:
    T* vectorArray;
    size_t size;
    size_t capacity = 256;
    void copy(const myVector<T>&);
    void reallocate(const size_t&);
};

template <class T>
myVector<T>::myVector(const T& initialValue, const size_t& s)
{
    size = s;

    if(size > capacity)
        capacity = size * 2;

    vectorArray = new T[capacity + 1];

    vectorArray[0] = T();

    for(size_t i = 1; i < size + 1; ++i)
        vectorArray[i] = initialValue;
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
const size_t &myVector<T>::_size() const
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

    vectorArray[size + 1] = value;

    ++size;
}

template <class T>
void myVector<T>::pop_back()
{
    if(empty())
        return;

    vectorArray[size + 1] = T();

    --size;

    if(capacity > 256 && (capacity / 4) > size)
        reallocate(capacity / 2);
}

template <class T>
void myVector<T>::resize(const size_t& newsize, const T& value)
{
    if(newsize > capacity)
        reallocate(newsize * 2);

    if(newsize > size)
        for(size_t i = size + 1; i < newsize + 1; ++i)
            vectorArray[i] = value;
    else
        for(size_t i = newsize + 1; i < size + 1; ++i)
            vectorArray[i] = T();

    size = newsize;
}

template <class T>
const T& myVector<T>::at(const size_t& index) const
{
    return vectorArray[index + 1];
}

template <class T>
T& myVector<T>::operator[](const size_t& index)
{
    try
    {
        if(index >= size)
            throw 0;
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

    return vectorArray[index + 1];
}

template <class T>
void myVector<T>::clear()
{
    for(size_t i = 1; i < size + 1; ++i)
        vectorArray[i] = T();

    size = 0;
}

template <class T>
void myVector<T>::copy(const myVector<T>& other)
{
    size = other.size;

    vectorArray = new T[size + 1];

    for(size_t i = 0; i < size + 1; ++i)
        vectorArray[i] = other.vectorArray[i];
}

template <class T>
void myVector<T>::reallocate(const size_t& allocation)
{
    capacity = allocation;

    T* temp = new T[capacity + 1];

    for(size_t i = 0; i < size + 1; ++i)
    {
        temp[i] = vectorArray[i];
        vectorArray[i] = T();
    }

    for(size_t i = size + 1; i < capacity + 1; ++i)
        temp[i] = T();

    delete [] vectorArray;

    vectorArray = temp;
}

#endif // MYVECTOR_H


