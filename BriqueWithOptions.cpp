#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

#include "BriqueWithOptions.h"
#include "Brique.h"

 // Brique::Brique(sf::Vector2f position, effetBrique effetObjet )

BriqueWithOption::BriqueWithOption(sf::Vector2f position, effetBrique effetObjet)
:Brique(position, effetObjet)
{
    //Brique::Brique(position, effetObjet);
}

void BriqueWithOption::update()
{
    // call function mother
    Brique::update();

    //update plugin
    for(std::list<OptionBrique*>::iterator it = m_listeOptions.begin(); it != m_listeOptions.end(); it++)
    {
        OptionBrique *plugin = *it;
        plugin->update();
    }

}
void BriqueWithOption::addOption(OptionBrique *option)
{
    m_listeOptions.push_back(option);
    option->setBrique(this) ;
    option->start();
}

