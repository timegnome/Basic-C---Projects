
#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class Stats{

private:
	int mp;
	int hp;
	int attack;

public:
	// get
	int geMp();
	int getHp();
	int getAttack();

	// set
	void setMp(int );
	void setHp(int );
	void setAttack(int );

};

#endif 


