#include "Inimigo.h"
#include "LeitorDeDados.h"

#include <vector>

Inimigo::Inimigo(std::vector<std::pair<std::string,std::vector<int>>>allStatus)
{
    this->name = allStatus[0].first;
    this->life = allStatus[0].second[2];
    this->atack = allStatus[0].second[0];
    this->defense = allStatus[0].second[1];
}

Inimigo::~Inimigo(){}


void Inimigo::getLife(){}

void Inimigo::getDefense(){}

void Inimigo::setLife(int &newLife){}

void Inimigo::setDefense(int &newDefense){}
