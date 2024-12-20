#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <cstdlib>
#include <initializer_list>

template <typename T>
class Vector_Custom {
public:
    Vector_Custom();
    Vector_Custom(size_t size);
    Vector_Custom(size_t size, T value);
    Vector_Custom(const Vector_Custom& other);
    Vector_Custom(Vector_Custom&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        // Leave other in valid but empty state
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    Vector_Custom(std::initializer_list<T> list) : size(list.size()), capacity(size * 2) {
        data = new T[capacity];
        std::copy(list.begin(), list.end(), data);
    };
    Vector_Custom& operator=(const Vector_Custom& other);
    Vector_Custom& operator=(std::initializer_list<T> list) {
        Vector_Custom temp(list);
        swap(temp);
        return *this;
    }
    ~Vector_Custom() {
        delete[] data;
    }

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t);
    const T& at(size_t) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

private:
    T* data;
    size_t size;
    size_t capacity;
    void swap(Vector_Custom& other);

};

template <typename T>
Vector_Custom<T>::Vector_Custom() : data(nullptr), size(0), capacity(0) {}

template <typename T>
Vector_Custom<T>::Vector_Custom(size_t size) : size(size), capacity(size * 2) {
    data = new T[capacity]();
}

template <typename T>
Vector_Custom<T>::Vector_Custom(size_t size, T value) : size(size), capacity(size * 2)  {
    data = new T[capacity]{value};

    // // This could also be another way to do this using the std::fill algorithm
    // // This might be better because it doesn't actually initialize any elements beyond index = size - 1
    // data = new T[capacity];
    // std::fill(data, data + size, value);
}

template <typename T>
Vector_Custom<T>::Vector_Custom(const Vector_Custom<T> &other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    std::copy(other.data, other.data + capacity, data);
}

template <typename T>
Vector_Custom<T>& Vector_Custom<T>::operator=(const Vector_Custom<T>& other) {
    // // This is the old way of implementing a copy assignment operator
    // if(this != &other) {
    //     destruct();
    //     copy(other);
    // }
    // return *this;

    Vector_Custom<T> temp(other);
    swap(temp);
    return *this;
}

template <typename T>
T& Vector_Custom<T>::at(size_t n) {
    if(n > size) throw std::out_of_range("Index out of range");
    return data[n];
}

template <typename T>
const T& Vector_Custom<T>::at(size_t n) const {
    if(n > size) throw std::out_of_range("Index out of range");
    return data[n];
}

template <typename T>
T& Vector_Custom<T>::front() {

}

template <typename T>
void Vector_Custom<T>::swap(Vector_Custom<T>& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

#endif // VECTOR_H
