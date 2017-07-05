#include <iostream>
#include <SFML/Graphics.hpp>

#include "BriqueMoving.h"
#include "Brique.h"

BriqueMoving::BriqueMoving(sf::Vector2f laPosition, effetBrique leEffetObjet, sf::Vector2f laTaille, sf::Color laCouleur)
: Brique(laPosition, leEffetObjet)
{
    std::cout << "constructeur de briqueMoving " << std::endl ;
    m_vitesseBrique = 2 ;
    m_amplitudeMoving = 200 ;
    m_directionDroite = true ;
    m_curseurBrique = 0;
}

BriqueMoving::~BriqueMoving()
{
    std::cout << "destructeur de brique moving " << std::endl ;
}
void BriqueMoving::update()
{
    Brique::update();
    if(m_directionDroite)
    {
        m_curseurBrique += m_vitesseBrique;
        m_rectangle.move(m_vitesseBrique, 0);
        if(m_curseurBrique > m_amplitudeMoving)
            m_directionDroite = false;

    }
    else
    {
        m_curseurBrique -= m_vitesseBrique;
        m_rectangle.move(-m_vitesseBrique, 0);
        if(m_curseurBrique < 0)
            m_directionDroite = true ;
    }


}
