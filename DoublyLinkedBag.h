/**
 * @file DoublyLinkedBag.h
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief DoublyLinkedBag header file
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 *
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG

#include "DoublyNode.h"
#include "bagInterface.h"
#include <vector>

template <class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
    DoublyNode<ItemType> *headPtr; // Pointer to first node
    DoublyNode<ItemType> *tailPtr; // Pointer to last node
    int itemCount;                 // Current count of bag items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    DoublyNode<ItemType> *getPointerTo(const ItemType &target) const;

public:
    /**
     * @brief Construct a new Doubly Linked Bag object
     *
     */
    DoublyLinkedBag();

    /**
     * @brief Construct a new Doubly Linked Bag object using a copy
     *
     * @param aBag : DoublyLinkedBag to copy
     */
    DoublyLinkedBag(const DoublyLinkedBag<ItemType> &aBag); // Copy constructor

    /**
     * @brief Destroy the Doubly Linked Bag object
     *
     */
    virtual ~DoublyLinkedBag();

    /**
     * @brief Get the Current Size of the doubly linked bag
     *
     * @return int : Size of the bag
     */
    int getCurrentSize() const;

    /**
     * @brief Checks if the bag is empty or not
     *
     * @return true if bag is empty; false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Adds a new entry into the Doubly linked bag
     *
     * @param newEntry : New item to add
     * @pre newEntry must not be empty
     * @post new entry gets added into the doubly linked list
     * @return true if item added successfully; false otherwise
     */
    bool add(const ItemType &newEntry);

    /**
     * @brief Removes an entry from the doubly linked list
     *
     * @param anEntry : Item to remove
     * @return true if item removed from bag; false otherwise
     */
    bool remove(const ItemType &anEntry);

    /**
     * @brief Clears out the doubly linked bag
     *
     */
    void clear();

    /**
     * @brief Checks if the bag contains an entry
     *
     * @param anEntry : Entry to check
     * @return true if bag contains the entry, false otherwise
     */
    bool contains(const ItemType &anEntry) const;

    /**
     * @brief Get the Frequency Of an item
     *
     * @param anEntry
     * @return int
     */
    int getFrequencyOf(const ItemType &anEntry) const;

    /**
     * @brief Converts the doubly linked bag to a vector
     *
     * @return std::vector<ItemType>
     */
    std::vector<ItemType> toVector() const;
};

#include "DoublyLinkedBag.cpp"
#endif
