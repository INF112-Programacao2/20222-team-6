#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Menu.h"
#include <iostream>

class MainMenu : public Menu
{
    protected:
        bool event;
        int cont;

    public:
        MainMenu();
        ~MainMenu();
        void init_variables();
        void init_second_variables();
        void loop();
        void draw();
        void run();
};

#endif