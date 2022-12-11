#ifndef HEROIS_H
#define HEROIS_H

#include <iostream>

class Herois
{
public:
    std::string race, name;
    int life, defense, atack;
    int uso = 0;

    Herois();
    virtual ~Herois();
    virtual int getLife() = 0;
    virtual int getDefense() = 0;
    virtual int getAtack() = 0;
    virtual void setLife(int &newLife) = 0;
    virtual int setDefense(int &newDefense) = 0;
};

#endif
