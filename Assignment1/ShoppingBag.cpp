#include "ShoppingBag.h"
#include <iostream>
#include <algorithm>

// A parameterized constructor
template <class ItemType>
ShoppingBag<ItemType>::ShoppingBag(const int _size) : Bag<ItemType>(_size)
{
}
// The method add items with specific quantities
template <class ItemType>
void ShoppingBag<ItemType>::addItem(const ItemType &_item, const int &quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        Bag<ItemType>::addItem(_item);
    }
}
