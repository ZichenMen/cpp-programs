#ifndef SHOPPING_BAG
#define SHOPPING_BAG
#include "Bag.h"
#include <map>

/**
 * Derived class from Bag, represents a shopping bag with quantities
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/16/2023
 * @version ___1.0____
 */
template <class ItemType>
class ShoppingBag : public Bag<ItemType>
{
private:
public:                                                       // default constructor
    ShoppingBag(const int = 10);                              // parameterized constructor
    void addItem(const ItemType &_item, const int &quantity); // add specific quantity of item
};

#include "ShoppingBag.cpp"

#endif