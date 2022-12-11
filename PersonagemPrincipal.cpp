#include "PersonagemPrincipal.h"
#include "LeitorDeDados.h"

PersonagemPrincipal::PersonagemPrincipal(){}

PersonagemPrincipal::PersonagemPrincipal(std::vector<std::pair<std::string,std::vector<int>>>allStatus)
{
    this->name = allStatus[0].first;
    this->life = allStatus[0].second[2];
    this->atack = allStatus[0].second[0];
    this->defense = allStatus[0].second[1];
}

PersonagemPrincipal::~PersonagemPrincipal(){}


int PersonagemPrincipal::getLife()
{
    return this->life;
}

int PersonagemPrincipal::getDefense()
{
    return this->defense;
}

int PersonagemPrincipal::getAtack()
{
    return this->atack;
}

void PersonagemPrincipal::setLife(int &newLife)
{
    this->life = newLife;
}

int PersonagemPrincipal::setDefense(int &newDefense)
{
    return newDefense;
}

