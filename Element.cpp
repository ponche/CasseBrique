#include <iostream>
#include <SFML/Graphics.hpp>

#include "Element.h"

int Element::nbElement = 0;

Element::Element()
: m_isLive(true)
{
    nbElement++;
}
Element::~Element()
{
    nbElement--;
}

void Element::update() {} ;

int Element::getElement()
{
    return nbElement;
}

bool Element::getIsLive()
{
    return m_isLive;
}
void Element::destructionElement()
{
    m_isLive = false ;
}

