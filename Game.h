#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Personagens.h"
#include "globalParameters.h"

/*
    Essa classe representa a game engine.
*/

class Personagens;

class Game
{
    private:
        // Variaveis
        Personagens* heroi;
        float timer;
        // Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;

        // Events
        sf::Event e;
        
        // Objetos do jogo

        
        // Funcoes privadas
        void initVariaveis();
        void initWindow();
        void initInimigos();
        void spriteMovement();
        void isMoving();
    
    public:
        // Contrutor e destrutor;
        Game();
        ~Game();

        // Funcoes
        void run();
        void update();
        void checkIfPressed();
        void render();
        sf::Event getEvent();
};

#endif 