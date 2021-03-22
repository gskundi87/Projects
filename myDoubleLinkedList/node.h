#ifndef NODE_H
#define NODE_H

template <typename U>
class node
{
public:
    node() : data{U()}, next{nullptr}, previous{nullptr}{}
    node(U d): data{d}, next{nullptr}, previous{nullptr}{}
    node(const node<U>&);
    ~node();
    node<U>& operator=(const node<U>&);

    template <typename V>
    friend bool operator>(const node<V>&, const node<V>&);

    template <typename V>
    friend bool operator<(const node<V>&, const node<V>&);

    template <typename V>
    friend bool operator>=(const node<V>&, const node<V>&);

    template <typename V>
    friend bool operator<=(const node<V>&, const node<V>&);

    template <typename V>
    friend bool operator==(const node<V>&, const node<V>&);

private:
    U data;
    node* next;
    node* previous;

    void copy(const node<U>&);
    void del();
};

template<typename U>
node<U>::~node()
{
    del();
}

template<typename U>
node<U>::node(const node<U>& other)
{
    copy(other);
}

template<typename U>
node<U>& node<U>::operator=(const node<U>& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

template <typename V>
bool operator>(const node<V>& x, const node<V>& y)
{
    return x.data > y.data;
}

template <typename U>
void node<U>::copy(const node<U>& other)
{
    data = other.data;
    next = other.next;
    previous = other.previous;
}

template <typename U>
void node<U>::del()
{
    data = U();
    next = nullptr;
    previous = nullptr;
}

#endif // NODE_H
