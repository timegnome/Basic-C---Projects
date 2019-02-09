//
//  Beverage.cpp
//  cs301
//
//  Created by MMaxwell on 10/1/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include "Beverage.h"

Beverage & Beverage::setDrinkName(char *name)
{
    strcpy(drinkName,name);
    return *this;
}
Beverage & Beverage::setcaffeineAmount(int amount)
{
    caffeineAmount=amount;
    return *this;
}
Beverage & Beverage::setPrice(double Dprice)
{
    price=Dprice;
    return *this;
}
Beverage & Beverage::setDatePurchased(Date dateP)
{
    datePurchased=dateP;
    return *this;
}
int Beverage::getcaffeineAmount()
{
    return caffeineAmount;
}
double Beverage::getPrice()
{
    return price;
}
const char* Beverage::getdrinkName()
{
    return drinkName;
}
const void Beverage::print()const
{
    cout<<datePurchased<<" "<<drinkName<<" "<<price<<'('<<caffeineAmount<<')'<<endl;
}
const void Beverage::print(ofstream& out)const
{
    out<<caffeineAmount<<' '<<price<<' '<<datePurchased.getMonth()<<'|'<<datePurchased.getDay()<<'|'<<datePurchased.getYear()<<' '<<drinkName<<'\n';
}