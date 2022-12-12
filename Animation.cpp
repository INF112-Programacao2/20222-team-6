//
// Created by pedro on 14/11/22.
//
/*
#include "Animation.h"
#include <vector>
#include <string>

Animation::Animation(char* textures[12])
{
    this->textura = this-> loadTexture(textures);
}

std::vector<sf::Texture> Animation::loadTexture(char* textures[12])
{
    std::vector<sf::Texture> auxTexture;
    sf::Texture aux;
    for (int i = 0; i < 12; i++){
        std::string str(textures[i]);
        aux.loadFromFile(str);
        auxTexture.push_back(aux);
    }
    return auxTexture;
}

sf::Texture Animation::getTexture(int index)
{
    return textura[index];
}
*/

