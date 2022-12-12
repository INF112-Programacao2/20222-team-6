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
#include "primeira_luta.h"
#include "segunda_luta.h"
/*
    Essa classe representa a game engine.
*/

class Personagens;

class Game : public Menu
{
    private:
        // Variaveis de classes de personagens
        float timer;
        bool running;
        bool fim = false;
        bool lutando1 = false;
        bool lutando2 = false;
        int i = 0;
        //Window
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        void initWindow();
        // Events
        sf::Event e;
        
        // Objetos do jogo
        MainMenu *menu;
        PersonagemPrincipal *heroi;
        Personagens *movement;
        PrimeiraLuta *luta1;
        SegundaLuta *luta2;
        // Funcoes privadas
        void initVariaveis();

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
        void checkWalk();
};

#endif 