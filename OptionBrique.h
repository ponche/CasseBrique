#ifndef OPTIONBRIQUE_H_INCLUDED
#define OPTIONBRIQUE_H_INCLUDED

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "Brique.h"
#include "Ball.h"


class OptionBrique
{
protected:
    // Pointeur de la brique
    Brique *m_pointeurBrique ;

public:
    OptionBrique() ;
    ~OptionBrique() ;
    // fonction
    void setBrique(Brique *pointeur) ;

    virtual void update() ; // m�thode virtuel
    virtual void start()  ;
    virtual void collision(Ball &boule) ;
    virtual void destruction() ;









};




#endif // OPTIONBRIQUE_H_INCLUDED
