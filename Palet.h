#ifndef PALET_H_INCLUDED
#define PALET_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Element.h"


class Palet : Element
{
protected:
    sf::Color couleur;
    sf::RectangleShape m_rectangle;
    sf::RenderWindow *m_fenetre;
    bool m_inversionCommand;

    //Ball *m_ballShooting;

public:
    Palet(sf::RenderWindow &fenetre);

    void agrandirPalet(float augmentation = 5);
    void diminuerPalet(float diminution = 5);
    void update();
    sf::Drawable& getShape();

    void reverseCommande();

    //Setter
    void setPositionPalet(sf::Vector2f position);

    //Getter
    sf::Vector2f getPositionPalet();
    sf::RectangleShape getRectange();



};
#endif // PALET_H_INCLUDED
