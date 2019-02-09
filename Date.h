//
//  Date.h
//  cpcs301
//
//  Created by MMaxwell on 9/29/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __cpcs301__Date__
#define __cpcs301__Date__

#include <iostream>
using namespace std;

class Date{
    friend ostream &operator<<(ostream&,const Date &);
public:
    Date(int Month=0,int Day=0,int Year=0);
    Date & setDate(int, int , int);
    bool operator<=(Date other)const;
    Date &operator=(const Date &rhs);
    const Date  &operator+=(int);
    bool isLeapYear(int) const;
    bool isEndOfMonth(int testDay) const;
    int getMonth()const;
    int getDay()const;
    int getYear()const;
    string getMonthString()const;
private:
    int month, day, year;
    static const int days[];
    static const string monthName[];
    void helpIncrement();
    
};
#endif /* defined(__cpcs301__Date__) */
