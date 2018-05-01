#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionAcceleratorBall.h"
#include "Ball.h"

void OptionAcceleratorBall::collision(Ball &boule)
{
    boule.augmenterVitesse(10) ;
}
