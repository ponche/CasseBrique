#include <iostream>
#include <SFML/Graphics.hpp>

#include "BriqueRegenerator.h"

using namespace sf;

//Constructeur
BriqueRegenerator::BriqueRegenerator(sf::Vector2f position, effetBrique effetObjet,  sf::Vector2f taille , sf::Color couleur )
: Brique(position, effetObjet)
{
    m_chrono.restart();
    m_timeRegenerator = sf::seconds(50.f);
}
BriqueRegenerator::~BriqueRegenerator() {} ;

// Fonction divers
void BriqueRegenerator::update()
{
    Brique::update();
    if(m_chrono.getElapsedTime() > m_timeRegenerator)
    {

        if(m_resitance < 3)
        {
            m_resitance++;
            m_chrono.restart();
        }

    }
}
