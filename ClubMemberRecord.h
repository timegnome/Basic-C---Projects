//
//  ClubMemberRecord.h
//  something
//
//  Created by MMaxwell on 10/22/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef __something__ClubMemberRecord__
#define __something__ClubMemberRecord__

#include <iostream>
#include <string>
#include "Date.h"

class ClubMemberRecord{
    friend ostream &operator<<(ostream&,const ClubMemberRecord &);
public:
    ClubMemberRecord();
    ClubMemberRecord &operator=(const ClubMemberRecord &);
    bool operator==(const ClubMemberRecord) const;
    void setLastName(string);
    string getLastName();
    void setFirstName(string);
    string getFirstName();
    void setEmail(string);
    string getEmail();
    void setBirthDate(Date);
    Date getBirthDate();
    void setId(int);
    int getID();
    void setNumberMeals(int);
    int getNumberMeals();
private:
    string lastName;
    string firstName;
    string email;
    Date birthDate;
    int ID;
    int numMeals;
};
#endif /* defined(__something__ClubMemberRecord__) */
