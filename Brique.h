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
    VIDE,
    DIMINUER_PALET,
    AUGMENTER_PALET,
    AUGMENTER_VITESSE,
    DIMINUER_VITESSE
};
class Brique : public Element
{
public:
    sf::RectangleShape m_rectangle;
    int m_resitance;
    int m_effetObjet;

public:
    Brique(sf::Vector2f position, effetBrique effetObjet =  VIDE);

    virtual ~Brique();
    void destructionBrique();

    virtual void collision();
    virtual void update();

    sf::Drawable& getShape();


    //Setter

    //Getter
    sf::RectangleShape& getRectangle();
    int getResistance();
    int getEffetObjet();



};



#endif // BRIQUE_H_INCLUDED
