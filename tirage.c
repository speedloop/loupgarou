#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "links.h"

char** tirage(char** selectionnes,char** joueurs,int nbjoueurs){
    char ** done = allocation(nbjoueurs,100); //liste des rôles déjà attribués
    int nb_attribues = 0; //nombre de rôles déjà attribués

    char** roles[2] = {
        allocation(nbjoueurs,100),allocation(nbjoueurs,100)
    };
    for(int i = 0 ; i < nbjoueurs ; i++){
        sprintf(roles[0][i],"%s",joueurs[i]);
    }
    
    while(nb_attribues != nbjoueurs){
        srand(time(NULL));
        int role = rand() % nbjoueurs;

        //recherche du rôle piché au hasard dans les rôles déjà attribués
        bool attribue = false;
        for(int j = 0 ; j < nb_attribues ; j++){
            if(strcmp(done[j],selectionnes[role]) == 0){
                attribue = true;
            }
        }

        if(!attribue){ //si le rôle n'est pas déjà attribué            
            sprintf(roles[1][nb_attribues],"%s", selectionnes[role]);
            sprintf(done[nb_attribues],"%s", selectionnes[role]);
            nb_attribues += 1;
        }
    }

    return roles[1];
}