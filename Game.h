#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Personagens.h"
#include "globalParameters.h"
#include "Menu.h"
#include "main_menu.h"

/*
    Essa classe representa a game engine.
*/

class Personagens;

class Game : public Menu
{
    private:
        // Variaveis
        Personagens* heroi;
        float timer;
        bool running;
        //Window
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        void initWindow();
        // Events
        sf::Event e;
        
        // Objetos do jogo
        MainMenu *teste;
        
        // Funcoes privadas
        void initVariaveis();
        void initInimigos();
        void spriteMovement();
        void isMoving();

    protected:

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