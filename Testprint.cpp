//
//  main.cpp
//  something
//
//  Created by MMaxwell on 10/6/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include "ClubMemberRecord.h"
#include "LinkedListAdtTemplate.h"
#include <fstream>
using namespace std;

//BEGIN MAIN() -------------------------------
void printMenu();

int main()
{
    List<ClubMemberRecord> MyList;
    char inChar;
    ifstream inFile;
    ofstream outFile;
    string inputString;
    int inputtInt;
    cout<<"Would you like to read from the Clubmember.txt?"<<endl<<"Y/N?: ";
    cin>>inChar;
    inChar=toupper(inChar);
    switch (inChar)
    {
            case 'Y':
        {
            inFile.open("CLUBMEMBERS.TXT");
            
            inFile.close();
            break;
        }
            case 'N':
        {
            
            break;
        }
            default:
        {
            cout<<"Failed input will default to not read in"<<endl;
        }
    }
    printMenu();
    
    while(cin>>inChar)
    {
        inChar=toupper(inChar);
            switch (inChar)
              {
                case 'A':
                {
                    cout<<"Please enter an integer: "<<endl;
                    cin>>inputtInt;
                    MyList.insert();
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
                    MyList.printList(MyList.);
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
    return 0;
}

void printMenu()
{
    cout << "Please select one of the following:" <<endl;
    cout << "A: Add a club member record" <<endl;
    cout << "D: Delete club member record"<<endl;
    cout << "R: Retrieve club record"<<endl;
    cout << "M: Modify a member record"<<endl;
    cout << "P: Print List" <<endl;
    cout << "Q: Quit the Program" <<endl;
    cout << ">> ";
}