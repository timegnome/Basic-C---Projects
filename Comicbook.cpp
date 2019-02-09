//
//  Comicbook.cpp
//  something
//
//  Created by MMaxwell on 10/6/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "Comicbook.h"

ComicBook::ComicBook(char * first, char *last, char *Title, int number, Date check, Date returnDate)
{
    strcpy(firstName,first);
    strcpy(lastName,last);
    strcpy(title,Title);
    issue=number;
    checkOut=check;
    due=returnDate;
}
ComicBook::ComicBook()
{
    
}
ComicBook & ComicBook::setCheckOutDate( Date newDate)
{
    checkOut=newDate;
    return *this;
}
ComicBook& ComicBook::setDueDate(Date newDate)
{
    due=newDate;
    return *this;
}
ComicBook & ComicBook::setFirstName(const char *first)
{
    strcpy(firstName,first);
    return *this;
}
ComicBook & ComicBook::setLastName(const char *last)
{
    strcpy(lastName,last);
    return *this;
}
ComicBook & ComicBook::setTitle(const char *first)
{
    strcpy(title,first);
    return *this;
}
ComicBook & ComicBook::setIssueNumber(const int number)
{
    issue=number;
    return *this;
}
const char * ComicBook::getFirstName() const
{
    return firstName;
}
const char * ComicBook::getLastName() const
{
    return lastName;
}
const char * ComicBook::getTitle() const
{
    return title;
}
const int ComicBook::getIssueNumber() const
{
    return issue;
}
Date ComicBook::getCheckOutDate() const
{
    return checkOut;
}
Date ComicBook::getDueDate() const
{
    return due;
}