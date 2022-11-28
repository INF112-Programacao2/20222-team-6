#include "Menu.h"
#include "Game.h"
#include "main_menu.h"
//#include "second_menu.h"

int main(){
    Game *ubx = new Game();
    MainMenu *abs = new MainMenu();
    //SecondMenu *ubx = new SecondMenu();
    //Game *ubs = new Game();

    abs->run();

    return 0;
}