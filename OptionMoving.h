#ifndef OPTIONMOVING_H_INCLUDED
#define OPTIONMOVING_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionBrique.h"


class OptionMoving : public OptionBrique
{
protected:
    // attributs
    int m_vitesseBrique;
    bool m_directionDroite;
    int m_amplitudeMoving;
    int m_curseurBrique;

public:
    OptionMoving();
    ~OptionMoving() ;

    void update() ;

};



#endif // OPTIONMOVING_H_INCLUDED
