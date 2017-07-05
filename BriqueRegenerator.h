#ifndef BRIQUEREGENERATOR_H_INCLUDED
#define BRIQUEREGENERATOR_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Brique.h"

class BriqueRegenerator : public Brique
{
protected:
    // Les Attributs
    sf::Clock m_chrono;
    sf::Time m_timeRegenerator;

public:
    BriqueRegenerator(sf::Vector2f position, effetBrique effetObjet =  vide ,  sf::Vector2f taille = sf::Vector2f(100, 50), sf::Color couleur = sf::Color::White );
    virtual ~BriqueRegenerator();

    //Fonctions divers

     virtual void update();
     void renegeration();
};


#endif // BRIQUEREGENERATOR_H_INCLUDED
