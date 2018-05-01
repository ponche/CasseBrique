#include <iostream>
#include <SFML/Graphics.hpp>

#include "Brique.h"
#include "GestionScores.h"
#include "Ball.h"

Brique::Brique(sf::Vector2f position, effetBrique effetObjet )
: m_resitance(1), m_effetObjet(effetObjet)
{
    std::cout << "creation de brique" << std::endl;
    m_rectangle = sf::RectangleShape(sf::Vector2f(100, 50)); // Magic Number
    m_rectangle.setPosition(position);

}
Brique::~Brique()
{
    GestionScores::ajouterScores();
    std::cout << "une brique a ete detruit " << std::endl;


}


void Brique::collision(Ball &laBall)
{
    m_resitance--;

}
void Brique::destructionBrique()
{

}
void Brique::update()
{
    switch(m_resitance)
    {
        case 3 :
            m_rectangle.setFillColor(sf::Color::Green);
            break;
        case 2:
            m_rectangle.setFillColor(sf::Color::Yellow);
            break;
        case 1:
            m_rectangle.setFillColor(sf::Color::Red);
            break;

    }
}
sf::Drawable& Brique::getShape()
{
    return m_rectangle;
}


//Setter

//getter

sf::RectangleShape& Brique::getRectangle()
{
    return m_rectangle;
}
int Brique::getResistance()
{
    return m_resitance;
}
int Brique::getEffetObjet()
{
    return m_effetObjet ;
}
