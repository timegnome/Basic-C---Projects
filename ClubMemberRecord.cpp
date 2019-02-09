//
//  ClubMemberRecord.cpp
//  something
//
//  Created by MMaxwell on 10/22/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "ClubMemberRecord.h"
ClubMemberRecord::ClubMemberRecord()
{
    lastName="";
    firstName="";
    email="";
    ID=0;
    numMeals=0;
}
bool ClubMemberRecord::operator==(const ClubMemberRecord Member)const
{
    return (*this).ID==Member.ID;
}
ClubMemberRecord &ClubMemberRecord::operator=(const ClubMemberRecord &Member)
{
    (*this).setLastName(Member.lastName);
    (*this).setFirstName(Member.firstName);
    (*this).setEmail(Member.email);
    (*this).setBirthDate(Member.birthDate);
    (*this).setId(Member.ID);
    (*this).setNumberMeals(Member.numMeals);
    return *this;
}
ostream &operator<<(ostream& out,const ClubMemberRecord &Member)
{
    out<<Member.lastName<<' '<<Member.firstName<<' '<<Member.email<<' '<<Member.ID<<' '<<Member.birthDate<<' '<<Member.numMeals<<endl;
    return out;
}
void ClubMemberRecord::setLastName(string Last)
{
    lastName=Last;
}
string ClubMemberRecord::getLastName()
{
    return lastName;
}
void ClubMemberRecord::setFirstName(string First)
{
    firstName=First;
}
string ClubMemberRecord::getFirstName()
{
    return firstName;
}
void ClubMemberRecord::setEmail(string EAddress)
{
    email=EAddress;
}
string ClubMemberRecord::getEmail()
{
    return email;
}
void ClubMemberRecord::setBirthDate(Date birth)
{
    birthDate=birth;
}
Date ClubMemberRecord::getBirthDate()
{
    return birthDate;
}
void ClubMemberRecord::setId(int newId)
{
    ID=newId;
}
int ClubMemberRecord::getID()
{
    return ID;
}
void ClubMemberRecord::setNumberMeals(int Meals)
{
    if(Meals>0&&Meals<10)
        numMeals=Meals;
    else if(Meals>=10)
    {
        cout<<"!!FREE MEAL!!"<<endl;
        numMeals=Meals/10;
    }
    else{
        cout<<"Too low of a number"<<endl;
    }
}
int ClubMemberRecord::getNumberMeals()
{
    return numMeals;
}