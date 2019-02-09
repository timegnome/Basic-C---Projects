//
//  Date.cpp
//  cpcs301
//
//  Created by MMaxwell on 9/29/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "Date.h"
using namespace std;

ostream & operator<<(ostream& streamOut,const Date & inDate)
{
    streamOut<<inDate.month<<"/"<<inDate.day<<"/"<<inDate.year;
    return streamOut;
}
bool Date::operator<=(Date other)const
{
    if((*this).year>other.year)
    {
        return false;
    }
    else if((*this).month>other.month)
    {
        return false;
    }
    return(*this).day>other.day;
}
Date::Date(int Month, int Day, int Year)
{
    setDate(Month, Day, Year);
}
Date & Date::setDate(int mm, int dd, int yy)
{
        month = ( mm >= 1 && mm <= 12 ) ? mm : 1;
        year = ( yy >= 1900 && yy <= 2100 ) ? yy : 1900;
        // test for a leap year
        if ( month == 2 && isLeapYear(year ))
            day = ( dd >= 1 && dd <= 29 ) ? dd : 1;
        else
            day = ( dd >= 1 && dd <= days[ month ] ) ? dd : 1;
    return *this;
}
Date & Date::operator=(const Date &rhs)
{
    (*this).setDate(rhs.month, rhs.day, rhs.year);
    return *this;
}
const Date &Date::operator+=( int additionalDays )
{
    for ( int i = 0; i < additionalDays; i++ )
        helpIncrement();
    return *this; // enables cascading
}
int Date::getMonth()const
{
    return month;
}
int Date::getDay()const
{
    return day;
}
int Date::getYear()const
{
    return year;
}
string Date::getMonthString()const
{
    string temp;
    temp=month;
    temp=day+year;
    return temp;
}
bool Date:: isLeapYear(int testyear) const
{
    return ( testyear % 400 == 0 || ( testyear % 100 != 0 && testyear % 4 == 0 ) );
         // a leap year
    //return 0==testyear%4;
}
bool Date:: isEndOfMonth(int testDay) const
{
    if ( month == 2 && isLeapYear( year ) )
        
        return (testDay == 29); // last day of Feb. in leap year
    
    else
        
        return (testDay == days[ month ]);
    /*
    switch(month)
    {
        case 2: return(day==29||day==28);
            break;
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:return (day==31);
            break;
        case 5:
        case 4:
        case 6:
        case 11: return(day==30);
            break;
        default: return false;
    }*/
}
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30,
    
    31, 31, 30, 31, 30, 31 };

const string Date::monthName[] = { "", "January",
    
    "February", "March", "April", "May", "June",
    
    "July", "August", "September", "October",
    
    "November", "December" };
void Date::helpIncrement()
{
    if ( ! isEndOfMonth(day)) { // date is not at the end of the month
        day++;
    }
    else if (month < 12 ) { // date is at the end of the month, but month < 12
        day = 1;
        ++month;
    }
    else // end of month and year: last day of the year
    {
        day = 1;
        month = 1;
        ++year;
    }
}
