#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _maillon
 {
 uint8_t coup; // soit X(donc 2) soit 0(donc 1) soit vide(donc 0)
 uint8_t nbr_billes;
 struct _maillon *suivant;
 } maillon;

 typedef struct
 {
uint32_t taille;
maillon *tete;
maillon *queue;
 } liste;

typedef struct
 {
 liste **tab;
 uint32_t taille;
 } tab_hachage;


int main(){

int a=1;
lancer_menu(a);

return 0;
 }

void lancer_menu(int a ){

 while(a==1){

 int choix=0;
 choix = demandermode();
 lancer_mode(choix);
 a = a_nouveau();

 }

}
int demandermode(){// Fonction qui demande le mode autonome 1 ou bien mode joueur , elle recueille le choix de l'utilisateur

printf("            Bonjour, bienvenue dans le jeu morpion :%c\n\n",41);
char mode[2]="";
printf("Pour le mode autonome tapez 1:\n");
printf("Pour le mode joueur tapez 2:\n\n");
fgets(mode,3,stdin);
int C = mode[0]-48;
return C;
}
void lancer_mode(int m){
    //fonction qui lance soit le mode autonome ou le mode joueur selon le choix de l'utilisateur.
    if (m == 1) {
        printf("Vous avez choisi le mode autonome \n\n\n");
        menu_apprentissage();

    }
    else if (m == 2) {
        printf("Vous avez choisi le mode joueur \n\n\n");
        menu_reconnaisseur();
    }
}



