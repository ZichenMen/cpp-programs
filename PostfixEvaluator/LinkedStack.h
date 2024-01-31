#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "Stack.h"
#include "Node.h"

/**
 * Header file for LinkedStack class.
 * LinkedStack is derived from the Stack class and implements a stack
 * using a singly linked list.
 * pTop: Pointer to the top node of the stack.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/17/2023
 * @version ___1.0___
 */

template <class T>
class LinkedStack : public Stack<T>
{
private:
    Node<T> *pTop; // Pointer to the top node

public:
    /**
     * Default constructor.
     * Initializes the top pointer to nullptr.
     */
    LinkedStack();

    /**
     * Destructor.
     * Frees the memory allocated by the stack.
     */
    virtual ~LinkedStack();

    /**
     * Check if the stack is empty.
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty() const override;

    /**
     * Push an item onto the stack.
     * @param item The item to push.
     */
    void push(const T &) override;

    /**
     * Pop an item from the stack.
     */
    void pop() override;

    /**
     * Check if the stack is full.
     * For a linked-list implementation, it's usually determined by system memory.
     * @return true if the stack is full, false otherwise.
     */
    bool isFull() const override;

    /**
     * Peek at the top item of the stack.
     * @return The top item of the stack.
     */
    T peek() const override;
};

#include "LinkedStack.cpp"

#endif
