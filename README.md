# CasseBrique
my  Brick breaker

## Issues : 

* problème du palet quand il est en mode inversion commande, il disparait sur la gauche


------------------------------------------------------------------------------------------


## Rules : 
* déplacement de la souris pour déplacer le palet
* lancement de la balle avec la touche ESPACE 
* certaines briques lachent des objets spéciaux qui déclenchent des bonus/malus (malus: couleur rose, bonus couleur verte)
* quand il n'y a plus de balles sur la zone de jeu, une vie sera perdue
* quand le joueur n'a plus de vie, la fenetre se ferme et le programme se termine 

## Gestion des scores :
* nombre en rouge = scores
* nombre en bleu = vie 
* nombre en jaune = level 


## Touches de test : 
* NumPad7 : switch malus inversion commande
* NumPad8 : placementBrique (attention, replace les briques par dessus)
* NumPad5 : indique le nombre d'élements dans la console
* NumPad4 : place une nouvelle balle sur le palet (si une balle est déja sur le palet, elle sera lancée) 
* NumPad9 : agrandir le palet 
* NumPad3 : dimininuer le palet

-------------------------------------------------------------------------------------------

## Todo : 
* créer plusieurs niveaux 
* faire un systeme de chargement de niveau (via un fichier externe) 
* mettre en place le pattern decorator sur les Briques 
* réactiver les bonus/malus vitesse ball. (désactivé a cause du mutli-ball) 

