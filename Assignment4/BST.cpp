/**
 * A template Binary search tree that supports insertion, deletion, and
 * search operations, and implementation of big rule of three
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/13/2023
 * @version __1.0__
 *
 */

#include "BST.h"

/**
 * Default constructor.
 * Initializes an empty BST.
 */
template <class T>
BST<T>::BST() : root(nullptr)
{
}

/**
 * Copy constructor.
 * Creates a deep copy of the given BST.
 * @param other the BST needed to be copy.
 */
template <class T>
BST<T>::BST(const BST<T> &other) : root(copyTree(other.root))
{
}

/**
 * Helper function for copy constructor.
 * @param node the current node that the function is examining.
 */
template <class T>
std::unique_ptr<BinaryNode<T>> BST<T>::copyTree(const std::unique_ptr<BinaryNode<T>> &node)
{
    if (!node)
        return nullptr;
    auto newNode = std::make_unique<BinaryNode<T>>(node->data);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

/**
 * Assignment operator overload.
 * Assigns the contents of a given BST to this BST.
 * @param other The BST to assign from.
 * @return Reference to this BST after assignment.
 */
template <class T>
BST<T> &BST<T>::operator=(const BST<T> &other)
{
    if (this != &other)
    {
        root = copyTree(other.root);
    }
    return *this;
}

/**
 * Add a new value to the BST.
 * @param value The value needed to be added.
 */
template <class T>
void BST<T>::insert(const T &value)
{
    root = insertNode(std::move(root), value);
}

/**
 * Helper function for insert.
 * Recursively traverse the tree to find the appropriate position for the new value.
 * @param node the current node that the function is examining.
 * @param value the value need to be added.
 */
template <class T>
std::unique_ptr<BinaryNode<T>> BST<T>::insertNode(std::unique_ptr<BinaryNode<T>> node, const T &value)
{
    if (!node)
    {
        return std::make_unique<BinaryNode<T>>(value);
    }
    if (value < node->data)
    {
        node->left = insertNode(std::move(node->left), value);
    }
    else if (value > node->data)
    {
        node->right = insertNode(std::move(node->right), value);
    }
    return node;
}

/**
 * Remove a given value from the BST.
 * @param value The value needed to be removed.
 */
template <class T>
void BST<T>::remove(const T &value)
{
    root = removeNode(std::move(root), value);
}

/**
 * Helper function for remove.
 * Recursively traverse the tree to find the target node to delete.
 * @param node the current node that the function is examining.
 * @param value the value of the node needed to be removed.
 */
template <class T>
std::unique_ptr<BinaryNode<T>> BST<T>::removeNode(std::unique_ptr<BinaryNode<T>> node, const T &value)
{
    if (!node)
        return nullptr;
    if (value < node->data)
    {
        node->left = removeNode(std::move(node->left), value);
    }
    else if (value > node->data)
    {
        node->right = removeNode(std::move(node->right), value);
    }
    else
    {
        if (!node->left)
            return std::move(node->right);
        else if (!node->right)
            return std::move(node->left);
        node->data = findMin(node->right.get());
        node->right = removeNode(std::move(node->right), node->data);
    }
    return node;
}

/**
 * Helper function for removeNode.
 * Return the minimum value of the subtree.
 * @param node the current node that the function is examining.
 */
template <class T>
T BST<T>::findMin(BinaryNode<T> *node) const
{
    while (node && node->left)
        node = node->left.get();
    return node->data;
}

/**
 * Search the given value in BST.
 * @param value The value needed to be found.
 */
template <class T>
bool BST<T>::search(const T &value) const
{
    return searchNode(root.get(), value);
}

/**
 * Helper function for search.
 * Recursively traverse the tree to find a node with the given value.
 * @param node the current node that the function is examining.
 * @param value the value of the node needed to be found.
 */
template <class T>
bool BST<T>::searchNode(const BinaryNode<T> *node, const T &value) const
{
    if (!node)
        return false;
    if (value == node->data)
        return true;
    return value < node->data ? searchNode(node->left.get(), value) : searchNode(node->right.get(), value);
}

/**
 * Perform a level-order traversal of the BST,
 * and convert each node's value into a string representation.
 */
template <class T>
std::string BST<T>::serializeLevelOrder() const
{
    if (!root)
        return "";

    Queue<BinaryNode<T> *> queue;
    std::string result;

    queue.enqueue(root.get());
    while (!queue.isEmpty())
    {
        BinaryNode<T> *current = queue.dequeue();
        if (current)
        {
            result += std::to_string(current->data) + ",";
            queue.enqueue(current->left.get());
            queue.enqueue(current->right.get());
        }
        else
        {
            result += "#,";
        }
    }

    return result;
}

/**
 * Take a string representation of a BST and reconstruct the tree.
 * @param data the string representation of a BST
 */
template <class T>
void BST<T>::deserializeLevelOrder(const std::string &data)
{
    if (data.empty())
    {
        root = nullptr;
        return;
    }

    std::stringstream ss(data);
    std::string item;
    getline(ss, item, ',');
    root = std::make_unique<BinaryNode<T>>(std::stoi(item));

    Queue<BinaryNode<T> *> queue;
    queue.enqueue(root.get());

    while (!queue.isEmpty())
    {
        BinaryNode<T> *current = queue.dequeue();
        if (getline(ss, item, ','))
        {
            if (item != "#")
            {
                current->left = std::make_unique<BinaryNode<T>>(std::stoi(item));
                queue.enqueue(current->left.get());
            }
        }
        if (getline(ss, item, ','))
        {
            if (item != "#")
            {
                current->right = std::make_unique<BinaryNode<T>>(std::stoi(item));
                queue.enqueue(current->right.get());
            }
        }
    }
}

/**
 * Serialize the BST to a file.
 * @param filename the file's name
 */
template <class T>
void BST<T>::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << serializeLevelOrder();
        file.close();
    }
    else
    {
        throw PreconViolatedExcept();
    }
}

/**
 * Rebuild the BST from a file
 * @param filename the file's name
 */
template <class T>
void BST<T>::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string data;
        std::getline(file, data);
        file.close();
        deserializeLevelOrder(data);
    }
    else
    {
        throw PreconViolatedExcept();
    }
}

/**
 * Display the structure of the BST in level order.
 */
template <class T>
void BST<T>::displayLevelOrder() const
{
    if (!root)
    {
        std::cout << "The BST is empty." << std::endl;
        return;
    }

    Queue<BinaryNode<T> *> queue;
    queue.enqueue(root.get());

    while (!queue.isEmpty())
    {
        BinaryNode<T> *current = queue.dequeue();
        std::cout << current->data << " ";

        if (current->left)
        {
            queue.enqueue(current->left.get());
        }

        if (current->right)
        {
            queue.enqueue(current->right.get());
        }
    }

    std::cout << std::endl;
}

/**
 * Destructor.
 * Smart pointers automatically cleaned up.
 */
template <class T>
BST<T>::~BST()
{
}