#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "links.h"

void create_file(){
    //creation du fichier info.game contenant toutes les infos sur les différents rôles (ex : potions utilisées par la sorciere ou camp du chien-loup)
    FILE* fichier = fopen("/home/alexandre/coding/C/coding games/loupgarou/info.game", "w+");

    /*informations du fichier info.game
    Ligne 1 : potion de vie - sorciere : = nombre de potions disponibles 
    Ligne 2 : potion de mort - sorciere : = nombre de potions disponibles 
    Ligne 3 : camp du chien-loup : lg si avec les loups / vi si avec le Village / None si pas encore choisi
    Ligne 4 : infection - infecte pere des loups : = True si compétence utilisée / False sinon
    Ligne 5 : modele en vie - enfant sauvage : = True si modele en vie / False si modele rip
    Ligne 6 : aucun lg mort - grand mechant loup : = True si aucun loup n'est mort / False si au moins un loup est mort
    Ligne 7 : résurrection de l'Ancien : = False si non utilisé / True si utilisé
    Ligne 8 : nom du joueur auquel le Joker donne une seconde vie :  = None tant qu'il n'a désigné personne
    Ligne 9 : pouvoir du Juge Bègue utilisé : = False si non utilisé / True si utilisé
    Ligne 10 : livraison du Livreur effectuée : = False si le Livreur n'a pas encore trouvé la Sorcière / True sinon
    Ligne 11 : Le Pirate a déjà désigné son otage : = False s'il n'a désigné personne / True sinon
    Ligne 12 : immunité du Prince : = True si pas encore utilisée / False si déjà utilisée
    Ligne 13 : pouvoir du Renard : = True si encore actif / False sinon
    Ligne 14 : Idiot du Village grâcié : = True si l'idiot peut encore survivre à un vote / False s'il a déjà été épargné 
    Ligne 15 : nom du modèle de l'enfant sauvage
    Ligne 16 : nom du premier amoureux
    Ligne 17 : nom du deuxième amoureux
    Ligne 18 : nom du premier client de l'Avocat
    Ligne 19 : nom du deuxième client de l'Avocat
    Ligne 20 : nom de l'otage du pirate 
    */

    fprintf(fichier, "1\n1\n"); //potions de la sorciere 
    fprintf(fichier, "None\n"); // camp du chien-loup
    fprintf(fichier, "False\n"); //compétence infection de l'infecte pere des loups
    fprintf(fichier, "True\n"); //modèle de l'enfant sauvage en vie
    fprintf(fichier, "True\n"); //capacité double kill gran mechant loup
    fprintf(fichier, "False\n"); //resurrection de l'Ancien
    fprintf(fichier, "None\n"); //nom de l'ami du Joker
    fprintf(fichier, "False\n"); //pouvoir du Juge Bègue
    fprintf(fichier, "False\n"); //le Livreur a sonné chez la Sorcière
    fprintf(fichier, "False\n"); //désignation de son otage par le pirate
    fprintf(fichier, "Ture\n"); //imunité du Prince
    fprintf(fichier, "Ture\n"); //pouvoir du Renard actif
    fprintf(fichier, "True\n"); //pouvoir de l'Idiot du Village 
    fprintf(fichier, "None\n");
    fprintf(fichier, "None\n");
    fprintf(fichier, "None\n");
    fprintf(fichier, "None\n");
    fprintf(fichier, "None\n");
    fprintf(fichier, "None\n");

    fclose(fichier);
}