#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"


template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
  //This will initialize the data
  headPtr = nullptr;
  itCount = 0;
}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList& copy)
{
//this will copy each node
//I must create a pointer that iterated using a loop through the list
  DoubleNode<ItemType>* rater = copy.headPtr;
  for(int i = 1; i <= copy.itCount; i++){
    ItemType item = rater -> getItem();
    this -> insert(i,item);
    rater = rater -> getNextNode();
  }
}


template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
  //This will delete all of the nodes
   clear();
}//end destructor


template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(ItemType item, const int& position)
{
  //I must first be sure position is correct
  if(position <1 || position > size + 1){
    return false;
  }else{
    DoubleNode<ItemType>* node = new DoubleNode<ItemType>(item);
    if(position == 1){
      if(headPtr == nullptr){
        headPtr = node;
      }else{
        node -> setNextNode(headPtr);
        headPtr -> setPrevNode(node);
        headPtr = node;
      }
    }else{
      DoubleNode<ItemType>* rater = headPtr;
      for(int i = 2; i < position; i++){
        rater = rater -> getNextNode();
      }
      if(rater -> getNextNode()!= nullptr){
        rater -> getNextNode() -> setPrevNode(node);
        node->setNextNode(rater->getNextNode());
      }
      rater -> setNextNode(node);
      node -> setPrevNode(rater);
    }
    itCount++;
    return true
  }
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
  if(position < 1 || position > itCount){
    return false
  }else{
    DoubleNode<ItemType>* sub;
    if(position == 1){
      sub = headPtr;
      headPtr = headPtr ->getNextNode();
      if(headPtr != nullptr){
        headPtr ->setPrevNode(nullptr);
      }
      delete sub;
    }else{
      DoubleNode<ItemType>* rater = headPtr;
      for(int i = 2; i< position; i++){
        sub = rater -> getNextNode();
        if(rater -> getNextNode() -> getNextNode() != nullptr){
          rater -> getNextNode() -> getNextNode() -> setPrevNode(rater);
          rater -> setNextNode(rater -> setNextNode() -> getNextNode());
        }else{
          rater -> setNextNode(nullptr)
        }
        delete sub;
      }
    }
    itCount --;
    return true;
  }
}



template <typename ItemType>
DoublyLinkedList<ItemType>::DoubleNode<ItemType> *getAtPos(const int& position) const
{
  if(position < 1 || position > size){
    return nullptr;
  }else{
    DoubleNode<ItemType>* rater = headPtr;
    for(int i = 1; i < position; i++){
      rater = rater -> getNextNode();
    }
    return rater;
  }
}


template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
return itCount == 0;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::clear()
{
  //this will delete all of the nodes from the list
  itCount = 0;
  DoubleNode<ItemType>* sub = headPtr;
  while(headPtr != nullptr){
    headPtr = headPtr -> getNextNode();
    delete sub;
    sub = headPtr;
  }
  delete sub;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::display() const
{
  //this will print the data in the list
  DoubleNode<ItemType>* rater = headPtr;
  for(int i = 0; i < itCount; i++){
    std::cout << rater -> getItem();
    if(i < itCount-1){
      std::cout << " ";
      //This will put a space after each node except the last
    }
    //Now on to the next node
    rater = rater -> getNextNode();
  }
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
  //I need to first go to the end of the list
  DoubleNode<ItemType>* rater = headPtr;
  for(int i = 1; i < itCount; i++){
    rater = rater -> getNextNode();
  }
  for(int i = 0; i < itCount; i++){
    std::cout << rater ->getItem();
    if(i < itCount - 1){
      //Gives a space after every node except the last
      std::cout << " ";
    }
    rater = rater -> getPrevNode();
  }
}


template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list)
{
  //I need to first make a list to return
  DoublyLinkedList<ItemType>* return_list = new DoublyLinkedList();
  int location = 1; // this will be the index of the node that will be added to list
  DoubleNode<ItemType>* rater_one = this -> headPtr;
  DoubleNode<ItemType>* rater_two = a_list.headPtr;
  while(!(rater_one == nullptr && rater_two == nullptr)){
    if(rater_one != nullptr){
      return_list -> insert(location, rater_one -> getItem());
      rater_one = rater_one -> getNextNode();
      location ++;
    }
    if(rater_two != nullptr){
      return_list -> insert(location, rater_two -> getItem());
      rater_two = rater_two -> getNextNode();
      location++;
    }
  }
  return *return_list;
}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    return itCount;
}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoubleNode<ItemType> *getHeadPtr() const
{
  return headPtr;
}
#endif
