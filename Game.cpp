#include "Game.h"
#include "Personagens.h"
#include "main_menu.h"
#include "PersonagemPrincipal.h"

void Game::initVariaveis()
{
    this-> window = nullptr;
    heroi = new PersonagemPrincipal(sendStatus("Dwarf"));
    movement = new Personagens();
    menu = new MainMenu();
    running = true;
    nomeArquivo = "path1.png";
    movement->personagemS.setPosition(700.f,720.f);
    movement->backGroundS.setPosition(0.f,0.f);
    movement->backGroundT.loadFromFile(nomeArquivo);
    movement->backGroundS.setTexture(movement->backGroundT);
}

void Game::initWindow()
{
    this-> videoMode.height = 720;
    this-> videoMode.width = 1280;
    this-> window = new sf::RenderWindow(this-> videoMode, "Holy Avenger", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
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
            timer += 1.f;
        }
        else {teclas[0] = 0; timer = 0;}
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::A){
            teclas[1] = 1;
            timer += 1.f;
        }
        else {teclas[1] = 0; timer = 0;}
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::S){
            teclas[2] = 1;
            timer += 1.f;
        }
        else {teclas[2] = 0; timer = 0;}
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::D){
            teclas[3] = 1;
            timer += 1.f;
        }
        else {teclas[3] = 0; timer = 0;}
    
}

void Game::checkWalk()
{
    if (nomeArquivo == "path1.png")
    {
        {
            if (movement->personagemS.getPosition().x < 639) {
                movement->personagemS.setPosition(639, movement->personagemS.getPosition().y);
            }
            if (movement->personagemS.getPosition().x > 739) {
                movement->personagemS.setPosition(739, movement->personagemS.getPosition().y);
            }
            if (movement->personagemS.getPosition().y < 120) {
                movement->personagemS.setPosition(movement->personagemS.getPosition().x, 120);
            }
            if (movement->personagemS.getPosition().y == 120 && e.Event::KeyPressed &&
                e.Event::key.code == sf::Keyboard::Enter) {
                lutando = true;
                nomeArquivo = "primeira-luta.png";
            }
        }
    }
    if (nomeArquivo == "path2.png")
    {
        if (movement->personagemS.getPosition().x < 639) {
            movement->personagemS.setPosition(639, movement->personagemS.getPosition().y);
        }
        if (movement->personagemS.getPosition().x > 739) {
            movement->personagemS.setPosition(739, movement->personagemS.getPosition().y);
        }
        if (movement->personagemS.getPosition().y <= -63) {
            movement->personagemS.setPosition(700, 720);
            nomeArquivo = "path3.png";
            movement->backGroundT.loadFromFile(nomeArquivo);
            movement->backGroundS.setTexture(movement->backGroundT);
        }
    }
    if (nomeArquivo == "path3.png")
    {
        if (movement->personagemS.getPosition().x < 639) {
            movement->personagemS.setPosition(639, movement->personagemS.getPosition().y);
        }
        if (movement->personagemS.getPosition().x > 739) {
            movement->personagemS.setPosition(739, movement->personagemS.getPosition().y);
        }
        if (movement->personagemS.getPosition().y <=63){
            movement->personagemS.setPosition(movement->personagemS.getPosition().x, 63);
        }
        if (movement->personagemS.getPosition().y == 63 && e.Event::KeyPressed &&
            e.Event::key.code == sf::Keyboard::Enter) {
            movement->personagemS.setPosition(880,720);
            nomeArquivo = "path4.png";
            movement->backGroundT.loadFromFile(nomeArquivo);
            movement->backGroundS.setTexture(movement->backGroundT);
        }
    }
    if (nomeArquivo == "path4.png") {
        if(movement->personagemS.getPosition().y <= 438) {
            movement->personagemS.setPosition(movement->personagemS.getPosition().x,438);
        }
        if (movement->personagemS.getPosition().y == 120 && e.Event::KeyPressed &&
            e.Event::key.code == sf::Keyboard::Enter) {
            lutando = true;
            nomeArquivo = "segunda-luta.png";
        }
    }
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
        
        while(running)
        {
            menu->menu_update(this->window, running);
            menu->menu_draw(this->window);
        }
        this->checkIfPressed();
        movement->movement();
        this-> checkWalk();
        while(lutando)
            {
                movement->backGroundT.loadFromFile(nomeArquivo);
                movement->backGroundS.setTexture(movement->backGroundT);
                break;

            }

        this->window->clear();
        this->window->draw(movement->backGroundS);
        this->window->draw(movement->personagemS);
        this->window->display();
    }
}
