//
//  File.cpp
//  Final
//
//  Created by MMaxwell on 12/15/15. Like a Boss
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Job.h"
#include "Queue.h"

using namespace std;

void printMenu();

int main()
{
    Job temp;
    Queue<Job> standardJob;
    Queue<Job> priorityJob;
    char userSelection;
    string description, contactName;
    int Phone;
    int Id;
    ifstream inFile;
    inFile.open("Save.txt");
    if(inFile.is_open())
    {
        while(!inFile.eof())
        {
            inFile>>Id;
            //cin.ignore();
            getline(inFile,description);
            inFile>>Phone;
            getline(inFile, contactName);
            temp.setJobID(Id);
            temp.setJobDescription(description);
            temp.setPhoneExt(Phone);
            temp.setContact(contactName);
            if(temp.getJobID() != 0 && temp.getPhoneExt() != 0)
            {
                if(standardJob.enqueue(temp))
                {
                    
                }
                else
                {
                    cout<<"Failed"<<endl;
                }
            }
        }
    }
    else
    {
        cout<<"No Text file"<<endl;
    }
    if(standardJob.isEmpty())
    {
        cout<<"No saved data"<<endl;
    }
    inFile.close();
    while(true)
    {
        printMenu();
        cin>>userSelection;
        userSelection = toupper(userSelection);
        switch (userSelection)
        {
                case 'J':
            {
                cout<<"Select standard of priority job: \nS/P?"<<endl;
                cin>>userSelection;
                if(userSelection == 'P')
                {
                    cout<<"\nEnter Job Id: ";
                    cin>>Id;
                    cout<<"\nEnter Job description: ";
                    cin.ignore();
                    getline(cin,description);
                    cout<<"\nEnter Phone extentension: ";
                    cin>>Phone;
                    cout<<"\nEnter Contact name: ";
                    cin.ignore();
                    getline(cin, contactName);
                    temp.setJobID(Id);
                    temp.setJobDescription(description);
                    temp.setPhoneExt(Phone);
                    temp.setContact(contactName);
                    if(priorityJob.enqueue(temp))
                    {
                        cout<<"Added to priority"<<endl;
                    }
                    else
                    {
                        cout<<"Failed to add"<<endl;
                    }
                }
                else
                {
                    cout<<"\nEnter Job Id: ";
                    cin>>Id;
                    cout<<"\nEnter Job description: ";
                    cin.ignore();
                    getline(cin,description);
                    cout<<"\nEnter Phone extentension: ";
                    cin>>Phone;
                    cout<<"\nEnter Contact name: ";
                    cin.ignore();
                    getline(cin, contactName);
                    temp.setJobID(Id);
                    temp.setJobDescription(description);
                    temp.setPhoneExt(Phone);
                    temp.setContact(contactName);
                    if(standardJob.enqueue(temp))
                    {
                        cout<<"Added to standard"<<endl;
                    }
                    else
                    {
                        cout<<"Failed to add"<<endl;
                    }
                }
                break;
            }
                case 'N':
            {
                if(priorityJob.isEmpty())
                {
                    if(standardJob.dequeue(temp))
                    {
                        cout<<"Standard job"<<temp<<endl;
                    }
                    else
                    {
                        cout<<"Failed to remove/isEmpty"<<endl;
                    }
                }
                else
                {
                    if(priorityJob.dequeue(temp))
                    {
                        cout<<"Priority Job"<<temp<<endl;
                    }
                    else
                    {
                        cout<<"Failed to remove/isEmpty"<<endl;
                    }
                }
                break;
            }
                case 'Q':
            {
                ofstream outFile;
                outFile.open("Save.txt");
                if(priorityJob.isEmpty())
                {
                    while(!standardJob.isEmpty())
                    {
                        if(standardJob.dequeue(temp))
                        {
                            outFile<<temp.getJobID()<<" "<<temp.getJobDescription()<<"\n"<<temp.getPhoneExt()<<" "<<temp.getContact()<<endl;
                        }
                        else
                        {
                            cout<<"Failed to remove/isEmpty"<<endl;
                        }
                    }
                }
                else
                {
                    while(!priorityJob.isEmpty())
                    {
                        if(priorityJob.dequeue(temp))
                        {
                            cout<<"Priority Job"<<temp<<endl;
                        }
                        else
                        {
                            cout<<"Failed to remove/isEmpty"<<endl;
                        }
                    }
                    while(!standardJob.isEmpty())
                    {
                        if(standardJob.dequeue(temp))
                        {
                            outFile<<temp.getJobID()<<" "<<temp.getJobDescription()<<"\n"<<temp.getPhoneExt()<<" "<<temp.getContact()<<endl;
                        }
                        else
                        {
                            cout<<"Failed to remove/isEmpty"<<endl;
                        }
                    }
                }
                outFile.close();
                return 0;
                break;
            }
            default:
                cout<<"In valid Selection"<<endl;
                break;
        }
    }
}
void printMenu()
{
    cout<<"J: Add a new job"<<endl;
    cout<<"N: Remove a job"<<endl;
    cout<<"Q: Quit program and Save data"<<endl;
}
