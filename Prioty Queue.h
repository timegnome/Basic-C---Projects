//
//  Prioty Queue.h
//  CS301
//
//  Created by MMaxwell on 11/3/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef CS301_Prioty_Queue_h
#define CS301_Prioty_Queue_h

#include <iostream>
#include <fstream>
using namespace std;

template<class Classtype>
struct NodeType {
    
public:
    Classtype info; // data
    int prioty=0;
    NodeType * nextPtr; // pointer to next node in the list
};


template <class Classtype>
class priotyQueue
{
public:
    NodeType<Classtype> * getFirstNode()
    {
        return head;
    }
    ~priotyQueue()
    {
        while (head!=NULL)
        {
            last=head->nextPtr;
            delete head;
            head=last;
        }
    }
    NodeType<Classtype>* &Find(Classtype input);
    void printList(NodeType<Classtype>* Next)
    {
        if(Next==NULL)
            return;
        else
        {
            cout<<Next->info;
            printList(Next->nextPtr);
        }
    }
    void printList(ofstream& fileOut,NodeType<Classtype>* Next)
    {
        if(Next==NULL)
            return;
        else
        {
            fileOut<<Next->info;
            printList(fileOut,Next->nextPtr);
        }
    }
    void enqueue(NodeType<Classtype> *newItem)
    {
        if(head==NULL)
        {
            head=newItem;
            last=head;
        }
        else
        {
            NodeType<Classtype> *temp,*previous;
            temp=head;
            previous=NULL;
            if(temp->nextPtr==NULL)
            {
                if(temp->prioty>newItem->prioty)
                {
                    temp->nextPtr=newItem;
                    temp=newItem;
                }
                else
                {
                    head=newItem;
                    head->nextPtr=temp;
                }
                last=temp;
            }
            else
            {
                while(temp->nextPtr!=NULL)
                {
                    if(temp->prioty>=newItem->prioty)
                    {
                        temp = temp->nextPtr;
                    }
                    else
                    {
                        if(previous==NULL)
                        {
                            head=newItem;
                            head->nextPtr=temp;
                        }
                        else
                        {
                            previous->nexPtr=newItem;
                            newItem->nextPtr=temp;
                            return;
                        }
                    }
                }
                if(temp->prioty>newItem->prioty)
                {
                    temp->nextPtr=newItem;
                }
                else
                {
                    if(previous==NULL)
                    {
                        head=newItem;
                        head->nextPtr=temp;
                    }
                    else
                    {
                        previous->nexPtr=newItem;
                        newItem->nextPtr=temp;
                    }
                }
            }
        }
    }
    //void dequeue(NodeType<Classtype>* Item);
    NodeType<Classtype>* dequeue()
    {
        NodeType<Classtype> *temp;
        temp=head;
        if(head==NULL)
        {
            return head;
        }
        else
        {
            head=head->nextPtr;
            if(head==last)
            {
                head=last=NULL;
            }
            return temp;
        }
    }
private:
    NodeType<Classtype> *head;
    NodeType<Classtype> *last;
};

#endif
