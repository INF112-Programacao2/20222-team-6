#include "Inimigo.h"
#include "LeitorDeDados.h"

#include <vector>

Inimigo::Inimigo(){}

Inimigo::Inimigo(std::vector<std::pair<std::string,std::vector<int>>>allStatus)
{
    this->name = allStatus[0].first;
    this->life = allStatus[0].second[2];
    this->atack = allStatus[0].second[0];
    this->defense = allStatus[0].second[1];
}

Inimigo::~Inimigo(){}


int Inimigo::getLife()
{
    return this->life;
}

int Inimigo::getDefense()
{
    return this->defense;
}

int Inimigo::getAtack()
{
    return this->atack;
}

void Inimigo::setLife(int &newLife)
{
    this->life = newLife;
}

int Inimigo::setDefense(int &newDefense)
{
    return newDefense;
}
