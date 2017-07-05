#include <iostream>

#include <SFML/Graphics.hpp>
#include "GestionScores.h"

int GestionScores::m_scores(0);
int GestionScores::m_vies(5);
int GestionScores::m_level(1);

void GestionScores::ajouterScores(int scores)
{
    m_scores += scores;
}
void GestionScores::ajouterVie(int vies)
{
    m_vies += vies;
}
void GestionScores::ajouterLevel(int level)
{
    m_level += level;
}
void GestionScores::enleverScores(int scores)
{
    m_scores -= scores;
    if(m_scores < 0)
        m_scores = 0;
}
void GestionScores::enleverVie(int vies)
{
    m_vies -= vies;
    if(m_vies < 0)
    {
        std::cout << "game over" << std::endl;
        m_vies = 0;
    }
}
void GestionScores::enleverLevel(int level)
{
    m_level -= level;
    if(m_level < 1)
        m_level = 1;
}
int GestionScores::getScores()
{
    return m_scores;
}
int GestionScores::getVies()
{
    return m_vies;
}
int GestionScores::getLevel()
{
    return m_level;
}
void GestionScores::reset(int vies, int scores, int level)
{
    m_vies = vies;
    m_scores = scores;
    m_level = level;
}

