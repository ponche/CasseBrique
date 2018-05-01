#ifndef BRIQUEMOVING_H_INCLUDED
#define BRIQUEMOVING_H_INCLUDED

#include "Brique.h"

#include <iostream>


class BriqueMoving : public Brique
{
protected:
    // attributs
    int m_vitesseBrique;
    bool m_directionDroite;
    int m_amplitudeMoving;
    int m_curseurBrique;


public:
    //Constructeur
    BriqueMoving(sf::Vector2f laPosition, effetBrique leEffetObjet =  VIDE ,  sf::Vector2f laTaille = sf::Vector2f(100, 50), sf::Color laCouleur = sf::Color::White);

    ~BriqueMoving();

    //fonction divers
     void update();


};


#endif // BRIQUEMOVING_H_INCLUDED
