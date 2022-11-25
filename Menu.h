#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Menu
{ 
    private:
    
        int _pos;
        bool _select, _click_enter;

        sf::RenderWindow *_tela;
        sf::Texture *imageT;
        sf::Sprite *imgS;
        sf::Font *font;

        //alocar essas variaveis dinamicamente.
        std::vector<std::string> _opcoes;
        std::vector<sf::Vector2f> _coordenadas;
        std::vector<sf::Text> _texts;
        std::vector<std::size_t> _sizes;

    public:
        Menu();
        ~Menu();
        void run_menu();
        void init_variaveis();
        void loop_events();
        void draw_menu();
        void init_variables_first_menu();
        void init_variables_second_menu();
};



#endif