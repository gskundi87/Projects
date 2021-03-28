#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename K, typename V>
class node
{
public:
    node() : key{K()}, data{V()}, next{nullptr}, previous{nullptr}{}
    node(const K& k, const V& v): key{k}, data{v}, next{nullptr}, previous{nullptr}{}
    node(const K& k, const V& v, node<K,V>* n, node<K,V>* p): key{k}, data{v}, next{n}, previous{p}{}
    node(const node<K,V>&);
    ~node();
    node<K,V>& operator=(const node<K,V>&);

    K key;
    V data;
    node* next;
    node* previous;

    void copy(const node<K,V>&);
    void del();

    template <typename A, typename B>
    friend bool operator>(const node<A,B>&, const node<A,B>&);

    template <typename A, typename B>
    friend bool operator<(const node<A,B>&, const node<A,B>&);

    template <typename A, typename B>
    friend bool operator>=(const node<A,B>&, const node<A,B>&);

    template <typename A, typename B>
    friend bool operator<=(const node<A,B>&, const node<A,B>&);

    template <typename A, typename B>
    friend bool operator==(const node<A,B>&, const node<A,B>&);

    template <typename A, typename B>
    friend std::ostream& operator<<(std::ostream&, const node<A,B>&);
};

template <typename K, typename V>
node<K,V>::~node()
{
    del();
}

template <typename K, typename V>
node<K,V>::node(const node<K,V>& other)
{
    copy(other);
}

template <typename K, typename V>
node<K,V>& node<K,V>::operator=(const node<K,V>& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename K, typename V>
void node<K,V>::copy(const node<K,V>& other)
{
    key = other.key;
    data = other.data;
    next = other.next;
    previous = other.previous;
}

template <typename K, typename V>
void node<K,V>::del()
{
    key = K();
    data = V();
    next = nullptr;
    previous = nullptr;
}

template <typename A, typename B>
bool operator>(const node<A,B>& x, const node<A,B>& y)
{
    return x.data > y.data;
}

template <typename A, typename B>
bool operator<(const node<A,B>& x, const node<A,B>& y)
{
    return x.data < y.data;
}

template <typename A, typename B>
bool operator>=(const node<A,B>& x, const node<A,B>& y)
{
    return x.data >= y.data;
}

template <typename A, typename B>
bool operator<=(const node<A,B>& x, const node<A,B>& y)
{
    return x.data <= y.data;
}

template <typename A, typename B>
bool operator==(const node<A,B>& x, const node<A,B>& y)
{
    return x.data == y.data;
}

template <typename A, typename B>
std::ostream& operator<<(std::ostream& out, const node<A,B>& x)
{
    out << x.data;

    return out;
}

#endif // NODE_H

