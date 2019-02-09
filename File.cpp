//
//  File.cpp
//  cpcs301
//
//  Created by MMaxwell on 9/29/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//  ComicBook Personal Library
#include <iostream>
#include <string>
#include <fstream>
#include "ComicBook.cpp"

using namespace std;

void menu();

// The main function of this program is to take in a comicbook list of checked out comic books, display a menu
// to four different options


int main()
{
    ComicBook *comicBook,temp;
    Date todaysDate;
    ifstream inFile;
    ofstream outFile;
    char input;
    int year,day,month,size=0,maxsize, issueIn;
    cout<<"Welcome to CS comic library program"<<endl;
    cout<<"Please enter the today date in integers according to the following format -"<<endl;
    cout<<"mm dd yyyy: ";
    cin>>month>>day>>year;
    // Sets the date for today
    todaysDate.setDate(month, day, year);
    inFile.open("CheckedOutComics.dat");
    while(!inFile.eof())
    {
        //Gets the size of the file for how many
        size++;
        inFile.read(reinterpret_cast<char*>(&temp),sizeof(ComicBook));
    }
    inFile.seekg(0);
    maxsize=size*2;
    comicBook=new ComicBook[maxsize];
    for(int index=0; index<size; index++)
    {
        inFile.read(reinterpret_cast<char*>(&comicBook[index]),sizeof(ComicBook));
    }
    while(cin>>input)
    {
        menu();
        toupper(input);
        char firstIn[20],lastIn[30], titleIn[50];
        switch(input)
        {
                case'C':
            {
                Date tempDate=todaysDate;
                cout<<"Please enter your one line consisting the first and last names of the author"<<endl;
                cout<<"followed by the title of the comic book and issue number."<<endl;
                if (size<maxsize)
                {
                    comicBook[size].setCheckOutDate(todaysDate);
                    cin>>firstIn>>lastIn>>titleIn>>issueIn;
                    comicBook[size].setIssueNumber(issueIn);
                    comicBook[size].setLastName(lastIn);
                    comicBook[size].setTitle(titleIn);
                    comicBook[size].setFirstName(firstIn);
                    comicBook[size].setDueDate(tempDate+=14);
                }
                else
                {
                    maxsize*=2;
                    ComicBook *copy=new ComicBook[maxsize];
                    for(int index=0; index<size; index++)
                    {
                        copy[index]=comicBook[index];
                    }
                    delete comicBook;
                    comicBook=copy;
                }
                for(int index=0;index<size-1;index++)
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
            }
                break;
                case'D':
            {
                cout<<"Please enter your one line consisting the first and last names of the author"<<endl;
                cout<<"followed by the title of the comic book and issue number."<<endl;
                cin>>firstIn>>lastIn>>titleIn>>issueIn;
                for(int index=0;index<size;index++)
                {
                    if(comicBook[index].getFirstName()==firstIn&&comicBook[index].getLastName()==lastIn&&comicBook[index].getIssueNumber()==issueIn&&comicBook[index].getTitle()==titleIn)
                    {
                        if(comicBook[index].getDueDate()<todaysDate)
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
                        break;
                    }
                    cout<<"Book not found, please try again"<<endl;
                }
            }
                break;
                case'T':
            {
                cout<<"Author\t\t\tTitle & Issue # \t\tCheck out Date \tDue Date";
                for(int index=0; index<size; index++)
                {
                    cout<<comicBook[index].getFirstName()<<","<<comicBook[index].getLastName();
                    cout<<"\t"<<comicBook[index].getTitle()<<" #"<<comicBook[index].getIssueNumber();
                    cout<<"\t\t"<<comicBook[index].getCheckOutDate()<<"\t"<<comicBook[index].getDueDate();
                }
            }
                break;
                case'Q':
            {
                outFile.open("CheckedOutComics.dat");
                for(int index=0; index<size; index++)
                {
                    outFile.write(reinterpret_cast<const char*>(&comicBook[index]),sizeof(ComicBook));
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