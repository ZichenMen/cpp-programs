#include "Bag.h"
#include <algorithm>
#include <iostream>

// A parameterized constrcutor
template <class ItemType>
Bag<ItemType>::Bag(const int _size) : size(_size)
{
    items.reserve(_size);
}

// The method add an item to the items
template <class ItemType>
void Bag<ItemType>::addItem(const ItemType &_item)
{
    items.push_back(_item);
    size++;
}

// The method remove a item from the items
template <class ItemType>
bool Bag<ItemType>::removeItem(const ItemType &_item)
{
    if (checkEmpty())
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (items[i] == _item)
        {
            items.erase(items.begin() + i);
            size--;
            return true;
        }
    }
    return false;
}

// The method check if the items is empty
template <class ItemType>
bool Bag<ItemType>::checkEmpty() const
{
    return items.empty();
}

// The method print all item in the items
template <class ItemType>
void Bag<ItemType>::displayContents() const
{
    std::cout << "[";
    for (int i = 0; i < items.size(); i++)
    {

        std::cout << items[i];
        if (i != items.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}