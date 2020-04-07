#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

#include "DoubleNode.cpp"
#include <iostream>


template<typename ItemType>
class DoublyLinkedList
{
private:
    DoubleNode<ItemType>* headPtr;
    DoubleNode<ItemType>* tailPtr;
    int itCount;
public:
    DoublyLinkedList(); //This is the default constructor
    DoublyLinkedList(const DoublyLinkedList& copy); //copying the constructor
    virtual ~DoublyLinkedList(); //the destructor
    bool insert(ItemType item,const int& position); //this will insert item at the position
    bool remove(const int& position); //this will remove the node at the indexed position
    DoubleNode<ItemType> *getAtPos(const int& position) const; //returns the node that is at that position
    bool isEmpty() const; //says if list is empty or not
    void clear(); //this will clear the list
    void display() const; //this will display the content of the list in the order it's in
    void displayBackwards() const; //this displays it backwards
    int getSize() const;
    DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list);
    //This will alter the calling list to be interleaved list of the original and parameter list
    DoubleNode<ItemType> *getHeadPtr() const;
};
#include "DoublyLinkedList.cpp"
#endif
