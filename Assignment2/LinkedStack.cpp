#include <cassert>
#include "LinkedStack.h"

/**
 * The source file of LinkedStack.
 * LinkedStack class is a derived class from Stack class.
 * Implementing the stack using linked list data structure.
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/17/2023
 * @version ___1.0____
 */

/**
 * Default constructor.
 * Initializes the top pointer to nullptr.
 */
template <class T>
LinkedStack<T>::LinkedStack() : pTop(nullptr) {}

/**
 * Destructor
 * Pop remaining elements from the stack until the stack become empty.
 */
template <class T>
LinkedStack<T>::~LinkedStack()
{
    // Postcondition: All elements of the stack are removed
    while (!isEmpty())
        pop();
}

/**
 * Push an item onto the stack.
 * @param item The item to push.
 */
template <class T>
void LinkedStack<T>::push(const T &newItem)
{
    Node<T> *newNodePtr = new Node<T>(newItem, pTop);
    pTop = newNodePtr;
    newNodePtr = nullptr;
}

/**
 * Pop an item from the stack.
 */
template <class T>
void LinkedStack<T>::pop()
{
    if (!isEmpty())
    {
        Node<T> *nodeToDeletePtr = pTop;
        pTop = pTop->next;

        nodeToDeletePtr->next = nullptr;
        delete nodeToDeletePtr;
    }
}

/**
 * Peek at the top item of the stack.
 * @return The top item of the stack.
 */
template <class T>
T LinkedStack<T>::peek() const
{
    assert(pTop != nullptr && "Stack is empty");
    return pTop->data;
}

/**
 * Check if the stack is empty.
 * @return true if the stack is empty, false otherwise.
 */
template <class T>
bool LinkedStack<T>::isEmpty() const
{
    return pTop == nullptr;
}

/**
 * Check if the stack is full.
 * For a linked-list implementation, it's usually determined by system memory.
 * @return true if the stack is full, false otherwise.
 */
template <class T>
bool LinkedStack<T>::isFull() const
{
    return pTop != nullptr;
}