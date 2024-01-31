/**
 * A template Binary search tree that supports insertion, deletion, and
 * search operations, and implementation of big rule of three
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/13/2023
 * @version __1.0__
 *
 */

#ifndef BST_H
#define BST_H
#include "BinaryNode.h"
#include "Queue.h"
#include "PreconViolatedExcept.h"
#include <memory>
#include <string>
#include <fstream>
#include <sstream>

template <class T>
class BST
{
private:
    std::unique_ptr<BinaryNode<T>> root;

    /**
     * Helper function for copy constructor.
     * @param node the current node that the function is examining.
     */
    std::unique_ptr<BinaryNode<T>> copyTree(const std::unique_ptr<BinaryNode<T>> &node);

    /**
     * Helper function for insert.
     * Recursively traverse the tree to find the appropriate position for the new value.
     * @param node the current node that the function is examining.
     * @param value the value need to be added.
     */
    std::unique_ptr<BinaryNode<T>> insertNode(std::unique_ptr<BinaryNode<T>> node, const T &value);

    /**
     * Helper function for remove.
     * Recursively traverse the tree to find the target node to delete.
     * @param node the current node that the function is examining.
     * @param value the value of the node needed to be removed.
     */
    std::unique_ptr<BinaryNode<T>> removeNode(std::unique_ptr<BinaryNode<T>> node, const T &value);

    /**
     * Helper function for removeNode.
     * Return the minimum value of the subtree.
     * @param node the current node that the function is examining.
     */
    T findMin(BinaryNode<T> *node) const;

    /**
     * Helper function for search.
     * Recursively traverse the tree to find a node with the given value.
     * @param node the current node that the function is examining.
     * @param value the value of the node needed to be found.
     */
    bool searchNode(const BinaryNode<T> *node, const T &value) const;

public:
    /**
     * Default constructor.
     * Initializes an empty BST.
     */
    BST();

    /**
     * Copy constructor.
     * Creates a deep copy of the given BST.
     * @param other the BST needed to be copy.
     */
    BST(const BST<T> &other);

    /**
     * Assignment operator overload.
     * Assigns the contents of a given BST to this BST.
     * @param other The BST to assign from.
     * @return Reference to this BST after assignment.
     */
    BST<T> &operator=(const BST<T> &other);

    /**
     * Add a new value to the BST.
     * @param value The value needed to be added.
     */
    void insert(const T &value);

    /**
     * Remove a given value from the BST.
     * @param value The value needed to be removed.
     */
    void remove(const T &value);

    /**
     * Search the given value in BST.
     * @param value The value needed to be found.
     */
    bool search(const T &value) const;

    /**
     * Perform a level-order traversal of the BST,
     * and convert each node's value into a string representation.
     */
    std::string serializeLevelOrder() const;

    /**
     * Take a string representation of a BST and reconstruct the tree.
     * @param data the string representation of a BST
     */
    void deserializeLevelOrder(const std::string &);

    /**
     * Serialize the BST to a file.
     * @param filename the file's name
     */
    void saveToFile(const std::string &filename);

    /**
     * Rebuild the BST from a file
     * @param filename the file's name
     */
    void loadFromFile(const std::string &filename);

    /**
     * Display the structure of the BST in level order.
     */
    void displayLevelOrder() const;

    /**
     * Destructor.
     * Smart pointers automatically cleaned up.
     */
    ~BST();
};

#include "BST.cpp"
#endif