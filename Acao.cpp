#include <iostream>
#include "Acao.h"


Acao::Acao(){}

Acao::~Acao(){}

bool Acao::defineAtack(Herois* heroi, Herois* inimigo){
    
    int actualHP;
    if(inimigo->uso == 0){
    actualHP = inimigo->getLife() - (heroi->getAtack() - inimigo->getDefense());
    }

    if(inimigo->uso >= 1)
    {
        int defense = 30;
        inimigo->uso = 0;
        actualHP = inimigo->getLife() - (heroi->getAtack() - inimigo->setDefense(defense) - inimigo->getDefense());
    }
    
    if(actualHP <= 0)
    {
        return false;
    }
    else
    {
        inimigo->setLife(actualHP);
        return true;
    } 
}

void Acao::defineDefense(Herois* heroi){
    
    heroi->uso++;
}

void Acao::defineHeal(Herois* heroi){

    int Heal = 20;
    Heal += heroi->getLife();
    heroi->setLife(Heal);   
}