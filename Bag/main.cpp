#include "Bag.h"
#include "MagicBag.h"
#include "ShoppingBag.h"
#include <iostream>

int main()
{
    // Create bags
    Bag<int> bag1(5);
    MagicBag<std::string> bag2(5);
    MagicBag<int> bag3(5);
    ShoppingBag<std::string> bag4(5);

    // Add items to bags
    bag1.addItem(42);
    bag1.addItem(10);
    bag1.addItem(42);
    bag1.addItem(99);

    bag2.addItem("Rabbit's Foot");
    bag2.addItem("Wand");
    bag2.addItem("Crystal Ball");

    bag3.addItem(1);
    bag3.addItem(2);
    bag3.addItem(3);

    bag4.addItem("Apples", 5);
    bag4.addItem("Milk", 2);
    bag4.addItem("Bread", 3);

    // Display bag contents
    std::cout << "Plain Bag:";
    bag1.displayContents();
    std::cout << "Magic Bag #1:";
    bag2.displayContents();
    std::cout << "Magic Bag #2:";
    bag3.displayContents();
    std::cout << "Shopping Bag:";
    bag4.displayContents();

    // Remove items from bags
    bool removed = bag1.removeItem(42);
    if (removed)
    {
        std::cout << "\nRemoved 42 from Plain Bag.\n";
    }
    else
    {
        std::cout << "\n42 not found in Plain Bag.\n";
    }

    removed = bag2.removeItem("Wand");
    if (removed)
    {
        std::cout << "Removed Wand from Magic Bag 1.\n";
    }
    else
    {
        std::cout << "Wand not found in Magic Bag 1.\n";
    }

    removed = bag3.removeItem(1);
    if (removed)
    {
        std::cout << "Removed 1 from Magic Bag 2.\n";
    }
    else
    {
        std::cout << "1 not found in Magic Bag 2.\n";
    }

    // Display updated bag contents
    std::cout << "\nUpdated Plain Bag:";
    bag1.displayContents();
    std::cout << "\nUpdated Magic Bag 1:";
    bag2.displayContents();
    std::cout << "\nUpdated Magic Bag 2:";
    bag3.displayContents();

    return 0;
}
