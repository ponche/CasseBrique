#include <iostream>
#include <SFML/Graphics.hpp>

#include "GestionJeu.h"



using namespace sf;



int main()
{

    RenderWindow fenetre(VideoMode(800, 600), "CaseBrique", sf::Style::Titlebar | sf::Style::Close);
    fenetre.setMouseCursorVisible(false);

    fenetre.setFramerateLimit(50);
    GestionJeu systemJeu(fenetre);
    systemJeu.placementBrique();
    systemJeu.boucleSystem();


    return 0 ;




}
