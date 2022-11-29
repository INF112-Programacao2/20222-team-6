#include "main_menu.h"
#include "Game.h"


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
    _opcoes = {"Play", "Credits"};
    _coordenadas = {{275, 505}, {825, 515}};
    _sizes = {80, 68};
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

void MainMenu::init_second_variables()
{
    _opcoes = {"Elf", "Dwarf", "Human"};
    _coordenadas = {{225, 575}, {535, 575}, {890, 575}};
    _sizes = {100, 90, 90};
    _texts.resize(3);
    

    for (std::size_t i{}; i < _texts.size(); i++)
    {
        _texts[i].setFont(*font);
        _texts[i].setString(_opcoes[i]);
        _texts[i].setCharacterSize(_sizes[i]);
        _texts[i].setOutlineColor(sf::Color::Black);
        _texts[i].setFillColor(sf::Color::White);
        _texts[i].setPosition(_coordenadas[i]);
    }

    imageT->loadFromFile("./race-selection.png");
    imgS->setTexture(*imageT);
}
void MainMenu::menu_update(sf::RenderWindow *janela, bool &running)
{
    sf::Event e;
    
    if(event == false)
    {
    _texts[_pos].setOutlineThickness(4);
    _texts[_pos].setOutlineColor(sf::Color::Cyan);
    }

    if(event == true)
    {
    _texts[_pos].setOutlineThickness(8);
    _texts[_pos].setOutlineColor(sf::Color::Black);
    }

    while(janela->pollEvent(e))
    {
        if(e.type == sf::Event::Closed)
        {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_select && event == false){
            if(_pos < cont)
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_select && event == false)
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _pos == 0 && !_click_enter && event == false)
        {
            _click_enter = true;
            cont++;
            event = true;
            init_second_variables();
            _click_enter = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_select && event == true)
        {
            if( _pos < cont)
            {
                _pos++;
                _select = true;
                _texts[_pos].setOutlineThickness(8);
                _texts[_pos].setOutlineColor(sf::Color::Black);
                _texts[_pos - 1].setOutlineThickness(0);
                _select = false;
                _click_enter = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_select && event == true){
            if( _pos > 0)
            {
                _pos--;
                _select = true;
                _texts[_pos].setOutlineThickness(8);
                _texts[_pos].setOutlineColor(sf::Color::Black);
                _texts[_pos + 1].setOutlineThickness(0);
                _select = false;
                _click_enter = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _pos == 0 && !_click_enter && event == true)
        {
            _click_enter = true;
            running = false;
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