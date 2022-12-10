#include "PersonagemPrincipal.h"
#include "LeitorDeDados.h"

PersonagemPrincipal::PersonagemPrincipal(std::vector<std::pair<std::string,std::vector<int>>>allStatus)
{
    this->name = allStatus[0].first;
    this->life = allStatus[0].second[2];
    this->atack = allStatus[0].second[0];
    this->defense = allStatus[0].second[1];
}

PersonagemPrincipal::~PersonagemPrincipal(){}


void PersonagemPrincipal::getLife(){}

void PersonagemPrincipal::getDefense(){}

void PersonagemPrincipal::setLife(int &newLife){}

void PersonagemPrincipal::setDefense(int &newDefense){}


