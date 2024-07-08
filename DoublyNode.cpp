/**
 * @file DoublyNode.cpp
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief DoublyNode implementation file
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 * 
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "DoublyNode.h"
#include <cstddef>

/**
 * @brief Construct a new Doubly Node< Item Type>:: Doubly Node object
 * 
 * @tparam ItemType 
 */
template <class ItemType>
DoublyNode<ItemType>::DoublyNode() : next(nullptr), prev(nullptr)
{
}

/**
 * @brief Construct a new Doubly Node< Item Type>:: Doubly Node object
 * 
 * @tparam ItemType 
 * @param anItem : Item of the node
 */
template <class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
{
}

/**
 * @brief Construct a new Doubly Node< Item Type>:: Doubly Node object
 * 
 * @tparam ItemType 
 * @param anItem : Item of the node
 * @param nextNodePtr : Pointer to next node
 * @param prevNodePtr : Pointer to previos node
 */
template <class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextNodePtr, DoublyNode<ItemType>* prevNodePtr)
    : item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
}

/**
 * @brief Setter of Item
 * 
 * @tparam ItemType 
 * @param anItem : Item to set
 */
template <class ItemType>
void DoublyNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

/**
 * @brief Setter of next pointer
 * 
 * @tparam ItemType 
 * @param nextNodePtr : Next node pointer
 */
template <class ItemType>
void DoublyNode<ItemType>::setNext(DoublyNode<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

/**
 * @brief Setter of previous pointer
 * 
 * @tparam ItemType 
 * @param prevNodePtr : previous node pointer
 */
template <class ItemType>
void DoublyNode<ItemType>::setPrev(DoublyNode<ItemType>* prevNodePtr)
{
    prev = prevNodePtr;
}

/**
 * @brief Getter of item
 * 
 * @tparam ItemType 
 * @return ItemType 
 */
template <class ItemType>
ItemType DoublyNode<ItemType>::getItem() const
{
    return item;
}

template <class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getNext() const
{
    return next;
}

template <class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getPrev() const
{
    return prev;
}
