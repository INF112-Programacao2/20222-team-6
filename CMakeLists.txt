cmake_minimum_required(VERSION 3.23)
project(rpg_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(rpg_game main.cpp LeitorDeDados.cpp LeitorDeDados.h main_menu.cpp Game.cpp Personagens.cpp Luta.cpp)

