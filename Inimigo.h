#ifndef INIMIGO_H
#define INIMIGO_H

#include "Herois.h"

#include <vector>

class Inimigo : public Herois
{
  public:
    Inimigo();
    Inimigo(std::vector<std::pair<std::string,std::vector<int>>>allStatus);
    ~Inimigo();
    virtual int getLife();
    virtual int getDefense();
    virtual int getAtack();
    virtual void setLife(int &newLife);
    virtual int setDefense(int &newDefense);
};

#endif