#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "OptionBrique.h"

OptionBrique::OptionBrique()
: m_pointeurBrique(0)
{
    // creaion de option brique
}
OptionBrique::~OptionBrique()
{
    // Destructeur de la brique
}

void OptionBrique::setBrique(Brique *pointeur)
{
    m_pointeurBrique = pointeur ;
}
