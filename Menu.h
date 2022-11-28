#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


class Menu
{ 
    protected:
    
        int _pos;
        bool _select, _click_enter;
        bool run = false;

        sf::Texture *imageT;
        sf::Sprite *imgS;
        sf::Font *font;

        //alocar essas variaveis dinamicamente.
        std::vector<std::string> _opcoes;
        std::vector<sf::Vector2f> _coordenadas;
        std::vector<sf::Text> _texts;
        std::vector<std::size_t> _sizes;

        sf::Event loop;



    public:
        Menu();
        ~Menu();

        
        sf::Event get_event();
        //void run();
        //void init_variables();
        //void loop();
        //void draw();
        //void init_variables_first_menu();
        //void init_variables_second_menu();
};



#endif