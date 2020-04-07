#ifndef DOUBLENODE_C_
#define DOUBLENODE_C_

#include "DoubleNode.hpp"

//***********************************************//
//Part 1: 1. Default Constructor
//***********************************************//
template <typename ItemType>
DoubleNode<ItemType>::DoubleNode()
{
  item = 0;
  next = nullptr;
  previous = nullptr;
}

//***********************************************//
//Part 1: 2. Parameterized Constructor(s)
//Hint: You can use default parameters as
//you did in Project 1 to require the use
//of only a single parameterized constructor.
//***********************************************//
template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType one_item)
{
  item = one_item;
  next = nullptr;
  previous = nullptr;
}


//***********************************************//
//Part 1: 3. A method that allows you
//to set the item within the DoubleNode.
//***********************************************//
template <typename ItemType>
void DoubleNode<ItemType>::setItem(ItemType one_item){
    this->item = one_item;
}

//***********************************************//
//Part 1: 4. A method that allows you to
//set the next node of the DoubleNode.
//***********************************************//
template <typename ItemType>
void DoubleNode<ItemType>::setNextNode(DoubleNode<ItemType>* next){
    this -> next = next;
}

//***********************************************//
//Part 1: 5. A method that allows you to
//set the previous node of the DoubleNode.
//***********************************************//
template <typename ItemType>
void DoubleNode<ItemType>::setPrevNode(DoubleNode<ItemType>* previous){
    this -> previous = previous;
}

template <typename ItemType>
ItemType DoubleNode<ItemType>::getItem(){
    return item;
}


template <typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNextNode() const{
    return next;
}

template <typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevNode() const{
    return previous;
}

#endif
