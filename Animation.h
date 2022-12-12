//
// Created by pedro on 14/11/22.
//

/*#ifndef RPG_GAME_ANIMATION_H
#define RPG_GAME_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <string>

class Animation
{
private:
    std::vector<sf::Texture> textura;
    std::vector<sf::Texture> loadTexture(char* textures[12]);
public:
    Animation();
    Animation(char* textures[12]);
    sf::Texture getTexture(int index);
};


#endif //RPG_GAME_ANIMATION_H
