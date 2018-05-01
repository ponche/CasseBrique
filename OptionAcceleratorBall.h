#ifndef OPTIONACCELERATORBALL_H_INCLUDED
#define OPTIONACCELERATORBALL_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionBrique.h"
#include "Ball.h"

class OptionAcceleratorBall : public OptionBrique
{
protected :
    // les attributs
    //int m_augmentationVitesse ;

public :

    void collision(Ball &boule) ;
};




#endif // OPTIONACCELERATORBALL_H_INCLUDED
