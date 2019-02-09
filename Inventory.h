//
//  Inventory.h
//  Game
//
//  Created by MMaxwell on 11/12/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#ifndef Game_Inventory_h
#define Game_Inventory_h

#include "Items.h"

using namespace std;

class Inventory
{
public:
    int getMoney()
    {
        return money;
    }
    void changeMoney(int income)
    {
        money+=income;
    }
    Item[] getItems()
    {
        return playerItems;
    }
private:
    Item playerItems[6];
    int money;
}

#endif
