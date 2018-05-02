#include <iostream>
#include <SFML/Graphics.hpp>

#include "OptionGrossirBall.h"
#include "Ball.h"

void OptionGrossirBall::collision(Ball &boule)
{
    boule.grosirBall(10);
}
