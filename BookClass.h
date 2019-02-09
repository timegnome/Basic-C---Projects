//
//  BookClass.h
//  CS301
//
//  Created by MMaxwell on 11/3/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __CS301__BookClass__
#define __CS301__BookClass__

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Book
{
    friend ostream & operator<<(ostream&, const Book &);
public:
    Book(string newbook="nothing", string newReview="nothing");
    string getBook();
    void setBook(string);
    string getReview();
    void setReview(string);
    Date getDate();
    void setDate(Date);
private:
    string book;
    string review;
    Date dateCompleted;
};
#endif /* defined(__CS301__BookClass__) */
