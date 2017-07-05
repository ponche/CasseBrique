#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#include "AfficheurScore.h"
#include "GestionScores.h"



using namespace sf ;

AfficheurScores::AfficheurScores(RenderWindow &fenetre)
: m_fenetre(fenetre)
{
    // Initialision des couleurs
    m_textScores.setColor(Color::Red);
    m_textVies.setColor(Color::Cyan);
    m_textLevel.setColor(Color::Yellow);

    // Init des tailles de police
    m_textScores.setCharacterSize(50);
    m_textVies.setCharacterSize(50);
    m_textLevel.setCharacterSize(50);

    // Init des position
    m_textScores.setPosition(20, 50);
    m_textVies.setPosition(20, 100);
    m_textLevel.setPosition(20, 150);

    // selection de la police
    m_font.loadFromFile("BOOMERAN.TTF");

    //selection de la police sur le text
    m_textScores.setFont(m_font);
    m_textVies.setFont(m_font);
    m_textLevel.setFont(m_font);


}

void AfficheurScores::update()
{
    // Modification de la chaine
    m_chaineScores = IntToString(GestionScores::getScores());
    m_chaineVies = IntToString(GestionScores::getVies());
    m_chaineLevel = IntToString(GestionScores::getLevel());


    m_textScores.setString(m_chaineScores);
    m_textVies.setString(m_chaineVies);
    m_textLevel.setString(m_chaineLevel);

}

void AfficheurScores::dessineScores()
{
    m_fenetre.draw(m_textScores);
    m_fenetre.draw(m_textVies);
    m_fenetre.draw(m_textLevel);
}


String AfficheurScores::IntToString ( int number )
{
  std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string
  std::string valeurFinal = oss.str();
  return String(valeurFinal);
}
