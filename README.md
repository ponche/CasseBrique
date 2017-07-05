# CasseBrique
my  Brick breaker

Issues : 

-problème du palet quand il est en mode inversion commande, il disparais sur la gauche


------------------------------------------------------------------------------------------


Rules : 

- déplacement de la souris pour déplacer le palet
- lancement de la balle avec la touche ESPACE 
- certain brique lache des object spécial qui déclenche des bonus/malus(malus: couleurs rose, bonus couleur vert)
- quand il a plus de ball sur la zone de jeu, une vie sera perdu
- quand le joueur n'as plus de vie, la fenetre se ferme et le programme se termine 

gestion des scores :
nombre en rouge = scores
nombre en bleu = vie 
nombre en jauen = level 


touche de test : 
NumPad7 : switch malus inversion commande
NumPad8 : placementBrique (attention, replace les brique par dessus)
NumPad5 : indique le nombre d'élement  dans la console
NumPad4 : place une nouvelle balle sur le palet (si une balle est déja sur le palet, elle sera lancé) 
NumPad9 : agrandir le palet 
NumPad3 : dmininue le palet

-------------------------------------------------------------------------------------------

Todo : 

- crée plusieurs niveaux 
- faire un systeme de chargement de niveau (via un fichier externe) 
- mettre en place le patern decorator sur les Brique 
- réactiver les bonus/malus vitesse ball. (désactivé a cause du mutli-ball) 

