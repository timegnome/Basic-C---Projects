//
//  main.cpp
//  CS301
//
//  Created by MMaxwell on 11/3/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

using namespace std;

void entryMenu();
void userMenu(int );
void manipulationMenu();
int login(string name, User* ,int);
bool found(string,User*,int);
bool registerUser(User*&,int);

int main()
{
    int menuChoice =0,numberOfUsers=0,location=0,arraySize=1, numberOfReaders=0;
    string userName;
    char inChar;
    User *Users;
    Users=new User[arraySize];
    do
    {
        entryMenu();
        cin>>userName;
        location=found(userName,Users,numberOfUsers);
        if(location>0)
        {
            cout<<"Please enter Password"<<endl;
            menuChoice=login(userName,Users,location);
        }
        else
        {
            if(arraySize==numberOfUsers)
            {
                arraySize*=2;
                User *copy=new User[arraySize];
                for(int index=0; index<numberOfUsers; index++)
                {
                    copy[index]=Users[index];
                }
                delete [] Users;
                Users=copy;
            }
            if(registerUser(Users,numberOfUsers))
            {
                numberOfReaders++;
                menuChoice=2;
            }
            else{
                menuChoice=1;
            }
            numberOfUsers++;
        }
        while(menuChoice==1)
        {
            userMenu(menuChoice);
            cin>>inChar;
            inChar=toupper(inChar);
            string InputString;
            //int inputInt;
            switch(inChar)
            {
                    case 'F':
                {
                    for(int index=0; index< numberOfUsers; index++)
                    {
                        if(Users[index].getIsReader())
                        {
                            cout<<Users[index].getUserName()<<" "<<Users[index].booksToRead.getFirstNode()->info.getBook()<<endl;
                            cout<<Users[index].getUserName()<<" "<<Users[index].booksToRead.getFirstNode()->info.getReview()<<endl;
                        }
                    }
                    cout<<"Would you like to approve a summary? Y//N"<<endl;
                    cin>>inChar;
                    inChar=toupper(inChar);
                    if(inChar=='Y')
                    {
                        cout<<"Which reader would you like to approve a summary for?"<<endl;
                    }
                    cin>>InputString;
                    location=-1;
                    for(int index=0; index< numberOfUsers; index++)
                    {
                        if(Users[index].getIsReader() && Users[index].getUserName().compare(InputString)==0)
                        {
                            location=index;
                        }
                    }
                    if(location>0)
                    {
                        manipulationMenu();
                        cin>>inChar;
                        inChar = toupper(inChar);
                        NodeType <Book> *temp;
                        if(inChar=='A')
                        {
                            temp = new NodeType<Book>;
                            temp->info = Users[location].booksToRead.getFirstNode()->info;
                            Users[location].booksToRead.dequeue();
                            Users[location].readBooks.insert(temp);
                        }
                    }
                    break;
                }
                    case 'R':
                {
                    for(int index=0; index< numberOfUsers; index++)
                    {
                        if(Users[index].getIsReader())
                        {
                            cout<<Users[index].getUserName()<<endl;
                        }
                    }
                    cin>>InputString;
                    location=-1;
                    for(int index=0; index< numberOfUsers; index++)
                    {
                        if(Users[index].getIsReader() && Users[index].getUserName().compare(InputString)==0)
                        {
                            location=index;
                        }
                    }
                    Users[location].readBooks.printlist(Users[location].readBooks.getHead());
                    break;
                }
                    case 'S':
                {
                    User *ptrList[numberOfReaders];
                    for(int index=0; index< numberOfUsers; index++)
                    {
                        for(int reader=index; reader<numberOfUsers; reader++)
                            if(Users[index].getIsReader() && Users[reader].readBooks.getSize()>location)
                            {
                                location=Users[reader].readBooks.getSize();
                                ptrList[index]=&Users[reader];
                            }
                        if(index==numberOfReaders)
                            break;
                    }
                    for(int index=0; index<numberOfReaders;index++)
                    {
                        cout<<ptrList[index]->getUserName()<<": "<<ptrList[index]->readBooks.getSize()<<endl;
                    }
                    break;
                }
                    case 'L':
                {
                    menuChoice=0;
                    break;
                }
                    case 'Q':
                {
                    cout<<"Have a nice Day"<<endl;
                    return 0;
                }
                default: cout<<"Invalid input"<<endl;
            }
        }
        while(menuChoice==2)
        {
            userMenu(menuChoice);
            cin>>inChar;
            inChar=toupper(inChar);
            string InputString;
            int inputInt;
            switch(inChar)
            {
                case 'W':
                {
                    cout<<"Please enter your summary for "<<(Users[location].booksToRead.getFirstNode())->info.getBook()<<endl;
                    cin>>InputString;
                    Users[location].booksToRead.getFirstNode()->info.setReview(InputString);
                    Users[location].booksToRead.getFirstNode()->prioty=1;
                    //Users[location].booksToRead.enqueue(NodeType<Book> *newItem)
                    break;
                }
                case 'R':
                {
                    Users[location].readBooks.printlist(Users[location].readBooks.getHead());
                    break;
                }
                case 'A':
                {
                    cout<<"Please enter the book you would like to add";
                    cin>>InputString;
                    Book newBook(InputString);
                    cout<<"Please enter the priorty from 1-5";
                    if(cin>>inputInt)
                    {
                        if(inputInt>0)
                            inputInt=5;
                    }
                    else
                    {
                        inputInt=0;
                    }
                    NodeType<Book> *newEntry = new NodeType<Book>;
                    newEntry->info=newBook;
                    newEntry->prioty=inputInt;
                    Users[location].booksToRead.enqueue(newEntry);
                    break;
                }
                case 'L':
                {
                    menuChoice=0;
                    break;
                }
                case 'Q':
                {
                    cout<<"Have a nice Day"<<endl;
                    return 0;
                }
                default: cout<<"Invalid input"<<endl;
            }
        }
    }while (menuChoice>=0);
    return 0;
}
bool found(string name, User* Users,int arraySize)
{
    for(int index=0; index<arraySize; index++)
    {
        if(name.compare(Users[index].getUserName())==0)
        return true;
    }
    return false;
}
int login(string name, User* Users,int arrayLocation)
{
    if(Users[arrayLocation].isPassword(name))
    {
        if(Users[arrayLocation].getIsReader())
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 0;
}
bool registerUser(User* &Users,int arraySize)
{
    string tempUser,tempPass;
    char inchar;
    bool reader;
    cout<<"Please enter if you are a volounteer or reader V/R"<<endl;
    cin>>inchar;
    inchar= toupper(inchar);
    if(inchar=='V')
    {
        reader=false;
    }
    else
    {
        reader=true;
    }
    cout<<"Please enter User Name"<<endl;
    cin>>tempUser;
    cout<<"Please enter password"<<endl;
    cin>>tempPass;
    //User temp(tempUser,tempPass,reader);
    //Users[arraySize]=temp;
    Users[arraySize]=*new User(tempUser,tempPass,reader);
    return reader;
}
void entryMenu()
{
    cout<<"Hello please Enter your user Name and password"<<endl;
    cout<<"If You Do Not Have A User Name Please type \"New\""<<endl;
}

void userMenu(int user)
{
    if(user ==1)
    {
        cout<<"F: Find & View Youth Book Summary"<<endl;
        cout<<"R: Find & view reader book history"<<endl;
        cout<<"S: View Ranking of Readers"<<endl;
        cout<<"L: Log Out"<<endl;
        cout<<"Q: Quit Program"<<endl;
    }
    else
    {
        cout<<"W: Write the review for Current book"<<endl;
        cout<<"R: View books read"<<endl;
        cout<<"A: Add Completed book"<<endl;
        cout<<"L: Log Out"<<endl;
        cout<<"Q: Quit Program"<<endl;
    }
}

void manipulationMenu()
{
    cout<<"A: Approve Summary"<<endl;
    cout<<"D: Decline Summary"<<endl;
}