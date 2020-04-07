#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"


//***********************************************//
//Part 2: 1. Default Constructor
//***********************************************//
template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
  //This will initialize the data
  headPtr = nullptr;
  itCount = 0;
}

//***********************************************//
//Part 2: 2. Copy Constructor
//***********************************************//
template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList& copy)
{
  DoubleNode<ItemType>* rater = copy.headPtr;
  for(int i = 1; i <= copy.itCount; i++){
    ItemType data = rater -> getItem();
    this -> insert(data,i);
    rater = rater -> getNextNode();
  }
}

template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
  //This will delete all of the nodes
   clear();
}//end destructor


//***********************************************//
//Part 2: 3. bool insert(const int& position,
// ItemType item), which is intended to insert
//item at index position in your list
//Note: Let the list be 1 indexed unlike arrays,
//which are 0 indexed.
//***********************************************//
template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(ItemType item, const int& position)
{
  //I must first be sure position is correct
  if(position <1 || position > itCount + 1){
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
    return true;
  }
}

//***********************************************//
//Part 2: 4. bool remove(const int& position),
//which is intended to remove the node at index
//position
//***********************************************//
template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
  if(position < 1 || position > itCount){
    return false;
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
          rater -> setNextNode(rater -> getNextNode() -> getNextNode());
        }else{
          rater -> setNextNode(nullptr);
        }
        delete sub;
      }
    }
    itCount --;
    return true;
  }
}


//***********************************************//
//Part 2: 5. DoubleNode<itemType> getAtPos
//(const int& position) const, which returns
//the node at position
//***********************************************//
template <typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& position) const
{
  if(position < 1 || position > itCount){
    return nullptr;
  }else{
    DoubleNode<ItemType>* rater = headPtr;
    for(int i = 1; i < position; i++){
      rater = rater -> getNextNode();
    }
    return rater;
  }
}

//***********************************************//
//Part 2: 6. bool isEmpty() const, which returns
//whether the list is empty
//***********************************************//
template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
  return itCount == 0;
}

//***********************************************//
//Part 2: 7. void clear(), which clears the list
//***********************************************//
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

//***********************************************//
//Part 2: 8. void display() const, which prints
//the contents of the list in order
//***********************************************//
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
  std::cout<< "\n";
}

//***********************************************//
//Part 2: 9. void displayBackwards() const,
//which prints the contents of the list
//backwards.
//***********************************************//
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
  std::cout << "\n";
}

//***********************************************//
//Part 2: 10. DoublyLinkedList<itemType>
//interleave(const DoublyLinkedList<itemType>& a list),
//which alters the calling list to be the interleaved
//list of the original and parameter lists
//***********************************************//
template <typename ItemType>
DoublyLinkedList<ItemType>& DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
  //I need to first make a list to return
  DoublyLinkedList<ItemType>* return_list = new DoublyLinkedList();
  int location = 1; // this will be the index of the node that will be added to list
  DoubleNode<ItemType>* rater_one = this -> headPtr;
  DoubleNode<ItemType>* rater_two = a_list.headPtr;
  while(!(rater_one == nullptr && rater_two == nullptr)){
    if(rater_one != nullptr){
      return_list -> insert(rater_one -> getItem(),location);
      rater_one = rater_one -> getNextNode();
      location ++;
    }
    if(rater_two != nullptr){
      return_list -> insert(rater_two -> getItem(),location);
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
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
  return headPtr;
}
#endif
