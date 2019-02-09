//
//  BookClass.cpp
//  CS301
//
//  Created by MMaxwell on 11/3/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "BookClass.h"

ostream & operator<<(ostream& streamOut,const Book & inBook)
{
    streamOut<<inBook.dateCompleted<<inBook.book<<"\n"<<inBook.review<<endl;
    return streamOut;
}
Book::Book(string newBook, string newReview)
{
    book=newBook;
    review=newReview;
}
string Book::getBook()
{
    return book;
}
void Book::setBook(string newBook)
{
    book=newBook;
}
string Book::getReview()
{
    return review;
}
void Book::setReview(string newReview)
{
    review=newReview;
}
Date Book::getDate()
{
    return dateCompleted;
}
void Book::setDate(Date newDate)
{
    dateCompleted=newDate;
}