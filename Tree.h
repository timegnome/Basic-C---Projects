//
//  Tree.h
//  CS301
//
//  Created by MMaxwell on 11/10/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using namespace std;
// Content of TreeNode.h
// Original source attribution available. Modified by Molodowitch
// TreeNode template definition: each TreeNode object contains data,
// left pointer, and right pointer.
template< class ItemType > class Tree;
// forward declarations
/*Ensures that there is not a cyclic reference. Ask if you have questions about this.*/
// Begin TreeNode Class

template<class ItemType>
class TreeNode {
    friend class Tree< ItemType >; // make Tree a friend
public:
    
    TreeNode( ItemType ); // constructor
    TreeNode(); // constructor with data uninitialized
    ItemType getData() const; // return data in the node
private:
    
    ItemType data;
    TreeNode< ItemType > *leftPtr;
    TreeNode< ItemType > *rightPtr;
};
// Constructor

template<class ItemType>
TreeNode< ItemType >::TreeNode( ItemType newItem )
{
    data = newItem;
    leftPtr = NULL;
    rightPtr = NULL;
}
template<class ItemType>
TreeNode< ItemType >::TreeNode( )
{
    leftPtr = NULL;
    rightPtr = NULL;
}
// Return a copy of the data in the node
template< class ItemType >
ItemType TreeNode< ItemType >::getData() const
{
    return data;
}

#endif

