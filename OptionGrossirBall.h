#ifndef OPTIONGROSSIRBALL_H_INCLUDED
#define OPTIONGROSSIRBALL_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionBrique.h"
#include "Ball.h"

class OptionGrossirBall : public OptionBrique
{
protected :
    // Les attributs

public :

    void collision(Ball &boule) ;
};




#endif // OPTIONGROSSIRBALL_H_INCLUDED
