#ifndef OBJETSPECIAL_H_INCLUDED
#define OBJETSPECIAL_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Element.h"


class ObjetSpecial : public Element
{
protected:
    float m_vitesse;
    int m_effets;
    sf::CircleShape m_cercle;
    bool m_isLive;

public:
    ObjetSpecial(int effets, sf::Vector2f position);

    void update();
    sf::Drawable& getShape();

    //Setter
    void setVitesse(float vitesse);
    void setEffets(int effets);
    void setIsLive(bool live);

    //Getter
    float getVitesse();
    int getEffets();
    bool getIsLive();
    sf::CircleShape getCercle();
};

#endif // OBJETSPECIAL_H_INCLUDED
