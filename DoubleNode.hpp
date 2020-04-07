#ifndef _DOUBLE_NODE_H_
#define _DOUBLE_NODE_H_


template<typename ItemType>
class DoubleNode {

private:
    ItemType item; //the data item
    DoubleNode<ItemType>* previous; //pointer to the previous node
    DoubleNode<ItemType>* next; //pointer to the next node
public:
    //Default constructor
    DoubleNode();
    //Parameterized constructors
    DoubleNode(ItemType one_item);

    //Sets item within DoubleNode
    void setItem(ItemType one_item);
    //Sets the next node of the DoubleNode
    void setNextNode(DoubleNode<ItemType>* next);
    //Sets the previous node of the DoubleNode
    void setPrevNode(DoubleNode<ItemType>* previous);
    ItemType getItem();
    DoubleNode<ItemType>* getNextNode() const;
    DoubleNode<ItemType>* getPrevNode() const;

}; //end DoubleNode


#endif
