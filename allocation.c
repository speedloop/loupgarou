#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

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

char ** allocation(int nb_string, int taille_max){
  char ** tab = NULL;
  
  tab = malloc(nb_string * sizeof(*tab));
  if (tab != NULL){
    memset(tab, 0, nb_string*sizeof(char*));
    for (int i = 0; i < nb_string ; i++){
      tab[i] = malloc(taille_max * sizeof(**tab));
    }
  }

  return tab;
}
