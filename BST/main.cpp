/**
 * Main program file with user interaction for BST operations,
 * and demonstration of file I/O for serialization/deserialization.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/17/2023
 * @version __1.0__
 *
 */

#include "BST.h"
#include <iostream>
#include <string>

int main()
{
    BST<int> bst;
    int choice, value;
    std::string filename;

    while (true)
    {
        std::cout << "-- Binary Search Tree Operations --\n";
        std::cout << "1. Insert Element\n";
        std::cout << "2. Serialize BST to File\n";
        std::cout << "3. Deserialize BST from File\n";
        std::cout << "4. Search in the BST\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter value to be inserted: ";
            std::cin >> value;
            bst.insert(value);
            std::cout << "\n";
            break;
        case 2:
            bst.saveToFile("bst_serialized.txt");
            std::cout << "BST serialized and saved to file successfully\n";
            std::cout << "\n";
            break;
        case 3:
            std::cout << "Enter file name: ";
            std::cin >> filename;
            bst.loadFromFile(filename);
            std::cout << "BST deserialized from file successfully.\n";
            bst.displayLevelOrder();
            std::cout << "\n";
            break;
        case 4:
            std::cout << "Enter a value: ";
            std::cin >> value;
            if (bst.search(value))
            {
                std::cout << "Search result: found\n";
            }
            else
            {
                std::cout << "Search result: not found\n";
            }
            std::cout << "\n";
            break;
        case 5:
            std::cout << "Exiting program\n";
            return 0;
        default:
            std::cout << "Invalid choice, please try again.\n";
            std::cout << "\n";
        }
    }

    return 0;
}
