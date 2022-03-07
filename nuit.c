#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "links.h"

#define NBROLES 34

int get_player_from_role(char** roles, char* request_role, int nbjoueur){
    for(int i = 0 ; i < nbjoueur ; i++){
        if(strcmp(roles[i],request_role) == 0){
            return i;
        }
    }    
}


char** nuit(char ** roles,char** players,int nb_nuits, int nbjoueurs){
    char ls_roles[40][50] = {"Cupidon", "La Sorcière", "La Voyante", "Le Chasseur", "Le Pirate", "L'Avocat", "Le Joker", "L'Enfant Sauvage", "L'Infecte Père des Loups",
			   "L'Ancien", "L'Ange", "Le Prince", "Le Devin Maléfique", "La Petite Fille", "Le Grand Méchant Loup", "Le Loup Blanc", "L'Assassin",
			   "Le Joueur de Flûte", "Le Chevalier à l'Épée Rouillée", "Le Chien-Loup", "La Fouineuse", "Le Livreur", "Le Gentleman", "Le Serveur",
			   "Le Montreur d'Ours", "Le Renard", "Le Juge Bègue", "Le Corbeau", "Le Voleur", "L'Idiot du Village", "Le Bouc Émissaire", "Le Berger",
			   "Le Fils de la Lune", "Le Salvateur","Un Loup-Garou","Un Simple Villageois"};

    char ** victimes = allocation(nbjoueurs,100);

    FILE* fichier = fopen("info.game", "r");
    char **infos = allocation(15,20);
    int nb_infos = 0; //infos collectees
    if (fichier != NULL){
        while(fgets(infos[nb_infos], 20, fichier) != NULL){            
            nb_infos++;
        }        
    }

    if(nb_nuits == 0){
        if(true/*get_player_from_role(roles, "Le Voleur",nbjoueurs) != NULL*/){
            printf("Le Voleur se réveille...\n");
            printf("(Voleur = %s)\n", players[get_player_from_role(roles,"Le Voleur",nbjoueurs)]);
            int nb_voles = 0;
            char** voles = allocation(3,50);
            while(nb_voles != 3){
                bool vole = false;
                bool selectionne = false;
                srand(time(NULL));
                char role[50] = "";
                sprintf(role,"%s",ls_roles[rand() % NBROLES]);
                //check si déjà dans les choix de vol
                for(int i = 0 ; i < nb_voles ; i++){
                    if(strcmp(voles[i],role)==0){
                        vole = true;
                    }
                }
                //check si déjà dans les rôles de la partie 
                for(int i = 0 ; i < NBROLES ; i++){
                    if(strcmp(roles[i],role)==0 && strcmp(role,"Un Simple Villageois") != 0 && strcmp(role, "Un Loup-Garou") != 0){
                        selectionne = true;
                    }
                }

                if(!selectionne && !vole){
                    sprintf(voles[nb_voles],"%s", role);
                    nb_voles++;
                }
            }
            for(int i = 0 ; i < 3 ; i++){
                printf("%s\n", voles[i]);
            }
        }
    }
}