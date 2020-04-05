#ifndef _DoubleNode
#define _DoubleNode

template<class ItemType>
class DoubleNode {

private:
    ItemType item; //the data item
    DoubleNode<ItemType>* previous; //pointer to the previous node
    DoubleNode<ItemType>* next; //pointer to the next node
public:
    //Default constructor
    DoubleNode();
    //Parameterized constructors
    DoubleNode(const ItemType& one_item);
    DoubleNode(const ItemType& one_item, DoubleNode<ItemType>* nextNode, DoubleNode<ItemType>* previousNode);
    //Sets item within DoubleNode
    void setItem(const ItemType& one_item);
    //Sets the next node of the DoubleNode
    void setNextNode(DoubleNode<ItemType>* nextNode);
    //Sets the previous node of the DoubleNode
    void setPrevNode(DoubleNode<ItemType>* previousNode);
    ItemType getItem() const;
    DoubleNode<ItemType>* getNextNode() const;
    DoubleNode<ItemType>* getPrevNode() const;

}; //end DoubleNode

#include "DoubleNode.cpp"
#endif
