#include <iostream>
#include "Game.cpp"

int main()
{
    // Inicia jogo
    Game jogo;

    // Loop do jogo

    while (jogo.running())
    {
        // Load
        jogo.update();
        // Render
        jogo.render();
    }

    return 0;
}