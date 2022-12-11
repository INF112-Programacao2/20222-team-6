#ifndef ACAO_H
#define ACAO_H

#include "Herois.h"

class Acao
{
public:
    Acao();
    ~Acao();
    bool defineAtack(Herois* heroi, Herois* inimigo);
    void defineDefense(Herois* heroi);
    void defineHeal(Herois* heroi);
    
};

#endif 
