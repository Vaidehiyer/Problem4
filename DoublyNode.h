/**
 * @file DoublyNode.h
 * @author Hakim Abdisalam
 * StartID: oc3378es
 * @brief DoublyNode header file
 * @version 0.1
 * @date 2024-07-07
 * Instructor: Jerome Covington
 * Due date: 07/08/2024
 *
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _DOUBLY_NODE
#define _DOUBLY_NODE

template <class ItemType>
class DoublyNode
{
private:
    ItemType item;              // A data item
    DoublyNode<ItemType> *next; // Pointer to next node
    DoublyNode<ItemType> *prev; // Pointer to previous node

public:
    /**
     * @brief Construct a new Doubly Node< Item Type>:: Doubly Node object
     *
     * @tparam ItemType
     */
    DoublyNode();

    /**
     * @brief Construct a new Doubly Node< Item Type>:: Doubly Node object
     *
     * @tparam ItemType
     * @param anItem : Item of the node
     */
    DoublyNode(const ItemType &anItem);

    /**
     * @brief Construct a new Doubly Node< Item Type>:: Doubly Node object
     *
     * @tparam ItemType
     * @param anItem : Item of the node
     * @param nextNodePtr : Pointer to next node
     * @param prevNodePtr : Pointer to previos node
     */
    DoublyNode(const ItemType &anItem, DoublyNode<ItemType> *nextNodePtr, DoublyNode<ItemType> *prevNodePtr);

    /**
     * @brief Setter of Item
     *
     * @tparam ItemType
     * @param anItem : Item to set
     */
    void setItem(const ItemType &anItem);

    /**
     * @brief Setter of next pointer
     *
     * @tparam ItemType
     * @param nextNodePtr : Next node pointer
     */
    void setNext(DoublyNode<ItemType> *nextNodePtr);

    /**
     * @brief Setter of previous pointer
     *
     * @tparam ItemType
     * @param prevNodePtr : previous node pointer
     */
    void setPrev(DoublyNode<ItemType> *prevNodePtr);

    /**
     * @brief Getter of item
     *
     * @tparam ItemType
     * @return ItemType: Item
     */
    ItemType getItem() const;

    /**
     * @brief Get the pointer to Next node
     *
     * @return DoublyNode<ItemType>* : next node ptr
     */
    DoublyNode<ItemType> *getNext() const;

    /**
     * @brief Get the pointer to Previous node
     *
     * @return DoublyNode<ItemType>* : prev node ptr
     */
    DoublyNode<ItemType> *getPrev() const;
};

#include "DoublyNode.cpp"
#endif
