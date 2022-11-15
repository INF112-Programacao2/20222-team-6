#include "Personagens.h"
#include "globalParameters.h"

float contador;

Personagens::Personagens(std::vector<std::pair<std::string,std::vector<int>>>allStatus){
    this->nome = allStatus[0].first;
    this->vida = allStatus[0].second[2];
    this->ataque = allStatus[0].second[0];
    this->defesa = allStatus[0].second[1];
}


void Personagens::movement() {
    personagemS.setScale(2.f,2.f);
    if (teclas[0] == 1 || teclas[2] == 1) {      /* Movimento do W e do S */
        personagemS.move(0,( teclas[2] - teclas[0]) * 2);
        contador += 1.f;
        if (contador > 20) contador = 0;
            if (contador >= 0 && contador < 5 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("human/human-back.png");
                personagemS.setTexture(personagemT);
            }
            if (contador >= 0 && contador < 5 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("human/human-front.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 5 && contador < 10 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("human/human-back-walking-1.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 10 && contador < 15 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("human/human-back.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 15 && contador < 20 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("human/human-back-walking-2.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 5 && contador < 10 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("human/human-front-walking-1.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 10 && contador < 15 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("human/human-front.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 15 && contador < 20 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("human/human-front-walking-2.png");
                personagemS.setTexture(personagemT);
            }
        }
}

/*     else if (teclas[1] == 1 || teclas[3] == 1){
        personagemS.move(teclas[1] - teclas[3], 0);
        if(_type == HUMANO){
            timer+= 1.f;
            if (checkTimer(timer) == 1 && teclas[1] < teclas[3]){
                personagemT.loadFromFile("human/human-left-walking-1.png");
            }
            if (checkTimer(timer) == 2 && teclas[1] < teclas[3]){
                personagemT.loadFromFile("human/human-left-walking-2.png");
            }
            if (checkTimer(timer) == 1 && teclas[1] > teclas[3]){
                personagemT.loadFromFile("human/human-right-walking-1.png");
            }
            if (checkTimer(timer) == 2 && teclas[1] > teclas[3]){
                personagemT.loadFromFile("human/human-right-walking-1.png");
            }
        }
    }
} */