#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Palet.h"
#include "Element.h"


class Ball : public Element
{
protected:
    sf::CircleShape m_cercle;
    float m_vitesse;
    float m_vitesseMax;
    sf::Vector2f m_direction;
    bool m_ballLancer;
    bool m_isLive;
    sf::RenderWindow *m_fenetre;
    Palet *m_pPalet ;

public:
    Ball();
    Ball(sf::RenderWindow &fenetre, Palet &lePalet);
    virtual ~Ball();


    //Fonction divers
    void update();
    void lancerBall();

    void augmenterVitesse(float augmentation = 1);
    void diminuerVitesse(float diminution = 1);

    sf::Drawable& getShape();

    //Setter
    void setVitesse(float vitesse);
    void setDirection(sf::Vector2f direction);
    void setBallLancer(bool ballLancer);


    //Getter
    sf::CircleShape& getCercle();
    float getVitesse();
    sf::Vector2f getDirection();
    bool getBallLanceer();
    sf::Vector2f getPosition();
    bool getIsLive();


};

#endif // BALL_H_INCLUDED
