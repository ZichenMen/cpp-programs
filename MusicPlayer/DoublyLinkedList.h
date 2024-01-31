#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include "PreconViolatedExcept.h"

/**
 * DoublyLinkedList class implements a template-based doubly linked list.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/30/2023
 * @version ___1.0___
 */

template <class T>
class DoublyLinkedList
{
private:
    Node<T> *pHead; // Pointer to the head node of the list.
    Node<T> *pTail; // Pointer to the tail node of the list.
    int itemCount;  // Count the item number of the list.

public:
    /**
     * Default constructor.
     * Initializes an empty list.
     */
    DoublyLinkedList();

    /**
     * Copy constructor.
     * Creates a deep copy of the given list.
     * @param aList The list to copy.
     */
    DoublyLinkedList(const DoublyLinkedList<T> &aList);

    /**
     * Assignment operator overload.
     * Assigns the contents of a given list to this list.
     * @param aList The list to assign from.
     * @return Reference to this list after assignment.
     */
    DoublyLinkedList<T> &operator=(const DoublyLinkedList<T> &aList);

    /**
     * Destructor.
     * Frees all the dynamically allocated memory in the list.
     */
    ~DoublyLinkedList();

    /**
     * Check if the list is empty.
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * Check the size of the list.
     * @return the items number of the list.
     */
    int getSize() const;

    /**
     * Get the node at a given index in the list.
     * Note: Indexing starts at 0.
     * @param index The index of the node in the list.
     * @return A pointer to the node at the given index.
     */
    Node<T> *at(int index) const;

    /**
     * add a new entry to the end of the list.
     * @param newEntry The entry to be appended.
     */
    void pushBack(const T &newEntry);

    /**
     * Check if the list contains a given entry.
     * @param entry The entry to be searched for.
     * @return true if the entry is found, false otherwise.
     */
    bool contains(const T &entry) const;

    /**
     * Replace the value at a given index in the list.
     * Note: Indexing starts at 0.
     * @param index The index of the node to replace.
     * @param newEntry The new value to insert.
     * @return true if replacement is successful, false otherwise.
     */
    bool replace(int index, const T &newEntry);

    /**
     * Removes the first occurrence of the given entry.
     * @param entry The targeting entry.
     * @return true if the item has been removed, false otherwise.
     */
    bool remove(const T &entry);

    /**
     * Clear all nodes from the list.
     */
    void clear();
};

#include "DoublyLinkedList.cpp"
#endif