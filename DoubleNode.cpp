#include "DoubleNode.hpp"

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode() : next(nullptr), previous(nullptr) {}

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &one_item) : item(one_item), next(nullptr), previous(nullptr) {}

template <typename ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType &one_item, DoubleNode<ItemType> *nextNode, DoubleNode<ItemType> *previousNode)
    : Item(one_item), next(nextNode), previous(previousNode) {}

template <typename ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& one_item){
    item = one_item;
}

template <typename ItemType>
void DoubleNode<ItemType>::setNextNode(DoubleNode<ItemType>* nextNode){
    next = nextNode;
}

template <typename ItemType>
void DoubleNode<ItemType>::setPrevNode(DoubleNode<ItemType>* previousNode){
    previous = previousNode;
}

template <typename ItemType>
ItemType DoubleNode<ItemType>::getItem() const{
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
