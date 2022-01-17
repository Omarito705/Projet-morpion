#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#define CONTINUE 0
#define FINISHED 1
//void creer(uint8_t g[3][3],int k,struct Tab_hachage* th);
uint8_t next_configuration(uint8_t grille[3][3]);



int main() {
    //FILE *out = fopen("sortie.txt", "w");

    uint8_t g[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int i,j;

  //  print_all_transformations_1d(g, out);
    while(next_configuration(g)==CONTINUE)
    {
       for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {

            printf("%d",g[i][j]);
    }
    }
    printf("\n");
    }


    return EXIT_SUCCESS;
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