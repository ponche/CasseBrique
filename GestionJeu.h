#ifndef GESTIONJEU_H_INCLUDED
#define GESTIONJEU_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

#include "Ball.h"
#include "Brique.h"
#include "Palet.h"
#include "ObjetSpecial.h"
#include "GestionScores.h"
#include "BriqueRegenerator.h"
class GestionJeu
{
protected:
    //Les différence conteneur des ball et brique

    Palet m_palet;
    // a supprimer par la suite quand gestion ball sera fait
    //AfficheurScores m_afficheurScores;
    bool m_jeuEnAction;
    sf::Event m_event;
    sf::Clock m_horloge;
    std::list<Brique*> m_listeBrique;
    std::list<ObjetSpecial*> m_listeObjet;
    std::list<Element*> m_listeElement;
    std::list<Ball*> m_listeBall;
    int m_niveau;
    Ball *m_ballShotting ;
    float m_axePaletY;
    float m_axeDeleteBallY;


    //Pointeurs fenetre
    sf::RenderWindow *m_fenetre;

public:
    GestionJeu(sf::RenderWindow &fenetre);

    //Les fonctions divers
    void dessinerJeu();
    void initialisationJeu();
    void boucleSystem();
    void testCollisionMur(Ball &boule);
    void testCollisionPalet(Ball &boule);
    void testCollisionBrique(Ball &boule);
    void testCollisionObjectSpecial();
    void gameOver();
    void updateBall();
    void ajouterBall();
    void catapultageBall();
    void preparationLanceur(Ball &laBall);


    void placementBrique();


    Palet getPalet();

};

#endif // GESTIONJEU_H_INCLUDED
