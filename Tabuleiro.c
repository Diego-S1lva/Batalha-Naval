#include <stdio.h>

int main()
{
    int i, j, tabuleiro[10][10];
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    int l = 11;
    int c = 9;

    // cria o tabuleiro
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
    int l_n1 = 9;
    int c_n1 = 3;
    if (l_n1 >= 0 && l_n1 < 10 && c_n1 >= 0 && c_n1 < 10 &&
        (c_n1 + 2) < 10)
    {
        tabuleiro[9][3] = navio1[0];
        tabuleiro[9][4] = navio1[1];
        tabuleiro[9][5] = navio1[2];
        printf("Navio 1 adicionado.\n");
    } else {
        printf("A posição do Navio 1 excede o tamanho do tabuleiro.\n");
    }

     // Valida e adiciona o segundo navio
    int l_n2 = 3;
    int c_n2 = 3;
    if (l_n2 >= 0 && l_n2 < 10 && c_n2 >= 0 && c_n2 < 10 &&
        (l_n2 + 2) < 10)
    {
        tabuleiro[3][3] = navio2[0];
        tabuleiro[4][3] = navio2[1];
        tabuleiro[5][3] = navio2[2];
        printf("Navio 2 adicionado.\n");
    } else {
        printf("A posição do Navio 2 excede o tamanho do tabuleiro.\n");
    }

    // Valida e adiciona o terceiro navio
    int l_n3 = 6;
    int c_n3 = 4;
    if (l_n3 >= 0 && l_n3 < 10 && c_n3 >= 0 && c_n3 < 10 &&
        (l_n3 + 2) < 10)
    {
        tabuleiro[6][4] = navio3[0];
        tabuleiro[7][5] = navio3[1];
        tabuleiro[8][6] = navio3[2];
        printf("Navio 3 adicionado.\n");
    } else {
        printf("A posição do Navio 3 excede o tamanho do tabuleiro.\n");
    }
    
    // Valida e adiciona o quarto navio (que vai falhar)
    int l_n4 = 1;
    int c_n4 = 9;
    if (l_n4 >= 0 && l_n4 < 10 && c_n4 >= 0 && c_n4 < 10)
    {
        tabuleiro[1][9] = navio4[0];
        tabuleiro[2][8] = navio4[1];
        tabuleiro[3][7] = navio4[2];
        printf("Navio 4 adicionado.\n");
    } else {
        printf("A posição do Navio 4 excede o tamanho do tabuleiro.\n");
    }

    // imprime o tabuleiro
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