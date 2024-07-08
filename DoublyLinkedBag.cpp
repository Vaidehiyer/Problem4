/**
 * @file DoublyLinkedBag.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief DoublyLinkedBag implementation file
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 * 
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "DoublyLinkedBag.h"

// Constructor: Initializes an empty DoublyLinkedBag
template <class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
}

// Copy Constructor: Creates a new DoublyLinkedBag that is a copy of an existing one
template <class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType> &aBag)
{
    itemCount = aBag.itemCount;
    DoublyNode<ItemType> *origChainPtr = aBag.headPtr;

    if (origChainPtr == nullptr)
        headPtr = nullptr; // Original bag is empty; so is copy
    else
    {
        // Create new head node
        headPtr = new DoublyNode<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        headPtr->setPrev(nullptr);
        DoublyNode<ItemType> *newChainPtr = headPtr;

        // Copy the rest of the chain
        while (origChainPtr->getNext() != nullptr)
        {
            origChainPtr = origChainPtr->getNext();
            ItemType nextItem = origChainPtr->getItem();
            DoublyNode<ItemType> *newNodePtr = new DoublyNode<ItemType>(nextItem, nullptr, newChainPtr);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newNodePtr;
        }

        // Set the tail pointer
        tailPtr = newChainPtr;
    }
}

// Destructor: Clears the bag to free up memory
template <class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
    clear();
}

// Returns the current size of the bag
template <class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

// Checks if the bag is empty
template <class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

// Adds a new entry to the bag
template <class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType &newEntry)
{
    // Create a new node for the entry
    DoublyNode<ItemType> *newNodePtr = new DoublyNode<ItemType>(newEntry, nullptr, tailPtr);

    if (isEmpty())
        headPtr = newNodePtr; // Bag was empty, new node is now the head
    else
        tailPtr->setNext(newNodePtr); // Append to the end of the list

    tailPtr = newNodePtr; // Update tail pointer
    itemCount++;
    return true;
}

// Converts the bag contents to a vector
template <class ItemType>
std::vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    DoublyNode<ItemType> *curPtr = headPtr;

    // Traverse the list and add each item to the vector
    while (curPtr != nullptr)
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
    }

    return bagContents;
}

// Checks if the bag contains a specific entry
template <class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType &anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}

// Gets a pointer to a node containing the target entry, or nullptr if not found
template <class ItemType>
DoublyNode<ItemType> *DoublyLinkedBag<ItemType>::getPointerTo(const ItemType &target) const
{
    DoublyNode<ItemType> *curPtr = headPtr;
    DoublyNode<ItemType> *endPtr = tailPtr;

    // Traverse the list from both ends
    while (curPtr != nullptr && endPtr != nullptr)
    {
        if (target == curPtr->getItem())
            return curPtr;
        else if (target == endPtr->getItem())
            return endPtr;
        else
        {
            curPtr = curPtr->getNext();
            endPtr = endPtr->getPrev();
        }
    }

    return nullptr;
}

// Removes an entry from the bag
template <class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType &anEntry)
{
    DoublyNode<ItemType> *entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

    if (canRemoveItem)
    {
        if (entryNodePtr == headPtr)
        {
            headPtr = headPtr->getNext(); // Update head pointer
            if (headPtr != nullptr)
                headPtr->setPrev(nullptr);
            else
                tailPtr = nullptr; // Bag is now empty
        }
        else if (entryNodePtr == tailPtr)
        {
            tailPtr = tailPtr->getPrev(); // Update tail pointer
            tailPtr->setNext(nullptr);
        }
        else
        {
            // Node is in the middle
            DoublyNode<ItemType> *prevNodePtr = entryNodePtr->getPrev();
            DoublyNode<ItemType> *nextNodePtr = entryNodePtr->getNext();
            prevNodePtr->setNext(nextNodePtr);
            nextNodePtr->setPrev(prevNodePtr);
        }

        delete entryNodePtr; // Free memory
        itemCount--;
    }

    return canRemoveItem;
}

// Clears all entries from the bag
template <class ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
    while (headPtr != nullptr)
    {
        DoublyNode<ItemType> *nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        delete nodeToDeletePtr;
    }

    headPtr = nullptr;
    tailPtr = nullptr;
    itemCount = 0;
}

// Gets the frequency of a specific entry in the bag
template <class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const
{
    int frequency = 0;
    DoublyNode<ItemType> *curPtr = headPtr;

    // Traverse the list and count the occurrences of anEntry
    while (curPtr != nullptr)
    {
        if (anEntry == curPtr->getItem())
            frequency++;
        curPtr = curPtr->getNext();
    }

    return frequency;
}
