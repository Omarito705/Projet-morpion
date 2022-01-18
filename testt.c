#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#define CONTINUE 0
#define FINISHED 1
//void creer(uint8_t g[3][3],int k,struct Tab_hachage* th);
uint8_t next_configuration(uint8_t grille[3][3]);
//void appliquer_transformation_base(uint8_t grille[3][3], transformation tr);
struct Liste *new_liste();
struct Tab_hachage** new_tab_hachage(uint32_t taille);
void creation_base_donnees(struct Tab_hachage **th,uint8_t g[3][3],int k);
void add_tete(struct Liste *l, int nbr_billes, int coup);
struct Maillon *new_maillon(int nbr_billes, int coup );


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


int main() {
    //FILE *out = fopen("sortie.txt", "w");

    uint8_t g[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int k=0;
    tab_hachage** th = new_tab_hachage(20000); // creation table de hachage assez grande
    while(next_configuration(g)==CONTINUE) //balaye tte les grilles
    {
    creation_base_donnees(th,g,k); //initialise une liste après l'autre avec la grille correspondante
      k++;
    }
  return EXIT_SUCCESS;
    }



void creation_base_donnees(struct Tab_hachage *th, uint8_t g[3][3],int k){ 

int i,j;
   for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {

    add_tete(th->tab[k],1,g[i][j]);

    }
  
}


uint8_t next_configuration(uint8_t grille[3][3])// passe à la grille suivante 
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

/*void appliquer_transformation_base(uint8_t grille[3][3], transformation tr)
{
    uint8_t t;
    switch(tr)
    {
        case(ID):
            break;

        case(ROT_90):
            t = grille[0][0];
            grille[0][0] = grille[2][0];
            grille[2][0]=grille[2][2];
            grille[2][2]=grille[0][2];
            grille[0][2]=t;

            t = grille[0][1];
            grille[0][1] = grille[1][0];
            grille[1][0]=grille[2][1];
            grille[2][1]=grille[1][2];
            grille[1][2]=t;
            break;

        case(ROT_180):
            appliquer_transformation_base(grille, ROT_90);
            appliquer_transformation_base(grille, ROT_90);
            break;

        case(ROT_270):
            appliquer_transformation_base(grille, ROT_90);
            appliquer_transformation_base(grille, ROT_90);
            appliquer_transformation_base(grille, ROT_90);
            break;

        case(MIROIR_VERT):
            t = grille[0][0];
            grille[0][0] = grille[0][2];
            grille[0][2] = t;

            t = grille[1][0];
            grille[1][0] = grille[1][2];
            grille[1][2] = t;

            t = grille[2][0];
            grille[2][0] = grille[2][2];
            grille[2][2] = t;
            break;

        case(MIROIR_HORIZ):
            appliquer_transformation_base(grille, ROT_90);
            appliquer_transformation_base(grille, MIROIR_VERT);
            appliquer_transformation_base(grille, ROT_270);
    }
}
*/
struct Liste *new_liste()  //alloue une liste vide
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

struct Tab_hachage** new_tab_hachage(uint32_t taille) // initialise nouvelle table de hachage de taille:taille
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

void add_tete(struct Liste *l, int nbr_billes, int coup) // ajoute en tete de liste un maillon correspondant à une case de la grille
{
maillon *m = new_maillon(nbr_billes, coup);
m->suivant = l->tete;
l->tete = m;

if( l->taille_liste == 0 )
{
l->queue = m;
}

l->taille_liste += 1;
}

 struct Maillon *new_maillon(int nbr_billes, int coup ) // cree nouveau maillon avc les données en paramètre 
{
maillon *m = malloc(sizeof(maillon));
if(m==NULL)
{
assert(0);
}
m->nbr_billes = nbr_billes;
m->coup= coup;
return m;
 }

