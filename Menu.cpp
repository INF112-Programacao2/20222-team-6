#include "Menu.h"

//construtor--------------------------------
Menu::Menu()
{
    imageT = nullptr;
    imgS = nullptr;
    font = nullptr;
}

//destrutor----------------------------------
Menu::~Menu(){}


sf::Event Menu::get_event()
{
    return loop;
}