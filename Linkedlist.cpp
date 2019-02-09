//
//  Linkedlist.cpp
//  something
//
//  Created by MMaxwell on 10/13/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "Linkedlist.h"

// List::List( )
// Used before any operations are done on the linked list.
// Initializes the linked list to empty.
// Preconditions: None.
// Postconditions: List is an empty linked list. The current position
// is 1.

List::List( )
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

void List::makeEmpty ( )
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

bool List::isEmpty ( )
{
    return isAtEnd()&&head==NULL;
}

// void List::goToStart ( )
// Moves the current position to the start of the list.
// Postconditions: Current position is set to 1.

void List::goToStart ( )
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

void List::goToNext ( )
{
    if(!isAtEnd())
    {
        previous=current;
        current=current->next;
        position+=1;
    }
}

// bool List::isAtEnd ( )
// Returns True if the list is empty or if the current position is
// at the end of the list.
// Postconditions: List remains unchanged.

bool List::isAtEnd ( )
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

ItemType List::CurrentItem ( )
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

void List::insert (ItemType newItem)
{
    if(isEmpty())
    {
        head=new NodeType;
        head->info=newItem;
        head->next=NULL;
        current=head;
    }
    else
    {
        NodeType *temp=new NodeType;
        temp->info=newItem;
        temp->next=current;
        if(currentPosition()<=1)
        {
            head=temp;
        }
        else
        {
            previous->next=temp;
        }
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

void List::deleteCurrentItem ( )
{
    NodeType *temp;
    if(!isAtEnd())
    {
        temp=current->next;
        if(previous!=NULL)
        {
            previous->next=temp;
        }
        else
        {
            head=temp;
        }
        delete current;
        current=temp;
    }
}

// int List::currentPosition ( )
// Returns the number of the current position. If there is an
// item at the current position, it will return the relative position
// of the item in the list. If the position is at the end of the
// list, it will return 1 + the number of items in the list(i.e. 4
// items in list, the function would return 5).
// Postconditions: List and current position remains unchanged.

int List::currentPosition ( )
{
    return position;
}