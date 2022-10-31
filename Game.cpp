#include "Game.h"


// Funcoes privadas
void Game::initVariaveis()
{
    this-> window = nullptr;

}

void Game::initWindow()
{
    this-> videoMode.height = 720;
    this-> videoMode.width = 1280;
    this-> window = new sf::RenderWindow(this-> videoMode, "Game", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
}

// Construtor
Game::Game()
{
    this-> initVariaveis();
    this-> initWindow();


}

// Destrutor
Game::~Game()
{
    delete this-> window;
}

// Funcoes

const bool Game::running() const
{
    return this-> window-> isOpen();
}

void Game::pollEvents()
{
    while (this-> window-> pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this-> window->close();
                break;
            case sf::Event::KeyPressed:
                if (this-> ev.key.code == sf::Keyboard::Escape)
                    this ->window->close();
                break;

        }
    }
}

void Game::update()
{
    this-> pollEvents();
}

void Game::render()
{
/*
    Renderiza o jogo
*/

    this->window->clear(sf::Color(0,0,255));

    this->window->display();
}

