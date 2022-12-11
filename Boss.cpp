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


int Boss::getLife()
{
    return this->life;
}

int Boss::getDefense()
{
    return this->defense;
}

int Boss::getAtack()
{
    return this->atack;
}

void Boss::setLife(int &newLife)
{
    this->life = newLife;
}

int Boss::setDefense(int &newDefense)
{
    return newDefense;
}