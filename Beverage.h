//
//  Beverage.h
//  cs301
//
//  Created by MMaxwell on 10/1/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef COFFEE_H
#define COFFEE_H

#include <cstring>
#include <iostream>
#include <fstream>
#include "Beverage.h"
#include "Date.h"

class Beverage
{
public:
    
    Beverage(){}; // constructor
    ~Beverage(){}; // deconstructor
    Beverage & setDrinkName(char *);
    Beverage & setcaffeineAmount(int);
    Beverage & setPrice(double);
    Beverage & setDatePurchased(Date);
    int getcaffeineAmount();
    double getPrice();
    const char* getdrinkName();
    const void print()const;
    const void print(ofstream& out)const;
    
private:
    
    char drinkName[25];
    int caffeineAmount;
    double price;
    Date datePurchased;
};

#endif
