//
//  Linkedlist.h
//  something
//
//  Created by MMaxwell on 10/13/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __something__Linkedlist__
#define __something__Linkedlist__

#include <iostream>

typedef int ItemType;
struct NodeType
{
    ItemType info;
    NodeType * next;
};

class List{
public:
    List();
    void makeEmpty();
    bool isEmpty();
    void goToStart();
    void goToNext();
    bool isAtEnd();
    ItemType CurrentItem();
    void insert(ItemType newItem);
    void deleteCurrentItem();
    int currentPosition();
    
private:
    NodeType *head;
    NodeType *current;
    NodeType *previous;
    int position;
};
#endif /* defined(__something__Linkedlist__) */
