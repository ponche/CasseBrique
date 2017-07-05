#ifndef AFFICHEURSCORE_H_INCLUDED
#define AFFICHEURSCORE_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class AfficheurScores
{
protected :
    sf::Text m_textScores;
    sf::Text m_textVies;
    sf::Text m_textLevel;
    sf::RenderWindow &m_fenetre;
    sf::Font m_font;
    sf::String m_chaineVies;
    sf::String m_chaineScores;
    sf::String m_chaineLevel;

public :
    AfficheurScores(sf::RenderWindow &fenetre);
    void update();
    void dessineScores();

    sf::String convertiseurIntToString(int nombre);
    sf::String IntToString ( int number );

    //setters
    void setTextScores(sf::Text text);
    void setTextVies(sf::Text text);

    //gettes
    sf::Text getTextScores();
    sf::Text getTextVies();


};

#endif // AFFICHEURSCORE_H_INCLUDED
