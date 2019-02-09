//
//  ListTemplate.h
//  CS301
//
//  Created by MMaxwell on 11/10/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef CS301_ListTemplate_h
#define CS301_ListTemplate_h


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

template<class Classtype>
class listTemplate
{
public:
	void insert(NodeType<Classtype> *Item)
	{
		Item->nextPtr = head;
		head = Item;
        size++;
	}
	void printlist(const NodeType<Classtype> *Next)
	{
		if(Next==NULL)
			return;
		cout<<Next->info<<endl;
		printlist(Next->nextPtr);
	}
	void printlist(ofstream &outStream, const NodeType<Classtype> *Next)
	{
		if(Next==NULL)
			return;
		outStream<<Next->info<<endl;
		printlist(outStream,Next->nextPtr);
	}
	void destroyList(NodeType<Classtype> *&Next)
	{
		if(Next==NULL)
			return;
		destroyList(Next->nextPtr);
		delete Next;
	}
    int getSize()
    {
        return size;
    }
	~listTemplate()
	{
		destroyList(head);
	}
	NodeType<Classtype>* &getHead()
	{
		return head;
	}
private:
	NodeType<Classtype> *head;
    int size=0;
};

#endif
