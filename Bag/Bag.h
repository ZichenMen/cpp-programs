#ifndef BAG_
#define BAG_
#include <vector>

/**
 * The base class for all types of bags.
 *  Items: a vector to store items of any data type
 *  Size: an integer representing the current size of the bag
 *  Methods to add an item, remove an item, check if the bag is empty, and
 * display the bag’s content
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/16/2023
 * @version ___1.0____
 */
template <class ItemType>
class Bag
{
protected:
    std::vector<ItemType> items; // A vector to store items of any data type
    int size;                    // An integer representing the current size of the bag

public:
    Bag(const int = 10); // Parameterized constructor

    void addItem(const ItemType &item);
    virtual bool removeItem(const ItemType &item);
    bool checkEmpty() const;
    void displayContents() const;
};

#include "Bag.cpp"

#endif
