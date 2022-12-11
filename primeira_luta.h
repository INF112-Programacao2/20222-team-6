#ifndef PRIMEIRA_LUTA_H
#define PRIMEIRA_LUTA_H

#include "Luta.h"
#include "PersonagemPrincipal.h"
#include "Inimigo.h"
#include "Acao.h"

class PrimeiraLuta : public Luta
{
private:
    PersonagemPrincipal *heroi;
    Inimigo *inimigo;
    Acao *acao;
    std::string vidaHeroi;
    std::string vidaInimigo;

    bool moviment;

public:
    PrimeiraLuta();
    ~PrimeiraLuta();
    void movimentEnemie(bool &moviment, bool &running);
    void initialize();
    void initializeVidas();
    void lutaUpdate(sf::RenderWindow *janela, bool &running);
    void lutaDraw(sf::RenderWindow *janela);
    
};

#endif