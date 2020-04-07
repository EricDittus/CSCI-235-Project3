#ifndef DOUBLENODE_C_
#define DOUBLENODE_C_

#include "DoubleNode.hpp"

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode()
{
  item = 0;
  next = nullptr;
  previous = nullptr;
}

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType one_item)
{
  item = one_item;
  next = nullptr;
  previous = nullptr;
}



template <typename ItemType>
void DoubleNode<ItemType>::setItem(ItemType one_item){
    this->item = one_item;
}

template <typename ItemType>
void DoubleNode<ItemType>::setNextNode(DoubleNode<ItemType>* next){
    this -> next = next;
}

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
