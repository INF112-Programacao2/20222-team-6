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
    virtual void getLife();
    virtual void getDefense();
    virtual void setLife(int &newLife);
    virtual void setDefense(int &newDefense);
};

#endif