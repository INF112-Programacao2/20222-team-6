#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Menu.h"
#include <iostream>

class MainMenu : public Menu
{
    public:
        MainMenu();
        ~MainMenu();
        void init_variables();
        void init_second_variables();
        void menu_update(sf::RenderWindow *janela, bool &running);
        void menu_draw(sf::RenderWindow *janela);
};

#endif
