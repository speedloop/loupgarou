#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "links.h"


static void lire(char* string, int length){
  char *pointer = NULL;

  fgets(string, length, stdin);
  do{
    pointer = strchr(string, '\n');
    if(pointer != NULL){
      *pointer = '\0';
    }
  }while(pointer != NULL);
}


int main(int argc, char* argv[]){
  char quepouic[5];
  char oon[5];                            //Oui Ou Non ===> OON

  int nbjoueurs;

  do{
    printf("Combien de joueurs êtes-vous ?\n");
    scanf("%d", &nbjoueurs); fgetc(stdin);
    printf("Êtes-vous bien %d joueurs ?\n", nbjoueurs);
    lire(oon,5);
  }while(strcmp(oon, "oui") != 0);                          //tant que l'utilisateur n'a pas rentré "oui"

  printf("Entrez les noms des joueurs UN PAR UN, dans le sens des aiguilles d'une montre.\n");
  
  char **joueurs = NULL;

  joueurs = allocation(nbjoueurs,25);
 
  for(int i = 0 ; i < nbjoueurs ; i++){    
    printf("%d/", i + 1);    
    lire(joueurs[i], 25);
  }

  char** selectionnes = selection(nbjoueurs);
  char** roles[2] = {
    allocation(nbjoueurs, 100),allocation(nbjoueurs,100)
  };
  for(int i = 0 ; i < nbjoueurs ; i++){
    sprintf(roles[0][i],"%s",joueurs[i]);
  }
  roles[1] = tirage(selectionnes,joueurs,nbjoueurs);

  create_file();


  int nb_nuits = 0;
  nuit(roles[1],roles[0],nb_nuits,nbjoueurs);




  if(joueurs != NULL){  
    //libération de la mémoire allouée après utilisation
    for(int i = 0 ; i < nbjoueurs ; i++){
      if(joueurs[i] != NULL){
        free(joueurs[i]);
      }
    }
    free(joueurs);
  }

  //supression du fichier info.game
  //remove("/home/alexandre/coding/C/coding games/loupgarou/info.game");

  return 0;
}
