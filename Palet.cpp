#include <iostream>
#include <SFML/Graphics.hpp>

#include "Palet.h"

Palet::Palet(sf::RenderWindow &fenetre)
{
    m_rectangle.setSize(sf::Vector2f(200, 10));
    m_rectangle.setOrigin(m_rectangle.getSize().x / 2, 10);
    m_rectangle.setFillColor(sf::Color::Green);
    m_rectangle.setPosition(250, 600);
    m_fenetre = &fenetre;
    m_inversionCommand = false ;

}
void Palet::agrandirPalet(float augmentation)
{
    sf::Vector2f taille = m_rectangle.getSize();
    taille.x += augmentation;
    m_rectangle.setSize(taille);
    m_rectangle.setOrigin(taille.x / 2, 10);
}
void Palet::diminuerPalet(float diminution)
{
    sf::Vector2f taille = m_rectangle.getSize();
    taille.x -= diminution;
    if(taille.x < 2)
        taille.x = 2;
    m_rectangle.setSize(taille);
    m_rectangle.setOrigin(taille.x / 2, 10);
}
void Palet::update()
{
    // problème de cast !!!
    sf::Vector2f positionSouris = (sf::Vector2f) sf::Mouse::getPosition(*m_fenetre);
    sf::Vector2f positionPalet;
    positionPalet.x = positionSouris.x;
    if(!m_inversionCommand)
        positionPalet.x = positionSouris.x;
    else
        positionPalet.x = m_fenetre->getSize().x - positionSouris.x;
    positionPalet.y = 600; // Number magic
    setPositionPalet(positionPalet);
    m_rectangle.setPosition(positionPalet);

    // test
    std::cout << "Palet : " << positionPalet.x <<  " Souris : " << positionSouris.x << std::endl ;
}
sf::Drawable& Palet::getShape()
{
    return m_rectangle;
}



void Palet::reverseCommande()
{
    m_inversionCommand = m_inversionCommand? false : true ;
    std::cout << "la commande est : " << m_inversionCommand << std::endl ;
}

//Setter
void Palet::setPositionPalet(sf::Vector2f position)
{
    m_rectangle.setPosition(position);
}

//Getter
sf::Vector2f Palet::getPositionPalet()
{
    return m_rectangle.getPosition();
}
sf::RectangleShape Palet::getRectange()
{
    return m_rectangle;
}

