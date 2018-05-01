#include <iostream>
#include <SFML/Graphics.hpp>

#include <cmath>

#include "GestionJeu.h"
#include "ObjetSpecial.h"
#include "Ball.h"

#include "BriqueWithOptions.h"
#include "OptionMoving.h"
#include "OptionSolid.h"

using namespace sf;

GestionJeu::GestionJeu(sf::RenderWindow &fenetre)
: m_palet(fenetre), m_ballShotting(0)
{
    m_fenetre = &fenetre;
    m_niveau = 1;
    m_axePaletY = 725 ; // Magic Number à remplacer
    m_axeDeleteBallY = 500; //a remplacer par un  calcul

}
void GestionJeu::dessinerJeu()
{
    m_fenetre->draw(m_palet.getRectange());

    for(std::list<Ball*>::iterator it = m_listeBall.begin(); it != m_listeBall.end(); it++)
    {
        Ball *laBall = *it;
        m_fenetre->draw(laBall->getShape());
    }
    for(std::list<Brique*>::iterator it = m_listeBrique.begin(); it != m_listeBrique.end(); it++)
    {
        Brique *laBrique = *it;
        m_fenetre->draw(laBrique->getShape());
        laBrique->update();
    }


    for(std::list<ObjetSpecial*>::iterator it = m_listeObjet.begin(); it != m_listeObjet.end(); it++)
    {
        ObjetSpecial *leObjet = *it;
        m_fenetre->draw(leObjet->getCercle());

    }
}
void GestionJeu::boucleSystem()
{
    while(m_fenetre->isOpen())
    {
        //Boucle d'evenement
        while(m_fenetre->pollEvent(m_event))
        {
            if(m_event.type == sf::Event::Closed)
                m_fenetre->close();
            if(m_event.type == sf::Event::MouseMoved)
            {
                //m_palet.update();
            }
            if(m_event.type == sf::Event::KeyPressed)
            {
                if(m_event.key.code == sf::Keyboard::Space)
                    catapultageBall(); // fonction a déplacer dans Gestion de jeu
                /*if(m_event.key.code == sf::Keyboard::Add)
                    //m_ball.augmenterVitesse();
                if(m_event.key.code == sf::Keyboard::Subtract)
                    //m_ball.diminuerVitesse();*/
                if(m_event.key.code == sf::Keyboard::Numpad3)
                    m_palet.diminuerPalet();
                if(m_event.key.code == sf::Keyboard::Numpad4)
                    ajouterBall();
                if(m_event.key.code == sf::Keyboard::Numpad7)
                    m_palet.reverseCommande();
                if(m_event.key.code == sf::Keyboard::Numpad8)
                    placementBrique();
                if(m_event.key.code == sf::Keyboard::Numpad9)
                    m_palet.agrandirPalet();
                if(m_event.key.code == sf::Keyboard::Numpad5)
                    std::cout << "nbElement : " << Element::getNbElement() << std::endl ;

            }

        }

        //mise a jour et test
        updateBall();
        testCollisionObjectSpecial();
        m_palet.update();


        // Test si joueur a gagner

        if(m_listeBrique.empty())
        {
            //std::cout << "Bravo vous avez gagner !!! " << std::endl;
            GestionScores::ajouterLevel();
            //Suppresion des ball
            for(std::list<Ball*>::iterator it = m_listeBall.begin(); it != m_listeBall.end(); it++)
            {
                delete *it;

            }
            m_listeBall.clear();
            std::cout << "suppression de tout les balle " << std::endl ;
            placementBrique();
        }

        // Test si le joueur a perdu
        else if(m_listeBall.empty())
        {
            gameOver();
        }


        //Mise a jour de l'écran

        m_fenetre->clear(sf::Color::Blue);
        dessinerJeu();
        /*m_afficheurScores.update();
        m_afficheurScores.dessineScores();*/
        //m_afficheurScores.dessineScores();
        m_fenetre->display();
    }
    //return 0;
}

void GestionJeu::placementBrique()
{

    m_listeBrique.push_back(new Brique(Vector2f(0, 0), DIMINUER_PALET));
    m_listeBrique.push_back(new Brique(Vector2f(50, 50), AUGMENTER_PALET));
    m_listeBrique.push_back(new Brique(Vector2f(100, 100)));
    m_listeBrique.push_back(new Brique(Vector2f(150, 150)));
    m_listeBrique.push_back(new Brique(Vector2f(200, 200)));
    m_listeBrique.push_back(new Brique(Vector2f(250, 250), DIMINUER_PALET));
    m_listeBrique.push_back(new Brique(Vector2f(300, 300),AUGMENTER_PALET));
    m_listeBrique.push_back(new Brique(Vector2f(350, 350), DIMINUER_PALET));
    m_listeBrique.push_back(new Brique(Vector2f(400, 400)));
    m_listeBrique.push_back(new Brique(Vector2f(450, 450),DIMINUER_PALET));

    m_listeBrique.push_back(new BriqueRegenerator(Vector2f(500, 500))); // BriqueRegenerator a supprimer
    BriqueWithOption *maNouvelleBrique =  new BriqueWithOption(Vector2f(200, 50)) ;
    maNouvelleBrique->addOption(new OptionMoving) ;
    maNouvelleBrique->addOption(new OptionSolid) ;
    m_listeBrique.push_back(maNouvelleBrique) ;



    ajouterBall();
}

void GestionJeu::gameOver()
{

    GestionScores::enleverVie();
    if(GestionScores::getVies() < 1)
        m_fenetre->close();
    else
    {
        ajouterBall();
    }

}

void GestionJeu::testCollisionMur(Ball &boule)
{
    if(boule.getCercle().getPosition().x < boule.getCercle().getRadius())
    {
        //std::cout << "collision a gauche" << std::endl;
        if(boule.getDirection().x < 0)
        {
            sf::Vector2f direction = boule.getDirection();
            direction.x *= -1;
            boule.setDirection(direction);
        }
    }
    if(boule.getCercle().getPosition().x > m_fenetre->getSize().x - boule.getCercle().getRadius())
    {
        //std::cout << "collision a droite" << std::endl;
        if(boule.getDirection().x > 0)
        {
            sf::Vector2f direction = boule.getDirection();
            direction.x *= -1;
            boule.setDirection(direction);
        }
    }
    if(boule.getCercle().getPosition().y < boule.getCercle().getRadius())
    {
        if(boule.getDirection().y < 0)
        {
            sf::Vector2f direction = boule.getDirection();
            direction.y *= -1;
            boule.setDirection(direction);
        }
    }
    if(boule.getCercle().getPosition().y > m_fenetre->getSize().y - boule.getCercle().getRadius())
    {
        if(boule.getDirection().y > 0)
        {


        }
    }
}
void GestionJeu::testCollisionBrique(Ball &boule)
{
    for(std::list<Brique*>::iterator it = m_listeBrique.begin(); it != m_listeBrique.end(); it++)
    {
        Brique *laBrique(*it);
        sf::FloatRect boxBrique = laBrique->getRectangle().getGlobalBounds();
        sf::FloatRect boxBall = boule.getCercle().getGlobalBounds();
        if(boxBall.intersects(boxBrique))
        {
            //Collision
            //std::cout << "collision entre une brique " << std::endl;
            //changement de direction
            sf::Vector2f direction = boule.getDirection();

            if((boxBall.top<boxBrique.top && boxBall.top + boxBall.height > boxBrique.top) || (boxBall.top < boxBrique.top + boxBrique.height && boxBall.top + boxBall.height > boxBrique.top + boxBrique.height))
                direction.y *= -1;
            if((boxBall.left < boxBrique.left && boxBall.left + boxBall.width > boxBrique.left) || (boxBall.left < boxBrique.left + boxBrique.width && boxBall.left + boxBall.width > boxBrique.left + boxBrique.width))
                direction.x *= -1;
            boule.setDirection(direction);

            laBrique->collision(boule);
            if(laBrique->getResistance() <= 0)
            {
                std::cout << "EffetsObjet = " << laBrique->getEffetObjet() << std::endl ;
                if(laBrique->getEffetObjet() != 0)
                {
                    laBrique->destructionBrique() ;
                    //laBrique->destructionBrique();
                    m_listeObjet.push_back(new ObjetSpecial(laBrique->getEffetObjet(), laBrique->getRectangle().getPosition()));
                    // a deplacer dans la fonction Brique ;

                }
                delete laBrique;
                m_listeBrique.erase(it);
            }
            break;
        }
    }
}
void GestionJeu::testCollisionPalet(Ball &boule)
{
    //test collision palet
    sf::FloatRect boxPalet = m_palet.getRectange().getGlobalBounds();
    sf::FloatRect boxBall = boule.getCercle().getGlobalBounds();

    if(boxBall.intersects(boxPalet))
    {
        //Collision
        float positionBallX = boule.getCercle().getPosition().x;
        float positionPalletX = m_palet.getRectange().getPosition().x;
        float largeurPalet = m_palet.getRectange().getSize().x;
        float distanceX = positionBallX - positionPalletX;
        distanceX /= (largeurPalet + 30) / 2;

        float distanceY = -1 * sqrt(1 - (distanceX * distanceX));
        boule.setDirection(sf::Vector2f(distanceX, distanceY));

    }
}
void GestionJeu::updateBall()
{
    std::list<Ball*>:: iterator caseSuppresion;
    Ball* bouleSuppresion;
    bool suppresioonBall = false;

    for(std::list<Ball*>::iterator it = m_listeBall.begin(); it != m_listeBall.end(); it++)
    {
        Ball *laBall(*it);

        // Action sur tout les balls
        laBall->update();

        testCollisionBrique(*laBall);
        testCollisionMur(*laBall);
        testCollisionPalet(*laBall);

        // vérification si la ball est toujours en vie
        if(!laBall->getIsLive())
        {
            caseSuppresion = it;
            bouleSuppresion = laBall;
            suppresioonBall = true;
        }

    }

    if(suppresioonBall)
    {
        suppresioonBall = false;
        delete bouleSuppresion;
        m_listeBall.erase(caseSuppresion);
    }

}



void GestionJeu::ajouterBall()
{
    Ball* nouvelBall = new Ball(*m_fenetre, m_palet);

    preparationLanceur(*nouvelBall);
    m_listeBall.push_back(nouvelBall);
}
void GestionJeu::testCollisionObjectSpecial()
{

    std::list<ObjetSpecial*>::iterator caseSuppresion;
    bool supressionCase = false;
    ObjetSpecial* objectDestruction;
    for(std::list<ObjetSpecial*>::iterator it = m_listeObjet.begin(); it != m_listeObjet.end(); it++)
    {
        ObjetSpecial *leObjet = *it;
        leObjet->update();

        sf::FloatRect boxPalet = m_palet.getRectange().getGlobalBounds();
        sf::FloatRect boxObjet = leObjet->getCercle().getGlobalBounds();
        if(boxPalet.intersects(boxObjet))
        {
            std::cout << "le palet touche objet " << std::endl ;
            leObjet->setIsLive(false);
            // Application de l'effet
            switch(leObjet->getEffets())
            {
            case DIMINUER_PALET :
                m_palet.diminuerPalet(60);
                break;
            case AUGMENTER_PALET :
                m_palet.agrandirPalet(10);
                break;
            case AUGMENTER_VITESSE :
                //m_ball.augmenterVitesse(4); DANGER m_ball n'existe plus
                break;
            case DIMINUER_VITESSE :
                //m_ball.diminuerVitesse(2);  DANGER m_ball n'existe plus
                break;
            default:
                std::cout << "pas d'effet pour cette objet " << std::endl ;
                break;
            }


        }
        if(leObjet->getIsLive() == false)
        {
           caseSuppresion = it;
           supressionCase = true;
           objectDestruction = leObjet;

        }

    }
    if(supressionCase)
    {
        delete objectDestruction;
        m_listeObjet.erase(caseSuppresion);
        supressionCase = false;
    }
}
void GestionJeu::catapultageBall()
{
    if(m_ballShotting)
    {
        m_ballShotting->lancerBall();
        m_ballShotting = 0 ;
    }
    else
    {
        std::cout << "pas de ball sur le palet " << std::endl ;
    }
}
void GestionJeu::preparationLanceur(Ball &laBall)
{
    // si une ball est sur le palet on la lance
    if(m_ballShotting)
    {
        m_ballShotting->lancerBall();
    }
    // affectation de la ball sur le palet
    m_ballShotting = &laBall;
}
