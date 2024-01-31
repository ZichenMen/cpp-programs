/**
 * Binary Node class for a template Binary search tree class.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/13/2023
 * @version __1.0__
 *
 */

#ifndef Binary_Node_H
#define Binary_Node_H
#include <memory>

template <class T>
class BinaryNode
{
public:
    T data;                               // Data contained in the BinaryNode
    std::unique_ptr<BinaryNode<T>> left;  // Pointer to the left BinaryNode in the list
    std::unique_ptr<BinaryNode<T>> right; // Pointer to the right BinaryNode in the list

    /**
     * Parameterized constructor.
     * Initializes the data to the given value and sets left and right pointer to nullptr.
     * @param data The data to store in the BinaryNode.
     */
    BinaryNode(const T &data);
};

// Parameterized constructor
template <class T>
BinaryNode<T>::BinaryNode(const T &data) : data(data), left(nullptr), right(nullptr) {}

#endif
