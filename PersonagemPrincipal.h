#ifndef PERSONAGEM_PRINCIPAL_H
#define PERSONAGEM_PRINCIPAL_H

#include "Herois.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class PersonagemPrincipal : public Herois
{
  public:
    PersonagemPrincipal();
    PersonagemPrincipal(std::vector<std::pair<std::string,std::vector<int>>>allStatus);
    ~PersonagemPrincipal();
    virtual int getLife();
    virtual int getDefense();
    virtual int getAtack();
    virtual void setLife(int &newLife);
    virtual int setDefense(int &newDefense);
};

#endif