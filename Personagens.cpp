#include "Personagens.h"
#include "globalParameters.h"

float contador;

Personagens::Personagens(/*std::vector<std::pair<std::string,std::vector<int>>>allStatus*/){
    /*
    this->nome = allStatus[0].first;
    this->vida = allStatus[0].second[2];
    this->ataque = allStatus[0].second[0];
    this->defesa = allStatus[0].second[1];
    */
}


void Personagens::movement() {
    personagemS.setScale(2.f,2.f);
    if (teclas[0] == 1 || teclas[2] == 1) {      /* Movimento do W e do S */
        personagemS.move(0,( teclas[2] - teclas[0]) * 2);
        contador += 1.f;
        if (contador > 20) contador = 0;
            if (contador >= 0 && contador < 5 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-back.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador >= 0 && contador < 5 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-front.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 5 && contador < 10 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back1.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-back1.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 10 && contador < 15 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-back.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 15 && contador < 20 && teclas[0] > teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-back2.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-back2.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 5 && contador < 10 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front1.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-front1.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 10 && contador < 15 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-front.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 15 && contador < 20 && teclas[0] < teclas[2]) {
                personagemT.loadFromFile("sprites/anao/dwarf-front2.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-front2.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
        }
    if (teclas[1] == 1 || teclas[3] == 1) {      /* Movimento do A e do D */
        personagemS.move(( teclas[3] - teclas[1]) * 2,0);
        contador += 1.f;
        if (contador > 20) contador = 0;
            if (contador >= 0 && contador < 5 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-left.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador >= 0 && contador < 5 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-right.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 5 && contador < 10 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left1.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-left1.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 10 && contador < 15 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-left.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 15 && contador < 20 && teclas[1] > teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-left2.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-left2.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 5 && contador < 10 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right1.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-right1.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 10 && contador < 15 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-right.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
            if (contador > 15 && contador < 20 && teclas[1] < teclas[3]) {
                personagemT.loadFromFile("sprites/anao/dwarf-side-right2.png");
                if (!personagemT.loadFromFile("sprites/anao/dwarf-side-right2.png")){
                    throw std::invalid_argument("Houve um erro ao carregar a sprite");
                }
                try{
                personagemS.setTexture(personagemT);
                } 
                catch (std::invalid_argument &e){
                std::cout << e.what();
                }
            }
        }
}
