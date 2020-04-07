#include "DoublyLinkedList.hpp"

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), tailPtr(nullptr), itCount(0) {}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &double_list)
{


    if (double_list.headPtr == nullptr)
    {
        headPtr = nullptr;
        tailPtr = nullptr;
        itCount = 0;
    }
    else
    {
        //This is headPtr construction
        headPtr = new DoubleNode<ItemType>();
        headPtr.setItem(double_list.headPtr.getItem(), nullptr, nullptr);

        //This is to get through the rest of the list
        DoubleNode<ItemType> *chainFindPtr = double_list.headPtr;
        DoubleNode<ItemType> *navigatePtr = double_list.headPtr;
        while (chainFindPtr->getNextNode())
        {
            chainFindPtr = chainFindPtr->getNextNode();
            DoubleNode<itemType> fresh_Node = new DoubleNode<ItemType>;
            fresh_Node->setItem(chainFindPtr->getItem());
            fresh_Node->setPrevNode(navigatePtr);
            navigatePtr->setNextNode(fresh_Node);
            navigatePtr = navigatePtr->getNextNode();
        }

        //this is for the last node
        DoubleNode<itemType> fresh_Node= new DoubleNode<ItemType>;
        fresh_Node->setItem(chainFindPtr->getItem());
        navigatePtr>setItem(fresh_Node);
        fresh_Node->setPrevNode(navigatePtr);
        fresh_Node->setNextNode(nullptr);
    }
}

template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
}//end destructor


template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const int& position, ItemType item)
{
  Node<ItemType>* entry_ptr = new Node<ItemType>(item); // dynamically allocate memory for the new entry
  Node<ItemType>* temp_ptr = headPtr; // points to the position of the new node
  //while the pointer is not null keep going down the chain
  if (headPtr == nullptr) {
    headPtr = entry_ptr;
    itCount++;
    return true;
   }
   int counter = 1;
   while (counter < position) {
      temp_ptr = temp_ptr -> getNextNode();
      counter ++;
   }
  temp_ptr->setNextNode(entry_ptr); // set the node to the node that we want
  itCount++;
  return true; // if it worked return true
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{


}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
  return itCount;
}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoubleNode<ItemType> *getHeadPtr()
{

}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoubleNode<ItemType> *getAtPos(const int& position) const
{
  Node<ItemType>* nodeToReturn = headPtr;
  int counter = 1;
  while(counter < position){
    nodeToReturn = nodeToReturn -> getNextNode();
  }
  return nodeToReturn;

}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{

  if(itCount == 0){
    return true;
  }else{
    return false;
  }

}

template <typename ItemType>
void DoublyLinkedList<ItemType>::clear()
{

  Node<ItemType>* nodeToDeletePtr = headPtr;
  while (headPtr != nullptr)
  {
     headPtr = headPtr->getNextNode();

     // Return node to the system
     nodeToDeletePtr->setNextNode(nullptr);
     delete nodeToDeletePtr;

     nodeToDeletePtr = headPtr;
  }  // end while
  // headPtr is nullptr; nodeToDeletePtr is nullptr

 itCount = 0;

}

template <typename ItemType>
void DoublyLinkedList<ItemType>::display() const{}

template <typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const{}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list)
{
  Node<ItemType>* a_listHead = a_list.headPtr;
  Node<ItemType>* a_listTail = a_list.tailPtr;
  Node<ItemType>* origin_head = headPtr;
  Node<ItemType>* new_head = headPtr;
  int a_listCount = a_list.itCount;
  if (a_list.headPtr == nullptr)
  {
      a_listHead = nullptr;
      a_listTail = nullptr;
      a_listCount = 0;
  }
  else
  {
      new_head->setNextNode(a_listHead);
      origin_head = origin_head -> getNextNode();
      a_listHead = a_listHead -> getNextNode();
      //This is headPtr construction
      for(int i = 1; i <= a_listCount + itCount-1; i++){
        if(i%2==0){
          new_head->setNextNode(origin_head);
          new_head = new_head -> getNextNode();
          origin_head = origin_head -> getNextNode();
        }else{
          new_head->setNextNode(a_listHead);
          new_head = new_head -> getNextNode();
          a_listHead = a_listHead -> getNextNode();
        }
      }
    }

  }
