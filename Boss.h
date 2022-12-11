#ifndef BOSS_H
#define BOSS_H

#include "Herois.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Boss : public Herois
{
  public:
    Boss();
    Boss(std::vector<std::pair<std::string,std::vector<int>>>allStatus);
    ~Boss();
    virtual int getLife();
    virtual int getDefense();
    virtual int getAtack();
    virtual void setLife(int &newLife);
    virtual int setDefense(int &newDefense);
};

#endif