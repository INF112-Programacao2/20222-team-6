#ifndef PERSONAGENS_H
#define PERSONAGENS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <string>
#include <vector>
#include "Game.h"
#include "LeitorDeDados.h"
enum race 
{HUMANO,ANAO,ELFO};

class Personagens
{
    private:
    std::string nome;
    int vida, ataque, defesa;

    public:
        Personagens();
        //Personagens(/*vector<pair<string,vector<int>>> allStatus*/);
        ~Personagens();
        sf::Texture personagemT;
        sf::Sprite personagemS;

        // Funcoes

        void movement();
        
        void update();
        void render();
        void initPersonagens();
        
};

#endif