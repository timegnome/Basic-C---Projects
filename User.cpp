//
//  User.cpp
//  CS301
//
//  Created by MMaxwell on 11/3/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "User.h"

User::User(string name,string password,bool reader)
{
    userName=name;
    userPassword=password;
    isReader=reader;
}
string User::getUserName()
{
    return userName;
}
void User::setUserName(string name)
{
    userName=name;
}
bool User::isPassword(string password)
{
    return (userPassword.compare(password)==0);
}
bool User::getIsReader()
{
    return isReader;
}