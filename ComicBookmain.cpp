//
//  main.cpp
//  something
//
//  Created by MMaxwell on 10/6/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Comicbook.h"

using namespace std;

void menu();
int main()
{
    ComicBook *comicBook,temp;
    Date todaysDate;
    ifstream inFile;
    ofstream outFile;
    bool found =false;
    char input;
    int year,day,month,size=0,maxsize=1, issueIn=-1;
    cout<<"Welcome to CS comic library program"<<endl;
    cout<<"Please enter the today date in integers according to the following format -"<<endl;
    cout<<"mm dd yyyy: ";
    cin>>month>>day>>year;
    todaysDate.setDate(month, day, year);
    inFile.open("CheckedOutComics.dat", ios::binary);
    if(!inFile)
    // check that file is attached
    {
        cout << "File not attached." <<endl;
        maxsize*=2;
        comicBook=new ComicBook[maxsize];
    //    temp.setCheckOutDate(todaysDate);
    //    temp.setCheckOutDate(todaysDate);
    }
    else
    {
        while(inFile.read(reinterpret_cast<char*>(&temp),sizeof(ComicBook)))
        {
            size++;
        }
        inFile.close();
        maxsize=size*2;
        comicBook=new ComicBook[maxsize];
        inFile.open("CheckedOutComics.dat",ios::binary);
        for(int index=0; index<size; index++)
        {
            inFile.read(reinterpret_cast<char*>(&comicBook[index]),sizeof(ComicBook));
        }
        inFile.close();
    }
    menu();
    while(cin>>input)
    {
        input=toupper(input);
        char firstIn[20],lastIn[30], titleIn[50];
        switch(input)
        {
            case'C':
            {
                Date tempDate=todaysDate;
                cout<<"Please enter your one line consisting the first and last names of the author"<<endl;
                cout<<"followed by the title of the comic book and issue number."<<endl;
                cin>>firstIn>>lastIn;
                //cin.getline(titleIn, 50,'#');
                int index=0;
                cin.get(titleIn[index]);
                while(titleIn[index]!='#'&&index!=49)
                {
                    index++;
                    cin.get(titleIn[index]);
                }
                titleIn[index]='\0';
                cin>>issueIn;
                if(issueIn<0)
                {
                    cout<<"Please re-enter the issue number"<<endl;
                    cin>>issueIn;
                }
                if (size<maxsize)
                {
                    comicBook[size].setCheckOutDate(todaysDate);
                    comicBook[size].setIssueNumber(issueIn);
                    comicBook[size].setLastName(lastIn);
                    comicBook[size].setTitle(titleIn);
                    comicBook[size].setFirstName(firstIn);
                    comicBook[size].setDueDate(tempDate+=14);
                    size++;
                }
                else
                {
                    maxsize*=2;
                    ComicBook *copy=new ComicBook[maxsize];
                    for(int index=0; index<size; index++)
                    {
                        copy[index]=comicBook[index];
                    }
                    delete [] comicBook;
                    comicBook=copy;
                    comicBook[size].setCheckOutDate(todaysDate);
                    comicBook[size].setIssueNumber(issueIn);
                    comicBook[size].setLastName(lastIn);
                    comicBook[size].setTitle(titleIn);
                    comicBook[size].setFirstName(firstIn);
                    comicBook[size].setDueDate(tempDate+=14);
                    size++;
                }
                for(int index=0;index<size;index++)
                {
                    for(int secIndex=index;secIndex<size;secIndex++)
                    {
                        if(comicBook[index].getFirstName()[0]>comicBook[index+1].getFirstName()[0])
                        {
                            temp=comicBook[index];
                            comicBook[index]=comicBook[secIndex];
                            comicBook[secIndex]=temp;;
                        }
                    }
                }
                cout<< "Added"<<endl;
            }
                break;
            case'D':
            {
                cout<<"Please enter your one line consisting the first and last names of the author"<<endl;
                cout<<"followed by the title of the comic book and issue number."<<endl;
    //            comicBook[size].setCheckOutDate(todaysDate);
                cin>>firstIn>>lastIn;
                int index=0;
                cin.get(titleIn[index]);
                while(titleIn[index]!='#'&&index!=49)
                {
                    index++;
                    cin.get(titleIn[index]);
                }
                titleIn[index]='\0';
                cin>>issueIn;
                if(issueIn<0)
                {
                    cout<<"Please re-enter the issue number"<<endl;
                    cin>>issueIn;
                }
                found =false;
                for(int index=0;index<size;index++)
                {
                    if(strcmp(comicBook[index].getFirstName(),firstIn) + strcmp(comicBook[index].getLastName(),lastIn) + comicBook[index].getIssueNumber() -issueIn + strcmp(comicBook[index].getTitle(),titleIn)==0)
                    {
                        if(!(comicBook[index].getDueDate()<=todaysDate))
                        {
                            cout<<"Returned on time"<<endl;
                        }
                        else
                        {
                            cout<<"This comic book is OverDue"<<endl;
                        }
                        size--;
                        for(int secIndex=index; secIndex<size;secIndex++)
                        {
                            comicBook[secIndex]=comicBook[secIndex+1];
                        }
                        found = true;
                    }
                }if(!found)
                cout<<"Book not found, please try again"<<endl;
                break;
            }
            case'T':
            {
                cout<<"Author\t\t\tTitle & Issue # \t\tCheck out Date \t\tDue Date"<<endl;
                for(int index=0; index<size; index++)
                {
                    cout<<comicBook[index].getFirstName()<<","<<comicBook[index].getLastName();
                    cout<<'\t'<<comicBook[index].getTitle()<<" #"<<comicBook[index].getIssueNumber();
                    cout<<'\t'<<comicBook[index].getCheckOutDate()<<'\t'<<comicBook[index].getDueDate()<<endl;
                }
            }
                break;
            case'Q':
            {
                outFile.open("CheckedOutComics.dat");
                cout<<size;
                int index =0;
                while(index<size)
                {
                    outFile.write(reinterpret_cast<const char*>(&comicBook[index]),sizeof(ComicBook));
                    index++;
                }
                outFile.close();
                return 0;
            }
                break;
            default:
            {
                cout<<"Incorrect input. Please try again"<<endl;
            }
        }
        menu();
    }
}
void menu()
{
    
    cout<<"Please enter your one letter choice as follows:"<<endl;
    cout<<"   C: Check out a comic book"<<endl;
    cout<<"   D: Check in a comic book"<<endl;
    cout<<"   T: Print all cominc books currently checked out"<<endl;
    cout<<"   Q: Quit this program"<<endl;
}
