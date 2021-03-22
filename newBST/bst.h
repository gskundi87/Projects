#ifndef BST_H
#define BST_H

#include <cmath>
#include <ostream>

template <class T>
class bst
{
public:
    bst();
    bst(const bst<T>&);
    ~bst();
    const bst<T>& operator=(const bst<T>&);

    const size_t& _size() const;
    const size_t& _root() const;
    bool empty() const;
    bool full() const;
    int depth();
    int nodecount();
    int datacount();
    void insert(const T&);
    void remove(const T&);
    void print(const size_t&, std::ostream&);

private:
    T** tree;
    int* left;
    int* right;
    size_t* count;
    size_t size = 0, capacity = 256, root = 0;
    void copy(const bst<T>&);
    void deleteBST();
    int findIndex(const T&, bool&);
    int depth(const int&);
    int nodecount(const int&);
    int datacount(const int&);
    bool balanced(const int&);
    void rebalance(int, int);
    void rotateLeftLeft(const int&, const int&);
    void rotateLeftRight(const int&, const int&);
    void rotateRightLeft(const int&, const int&);
    void rotateRightRight(const int&, const int&);
};

template <class T>
bst<T>::bst()
{
    T* tempPtr;

    tree = static_cast<T**>(malloc(sizeof(T*) * capacity));
    left = static_cast<int*>(malloc(sizeof(int) * capacity));
    right = static_cast<int*>(malloc(sizeof(int) * capacity));
    count = static_cast<size_t*>(malloc(sizeof(size_t) * capacity));

    for(size_t i = 0; i < capacity; ++i)
    {
        tempPtr = static_cast<T*>(malloc(sizeof(T)));
        *tempPtr = T();
        tree[i] = tempPtr;

        left[i] = -1;
        right[i] = -1;
        count[i] = 0;
    }

    tempPtr = nullptr;
}

template <class T>
bst<T>::bst(const bst<T>& other)
{
    copy(other);
}

template <class T>
bst<T>::~bst()
{
    deleteBST();
}

template <class T>
const bst<T>& bst<T>::operator=(const bst<T>& other)
{
    if(this != &other)
    {
        deleteBST();
        copy(other);
    }

    return *this;
}

template <class T>
const size_t& bst<T>::_size() const
{
    return size;
}

template <class T>
const size_t& bst<T>::_root() const
{
    return root;
}

template <class T>
bool bst<T>::empty() const
{
    return !size;
}

template <class T>
bool bst<T>::full() const
{
    return (size == capacity);
}

template <class T>
int bst<T>::depth()
{
    return depth(root);
}

template <class T>
int bst<T>::nodecount()
{
    if(empty())
        return 0;

    return nodecount(root);
}

template <class T>
int bst<T>::datacount()
{
    if(empty())
        return 0;

    return datacount(root);
}

template <class T>
void bst<T>::insert(const T& value)
{
    if(full())
        return;

    if(empty())
    {
        *tree[size] = value;
        ++count[size];
        ++size;
        return;
    }

    bool found = 0;
    int position = findIndex(value, found);

    if(found == true)
    {
        ++count[position];
        return;
    }

    if(*tree[position] > value)
        left[position] = size;
    else
        right[position] = size;

    *tree[size] = value;
    ++count[size];
    ++size;

    rebalance(root, -1);

    return;
}

template <class T>
void bst<T>::remove(const T& value)
{
    bool found = 0;
    int position = findIndex(value, found);

    if(found == 0)
        return;

    while(right[position] != -1)
    {

    }
}

template <class T>
void bst<T>::print(const size_t& index, std::ostream& out)
{
    if(left[index] != -1)
        print(left[index], out);

    out << *tree[index] << " ";

    if(right[index] != -1)
        print(right[index], out);
}

template<class T>
void bst<T>::copy(const bst<T>& other)
{
    T* tempPtr;

    size = other.size;
    capacity = other.capacity;
    root = other.root;

    tree = static_cast<T**>(malloc(sizeof(T*) * capacity));
    left = static_cast<int*>(malloc(sizeof(int) * capacity));
    right = static_cast<int*>(malloc(sizeof(int) * capacity));
    count = static_cast<size_t*>(malloc(sizeof(size_t) * capacity));

    for(size_t i = 0; i < size; ++i)
    {
        tempPtr = static_cast<T*>(malloc(sizeof(T)));
        *tempPtr = *other.tree[i];
        tree[i] = tempPtr;
    }

    for(size_t i = 0; i < capacity; ++i)
    {
        if(i >= size)
        {
            tempPtr = static_cast<T*>(malloc(sizeof(T)));
            *tempPtr = T();
            tree[i] = tempPtr;
        }

        left[i] = other.left[i];
        right[i] = other.right[i];
        count[i] = other.count[i];
    }

    tempPtr = nullptr;
}

template <class T>
void bst<T>::deleteBST()
{
    for(size_t i = 0; i < capacity; ++i)
        free(tree[i]);

    free(tree);
    free(left);
    free(right);
    free(count);

    size = capacity = root = 0;
}

template <class T>
int bst<T>::findIndex(const T& value, bool &found)
{
    int index = static_cast<int>(root);

    while(*tree[index] != value)
    {
        if(left[index] != -1 && *tree[index] > value)
        {
            index = left[index];
            continue;
        }
        else if(right[index] != -1 && *tree[index] < value)
        {
            index = right[index];
            continue;
        }

        found = false;
        return index;
    }

    found = true;
    return index;
}

template <class T>
int bst<T>::depth(const int& index)
{
    if(index == -1 || empty())
        return 0;

    return 1 + std::max(depth(left[index]), depth(right[index]));
}

template <class T>
int bst<T>::nodecount(const int& index)
{
    if(index == -1 || empty())
        return 0;

    return 1 + nodecount(left[index]) + nodecount(right[index]);
}

template <class T>
int bst<T>::datacount(const int& index)
{
    if(index == -1 || empty())
        return 0;

    return count[index] + datacount(left[index]) + datacount(right[index]);
}

template <class T>
bool bst<T>::balanced(const int& index)
{
    if(index == -1 || empty())
        return 1;

    return (abs(static_cast<int>(depth(left[index])) - static_cast<int>(depth(right[index]))) <= 1);
}

template <class T>
void bst<T>::rebalance(int index, int parent)
{
    if(empty())
        return;

    if(left[index] != -1)
        rebalance(left[index], index);

    if(right[index] != -1)
        rebalance(right[index], index);

    if(!balanced(index))
    {
        if(depth(left[index]) > depth(right[index]))
        {
            if(depth(left[left[index]]) > depth(right[left[index]]))
                rotateLeftLeft(index, parent);
            else
                rotateLeftRight(index, parent);
        }
        else
        {
            if(depth(right[right[index]]) > depth(left[right[index]]))
                rotateRightRight(index, parent);
            else
                rotateRightLeft(index, parent);
        }
    }
}

template <class T>
void bst<T>::rotateLeftLeft(const int& index, const int& parent)
{
    size_t temp = left[index];
    if(static_cast<size_t>(index) == root)
        root = temp;
    else
    {
        if(left[parent] == index)
            left[parent] = temp;
        else
            right[parent] = temp;
    }
    left[index] = right[temp];
    right[temp] = index;
}

template <class T>
void bst<T>::rotateLeftRight(const int& index, const int& parent)
{
    size_t temp = right[left[index]];
    if(static_cast<size_t>(index) == root)
        root = temp;
    else
    {
        if(left[parent] == index)
            left[parent] = temp;
        else
            right[parent] = temp;
    }
    right[left[index]] = left[temp];
    left[temp] = left[index];
    left[index] = right[temp];
    right[temp] = index;
}

template <class T>
void bst<T>::rotateRightLeft(const int& index,const int& parent)
{
    size_t temp = left[right[index]];
    if(static_cast<size_t>(index) == root)
        root = temp;
    else
    {
        if(left[parent] == index)
            left[parent] = temp;
        else
            right[parent] = temp;
    }
    left[right[index]] = right[temp];
    right[temp] = right[index];
    right[index] = left[temp];
    left[temp] = index;
}

template <class T>
void bst<T>::rotateRightRight(const int& index, const int& parent)
{
    size_t temp = right[index];
    if(static_cast<size_t>(index) == root)
        root = temp;
    else
    {
        if(left[parent] == index)
            left[parent] = temp;
        else
            right[parent] = temp;
    }
    right[index] = left[temp];
    left[temp] = index;
}

#endif // BST_H
