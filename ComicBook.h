//
//  ComicBook.h
//  cpcs301
//
//  Created by MMaxwell on 9/29/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __cpcs301__ComicBook__
#define __cpcs301__ComicBook__

#include <iostream>
#include <fstream>
#include "Date.cpp"
using namespace std;

class ComicBook
{
public:
    ComicBook(char *, char *, char *, int, Date, Date);
    ComicBook();
    ~ComicBook();
    ComicBook & setCheckOutDate( Date);
    ComicBook & setDueDate( Date);
    ComicBook & setFirstName(const char*);
    ComicBook & setLastName(const char *);
    ComicBook & setTitle(const char *);
    ComicBook & setIssueNumber(const int);
    const char * getFirstName() const;
    const char * getLastName() const;
    const char * getTitle() const;
    const int getIssueNumber() const;
    Date getCheckOutDate() const;
    Date getDueDate() const;
    
private:
    char firstName[20];
    char lastName[30];
    char title[50];
    int issue;
    Date checkOut;
    Date due;
};
#endif /* defined(__cpcs301__ComicBook__) */
