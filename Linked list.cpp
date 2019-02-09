//
//  Linked list.cpp
//  something
//
//  Created by MMaxwell on 10/8/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//
/*
#include "Linked list.h"

using namespace std;


void insert(NodeType*& , int );
void printList(NodeType*);
void printMenu();
void deleteNode(NodeType*&);
bool Find(NodeType*,int );
bool deleteKeyNode(NodeType*&,int);
int main()
{
    NodeType * head;
    int value;
    char inchar;
    head = NULL;
    printMenu();
    while(cin>>inchar)
    {
        inchar=toupper(inchar);
        switch(inchar)
        {
            case 'A':
            {
                cout<<"Please input a value."<<endl;
                cin>>value;
                insert(head,value);
                break;
            }
                case 'D':
            {
                deleteNode(head);
                break;
            }
                case 'F':
            {
                cout<<"Please input the value your looking for."<<endl;
                cin>>value;
                if(Find(head,value))
                {
                    cout<<"Found"<<endl;
                }
                else
                {
                    cout<<"Not Found"<<endl;
                }
                break;
            }
                case 'K':
            {
                cout<<"Please input the value your looking to delete."<<endl;
                cin>>value;
                if(deleteKeyNode(head, value))
                {
                    cout<<"Removed"<<endl;
                }
                else
                {
                    cout<<"Not in the List"<<endl;
                }
                break;
            }
            case 'P':
            {
                printList(head);
                break;
            }
            case 'Q':
            {
                cout<<"Thank for your time"<<endl;
                return 0;
            }
            default:{
                cout << "Error! Unknown value. Please try again." <<endl<<endl;
                break;}
        }
        printMenu();
    }
}
void printMenu()
{
    cout << "Please select one of the following:" <<endl;
    cout << "A: Add a Node" <<endl;
    cout << "D: Deletes front Node"<<endl;
    cout << "F: Finds a value"<<endl;
    cout << "K: DeleteKey Node"<<endl;
    cout << "P: Print Node Stats to Screen" <<endl;
    cout << "Q: Quit the Program" <<endl;
    cout << ">> ";
}
void deleteNode(NodeType*& nodePtr)
{
    NodeType * currentPtr;
    currentPtr=nodePtr;
    nodePtr=nodePtr->nextPtr;
    delete currentPtr;
}
bool deleteKeyNode(NodeType* &nodePtr,int number)
{
    NodeType *previousPtr,*currentPtr;
    previousPtr=NULL;
    currentPtr=nodePtr;
    while(currentPtr!=NULL)
    {
        if(currentPtr->info==number)
        {
            if(previousPtr==NULL)
            {
                previousPtr=nodePtr;
                nodePtr=nodePtr->nextPtr;
                delete previousPtr;
                if(previousPtr==NULL)
                cout<<"pointer is null"<<endl;
            }
            else
            {
                previousPtr->nextPtr=currentPtr->nextPtr;
                delete currentPtr;
            }
            return true;
        }
        previousPtr=currentPtr;
        currentPtr=currentPtr->nextPtr;
    }
    
//    if(nodePtr->info==number)
//    {
        
//    }
//    if(nodePtr==NULL||nodePtr->nextPtr->info==number)
//    {
        
//    }
//    else
//    {
//        deleteKeyNode(nodePtr->nextPtr, number);
//    }
   //  /
    return false;
}
bool Find(NodeType* nodePtr,int number)
{
    if(nodePtr==NULL)
    return false;
    else
    if(nodePtr->info==number)
    {
        return true;
    }
    else
    return Find(nodePtr->nextPtr,number);
}
void printList(NodeType* nodePtr)
{
    if(nodePtr==NULL)
        return;
    cout<<nodePtr->info<<endl;
    printList(nodePtr->nextPtr);
}
void insert(NodeType *&nodePtr, int num)
{
    NodeType * currentPtr;
    currentPtr= new NodeType;
    currentPtr->info=num;
    currentPtr->nextPtr=nodePtr;
    nodePtr= currentPtr;
}*/