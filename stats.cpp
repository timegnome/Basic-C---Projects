
#include "stats.h"

using namespace std;

// get
int Stats::geMp(){
	return mp;
}

int Stats::getHp(){
	return hp;
}

int Stats::getAttack(){
	return attack;
}

// set
void Stats::setMp(int tempMP) {
	mp = tempMP;
}

void Stats::setHp(int tempHp){
	hp = tempHp;
}

void Stats::setAttack(int tempAttack){
	attack = tempAttack;
}