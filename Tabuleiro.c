#include <stdio.h>

int main(){
    int i,j,tabuleiro[10][10];
    int navil1[3] = {3,3,3};
    int navil2[3] = {3,3,3};


for ( i = 0; i < 10; i++)
{
    for (j = 0; j < 10; j++)
    {
        tabuleiro[i][j] = 0;

    }
    
}
        tabuleiro[9][3] = navil1[0];
        tabuleiro[9][4] = navil1[1];
        tabuleiro[9][5] = navil1[2];

for ( i = 0; i < 10; i++)
{
    for ( j = 0; j < 10; j++)
    {
    
        if (tabuleiro[i][j] == 3)
        {
            printf("Posição %d %d ocupada\n",i,j);
        }
        else{

        tabuleiro[3][3] = navil2[0];
        tabuleiro[4][3] = navil2[1];
        tabuleiro[5][3] = navil2[2];
        }
            
    }
    
}



    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    




    return 0;
}