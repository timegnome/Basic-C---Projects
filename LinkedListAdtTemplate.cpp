//
//  Linkedlist.cpp
//  something
//
//  Created by MMaxwell on 10/13/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "LinkedListAdtTemplate.h"


// List::List( )
// Used before any operations are done on the linked list.
// Initializes the linked list to empty.
// Preconditions: None.
// Postconditions: List is an empty linked list. The current position
// is 1.
template<class Classtype>
Lists<Classtype>::Lists()
{
    head=current=previous=NULL;
    position=1;
}

// void List::makeEmpty ( )
// Note: function body is different from the constructor.
// Makes the linked list empty if it is not empty already.
// Preconditions: The list may be empty or have items in it.
// Postconditions: List is now an empty linked list. Any dynamically
// allocated memory which is no longer used is returned to the system.
// The current position is 1.
template<class Classtype>
void Lists<Classtype>::makeEmpty ( )
{
    goToStart();
    while(!isEmpty())
    {
        deleteCurrentItem();
    }
}

// bool List::isEmpty ( )
// Returns True if List is an empty list; returns False otherwise.
// Postconditions: List remains unchanged.
template<class Classtype>
bool Lists<Classtype>::isEmpty ( )
{
    return isAtEnd()&&head==NULL;
}

// void List::goToStart ( )
// Moves the current position to the start of the list.
// Postconditions: Current position is set to 1.
template<class Classtype>
void Lists<Classtype>::goToStart ( )
{
    previous=NULL;
    current=head;
    position=1;
}

// void List::goToNext ( )
// If current position is not at the end of the list, moves the
// current position to next position.
// Postconditions: Position has been moved to the next position,
// unless position had been already at the end of the list.
// If the position had already been at the end of the list, it is
// unchanged.
// If the list is empty, nothing is changed.
template<class Classtype>
void Lists<Classtype>::goToNext ( )
{
    if(!isAtEnd())
    {
        previous=current;
        current=current->nextPtr;
        position+=1;
    }
}

// bool List::isAtEnd ( )
// Returns True if the list is empty or if the current position is
// at the end of the list.
// Postconditions: List remains unchanged.
template<class Classtype>
bool Lists<Classtype>::isAtEnd ( )
{
    return current==NULL;
}

// ItemType List::CurrentItem ( )
// Returns the value of the current item in the linked list.
// Assumes that the current item exists; i.e., the current position is
// not at the end of the list (which would make it NULL).
// Preconditions: List is not empty, and the current position is not
// at the end of the list.
// Postconditions: List and current position remain unchanged.
template<class Classtype>
Classtype Lists<Classtype>::CurrentItem ( )
{
    return current->info;
}

//void List::insert (ItemType newItem)
// Inserts the given newItem in the linked list before the item at
// the current position. After the insertion, the current position
// remains unchanged, but the newly inserted item is there. If there
// was an item at the current position before the insertion, that item
// would now be at current position +1.
// Preconditions: The list may be empty.
// Postconditions: The NewItem is inserted in the linked list before
// any item that was at the current position. The current position
// is unchanged and the newly inserted item will now be at that
// position.
template<class Classtype>
void Lists<Classtype>::insert (Classtype newItem)
{
    if(isEmpty())
    {
        head=new NodeType<Classtype>;
        head->info=newItem;
        head->nextPtr=NULL;
        current=head;
    }
    else
    {
        goToStart();
        NodeType<Classtype> *temp=new NodeType<Classtype>;
        temp->info = newItem;
        while (current!=NULL && current->info.getID() < temp->info.getID())
        {
            goToNext();
        }
        if(currentPosition()<=1)
        {
            head=temp;
        }
        else
        {
            previous->nextPtr=temp;
        }
        temp->nextPtr = current;
        current=temp;
    }
}

// void List::deleteCurrentItem ( )
// Deletes the item in the linked list at the current position.
// Assumes that the current item exits.
// Preconditions: List is not empty, and the current position is not
// at the end of the list.
// Postconditions: The item at the current position has been deleted.
// The current position remains unchanged with respect to the list:
// If the item had been the last item, the current position will be at
// the end of the list.
template<class Classtype>
void Lists<Classtype>::deleteCurrentItem ( )
{
    NodeType<Classtype> *temp;
    if(!isAtEnd())
    {
        temp=current->nextPtr;
        if(previous!=NULL)
        {
            previous->nextPtr=temp;
        }
        else
        {
            head=temp;
        }
        delete current;
        current=temp;
    }
}

template<class Classtype>
bool Lists<Classtype>::deleteKeyNode(Classtype number)
{
    current=head;
    while(current!=NULL)
    {
        if(current->info==number)
        {
            if(previous==NULL)
            {
                previous=head;
                head=head->nextPtr;
                delete previous;
                previous=NULL;
            }
            else
            {
                previous->nextPtr=current->nextPtr;
                delete current;
            }
            return true;
        }
        previous=current;
        current=current->nextPtr;
    }
    return false;
}

template<class Classtype>
NodeType<Classtype> *Lists<Classtype>::Find(Classtype input)
{
    current=head;
    while(current!=NULL)
    {
        if(current->info==input)
        {
            return current;
        }
        current=current->nextPtr;
    }
 //   if(current==NULL)
        return NULL;
 //   else
 //       if(current->info==input)
  //      {
  //          return current;
  //      }
  //      else
  //          return Find(current->nextPtr);
}

template<class Classtype>
void Lists<Classtype>::printList(NodeType<Classtype>* nodePtr)
{
    if(nodePtr==NULL)
        return;
    cout<<nodePtr->info<<endl;
    printList(nodePtr->nextPtr);
}

template <class Classtype>
void Lists<Classtype>::printList(ofstream & out, NodeType<Classtype>* nodePtr)
{
    if(nodePtr==NULL)
        return;
    out<<nodePtr->info<<endl;
    printList(out,nodePtr->nextPtr);
}

template<class Classtype>
NodeType<Classtype>* Lists<Classtype>::getHead()
{
    return head;
}
// int List::currentPosition ( )
// Returns the number of the current position. If there is an
// item at the current position, it will return the relative position
// of the item in the list. If the position is at the end of the
// list, it will return 1 + the number of items in the list(i.e. 4
// items in list, the function would return 5).
// Postconditions: List and current position remains unchanged.
template<class Classtype>
int Lists<Classtype>::currentPosition ( )
{
    return position;
}