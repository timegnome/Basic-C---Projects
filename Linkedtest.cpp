//
//  main.cpp
//  cs301
//
//  Created by MMaxwell on 9/15/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include "Linkedlist.h"

using namespace std;

void PrintList(List);
void printMenu();
int main()
{
    List MyList;
    printMenu();
    char inchar;
    ItemType inValue;
    while(cin>>inchar)
    {
        inchar=toupper(inchar);
        switch (inchar)
        {
            case 'A':
            {
                cout<<"Please enter an integer: "<<endl;
                cin>>inValue;
                MyList.insert(inValue);
                break;}
            case 'C':
            {
                cout<<"Current position in list is: "<<MyList.currentPosition()<<endl;
                break;}
            case 'D':
            {
                MyList.deleteCurrentItem();
                cout<<"Removed"<<endl;
                break;}
            case 'E':
            {
                MyList.makeEmpty();
                break;}
            case 'I':
            {
                cout<<"Current Item is: "<<MyList.CurrentItem()<<endl;
            }
            case 'N':
            {
                MyList.goToNext();
                break;}
            case 'P':
            {
                MyList.goToStart();
                PrintList(MyList);
                break;}
            case 'S':
            {
                MyList.goToStart();
                break;}
            case 'Q':
            {
                MyList.makeEmpty();
                cout<<"Thank you. :3"<<endl;
                return 0;
                break;}
            default:{
                cout << "Error! Unknown value. Please try again." <<endl<<endl;
                break;}
        }
        printMenu();
    }
}
void PrintList(List thisList)
{
    while(!thisList.isAtEnd())
    {
        cout<<"Node "<<thisList.currentPosition()<<":"<<thisList.CurrentItem()<<endl;
        thisList.goToNext();
    }
}
void printMenu()
{
    cout << "Please select one of the following:" <<endl;
    cout << "A: Add a Node" <<endl;
    cout << "C: CurrentPosition"<<endl;
    cout << "D: Deletes current Node"<<endl;
    cout << "E: Empty list"<<endl;
    cout << "I: Current Item"<<endl;
    cout << "N: Next Node"<<endl;
    cout << "P: Prints the list"<<endl;
    cout << "S: To the Start of List"<<endl;
    cout << "Q: Quit the Program" <<endl;
    cout << ">> ";
}

