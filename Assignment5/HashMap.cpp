/**
 * A template class that provides a basic hash table implementation
 * for mapping keys to values.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/27/2023
 * @version __1.0__
 *
 */

#include "HashMap.h"
#include <algorithm>
#include <functional>
#include <string>

template <typename K, typename V, int TableSize>
HashMap<K, V, TableSize>::HashEntry::HashEntry(K key, V value) : key(key), value(value) {}

// Constructor
template <typename K, typename V, int TableSize>
HashMap<K, V, TableSize>::HashMap() : table(TableSize) {}

template <typename K, typename V, int TableSize>
int HashMap<K, V, TableSize>::hashFunction(K key) const
{
    return std::hash<K>{}(key) % TableSize;
}

// Insert a key-value pair into the hash map.
template <typename K, typename V, int TableSize>
void HashMap<K, V, TableSize>::insert(const K &key, const V &value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto it = std::find_if(cell.begin(), cell.end(), [&key](const HashEntry &entry)
                           { return entry.key == key; });

    if (it != cell.end())
    {
        it->value = value;
    }
    else
    {
        cell.emplace_back(key, value);
    }
}

// Retrieve the value associated with a given key.
template <typename K, typename V, int TableSize>
bool HashMap<K, V, TableSize>::get(const K &key, V &value) const
{
    int hashValue = hashFunction(key);
    const auto &cell = table[hashValue];
    auto it = std::find_if(cell.begin(), cell.end(), [&key](const HashEntry &entry)
                           { return entry.key == key; });

    if (it != cell.end())
    {
        value = it->value;
        return true;
    }
    return false;
}

template <typename K, typename V, int TableSize>
V &HashMap<K, V, TableSize>::operator[](const K &key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto it = std::find_if(cell.begin(), cell.end(), [&key](const HashEntry &entry)
                           { return entry.key == key; });

    if (it != cell.end())
    {
        return it->value;
    }

    cell.emplace_back(key, V{});
    return cell.back().value;
}

// Remove a key-value pair from the hash map.
template <typename K, typename V, int TableSize>
void HashMap<K, V, TableSize>::remove(const K &key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    cell.remove_if([&key](const HashEntry &entry)
                   { return entry.key == key; });
}

// Check if the hash map contains a specific key.
template <typename K, typename V, int TableSize>
bool HashMap<K, V, TableSize>::contains(const K &key) const
{
    int hashValue = hashFunction(key);
    const auto &cell = table[hashValue];
    auto it = std::find_if(cell.begin(), cell.end(), [&key](const HashEntry &entry)
                           { return entry.key == key; });
    return it != cell.end();
}

// Sort the hash map by values.
template <typename K, typename V, int TableSize>
std::vector<std::pair<K, V>> HashMap<K, V, TableSize>::sortHashMapByValues()
{
    std::vector<std::pair<K, V>> sortedList;
    for (const auto &cell : table)
    {
        for (const auto &entry : cell)
        {
            sortedList.emplace_back(entry.key, entry.value);
        }
    }

    std::sort(sortedList.begin(), sortedList.end(), [](const std::pair<K, V> &a, const std::pair<K, V> &b)
              { return a.second > b.second; });

    return sortedList;
}

// Explicit template instantiation
template class HashMap<int, std::string, 100>;
