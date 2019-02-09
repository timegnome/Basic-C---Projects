#ifndef CHAR_H
#define CHAR_H
#include <iostream>
#include <string>
#include "stats.h"
using namespace std;

class Character
{
private:
	string name;
	int score;
	Stats charStat;
public:
	string getName() const;
	int getScore() const;
	Character & setScore(int);
	Character & setName(string);
	int incrementScore();
	Stats getStat();

};

string Character::getName() const
{
	return name;
}

int  Character::getScore() const
{
	return score;
}

Character & Character::setScore(int newScore)
{
	score = newScore;
	return (*this);
}

Character & Character::setName(string newName)
{
	name = newName;
	return (*this);
}

int Character::incrementScore()
{
	return score++;
}

Stats Character::getStat()
{
	return charStat;
}
#endif