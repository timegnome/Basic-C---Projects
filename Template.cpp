////
//  main.cpp
//  something
//
//  Created by MMaxwell on 10/6/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "LinkedListAdtTemplate.cpp"
#include "ClubMemberRecord.h"
#include <fstream>
using namespace std;

//BEGIN MAIN() -------------------------------
void printMenu();
void printMenu2();

int main()
{
    Lists<ClubMemberRecord> MyList;
    char inChar;
    ifstream inFile;
    ofstream outFile;
    string inputString1, inputString2;
    int inputInt,year,day,month;
    Date inDate;
    ClubMemberRecord temp;
    cout<<"Would you like to read from the Clubmember.txt?"<<endl<<"Y/N?: ";
    cin>>inChar;
    inChar=toupper(inChar);
    switch (inChar)
    {
        case 'Y':
        {
            inFile.open("CLUBMEMBERS.TXT");
            while(!inFile.eof())
            {
                inFile>>inputString1>>inputString2;
                temp.setLastName(inputString2);
                temp.setFirstName(inputString1);
                inFile>>inputString1>>inputInt;
                temp.setEmail(inputString1);
                temp.setId(inputInt);
                inFile>>month>>inChar>>day>>inChar>>year>>inputInt;
                inDate.setDate(month, day, year);
                temp.setBirthDate(inDate);
                temp.setNumberMeals(inputInt);
                inFile.ignore();
                MyList.insert(temp);
            }
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
                cout<<"Please enter an the first and last name: "<<endl;
                cin>>inputString1>>inputString2;
                temp.setLastName(inputString2);
                temp.setFirstName(inputString1);
                cout<<"Please enter an email: "<<endl;
                cin.ignore();
                getline(cin,inputString1);
                cout<<"Please enter an Id: "<<endl;
                cin>>inputInt;
                temp.setEmail(inputString1);
                temp.setId(inputInt);
                cout<<"Please enter the Date in this format mm/day/yyyy: "<<endl;
                cin>>month>>inChar>>day>>inChar>>year;
                cout<<"Please enter the number of meals eaten in the range 1-10: "<<endl;
                cin>>inputInt;
                inDate.setDate(month, day, year);
                temp.setBirthDate(inDate);
                temp.setNumberMeals(inputInt);
                MyList.insert(temp);
                break;}
            case 'C':
            {
                cout<<"Current position in list is: "<<MyList.currentPosition()<<endl;
                break;}
            case 'D':
            {
                cout<<"Please input the Id of the member your looking for: "<<endl;
                cin>>inputInt;
                if(MyList.deleteKeyNode(temp))
                {
                    cout<<"Removed"<<endl;
                }
                else
                {
                    cout<<"Not found"<<endl;
                }
                break;}
            case 'E':
            {
                MyList.makeEmpty();
                break;}
            case 'I':
            {
                cout<<"Current Item is: "<<MyList.CurrentItem()<<endl;
            }
            case 'M':
            {
                NodeType<ClubMemberRecord> *temp2;
                cout<<"Please input the Id of the member your looking Modify: "<<endl;
                if(cin>>inputInt)
                {
                    temp.setId(inputInt);
                    temp2=MyList.Find(temp);
                }
                else
                {
                    cout<<"Incorrect Input"<<endl;
                    break;
                }
                if(temp2)
                {
                    cout<<temp2->info<<endl;
                    cout<<"Would you like to modify the Member's info? Y/N?"<<endl;
                    cin>>inChar;
                    inChar=toupper(inChar);
                    if(inChar=='Y')
                        while(inChar!='N')
                        {
                            printMenu2();
                            cin>>inChar;
                            inChar=toupper(inChar);
                            switch (inChar)
                            {
                                case 'A':
                                {
                                    cout<<"Please enter an the first name: "<<endl;
                                    cin>>inputString1;
                                    temp2->info.setFirstName(inputString1);
                                    break;}
                                case 'D':
                                {
                                    cout<<"Please enter an the last name: "<<endl;
                                    cin>>inputString1;
                                    temp2->info.setLastName(inputString1);
                                    break;}
                                case 'M':
                                {
                                    cout<<"Please enter the number of meals eaten in the range 1-10: "<<endl;
                                    if(cin>>inputInt)
                                    {
                                        temp2->info.setNumberMeals(inputInt);
                                    }
                                    else
                                    {
                                        cout<<"Incorrect input"<<endl;
                                    }
                                    break;}
                                case 'R':
                                {
                                    cout<<"Please enter the Date in this format mm/day/yyyy: "<<endl;
                                    if(cin>>month>>inChar>>day>>inChar>>year)
                                    {
                                        inDate.setDate(month, day, year);
                                        temp2->info.setBirthDate(inDate);}
                                    else
                                    {
                                        cout<<"Incorrect Input"<<endl;
                                    }
                                    break;}
                                case 'P':
                                {
                                    cout<<"Please enter an email: "<<endl;
                                    cin>>inputString1;
                                    temp2->info.setEmail(inputString1);
                                }
                                case 'N':
                                {
                                    inChar='N';
                                    break;}
                            }
                        }
                }
                else
                {
                    cout<<"Member not found"<<endl;
                }
            }
            case 'R':
            {
                NodeType<ClubMemberRecord> *temp2;
                cout<<"Please input the Id of the member your looking Modify: "<<endl;
                if(cin>>inputInt)
                {
                    temp.setId(inputInt);
                    temp2=MyList.Find(temp);
                }
                else
                {
                    cout<<"Incorrect Input"<<endl;
                    break;
                }
                if(temp2)
                {
                    cout<<temp.getNumberMeals()<<endl;
                }
                break;}
            case 'P':
            {
                MyList.printList(MyList.getHead());
                break;}
            case 'S':
            {
                MyList.goToStart();
                break;}
            case 'Q':
            {
                MyList.printList(outFile, MyList.getHead());
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
void printMenu2()
{
    cout << "Please select one of the following:" <<endl;
    cout << "A: Change First name" <<endl;
    cout << "D: Change Last name"<<endl;
    cout << "R: Change Birth date"<<endl;
    cout << "M: Change meals consumed"<<endl;
    cout << "P: Change Email" <<endl;
    cout << "N: Quit the Program" <<endl;
    cout << ">> ";
}