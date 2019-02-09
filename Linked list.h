//
//  Linked list.h
//  something
//
//  Created by MMaxwell on 10/8/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __something__Linked_list__
#define __something__Linked_list__

#include <iostream>
class NodeType {
    
public:
    NodeType( int = 0 ); // constructor with default value for
    int info; // data
    NodeType * nextPtr; // pointer to next node in the list
};
// Constructor
NodeType::NodeType( int data )

{
    info = data;
    nextPtr = 0; // pointer set to NULL
}
#endif /* defined(__something__Linked_list__) */
