#include "DoublyLinkedList.h"

/**
 * DoublyLinkedList class implements a template-based doubly linked list.
 *
 * pHead: Pointer to the head node of the list.
 * pTail: Pointer to the tail node of the list.
 * itemCount: count the item number of the list.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/30/2023
 * @version ___1.0___
 */

/**
 * Default constructor.
 * Initializes an empty list.
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : pHead(nullptr), pTail(nullptr), itemCount(0)
{
}

/**
 * Copy constructor.
 * Creates a deep copy of the given list.
 * @param aList The list to copy.
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &otherList)
{
    pHead = nullptr;
    pTail = nullptr;
    itemCount = 0;

    Node<T> *pCurrent = otherList.pHead;
    while (pCurrent != nullptr)
    {
        pushBack(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

/**
 * Assignment operator overload.
 * Assigns the contents of a given list to this list.
 * @param aList The list to assign from.
 * @return Reference to this list after assignment.
 */
template <class T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &aList)
{
    if (this != &aList)
    {
        clear(); // Clear current list

        // Copy from aList
        Node<T> *temp = aList.pHead;
        while (temp != nullptr)
        {
            pushBack(temp->getItem());
            temp = temp->getNext();
        }
    }
    return *this; // Return *this to allow chained assignment
}

/**
 * Check if the list is empty.
 * @return true if the stack is empty, false otherwise.
 */
template <class T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return itemCount == 0;
}

/**
 * Check the size of the list.
 * @return the items number of the list.
 */
template <class T>
int DoublyLinkedList<T>::getSize() const
{
    return itemCount;
}

/**
 * Get the node at a given index in the list.
 * Note: Indexing starts at 0.
 * @param index The index of the node in the list.
 * @return A pointer to the node at the given index.
 */
template <class T>
Node<T> *DoublyLinkedList<T>::at(int index) const
{
    if (index < 0 || index >= itemCount)
    {
        throw PreconViolatedExcept();
    }

    Node<T> *pCurrent = pHead;
    for (int i = 0; i < index; i++)
    {
        pCurrent = pCurrent->next;
    }

    return pCurrent;
}

/**
 * Append a new entry to the end of the list.
 * @param newEntry The entry to be appended.
 */
template <class T>
void DoublyLinkedList<T>::pushBack(const T &newEntry)
{
    Node<T> *pNewNode = new Node<T>(newEntry);
    if (itemCount == 0)
    {
        pHead = pNewNode;
        pTail = pNewNode;
    }
    else
    {

        pTail->next = pNewNode;
        pNewNode->prev = pTail;
        pTail = pNewNode;
    }
    itemCount++;
}

/**
 * Check if the list contains a given entry.
 * @param entry The entry to be searched for.
 * @return true if the entry is found, false otherwise.
 */
template <class T>
bool DoublyLinkedList<T>::contains(const T &entry) const
{
    Node<T> *pCurrent = pHead;
    while (pCurrent != nullptr)
    {
        if (pCurrent->data == entry)
        {
            return true;
        }
        pCurrent = pCurrent->next;
    }
    return false;
}

/**
 * Replace the value at a given index in the list.
 * Note: Indexing starts at 0.
 * @param index The index of the node to replace.
 * @param newEntry The new value to insert.
 * @return true if replacement is successful, false otherwise.
 */
template <class T>
bool DoublyLinkedList<T>::replace(int index, const T &newEntry)
{
    if (index < 0 || index >= itemCount)
    {
        throw PreconViolatedExcept();
    }

    Node<T> *pCurrent = at(index);
    pCurrent->data = newEntry;

    return true;
}

/**
 * Removes the first occurrence of the given entry.
 * @param entry The targeting entry.
 * @return true if the item has been removed, false otherwise.
 */
template <class T>
bool DoublyLinkedList<T>::remove(const T &entry)
{
    Node<T> *pCurrent = pHead;
    while (pCurrent != nullptr)
    {
        if (pCurrent->data == entry)
        {
            // Handle previous node
            if (pCurrent->prev != nullptr)
            {
                pCurrent->prev->next = pCurrent->next;
            }
            else
            {
                pHead = pCurrent->next;
            }

            // Handle next node
            if (pCurrent->next != nullptr)
            {
                pCurrent->next->prev = pCurrent->prev;
            }
            else
            {
                pTail = pCurrent->prev;
            }

            delete pCurrent;
            itemCount--;
            return true;
        }
        pCurrent = pCurrent->next;
    }
    return false;
}

/**
 * Clear all nodes from the list.
 */
template <class T>
void DoublyLinkedList<T>::clear()
{
    while (pHead != nullptr)
    {
        Node<T> *temp = pHead->next;
        delete pHead;
        pHead = temp;
        itemCount--;
    }
}

/**
 * Destructor.
 * Frees all the dynamically allocated memory in the list.
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}
