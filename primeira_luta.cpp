#include "primeira_luta.h"
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

PrimeiraLuta::PrimeiraLuta()
{
    imageT = new sf::Texture();
    imageS = new sf::Sprite();
    font = new sf::Font();

    heroi = new PersonagemPrincipal(sendStatus("Dwarf"));
    inimigo = new Inimigo(sendStatus("Inimigo"));
    acao = new Acao();

    _select = false;
    _click_enter = false;
    _posicao = 0;
    moviment = false;
    vidaHeroi = "";
    vidaInimigo = "";

    initialize();
}

PrimeiraLuta::~PrimeiraLuta()
{
    delete imageT;
    delete imageS;
    delete font;
    delete heroi;
    delete inimigo;
    delete acao;
}

void PrimeiraLuta::initialize()
{
    vidaHeroi = to_string(heroi->getLife());
    vidaInimigo = to_string(inimigo->getLife());
    _opcoes = {"Ataque", "Defesa", "Curar", "HP: " + vidaHeroi, "HP: " + vidaInimigo};
    _coordenadas = {{570,70}, {800,70}, {1040,70}, {300, 70}, {550, 600}};
    _sizes = {50, 50, 50, 50, 60};
    _texts.resize(5);

    imageT->loadFromFile("./primeira-luta.png");
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

    initializeVidas();
}

void PrimeiraLuta::initializeVidas()
{
    vidaHeroi = to_string(heroi->getLife());
    vidaInimigo = to_string(inimigo->getLife());


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

void PrimeiraLuta::lutaUpdate(sf::RenderWindow *janela, bool &running)
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
            if(!acao->defineAtack(heroi, inimigo))
            {
                running = false;
                std::cout << "Morri" << std::endl;
            }
            initialize();
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
            initialize();
            moviment = true;
        }

        while(moviment){movimentEnemie(moviment, running);}
}
}

void PrimeiraLuta::lutaDraw(sf::RenderWindow *janela)
{
    janela->clear();
    janela->draw(*imageS);

    for(auto t : _texts)
    {
        janela->draw(t);
    }

    janela->display();
}

void PrimeiraLuta::movimentEnemie(bool &moviment, bool &running)
{
    srand(time(NULL));
    int movimento = rand()%3;

    int contador = 0;
    std::cout << movimento << std::endl;


    if(movimento == 0)
    {
        if(!acao->defineAtack(inimigo, heroi) && contador == 0)
        {
        contador++;
        running = false;
        std::cout << "Morri" << std::endl;
        }
        else
        {
        initialize();
        moviment = false;
        }
    }
    if(movimento == 1){acao->defineDefense(inimigo); moviment = false;}

    if(movimento == 2){acao->defineHeal(inimigo); initialize(); moviment = false;}

    _select = false;
}
