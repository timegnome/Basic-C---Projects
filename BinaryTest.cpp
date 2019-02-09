//
//  main.cpp
//  something
//
//  Created by MMaxwell on 10/6/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "BinaryTree.h"

using namespace std;

void menu();

int main()
{
    char inchar;
    int value, intLookingfor;
    Tree<int> intTree;
    menu();
    while(cin>>inchar)
    {
        inchar=toupper(inchar);
        switch(inchar)
        {
            case 'A':
            {
                cout<<"Please input a value."<<endl;
                cin>>value;
                intTree.insert(value);
                break;
            }
            case 'D':
            {
                cout<<"Please input a value."<<endl;
                cin>>value;
                intTree.deleteItem(value);
                break;
            }
            case 'E':
            {
                intTree.makeEmpty();
                cout<<"List Emptied"<<endl;
                break;
            }
            case 'R':
            {
                cout<<"Please input the value your looking for."<<endl;
                cin>>value;
                if(intTree.retrieve(value, intLookingfor))
                {
                    cout<<"Found"<<endl;
                }
                else
                {
                    cout<<"No Such Value"<<endl;
                }
                break;
            }
            case 'P':
            {
                cout<<"Which order pre, in, post? 1,2,3?"<<endl;
                cin>>inchar;
                if(inchar=='1')
                intTree.print(cout,preorder);
                if(inchar=='2')
                intTree.print(cout,inorder);
                if(inchar=='3')
                intTree.print(cout,postorder);
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
        menu();
    }
    return 0;
}

void menu()
{
    cout<<"Please enter your one letter choice as follows:"<<endl;
    cout<<"   R: Retrieve a node"<<endl;
    cout<<"   D: Delete a node"<<endl;
    cout<<"   P: Print all nodes"<<endl;
    cout<<"   A: Insert A node"<<endl;
    cout<<"   E: Empty List"<<endl;
    cout<<"   Q: Quit this program"<<endl;
}
