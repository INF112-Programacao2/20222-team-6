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
                personagemT.loadFromFile("sprites/anao/dwarf-back.png");
                personagemS.setTexture(personagemT);
            }
            if (contador >= 0 && contador < 5 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 5 && contador < 10 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back1.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 10 && contador < 15 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 15 && contador < 20 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back2.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 5 && contador < 10 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front1.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 10 && contador < 15 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 15 && contador < 20 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front2.png");
                personagemS.setTexture(personagemT);
            }
        }
    if (teclas[1] == 1 || teclas[3] == 1) {      /* Movimento do W e do S */
        personagemS.move(( teclas[3] - teclas[1]) * 2,0);
        contador += 1.f;
        if (contador > 20) contador = 0;
            if (contador >= 0 && contador < 5 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left.png");
                personagemS.setTexture(personagemT);
            }
            if (contador >= 0 && contador < 5 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 5 && contador < 10 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left1.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 10 && contador < 15 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 15 && contador < 20 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left2.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 5 && contador < 10 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right1.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 10 && contador < 15 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right.png");
                personagemS.setTexture(personagemT);
            }
            if (contador > 15 && contador < 20 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right2.png");
                personagemS.setTexture(personagemT);
            }
        }
}
