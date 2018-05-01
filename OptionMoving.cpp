#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionMoving.h"


//constructeur
OptionMoving::OptionMoving()
{
    m_vitesseBrique = 2 ;
    m_amplitudeMoving = 200 ;
    m_directionDroite = true ;
    m_curseurBrique = 0;
}
OptionMoving::~OptionMoving()
{

}

void OptionMoving::update()
{
    if(m_pointeurBrique != 0)
    {
        if(m_directionDroite)
        {
            m_curseurBrique += m_vitesseBrique;
            m_pointeurBrique->m_rectangle.move(m_vitesseBrique, 0);
            if(m_curseurBrique > m_amplitudeMoving)
                m_directionDroite = false;

        }
        else
        {
            m_curseurBrique -= m_vitesseBrique;
            m_pointeurBrique->m_rectangle.move(-m_vitesseBrique, 0);
            if(m_curseurBrique < 0)
                m_directionDroite = true ;
        }

    }
}


