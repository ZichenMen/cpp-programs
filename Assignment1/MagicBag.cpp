#include "MagicBag.h"
#include <iostream>
#include <vector>
#include <string>

// Predefined string list of magical items
template <>
const std::vector<std::string> MagicBag<std::string>::magicalItems = {
    "MagicItem1", "MagicItem2", "MagicItem3", "MagicItem4", "MagicItem5"};
// Predefined int list of magical items
template <>
const std::vector<int> MagicBag<int>::magicalItems = {
    10001, 20002, 30003, 40004, 50005};

// A parameterized constructor
template <class ItemType>
MagicBag<ItemType>::MagicBag(const int _size) : Bag<ItemType>(_size)
{
}

// The specialized version remove method
template <class ItemType>
bool MagicBag<ItemType>::removeItem(const ItemType &_item)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int randomValue = std::rand() % magicalItems.size();

    for (int i = 0; i < this->items.size(); i++)
    {
        if (this->items[i] == _item)
        {
            this->items[i] = magicalItems[randomValue];
            return true;
        }
    }
    return false;
}
