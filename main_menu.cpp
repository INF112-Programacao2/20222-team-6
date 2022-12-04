#include "main_menu.h"
#include "Game.h"
#include "LeitorDeDados.h"


MainMenu::MainMenu()
{
    imageT = new sf::Texture();
    imgS = new sf::Sprite();
    font = new sf::Font();
    init_variables();
}

MainMenu::~MainMenu()
{
    delete imageT;
    delete imgS;
    delete font;
}

void MainMenu::init_variables()
{
    _opcoes = {"Play", "Exit"};
    _coordenadas = {{275, 505}, {855, 510}};
    _sizes = {80, 80};
    _texts.resize(2);

    for (std::size_t i{}; i < _texts.size(); i++)
    {
        _texts[i].setFont(*font);
        _texts[i].setString(_opcoes[i]);
        _texts[i].setCharacterSize(_sizes[i]);
        _texts[i].setOutlineColor(sf::Color::Black);
        _texts[i].setFillColor(sf::Color::Black);
        _texts[i].setPosition(_coordenadas[i]);
    }

    imageT->loadFromFile("./Menu.png");
    imgS->setTexture(*imageT);
    font->loadFromFile("./alagard.ttf");
}

void MainMenu::menu_update(sf::RenderWindow *janela, bool &running)
{
    sf::Event e;
    
    _texts[_pos].setOutlineThickness(4);
    _texts[_pos].setOutlineColor(sf::Color::Cyan);
    
    while(janela->pollEvent(e))
    {
        if(e.type == sf::Event::Closed)
        {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_select){
            if(_pos < 1)
            {
                _pos++;
                _select = true;
                _texts[_pos].setOutlineThickness(4);
                _texts[_pos].setOutlineColor(sf::Color::Cyan);
                _texts[_pos - 1].setOutlineThickness(0);
                _select = false;
                _click_enter = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_select)
        {
            if( _pos > 0){
                _pos--;
                _select = true;
                _texts[_pos].setOutlineThickness(4);
                _texts[_pos].setOutlineColor(sf::Color::Cyan);
                _texts[_pos + 1].setOutlineThickness(0);
                _select = false;
                _click_enter = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _pos == 0 && !_click_enter)
        {
            _click_enter = true;
            running = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _pos == 1 && !_click_enter)
        {
            _click_enter = true;
            janela->close();
        }
    }
}

void MainMenu::menu_draw(sf::RenderWindow *janela)
{
    janela->clear();
    janela->draw(*imgS);

    for(auto t : _texts)
    {
        janela->draw(t);
    }

    janela->display();
}