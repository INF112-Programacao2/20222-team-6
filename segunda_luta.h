#ifndef SEGUNDA_LUTA_H
#define SEGUNDA_LUTA_H

#include "Luta.h"
#include "PersonagemPrincipal.h"
#include "Inimigo.h"
#include "Acao.h"
#include "Boss.h"

class SegundaLuta : public Luta
{
    PersonagemPrincipal *heroi;
    Boss *boss;
    Acao *acao;
    std::string vidaHeroi;
    std::string vidaBoss;

    bool moviment, gameover;

public:
    SegundaLuta();
    ~SegundaLuta();
    void movimentEnemie(bool &moviment, bool &gameover);
    void initialize();
    void initializeVidas();
    void lutaUpdate(sf::RenderWindow *janela, bool &running, bool &fim);
    void lutaDraw(sf::RenderWindow *janela);
};

#endif