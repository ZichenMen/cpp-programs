#include <cassert>
#include "DynamicArrayStack.h"

/**
 * The source file for DynamicArrayStack.
 * DynamicArrayStack is a derived class from the Stack class.
 * Implements the stack using a dynamic array data structure.
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/17/2023
 * @version ___1.0____
 */

/**
 * Default constructor.
 * Initializes an empty stack with default capacity of 10.
 */
template <class T>
DynamicArrayStack<T>::DynamicArrayStack(int initialSize) : top(-1), capacity(initialSize)
{
    arr = new T[capacity];
}

/**
 * Destructor
 * Frees the memory allocated by the stack.
 */
template <class T>
DynamicArrayStack<T>::~DynamicArrayStack()
{
    delete[] arr;
}

/**
 * Double the size of the array when full.
 */
template <class T>
void DynamicArrayStack<T>::resize()
{
    int newCapacity = 2 * capacity;
    T *newArr = new T[newCapacity];

    for (int i = 0; i <= top; ++i)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

/**
 * Push an item onto the stack.
 * @param item The item to push.
 */
template <class T>
void DynamicArrayStack<T>::push(const T &item)
{
    if (isFull())
    {
        resize();
    }
    arr[++top] = item;
}

/**
 * Pop an item from the stack.
 */
template <class T>
void DynamicArrayStack<T>::pop()
{
    assert(!isEmpty() && "Stack is empty");
    --top;
}

/**
 * Peek at the top item of the stack.
 * @return The top item of the stack.
 */
template <class T>
T DynamicArrayStack<T>::peek() const
{
    assert(!isEmpty() && "Stack is empty");
    return arr[top];
}

/**
 * Check if the stack is empty.
 * @return true if the stack is empty, false otherwise.
 */
template <class T>
bool DynamicArrayStack<T>::isEmpty() const
{
    return top == -1;
}

/**
 * Check if the stack is full.
 * @return true if the stack is full, false otherwise.
 */
template <class T>
bool DynamicArrayStack<T>::isFull() const
{
    return top == capacity - 1;
}
