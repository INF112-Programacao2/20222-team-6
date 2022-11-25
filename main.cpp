#include "Menu.h"

int main(){
    Menu *abs = new Menu();

    abs->run_menu();

    delete abs;

    return 0;
}