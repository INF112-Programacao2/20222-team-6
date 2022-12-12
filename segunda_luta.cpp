#include "segunda_luta.h"
#include "Acao.h"
#include "PersonagemPrincipal.h"
#include "Inimigo.h"
#include "LeitorDeDados.h"
#include "Game.h"
#include "Personagens.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

SegundaLuta::SegundaLuta()
{
    imageT = new sf::Texture();
    imageS = new sf::Sprite();
    font = new sf::Font();

    heroi = new PersonagemPrincipal(sendStatus("Dwarf"));
    boss = new Boss(sendStatus("Boss"));
    acao = new Acao();

    _select = false;
    _click_enter = false;
    gameover = false;
    _posicao = 0;
    moviment = false;
    vidaHeroi = "";
    vidaBoss = "";

    initialize();
}

SegundaLuta::~SegundaLuta()
{
    delete imageT;
    delete imageS;
    delete font;

    delete heroi;
    delete boss;
    delete acao;
}

void SegundaLuta::initialize()
{   
    vidaHeroi = to_string(heroi->getLife());
    vidaBoss = to_string(boss->getLife());
    _opcoes = {"Ataque", "Defesa", "Curar", "HP: " + vidaHeroi, "HP: " + vidaBoss};
    _coordenadas = {{570,70}, {800,70}, {1040,70}, {300, 70}, {850, 600}};
    _sizes = {50, 50, 50, 50, 60};
    _texts.resize(5);

    imageT->loadFromFile("./segunda-luta.png");
    imageS->setTexture(*imageT);
    font->loadFromFile("./alagard.ttf");

    for(std::size_t i{}; i<_texts.size()-2; i++)
    {
        _texts[i].setFont(*font);
        _texts[i].setString(_opcoes[i]);
        _texts[i].setCharacterSize(_sizes[i]);
        _texts[i].setOutlineColor(sf::Color::Black);
        _texts[i].setFillColor(sf::Color::Blue);
        _texts[i].setPosition(_coordenadas[i]);
    }

    //inicia as cores da vida do Boss e do Heroi;
    for(int i = 3; i< 5; i++)
    {
        _texts[i].setFont(*font);
        _texts[i].setString(_opcoes[i]);
        _texts[i].setCharacterSize(_sizes[i]);
        _texts[i].setOutlineColor(sf::Color::White);
        _texts[i].setFillColor(sf::Color::Black);
        _texts[i].setPosition(_coordenadas[i]);      
    }
}

//funcao usada apenas para atualizar a vida do Heroi e do Boss durante a luta.
void SegundaLuta::initializeVidas()
{
    vidaHeroi = to_string(heroi->getLife());
    vidaBoss = to_string(boss->getLife());
    _opcoes = {"Ataque", "Defesa", "Curar", "HP: " + vidaHeroi, "HP: " + vidaBoss};

    //atualiza as cores da vida do Boss e do Heroi;
    for(int i = 3; i< 5; i++)
    {
        _texts[i].setFont(*font);
        _texts[i].setString(_opcoes[i]);
        _texts[i].setCharacterSize(_sizes[i]);
        _texts[i].setOutlineColor(sf::Color::White);
        _texts[i].setFillColor(sf::Color::Black);
        _texts[i].setPosition(_coordenadas[i]);      
    }
}

void SegundaLuta::lutaUpdate(sf::RenderWindow *janela, bool &running, bool &fim)
{
sf::Event evento;

while(janela->pollEvent(evento))
{
    if(evento.type == sf::Event::Closed)
    {
        running = false;
        janela->close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_select)
    {
        if(_posicao < 2)
        {
            _posicao++;
            _select = true;
            _texts[_posicao].setOutlineThickness(4);
            _texts[_posicao].setOutlineColor(sf::Color::Black);
            _texts[_posicao - 1].setOutlineThickness(0);
            _select = false;
            _click_enter = false;
            moviment = false;        
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_select)
    {
        if(_posicao > 0)
        {
            _posicao--;
            _select = true;
            _texts[_posicao].setOutlineThickness(4);
            _texts[_posicao].setOutlineColor(sf::Color::Black);
            _texts[_posicao + 1].setOutlineThickness(0);
            _select = false;
            _click_enter = false;
            moviment = false;
        }
    }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _posicao == 0 && !_click_enter)
        {
            _texts[_posicao].setOutlineThickness(0);
            _select = true;
            _click_enter = true;
            if(!acao->defineAtack(heroi, boss))
            {
                running = false;
            }
            initializeVidas();
            moviment = true;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _posicao == 1 && !_click_enter)
        {
            _texts[_posicao].setOutlineThickness(0);
            _select = true;
            _click_enter = true;
            acao->defineDefense(heroi);
            moviment = true;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _posicao == 2 && !_click_enter)
        {
            _texts[_posicao].setOutlineThickness(0);
            _select = true;
            _click_enter = true;
            acao->defineHeal(heroi);
            initializeVidas();
            moviment = true;
        }

        while(moviment){movimentEnemie(moviment, gameover);}

        if(gameover){running = false; fim = true;}
}
}


void SegundaLuta::lutaDraw(sf::RenderWindow *janela)
{
    janela->clear();
    janela->draw(*imageS);

    for(auto t : _texts)
    {
        janela->draw(t);
    }

    janela->display();
}

void SegundaLuta::movimentEnemie(bool &moviment, bool &gameover)
{
    srand(time(NULL));
    int movimento = rand()%3;

    int contador = 0;

    if(movimento == 0)
    {
        if(!acao->defineAtack(boss, heroi) && contador == 0)
        {
        gameover = true;
        moviment = false;
        contador++;
        }
        else
        {
        initializeVidas();
        moviment = false;
        }
    }
    if(movimento == 1){acao->defineDefense(boss); moviment = false;}

    if(movimento == 2){acao->defineHeal(boss); initializeVidas(); moviment = false;}

    _select = false;
}

