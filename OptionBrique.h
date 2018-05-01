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

    virtual void update() = 0 ; // méthode virtuel
    virtual void start() = 0 ;









};




#endif // OPTIONBRIQUE_H_INCLUDED
