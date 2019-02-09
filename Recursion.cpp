//
//  main.cpp
//  something
//
//  Created by MMaxwell on 10/6/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include "Linked list.h"

using namespace std;

//FUNCTION PROTOTYPES -------------------------------
// Add a node at front - provided (Non-recursive)
void insertAtFront(NodeType * &headPtr, int value);

// Print with a loop - provided (Non-recursive)

void printLoop(NodeType * headPtr);
void printInorder(NodeType *);
void printBackwards(NodeType *);
void insertAtEnd(NodeType *&,int);
bool deleteAtEnd(NodeType *&);
bool deleteKeyNode(NodeType *&,int);
void printMenu();
void printBackward1(char *);
//BEGIN MAIN() -------------------------------

int main()
{
   NodeType * head = NULL; //Setting to NULL is important
   char input,something[5]{'t','o','o','l'};
   int value;
   printBackward1(something);
   printMenu();
   while(cin>>input)
   {
       input=toupper(input);
       switch(input)
       {
           case 'A':
           {
               cout<<"Please input a value."<<endl;
               cin>>value;
               insertAtFront(head, value);
               break;
           }
           case 'D':
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
           case 'K':
           {
               if(deleteAtEnd(head))
               {
                   cout<<"Removed"<<endl;
               }
               else
               {
                   cout<<"Not in the List"<<endl;
               }
               break;
           }
           case 'I':
           {
               cout<<"Please input a value."<<endl;
               cin>>value;
               insertAtEnd(head, value);
               break;
           }
           case 'P':
           {
               printInorder(head);
               break;
           }
           case 'S':
           {
               printBackwards(head);
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
   return 0;} //END MAIN()

//FUNCTION DEFINITIONS -------------------------------

void insertAtFront(NodeType * &headPtr, int value)
{
   NodeType * currentPtr = new NodeType;
   currentPtr->info = value;
   currentPtr->nextPtr = headPtr;
   headPtr = currentPtr;
}
void printInorder(NodeType *headPtr)
{
   if(!headPtr){}
   else
   {
       cout<<headPtr->info<<endl;
       printInorder(headPtr->nextPtr);
   }
}
void printBackwards(NodeType *headPtr)
{
   if(!headPtr){}
   else
   {
       printBackwards(headPtr->nextPtr);
       cout<<headPtr->info<<endl;
   }
}
void insertAtEnd(NodeType *&lastPtr,int value)
{
   if(lastPtr&&lastPtr->nextPtr)
   {
       insertAtEnd(lastPtr->nextPtr,value);
   }
   else
   {
       NodeType * currentPtr = new NodeType;
       currentPtr->info = value;
       if(lastPtr)
       {
           lastPtr->nextPtr = currentPtr;
       }
       else
       {
           lastPtr=currentPtr;
       }
   }
}
bool deleteAtEnd(NodeType *&headPtr)
{
   if(headPtr)
   {
       if(headPtr->nextPtr)
       {
           return deleteAtEnd(headPtr->nextPtr);
       }
       else
       {
           delete headPtr;
           headPtr=NULL;
           return true;
       }
   }
   return false;
}
bool deleteKeyNode(NodeType *&headPtr,int value)
{
   if(!headPtr)
   {
       cout<<"Value not found"<<endl;
       return false;
   }
   if(headPtr->info==value)
   {
       NodeType *temp;
       temp=headPtr;
       headPtr=headPtr->nextPtr;
       delete temp;
       return true;
   }
   if(headPtr->nextPtr)
   {
       if(headPtr->nextPtr->info==value)
       {
           NodeType *temp;
           temp=headPtr->nextPtr;
           headPtr->nextPtr=headPtr->nextPtr->nextPtr;
           delete temp;
           return true;
       }
   }
   return deleteKeyNode(headPtr->nextPtr, value);
}
void printLoop(NodeType * headPtr)
{
   while (headPtr != NULL)
   {
       cout << "[ " << headPtr->info << " ]->";
       headPtr = headPtr->nextPtr;
   }
   cout <<"NULL"<< endl;
}
void printBackward1(char *name)
{
   if(name[0]=='\0')
   {
       return;
   }
   printBackward1(&name[1]);
   cout<<name[0];
}
void printMenu()
{
   cout << "Please select one of the following:" <<endl;
   cout << "A: Inserts at the start" <<endl;
   cout << "D: Deletes specifc Node"<<endl;
   cout << "K: Deletes Node at end"<<endl;
   cout << "I: Inserts at the end"<<endl;
   cout << "P: Prints the list"<<endl;
   cout << "S: Prints the list backward"<<endl;
   cout << "Q: Quit the Program" <<endl;
   cout << ">> ";
}
