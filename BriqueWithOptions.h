#ifndef BRIQUEWITHOPTIONS_H_INCLUDED
#define BRIQUEWITHOPTIONS_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

#include "Brique.h"
#include "OptionBrique.h"


class BriqueWithOption : public Brique
{
protected:
    std::list<OptionBrique*> m_listeOptions;

public:


    BriqueWithOption(sf::Vector2f position, effetBrique effetObjet = VIDE);

    void update();
    void addOption(OptionBrique* option);
};





#endif // BRIQUEWITHOPTIONS_H_INCLUDED
