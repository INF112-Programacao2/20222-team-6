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

class Personagens
{
    private:
    std::string nome;

public:
        Personagens();
        ~Personagens();
        sf::Texture personagemT;
        sf::Sprite personagemS;
        sf::Texture backGroundT;
        sf::Sprite backGroundS;

        // Funcoes

        void movement();
    std::vector<std::string> allBG;
};

#endif