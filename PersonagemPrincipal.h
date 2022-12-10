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
    virtual void getLife();
    virtual void getDefense();
    virtual void setLife(int &newLife);
    virtual void setDefense(int &newDefense);
};

#endif