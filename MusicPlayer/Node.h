#ifndef NODE_H
#define NODE_H

/**
 * Node class for a templated linked list.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 10/30/2023
 * @version __1.0__
 */

template <class T>
class Node
{
public:
    T data;        // Data contained in the node
    Node<T> *next; // Pointer to the next node in the list
    Node<T> *prev; // Pointer to the previous node in the list

    /**
     * Default constructor.
     * Initializes the data to its default and sets next to nullptr.
     */
    Node();

    /**
     * Parameterized constructor.
     * Initializes the data to the given value and sets next to nullptr.
     * @param data The data to store in the node.
     */
    Node(const T &data);

    /**
     * Parameterized constructor.
     * Initializes the data and next pointer to the given values.
     * @param data The data to store in the node.
     * @param nextNode Pointer to the next node in the list.
     */
    Node(const T &data, Node<T> *nextNode);

    /**
     * Destructor.
     * No dynamic allocation in the class, so it's empty.
     */
    ~Node();
};

// Include the definitions in the header if using templates
// Default constructor
template <class T>
Node<T>::Node() : data(T()), next(nullptr) {}

// Parameterized constructor
template <class T>
Node<T>::Node(const T &data) : data(data), next(nullptr) {}

// Parameterized constructor with next node
template <class T>
Node<T>::Node(const T &data, Node<T> *nextNode) : data(data), next(nextNode) {}

// Destructor
template <class T>
Node<T>::~Node() {}

#endif
