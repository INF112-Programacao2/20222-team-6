#include "Game.h"
#include "Personagens.h"

// Funcoes privadas
void Game::initVariaveis()
{
    this-> window = nullptr;
    heroi = new Personagens(sendStatus());

}

void Game::initWindow()
{
    this-> videoMode.height = 720;
    this-> videoMode.width = 1280;
    this-> window = new sf::RenderWindow(this-> videoMode, "Jogo muito foda", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    this-> window->setFramerateLimit(60);
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
sf::Event Game::getEvent()
{
    return e;
}

void Game::checkIfPressed()
{
    
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::W){
            teclas[0] = 1;
            timer += 1.f;}
        else {teclas[0] = 0; timer = 0;}
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::A){
            teclas[1] = 1;
            timer += 1.f;}
        else {teclas[1] = 0; timer = 0;}
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::S){
            teclas[2] = 1;
            timer += 1.f;}
        else {teclas[2] = 0; timer = 0;}
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::D){
            teclas[3] = 1;
            timer += 1.f;}
        else {teclas[3] = 0; timer = 0;}
    
}


void Game::run()
{
    while(this->window->isOpen())
    {
        this-> update();
    }
}

void Game::update()
{
    while (this->window->pollEvent(e))
    {
        if (e.Event::type == sf::Event::Closed)
            this-> window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this-> window->close();
        this->checkIfPressed();
        heroi->movement();
        this->window->clear();
        this->window->draw(heroi->personagemS);
        this->window->display();
    }
}
