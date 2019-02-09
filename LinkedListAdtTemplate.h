//
//  Linkedlist.h
//  something
//
//  Created by MMaxwell on 10/13/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __something__LinkedlistAdtTemplate__
#define __something__LinkedlistAdtTemplate__

#include <iostream>
using namespace std;

template<class Classtype>
struct NodeType {
    
public:
    Classtype info; // data
    NodeType * nextPtr; // pointer to next node in the list
};

template<class Classtype>
class Lists{
public:
    Lists();
    bool deleteKeyNode(Classtype );
    NodeType<Classtype> * Find(Classtype input);
    void printList(NodeType<Classtype>* );
    void printList(ofstream&, NodeType<Classtype>*);
    void makeEmpty();
    bool isEmpty();
    void goToStart();
    void goToNext();
    bool isAtEnd();
    Classtype CurrentItem();
    void insert(Classtype newItem);
    void deleteCurrentItem();
    int  currentPosition();
    NodeType<Classtype>* getHead();
private:
    NodeType<Classtype> *head;
    NodeType<Classtype> *current;
    NodeType<Classtype> *previous;
    int position;
};
#endif /* defined(__something__LinkedlistAdtTemplate__) */
