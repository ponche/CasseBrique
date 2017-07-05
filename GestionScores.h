#ifndef GESTIONSCORES_H_INCLUDED
#define GESTIONSCORES_H_INCLUDED

#include <iostream>

class GestionScores
{
protected:
    static int m_scores;
    static int m_vies;
    static int m_level;

public:
    static int getScores();
    static int getVies();
    static int getLevel();
    static void ajouterVie(int vies = 1);
    static void ajouterScores(int scores = 100);
    static void ajouterLevel(int level = 1);
    static void enleverVie(int vies = 1);
    static void enleverScores(int scores = 100);
    static void enleverLevel(int level = 1);
    static void reset(int vies = 3, int scores = 0, int level = 1);

};

#endif // GESTIONSCORES_H_INCLUDED
