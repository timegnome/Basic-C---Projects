//
//  BinaryTree.h
//  CS301
//
//  Created by MMaxwell on 11/10/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef CS301_BinaryTree_h
#define CS301_BinaryTree_h

#include "Tree.h"
#include <iostream>
using namespace std;
//The following enumerated type declaration should be included.

enum TraversalOrderType {preorder, inorder, postorder};

template< class ItemType >
class Tree {
public:
    // Constructor used before any operations are done on the list.
    // Initializes the list to empty.
    //Preconditions: None.
    //Postconditions: Tree is an empty Tree.
    
    Tree(){
        rootPtr=NULL;};
    
    //Destructor
    //Precondition: Tree exists, but may be empty.
    //Postcondition: makeEmpty is called to ensure the tree is empty
    // when the destructor is called.
    
    ~Tree()
    {
        makeEmpty();
    }
    
    //Returns True if the tree is empty, otherwise returns false
    //Postcondition: Tree is unchanged.
    
    bool isEmpty() const
    {
        return (NULL==rootPtr);
    }
    
    //Makes the tree empty if it is not empty already.
    //Preconditions: The tree exists.
    //Postconditions: Tree is now empty. Any dynamically allocated
    // memory which is no longer used is returned to the system.
    
    void makeEmpty()
    {
        makeEmptyHelper(rootPtr);
    }
    
    // Inserts a copy of newItem in the tree.
    // Precondition: The tree exists, but may be empty. It has binary
    // search property. ItemType has comparison operators defined.
    // Postcondition: if the tree already has an item where item ==
    // newItem, the function returns false and the tree is unchanged.
    // Otherwise, the newItem is inserted in the tree preserving and the
    // binary search property is maintained.
    
    bool insert( ItemType newItem)
    {
        return insertHelper(rootPtr,newItem);
    }
    
    // Given a searchItem, it tries to retrieve as foundItem, an item
    // in the tree where the item == searchItem.
    // Precondition: The tree exists and has the binary search property.
    // It may be empty. ItemType has comparison operators defined.
    // Postcondition: If the tree already has an item where item ==
    // searchItem, foundItem is set to that item, and the function
    // returns true. If the tree has no such item, the function returns
    // false and foundItem remains unchanged. The tree is unchanged.
    // Think of this as retrieving a record based on a key value.
    
    bool retrieve( ItemType searchItem, ItemType & foundItem )
    {
        return retrieveHelper(searchItem,rootPtr,foundItem);
    }
    
    // Given a deleteItem, it deletes from the tree any item where item
    // == deleteItem.
    // Precondition: Tree exists and has binary search property.
    // ItemType has comparison operators defined.
    // Postcondition: If the tree has an item where item == deleteItem,
    // that item is removed from the tree, and the function returns
    // true, and the binary search property is maintained. If the tree
    // has no such item, the function returns false and the tree
    // remains unchanged.
    
    bool deleteItem (ItemType deleteItem)
    {
        return deleteHelper(rootPtr,deleteItem);
    }
    
    // Prints the information about all the items in the Tree in order
    // to an ostream object Outstream. The function should print nothing
    // (No messages!) if the Tree is empty. The particular order
    // (preorder, inorder, or postorder) is given by order, a variable of
    // TraversalOrderType.
    // Preconditions: Outstream has been assigned and opened for writing
    // to. The insertion operator (<<) has been defined for objects of
    // class ItemType.
    // Postconditions: Tree is unchanged. The information for all
    // items has been written out to Outstream in the order specified
    // by order.
    
    void print(ostream & Outstream, TraversalOrderType order )
    {
        if(!isEmpty())
        printHelper(rootPtr, Outstream, order);
    }
    
private:
    TreeNode< ItemType > * rootPtr; // pointer to the root
    //utility functions
    void printHelper( TreeNode< ItemType > * Node, ostream &Outstream, TraversalOrderType order)
    {
        if(!(Node==NULL))
        switch(order)
        {
                default:
            case preorder:
            {
                cout<<Node->data<<endl;
                printHelper(Node->leftPtr,Outstream,order);
                printHelper(Node->rightPtr,Outstream,order);
                break;
            }
            case inorder:
            {
                printHelper(Node->leftPtr,Outstream,order);
                cout<<Node->data<<endl;
                printHelper(Node->rightPtr,Outstream,order);
                break;
            }
            case postorder:
            {
                printHelper(Node->leftPtr,Outstream,order);
                printHelper(Node->rightPtr,Outstream,order);
                cout<<Node->data<<endl;
                break;
            }
        }
    }
    bool insertHelper( TreeNode< ItemType > * & NextNode, ItemType insertI)
    {
        if(NextNode == NULL)
        {
            NextNode = new TreeNode< ItemType >(insertI);
            return true;
        }
        if(NextNode->data == insertI)
            return false;
        if(NextNode->data > insertI)
            insertHelper(NextNode->leftPtr, insertI);
        else
            insertHelper(NextNode->rightPtr, insertI);
        return false;
    }
    bool deleteHelper( TreeNode< ItemType > * & NextNode, ItemType deleteI)
    {
        if(NextNode == NULL)
            return false;
        if(NextNode->data == deleteI)
        {
            deleteNode(NextNode);
            return true;
        }
        if(deleteI<  NextNode->data)
            return deleteHelper(NextNode->leftPtr,deleteI);
        else
            return deleteHelper(NextNode->rightPtr,deleteI);
    }
    void deleteNode( TreeNode<ItemType > * & rootNode)
    {
        TreeNode< ItemType > * temp;
        if(rootNode->leftPtr==NULL)
        {
            temp= rootNode->leftPtr;
            rootNode = rootNode->rightPtr;
            delete temp;
        }
        else if(rootNode->rightPtr==NULL)
        {
            temp= rootNode->rightPtr;
            rootNode= rootNode->leftPtr;
            delete temp;
        }
        else
        {
            temp = rootNode->leftPtr;
            
            if(temp->rightPtr==NULL)
            {
                rootNode->data = temp->data;
                
                rootNode->leftPtr= temp->leftPtr;
                delete temp;
            }
            else
            {
                while(!(temp->rightPtr->rightPtr==NULL))
                {
                    temp = temp->rightPtr;
                }
                rootNode->data = temp->rightPtr->data;
                temp= temp->rightPtr;
                delete temp;
            }
        }
        temp =NULL;
    }
    bool retrieveHelper( ItemType searchI, TreeNode< ItemType > * & NextNode, ItemType & foundI)
    {
        if(NextNode == NULL)
            return false;
        if(searchI == NextNode->data)
        {
            foundI=NextNode->data;
            return true;
        }
        if(searchI < NextNode->data)
        {
            return retrieveHelper(searchI,NextNode->leftPtr,foundI);
        }
        else
            return retrieveHelper(searchI,NextNode->rightPtr,foundI);
    }
    void makeEmptyHelper (TreeNode< ItemType > * & Node)
    {
        if(Node==NULL)
            return;
        makeEmptyHelper(Node->leftPtr);
        makeEmptyHelper(Node->rightPtr);
        delete Node;
        Node=NULL;
    }
};
        

#endif
