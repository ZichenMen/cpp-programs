/**
 * A template class that provides a basic hash table implementation
 * for mapping keys to values.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/27/2023
 * @version __1.0__
 *
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <list>
#include <utility>
#include <string>

template <typename K, typename V, int TableSize = 100>
class HashMap
{
private:
    class HashEntry
    {
    public:
        K key;
        V value;
        HashEntry(K key, V value);
    };

    // an array of linked lists to store key-value pairs.
    std::vector<std::list<HashEntry>> table;
    // Private helper function to calculate the hash value for a key.
    int hashFunction(K key) const;

public:
    HashMap();                                          // Constructor
    void insert(const K &key, const V &value);          // Insert a key-value pair into the hash map.
    bool get(const K &key, V &value) const;             // Retrieve the value associated with a given key.
    V &operator[](const K &key);                        // Overloaded operator.
    void remove(const K &key);                          // Remove a key-value pair from the hash map.
    bool contains(const K &key) const;                  // Check if the hash map contains a specific key.
    std::vector<std::pair<K, V>> sortHashMapByValues(); // Sort the hash map by values
};

#include "HashMap.cpp"
#endif // HASHMAP_H
