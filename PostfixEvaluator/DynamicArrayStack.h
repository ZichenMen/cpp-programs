#ifndef DYNAMIC_ARRAY_STACK_H
#define DYNAMIC_ARRAY_STACK_H

#include "Stack.h"
#include <cassert>

/**
 * DynamicArrayStack is derived from the Stack class and implements a stack
 * using a dynamic array.
 * arr: Pointer to the dynamically allocated array.
 * top: Index to the top element in the array.
 * capacity: The current capacity of the array.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/17/2023
 * @version ___1.0___
 */

template <class T>
class DynamicArrayStack : public Stack<T>
{
private:
    T *arr;       // Pointer to the dynamically allocated array
    int top;      // Index to the top element
    int capacity; // Current capacity of the array

    // Double the size of the array when full
    void resize();

public:
    /**
     * Default constructor.
     * Initializes an empty stack with a default capacity of 10.
     */
    DynamicArrayStack(int = 10);

    /**
     * Destructor.
     * Frees the memory allocated by the stack.
     */
    virtual ~DynamicArrayStack();

    /**
     * Push an item onto the stack.
     * @param item The item to push.
     */
    void push(const T &item) override;

    /**
     * Pop an item from the stack.
     */
    void pop() override;

    /**
     * Peek at the top item of the stack.
     * @return The top item of the stack.
     */
    T peek() const override;

    /**
     * Check if the stack is empty.
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty() const override;

    /**
     * Check if the stack is full.
     * @return true if the stack is full, false otherwise.
     */
    bool isFull() const override;
};

#include "DynamicArrayStack.cpp"

#endif
