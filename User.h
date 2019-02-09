//
//  User.h
//  CS301
//
//  Created by MMaxwell on 11/3/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __CS301__User__
#define __CS301__User__

#include <iostream>
#include <string>
#include "BookClass.h"
#include "Prioty Queue.h"
#include "ListTemplate.h"

using namespace std;

class User
{
public:
    User(string name="nothing",string password="nothing",bool reader=true);
    string getUserName();
    bool isPassword(string);
    void setUserName(string);
    bool getIsReader();
    listTemplate<Book> readBooks;
    priotyQueue<Book> booksToRead;
private:
    string userName;
    string userPassword;
    bool isReader;
};

#endif /* defined(__CS301__User__) */
