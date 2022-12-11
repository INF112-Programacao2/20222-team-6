#ifndef LUTA_H
#define LUTA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Luta
{
protected:
    int _posicao;
    bool _select, _click_enter;

    sf::Texture *imageT;
    sf::Sprite *imageS;
    sf::Font *font;

        
    std::vector<std::string> _opcoes;
    std::vector<sf::Vector2f> _coordenadas;
    std::vector<sf::Text> _texts;
    std::vector<std::size_t> _sizes;

    sf::Event loop;

public:
    Luta();
    ~Luta();
};

#endif