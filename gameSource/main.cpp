#include <SDL.h>

// Déclaration de la fonction mainFunction définie dans game.cpp
extern int mainFunction(int inArgCount, char **inArgs);

// Fonction main que SDL va renommer en SDL_main
int main(int argc, char **argv) {
    return mainFunction(argc, argv);
}