//
//  Special.h
//  Game
//
//  Created by MMaxwell on 11/12/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef Game_Special_h
#define Game_Special_h

#include <string>
#include <iostream>

using namespace std;

class Special
{
public:
    Special()
    {
        
    }
    Special(int damage, string name)
    {
        SpecialDamage = damage;
        SpecialName = name;
    }
    string getName()
    {
        return SpecialName;
    }
    int getDamage()
    {
        return SpecialDamage;
    }
private:
    string SpecialName;
    int SpecialDamage;
};

#endif
