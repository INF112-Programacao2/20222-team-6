#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
    Essa classe representa a game engine.
*/

class Game
{
    private:
    // Variaveis
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    
    // Funcoes privadas
    void initVariaveis();
    void initWindow();
    
    public:
        // Contrutor e destrutor
        Game();
        ~Game();

        const bool running() const;
        // Funcoes
        void pollEvents();
        void update();
        void render();
};
