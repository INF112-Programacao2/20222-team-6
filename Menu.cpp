#include "Menu.h"

//construtor--------------------------------
Menu::Menu()
{
    _tela = new sf::RenderWindow();
    imageT = new sf::Texture();
    imgS = new sf::Sprite();
    font = new sf::Font();
}

//destrutor----------------------------------
Menu::~Menu()
{
    delete _tela;
    delete imageT;
    delete imgS;
}

//define valores para as variaveis fixas---------------
void Menu::init_variaveis()
{

    _tela->create(sf::VideoMode(1280,720), "Menu do Jogo");
    _tela->setPosition(sf::Vector2i(0,0));

    _pos = 0;
    _select = false;
    _click_enter = false;

    font->loadFromFile("./alagard.ttf");
}

//inicia as variaveis que serao usadas no primeiro menu-------------------
void Menu::init_variables_first_menu()
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
}

//inicia as variaveis que serao usadas no segundo menu------------------
void Menu::init_variables_second_menu()
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

//onde acontece os eventos dentro da tela do menu------------
void Menu::loop_events()
{
    sf::Event loop;

    while(_tela->pollEvent(loop))
    {
        _texts[_pos].setOutlineThickness(4);
        _texts[_pos].setOutlineColor(sf::Color::Cyan);


        if(loop.type == sf::Event::Closed)
        {
            _tela->close();
        }

        //rever / refazer o codigo a partir daqui.
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_select){
            if( _pos < 1)
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_select){
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
            init_variables_second_menu();
        }
    }
}

//desenha a tela--------------------------
void Menu::draw_menu()
{
    _tela->clear();
    _tela->draw(*imgS);

    for(auto t : _texts)
    {
        _tela->draw(t);
    }

    _tela->display();
}

//inicia a tela do menu-----------------------
void Menu::run_menu()
{
    init_variaveis();
    init_variables_first_menu();

    while(_tela->isOpen())
    {
    loop_events();
    draw_menu();
    }
}