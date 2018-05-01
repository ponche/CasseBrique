#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "GestionJeu.h"

Ball::Ball(sf::RenderWindow &fenetre, Palet &lePalet)
: m_pPalet(&lePalet)
{
    m_cercle.setFillColor(sf::Color::Red);
    m_rayonBall = 10 ;
    m_cercle.setRadius(m_rayonBall);
    m_cercle.setOrigin(m_cercle.getRadius() / 2, m_cercle.getRadius() / 2);
    m_fenetre = &fenetre;
    m_vitesseMax = 27 ;
    m_vitesse = 5 ;
    m_isLive = true ;
    m_ballLancer = false ;
}
Ball::~Ball()
{
    std::cout << "destruction d'une balle " << std::endl ;
}

void Ball::update()
{
    if(!m_ballLancer)
    {
        sf::Vector2f position;
        position.y = 575;
        position.x =  m_pPalet->getPositionPalet().x;
        m_cercle.setPosition(position);
    }
    else
    {
        //Deplacement de la ball
        sf::Vector2f positionActuel = m_cercle.getPosition();
        positionActuel.x += m_direction.x * m_vitesse;
        positionActuel.y += m_direction.y * m_vitesse;
        m_cercle.setPosition(positionActuel);
        if(positionActuel.y > 650) // MagicNumber un peu en bas du pallet
            m_isLive = false;
    }
}
void Ball::lancerBall()
{
    if(!m_ballLancer)
    {
        m_ballLancer = true;
        m_direction = sf::Vector2f(0, -1);
    }
}
void Ball::augmenterVitesse(float augmentation)
{
    m_vitesse += augmentation;
    if(m_vitesse > m_vitesseMax)
        m_vitesse = m_vitesseMax;
    std::cout << "vitesse ball : " << m_vitesse << std::endl;
}
void Ball::diminuerVitesse(float diminution)
{

    m_vitesse -= diminution;
    if(m_vitesse < 1)
        m_vitesse = 1;
    std::cout << "vitesse ball : " << m_vitesse << std::endl;
}
sf::Drawable& Ball::getShape()
{
    return m_cercle;
}
void Ball::grosirBall(float augmentation)
{
    m_cercle.setRadius(m_cercle.getRadius() + augmentation) ;
    m_cercle.setOrigin(m_cercle.getRadius() / 2, m_cercle.getRadius() / 2);
}
void Ball::reduireBall(float diminution)
{
   m_cercle.setRadius(m_cercle.getRadius() - diminution) ;
   m_cercle.setOrigin(m_cercle.getRadius() / 2, m_cercle.getRadius() / 2);
}

//Setter
void Ball::setVitesse(float vitesse)
{
    m_vitesse = vitesse;
}
void Ball::setDirection(sf::Vector2f direction)
{
    m_direction = direction;
}
void Ball::setBallLancer(bool ballLancer)
{
    m_ballLancer = ballLancer;
}

//Getter
float Ball::getVitesse()
{
    return m_vitesse;
}
sf::Vector2f Ball::getDirection()
{
    return m_direction;
}
bool Ball::getBallLanceer()
{
    return m_ballLancer;
}
sf::CircleShape& Ball::getCercle()
{
    return m_cercle;
}
sf::Clock monHorloge;
bool Ball::getIsLive()
{
    return m_isLive;
}
