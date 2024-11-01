#ifndef MYVECTOR_V2_H
#define MYVECTOR_V2_H

#include <cstdlib>

enum MyVector_v2_Errors{INVALID_SIZE};

template <typename T>
class MyVector_v2 {
public:
    MyVector_v2(): _size{0}, _capacity{256} {
        data = new T[_capacity];
    }
    MyVector_v2(T initialValue, size_t size);
    ~MyVector_v2();
    MyVector(const MyVector_v2<T>& other);
    const MyVector_v2<T>& operator=(const MyVector_v2<T>& other);

private:
    T* data;
    size_t _size;
    size_t _capacity;
};

template<typename T>
MyVector_v2<T>::MyVector_v2(T initialValue, size_t size) {
    if(size < 0) throw(INVALID_SIZE);

    if(size > _capacity) { _capacity = size * 2; }
    else { _capacity = 256; }

    data = new T[_capacity];

    _size = size;

    for(size_t i{0}; i < _size; i++) {
        data[i] = initialValue;
    }
}

template <typename T>
MyVector_v2<T>::MyVector_v2(const MyVector_v2<T>& other) {

}

template <typename T>
MyVector_v2<T>::~MyVector_v2() {

}

template <typename T>
const MyVector_v2<T>& MyVector_v2::operator=(const MyVector_v2<T>& other) {

}

#endif // MYVECTOR_V2_H
