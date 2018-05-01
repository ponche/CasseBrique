#include <iostream>
#include <SFML/Graphics.hpp>

#include "ObjetSpecial.h"
#include "Brique.h"

ObjetSpecial::ObjetSpecial(int effets, sf::Vector2f position)
: m_vitesse(2) , m_effets(effets), m_isLive(true)
{
    m_cercle.setRadius(8);

    m_cercle.setPosition(position);
    // couleur en fonction du bonus ou malus
    int bonusMalus = m_effets % 2 ;

    // Amelioration sur le desgin des bonus malus.
    if(bonusMalus == 0)
    {
        //c'est un bonus couleur vert
        m_cercle.setFillColor(sf::Color::Green);
    }
    else
    {
        m_cercle.setFillColor(sf::Color::Magenta);
    }
}

void ObjetSpecial::update()
{
    sf::Vector2f position = m_cercle.getPosition();
    position.y += m_vitesse;
    m_cercle.setPosition(position);

    //Vérification de l'objet
    if(m_cercle.getPosition().y > 602)
        m_isLive = false;


}
sf::Drawable& ObjetSpecial::getShape()
{
    return m_cercle;
}

//Setter
void ObjetSpecial::setIsLive(bool live)
{
    m_isLive = live;
}
//Getter
sf::CircleShape ObjetSpecial::getCercle()
{
    return m_cercle;
}
int ObjetSpecial::getEffets()
{
    return m_effets;
}
bool ObjetSpecial::getIsLive()
{
    return m_isLive;
}
