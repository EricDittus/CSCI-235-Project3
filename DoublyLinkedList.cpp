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
        while (chainFindPtr->getNext())
        {
            chainFindPtr = chainFindPtr->getNext();
            DoubleNode<itemType> fresh_Node = new DoubleNode<ItemType>;
            fresh_Node->setItem(chainFindPtr->getItem());
            fresh_Node->setPrev(navigatePtr);
            navigatePtr->setNext(fresh_Node);
            navigatePtr = navigatePtr->getNext();
        }

        //this is for the last node
        DoubleNode<itemType> fresh_Node= new DoubleNode<ItemType>;
        fresh_Node->setItem(chainFindPtr->getItem());
        navigatePtr>setItem(fresh_Node);
        fresh_Node->setPrev(navigatePtr);
        fresh_Node->setNext(nullptr);
    }
}

template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
}//end destructor


template <typename ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position){}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{


}

template <typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const{}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoubleNode<ItemType> *getHeadPtr(){}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoubleNode<ItemType> *getAtPos(const int &position) const{}

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
     headPtr = headPtr->getNext();

     // Return node to the system
     nodeToDeletePtr->setNext(nullptr);
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
DoublyLinkedList<ItemType>::DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType> &a_list){}
