#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "OptionBrique.h"

OptionBrique::OptionBrique()
: m_pointeurBrique(0)
{
    // constructeur de optionBrique
}
OptionBrique::~OptionBrique()
{
    // Destructeur de OptionBrique
}

void OptionBrique::setBrique(Brique *pointeur)
{
    m_pointeurBrique = pointeur ;
}

void OptionBrique::start() {}
void OptionBrique::update() {}
void OptionBrique::collision(Ball &boule) {}
void OptionBrique::destruction() {}
