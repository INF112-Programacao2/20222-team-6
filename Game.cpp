#include "Game.h"
#include "Personagens.h"
#include "main_menu.h"
#include "PersonagemPrincipal.h"
#include "primeira_luta.h"
#include "segunda_luta.h"

void Game::initVariaveis()
{
    this-> window = nullptr;
    heroi = new PersonagemPrincipal(sendStatus("Dwarf"));
    luta1 = new PrimeiraLuta();
    luta2 = new SegundaLuta();
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
    this->window->setMouseCursorVisible(false);
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
    delete heroi;
    delete movement;
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
            if (movement->personagemS.getPosition().y <= 120) {
                movement->personagemS.setPosition(movement->personagemS.getPosition().x, 120);
            }
            if (movement->personagemS.getPosition().y <= 120 && e.Event::KeyPressed &&
                e.Event::key.code == sf::Keyboard::Enter) {
                lutando1 = true;
            }
        }
    }
    if (nomeArquivo == "path2.png")
    {
        
        if (movement->personagemS.getPosition().x < 639) {
            movement->personagemS.setPosition(639, movement->personagemS.getPosition().y);
        }
        if (movement->personagemS.getPosition().x > 739) {
            movement->personagemS.setPosition(739,movement->personagemS.getPosition().y);
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
        if (movement->personagemS.getPosition().y == 438 && e.Event::KeyPressed &&
            e.Event::key.code == sf::Keyboard::Enter) {
            lutando2 = true;
        }
    }

    if(nomeArquivo == "game-over.png")
    {
    if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this-> window->close();
    }

    if(nomeArquivo == "end-game1.png")
    {
    if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Right) //aperte a setinha da direita para mudar a pagina
    {
        nomeArquivo = "end-game2.png";
        movement->backGroundT.loadFromFile(nomeArquivo);
        movement->backGroundS.setTexture(movement->backGroundT);
    }
    }

    if(nomeArquivo == "end-game2.png")
    {
    if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) //aperte Esc para fechar a ultima pagina.
    {
        this->window->close();
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

            if(!running) delete menu;
        }
        while(lutando1)
        {
            luta1->lutaUpdate(this->window, lutando1, fim);
            luta1->lutaDraw(this->window);
            if(!lutando1 && !fim)    //atualiza a sprite contendo o segundo cenario
            {
            nomeArquivo = "path2.png";
            movement->backGroundT.loadFromFile(nomeArquivo);
            movement->backGroundS.setTexture(movement->backGroundT);
            movement->personagemS.setPosition(700, 720); //define a nova posicao do personagem no novo cenario.
            }
            if(!lutando1 && fim == true)
            {
                nomeArquivo = "game-over.png";
                movement->backGroundT.loadFromFile(nomeArquivo);
                movement->backGroundS.setTexture(movement->backGroundT);
            }
        }

        while(lutando2)
        {
            luta2->lutaUpdate(this->window, lutando2, fim);
            luta2->lutaDraw(this->window);
            if(!lutando2 && !fim)
            {
                nomeArquivo = "end-game1.png";
                movement->backGroundT.loadFromFile(nomeArquivo);
                movement->backGroundS.setTexture(movement->backGroundT);
            }
            if(!lutando2 && fim == true)
            {
                nomeArquivo = "game-over.png";
                movement->backGroundT.loadFromFile(nomeArquivo);
                movement->backGroundS.setTexture(movement->backGroundT);
            }      
        }
        if((nomeArquivo != "game-over.png") && (nomeArquivo != "end-game1.png") && (nomeArquivo != "end-game2.png"))
        {
        this->checkIfPressed();
        movement->movement();
        }

        this-> checkWalk();
        this->window->clear();
        this->window->draw(movement->backGroundS);

        if((nomeArquivo != "game-over.png") && (nomeArquivo != "end-game1.png") && (nomeArquivo != "end-game2.png"))
        {
                    this->window->draw(movement->personagemS);
        }
        this->window->display();
    }
}
