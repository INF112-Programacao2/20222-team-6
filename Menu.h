#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Menu
{ 
    protected:
    
        int _pos;
        bool _select, _click_enter;

        bool event;
        int cont;

        sf::Texture *imageT;
        sf::Sprite *imgS;
        sf::Font *font;

        
        std::vector<std::string> _opcoes;
        std::vector<sf::Vector2f> _coordenadas;
        std::vector<sf::Text> _texts;
        std::vector<std::size_t> _sizes;

        sf::Event loop;



    public:
        Menu();
        ~Menu();
};



#endif
