//
//  Items.h
//  Game
//
//  Created by MMaxwell on 11/12/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef Game_Items_h
#define Game_Items_h

#include <iostream>
#include <string>

using namespace std;


class Item
{
public:
    Item()
    {
        hp=attack=mp=0;
    }
    Item(int damage, int health, int magic, string name)
    {
        hp = health;
        attack = damage;
        mp = magic;
        itemName = name;
    }
    int getAttack()
    {
        return attack;
    }
    int getHp()
    {
        return hp;
    }
    int getMp()
    {
        return mp;
    }
    string getName()
    {
        return itemName;
    }
    
private:
    int hp;
    int attack;
    int mp;
    string itemName;
}

#endif
