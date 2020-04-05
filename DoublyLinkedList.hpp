#ifndef _DoublyLinkedList
#define _DoublyLinkedList

#include "DoubleNode.hpp"

template<typename ItemType>
class DoublyLinkedList
{
private:
    DoubleNode<ItemType>* headPtr;
    DoubleNode<ItemType>* tailPtr;
    int itCount;
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<ItemType>& double_list);
    virtual ~DoublyLinkedList();
    bool insert(const ItemType& item, const int& position);
    bool remove(const int& position);
    int getSize() const;
    DoubleNode<ItemType> *getHeadPtr();
    DoubleNode<ItemType> *getAtPos(const int& position) const;
    bool isEmpty() const;
    void clear();
    void display() const;
    void displayBackwards() const;
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list);
};

#endif
