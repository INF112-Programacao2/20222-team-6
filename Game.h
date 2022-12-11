#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Personagens.h"
#include "PersonagemPrincipal.h"
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
        // Variaveis de classes de personagens
        PersonagemPrincipal *heroi;
        Personagens *movement;
        float timer;
        bool running;
        bool lutando = false;
        int i = 0;
        //Window
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        void initWindow();
        // Events
        sf::Event e;
        
        // Objetos do jogo
        MainMenu *menu;
        
        // Funcoes privadas
        void initVariaveis();
        void initInimigos();
        void spriteMovement();
        void isMoving();
        void checkPosition();

    protected:

    public:
        // Contrutor e destrutor;
        Game();
        ~Game();

        // Funcoes
        void run();
        std::string nomeArquivo;
        void update();
        void checkIfPressed();
        void render();
        void checkWalk();
        sf::Event getEvent();
};

#endif 