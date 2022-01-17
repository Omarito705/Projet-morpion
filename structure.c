#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h> 
#include <assert.h>
#define CONTINUE 0
#define FINISHED 1

void lancer_menu(int a );
int demandermode();
void lancer_mode(int m);
int a_nouveau();
void menu_autonome();
void menu_joueur();
FILE* ouvrir_fichier(char nom[50]);
struct Tab_hachage* new_tab_hachage(uint32_t taille);
struct Liste *new_liste();
struct Tab_hachage* creation_base_donnees();
void creer(uint8_t g[3][3],int k,struct Tab_hachage* th);
uint8_t next_configuration(uint8_t grille[3][3]);
//void print_grille_1d(uint8_t grille[3][3], FILE *f)

typedef struct Maillon
 {
 uint8_t coup; // soit X(donc 2) soit 0(donc 1) soit vide(donc 0)
 uint8_t nbr_billes;
 struct _maillon *suivant;
 } maillon;

 typedef struct Liste
 {
uint32_t taille_liste;
maillon *tete;
maillon *queue;
 } liste;

typedef struct Tab_hachage
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
        menu_autonome();

    }
    else if (m == 2) {
        printf("Vous avez choisi le mode joueur \n\n\n");
        menu_joueur();
    }
}

int a_nouveau(){

int refaire;

printf("            Voulez-vous revenir au menu principale ?\n\n");
char choice[2]="";
printf("Si oui tapez 1:\n");
printf("Sinon tapez  2:\n\n");
fgets(choice,3,stdin);
 refaire = (choice[0]-48);

return refaire;
}

FILE* ouvrir_fichier(char nom[50]){//Fonction qui ouvre le fichier qui va être tester, et verifie si il a été ouvert avec succès.


FILE* data_base = NULL;
data_base = fopen(nom, "rb");

        if (data_base == NULL) {

            printf("Le fichier de r%cf%crence est vide ou introuvable\n\n",130,130);

        }
        else {

        if (NULL != data_base) {
            fseek (data_base, 0, SEEK_END);     // vérifie si la base de donnée est vide
            long size = ftell(data_base);

        if (0 == size) {
            printf("la base de donée est vide\n");
            creation_base_donnees(data_base);
       }
   }
        //printf("Le fichier de r%cf%crence n'est pas vide\n\n",130,130);

        }

 return data_base;

 }
struct Tab_hachage* new_tab_hachage(uint32_t taille)
{

uint32_t i;
struct Tab_hachage *th = malloc( sizeof(tab_hachage) );
assert(th != NULL);
th->tab = malloc(taille*sizeof(liste*));
assert(th->tab != NULL);

    for( i=0; i<taille; i=i+1 )
      {
    th->tab[i] = new_liste();
    }

th->taille = taille;
return th;
}

liste *new_liste()
{
 liste *r = malloc(sizeof(liste));
 if(r==NULL)
    {
        assert(0);
    }
r->taille_liste=0;
r->tete = NULL;
r->queue = NULL;
return r;

}
 tab_hachage* creation_base_donnees(){

tab_hachage* th=new_tab_hachage(304);
uint8_t g[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int k=0; // k c'est l 'indicateur de la liste (soit ici la configuration du morpion)


    while(next_configuration(g)==CONTINUE)
    {

        creer(g,k,th);
        k++;
    }
    
    return EXIT_SUCCESS;
}


 void creer(uint8_t g[3][3],int k,tab_hachage* th)
{
maillon* debut = th->tab[k]->tete;
int i,j;

    for(i=0; i<3; i++)
    {
    for(j=0; j<3; j++)
      {
      debut->nbr_billes=1;
      debut->coup=g[i][j];
      debut=debut->suivant;
      printf("nbr bille:%d\n",debut->nbr_billes);


    }
  }
}
uint8_t next_configuration(uint8_t grille[3][3])
{
    uint8_t i, j;

    grille[0][0]++;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(grille[i][j]==3)
            {
                grille[i][j]=0;
                if(j<2) grille[i][j+1]++;
                else if(i<2) grille[i+1][0]++;
                else return FINISHED;
            }
        }
    }

    return CONTINUE;
}
/*void print_grille_1d(uint8_t grille[3][3], FILE *f)
{
    fprintf(f, "%c%c%c%c%c%c%c%c%c", print_value(grille[0][0]), print_value(grille[0][1]), print_value(grille[0][2]), print_value(grille[1][0]), print_value(grille[1][1]), print_value(grille[1][2]), print_value(grille[2][0]), print_value(grille[2][1]), print_value(grille[2][2]));
}*/
