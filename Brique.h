#ifndef BRIQUE_H_INCLUDED
#define BRIQUE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GestionScores.h"
#include "ObjetSpecial.h"
#include "Element.h"

//Enumération des objet brique
enum effetBrique
{
    vide,
    diminuerPalet,
    augmenterPalet,
    augmenterVitesse,
    diminuerVitesse
};
class Brique : public Element
{
protected:
    sf::RectangleShape m_rectangle;
    int m_resitance;
    int m_effetObjet;

public:
    Brique(sf::Vector2f position, effetBrique effetObjet =  vide);

    virtual ~Brique();
    void destructionBrique();

    void collision();
    virtual void update();

    sf::Drawable& getShape();


    //Setter

    //Getter
    sf::RectangleShape& getRectangle();
    int getResistance();
    int getEffetObjet();



};



#endif // BRIQUE_H_INCLUDED
