#include "Boss.h"
#include "LeitorDeDados.h"

#include <vector>

Boss::Boss(std::vector<std::pair<std::string,std::vector<int>>>allStatus)
{
    this->name = allStatus[0].first;
    this->life = allStatus[0].second[2];
    this->atack = allStatus[0].second[0];
    this->defense = allStatus[0].second[1];
}

Boss::~Boss(){}


void Boss::getLife(){}

void Boss::getDefense(){}

void Boss::setLife(int &newLife){}

void Boss::setDefense(int &newDefense){}