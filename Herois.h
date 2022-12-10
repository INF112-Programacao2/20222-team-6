#ifndef HEROIS_H
#define HEROIS_H

#include <iostream>

class Herois
{
public:
    std::string race, name;
    int life, defense, atack;

    Herois();
    virtual ~Herois();
    virtual void getLife() = 0;
    virtual void getDefense() = 0;
    virtual void setLife(int &newLife) = 0;
    virtual void setDefense(int &newDefense) = 0;
};

#endif
