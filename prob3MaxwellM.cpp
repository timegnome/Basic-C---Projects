//
//  prob3MaxwellM.cpp
//  Final
//
//  Created by MMaxwell on 12/10/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>

using namespace std;

struct NodeType
{
    char Data = '\0';
    NodeType *nextPtr;
};
void Concatenate(NodeType*&,NodeType*&);
void print(NodeType*);
int CountVowles(NodeType*);

int main()
{
    NodeType *Ptr1, *Ptr2, *Ptr3, *Ptr4;
    Ptr1 = new NodeType;
    Ptr2 = new NodeType;
    Ptr3 = new NodeType;
    Ptr4 = new NodeType;
    Ptr1->Data = 'A';
    Ptr1->nextPtr = nullptr;
    Ptr2->Data = 'B';
    Ptr2->nextPtr = nullptr;
    Ptr3->Data = 'I';
    Ptr4->nextPtr = nullptr;
    Ptr4->Data = 'K';
    Ptr4->nextPtr = nullptr;
    Concatenate(Ptr1, Ptr2);
    Concatenate(Ptr3, Ptr4);
    Concatenate(Ptr1, Ptr3);
    print(Ptr1);
    cout<<CountVowles(Ptr1) << endl;
    return 0;
}
void Concatenate(NodeType * &Head, NodeType* & tail)
{
    if(Head->nextPtr == nullptr)
    {
        Head->nextPtr = tail;
        tail = nullptr;
    }
    else
    {
        Concatenate(Head->nextPtr, tail);
    }
}

void print(NodeType * Head)
{
    if(Head == nullptr)
    {
        cout << endl;
        return;
    }
    cout << Head->Data << " ";
    print(Head->nextPtr);
}

int CountVowles(NodeType* Head)
{
    if(Head == nullptr)
        return 0;
    switch (Head->Data)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1+CountVowles(Head->nextPtr);
        default:
            return CountVowles(Head->nextPtr);
            break;
    }
}