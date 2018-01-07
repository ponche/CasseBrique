#include <iostream>
#include <SFML/Graphics.hpp>

#include "GestionJeu.h"



using namespace sf;



int main() // première fonction appeler par le programme elle renvoie un entier
{
    //Initialisation
    RenderWindow fenetre(VideoMode(800, 600), "CaseBrique", sf::Style::Titlebar | sf::Style::Close);
    //fenetre.setMouseCursorVisible(false);
    // on lance la musique

    fenetre.setFramerateLimit(50);
    GestionJeu systemJeu(fenetre);
    systemJeu.placementBrique();
    systemJeu.boucleSystem();

    // Zone de test

    return 0 ;




}
