/**
 * Template Queue implementation using a dynamic array, designed for Binary Search Tree serialization and deserialization.
 *
 * @author Zichen Men
 * @date 11/16/2023
 * @version 1.0
 */

#ifndef Queue_H
#define Queue_H

#include <vector>
#include <stdexcept>

template <typename T>
class Queue
{
private:
    std::vector<T> data; // Dynamic array to store elements
    int frontIndex;      // Index of the front element
    int size;            // Current size of the queue

public:
    /**
     * Default constructor.
     * Initializes an empty queue.
     */
    Queue() : frontIndex(0), size(0) {}

    /**
     * Enqueue an element to the back of the queue.
     * @param value The value to be added.
     */
    void enqueue(const T &value)
    {
        data.push_back(value);
        size++;
    }

    /**
     * Dequeue an element from the front of the queue.
     * @return The value at the front of the queue.
     * @throws std::runtime_error if the queue is empty.
     */
    T dequeue()
    {
        if (isEmpty())
            throw std::runtime_error("Queue is empty");
        T value = data[frontIndex++];
        size--;
        return value;
    }

    /**
     * Check if the queue is empty.
     * @return True if the queue is empty, False otherwise.
     */
    bool isEmpty() const
    {
        return size == 0;
    }
};

#endif // Queue_H
