#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class Element
{
protected:
    static int nbElement;

    bool m_isLive;
public:
    Element();
    virtual ~Element() ;
    virtual void update() ;

    virtual sf::Drawable& getShape() = 0 ;

    static int getElement();

    bool getIsLive();
    void destructionElement();

};







#endif // ELEMENT_H_INCLUDED
