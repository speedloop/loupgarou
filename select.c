#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "links.h"

#define NBROLES 34


char** selection(int nbjoueurs){
  char ls_roles[40][50] = {"Cupidon", "La Sorcière", "La Voyante", "Le Chasseur", "Le Pirate", "L'Avocat", "Le Joker", "L'Enfant Sauvage", "L'Infecte Père des Loups",
			   "L'Ancien", "L'Ange", "Le Prince", "Le Devin Maléfique", "La Petite Fille", "Le Grand Méchant Loup", "Le Loup Blanc", "L'Assassin",
			   "Le Joueur de Flûte", "Le Chevalier à l'Épée Rouillée", "Le Chien-Loup", "La Fouineuse", "Le Livreur", "Le Gentleman", "Le Serveur",
			   "Le Montreur d'Ours", "Le Renard", "Le Juge Bègue", "Le Corbeau", "Le Voleur", "L'Idiot du Village", "Le Bouc Émissaire", "Le Berger",
			   "Le Fils de la Lune", "Le Salvateur","Un Loup-Garou","Un Simple Villageois"};

  char fullpath[1000];
  FILE *fichier = NULL;

  system("clear");
  printf("\n\t\t==SELECTION DES ROLES==\n\n");

  printf("ROLES DISPONIBLES : \n");
  for(int i = 0 ; i < NBROLES ; i++){
    printf("%d/%s\n", i+1, ls_roles[i]);
  }
  
  printf("\nPour sélectionner un personnage , entrez son numéro\n");
  printf("En cas d'hésitation sur un rôle, rentrez son numéro suivi d'un point d'interrogation pour en savoir plus\n\n");

  int nb_selectionnes = 0;
  char ** selectionnes = NULL;
  selectionnes = allocation(nbjoueurs,100);

  while(nb_selectionnes != nbjoueurs){
    char entry[10];
    char *pointeur = NULL;

    printf("Rôle n.%d : ", nb_selectionnes+1);    
    scanf("%s", entry);
    
    pointeur = strchr(entry, '?');
    if (pointeur != NULL){   //utilisateur demande de l'aide sur un rôle 
      char request[5] = "";
      int index = 0; //index du caractère '?' dans l'entrée de l'utilisateur 
      for(int character = 0 ; character < strlen(entry); character++){
        if (entry[character] != '?'){
          strncat(request,&entry[character],1);
        }
      }      
      sprintf(fullpath,"/home/alexandre/coding/C/coding games/loupgarou/roles/%s.txt",ls_roles[atoi(request)]);
      fichier = fopen(fullpath,"r");
      if (fichier != NULL){
        char chaine[1000] = "";
        putchar('\n');
        while (fgets(chaine, 1000, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
          {
              printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
          }
        fclose(fichier);
        putchar('\n');
      }
      else{
        printf("fichier introuvable\n");
      }
    }
    else{
      if (atoi(entry) <= NBROLES && atoi(entry) > 0){
        strcpy(selectionnes[nb_selectionnes],ls_roles[atoi(entry)-1]);
        nb_selectionnes ++;      
      }
      else{
        printf("Ce rôle n'est pas disponible\n");
      }
    }
  }
  return selectionnes;
}
