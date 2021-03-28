#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <array>
#include <algorithm>
#include "node.h"

template <typename K, typename V>
class HashTable
{
public:
    HashTable();
    ~HashTable();

    int hash(const K&);


private:
    static constexpr int dim = 256;
    std::array<std::list<node<K,V>>*, dim> hashTable;

};

template <typename K, typename V>
HashTable<K,V>::HashTable()
{
    for(auto& x : hashTable)
    {
        x = nullptr;
    }
}

template <typename K, typename V>
HashTable<K,V>::~HashTable()
{
    for(auto& x : hashTable)
    {
        delete x;
        x = nullptr;
    }
}

template <typename K, typename V>
int HashTable<K,V>::hash(const K& key)
{

}

#endif // HASHTABLE_H
