#include <stdio.h>

int main()
{
    int i, j, tabuleiro[10][10];
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    int cone[3][5];
    int cruz[5][5];
    int octaedro[5][5];
    int l_origem;
    int c_origem;

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
    //Cone
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    //Cruz
     for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }


    //Octaedro
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if ((i - 2) + (j - 2) <= 2 && (i - 2) + (j - 2) >= -2 && (2 - i) + (j - 2) <= 2 && (2 - i) + (j - 2) >= -2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    
     l_origem = 2;
    c_origem = 4;
    for (i = 0; i < 3; i++) { 
        for (j = 0; j < 5; j++) {
            int l_tabuleiro = l_origem + i;
            int c_tabuleiro = c_origem - 2 + j;
            if (l_tabuleiro >= 0 && l_tabuleiro < 10 && c_tabuleiro >= 0 && c_tabuleiro < 10) {
                if (cone[i][j] == 1 && tabuleiro[l_tabuleiro][c_tabuleiro] != 3) {
                    tabuleiro[l_tabuleiro][c_tabuleiro] = 5;
                }
            }
        }
    }
    printf("\nTabuleiro com a Habilidade: Cone\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

     // Exibir o tabuleiro com a HABILIDADE CRUZ (reinicializa o tabuleiro antes) ---
    // Reinicializa o tabuleiro para remover o cone
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[9][3] = navio1[0]; tabuleiro[9][4] = navio1[1]; tabuleiro[9][5] = navio1[2];
    tabuleiro[3][3] = navio2[0]; tabuleiro[4][3] = navio2[1]; tabuleiro[5][3] = navio2[2];
    tabuleiro[6][4] = navio3[0]; tabuleiro[7][5] = navio3[1]; tabuleiro[8][6] = navio3[2];
    tabuleiro[1][9] = navio4[0]; tabuleiro[2][8] = navio4[1]; tabuleiro[3][7] = navio4[2];

    l_origem = 5;
    c_origem = 5;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int l_tabuleiro = l_origem - 2 + i;
            int c_tabuleiro = c_origem - 2 + j;
            if (l_tabuleiro >= 0 && l_tabuleiro < 10 && c_tabuleiro >= 0 && c_tabuleiro < 10) {
                if (cruz[i][j] == 1 && tabuleiro[l_tabuleiro][c_tabuleiro] != 3) {
                    tabuleiro[l_tabuleiro][c_tabuleiro] = 5;
                }
            }
        }
    }
    printf("\nTabuleiro com a Habilidade: Cruz\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Exibir o tabuleiro com a HABILIDADE OCTAEDRO (reinicializa o tabuleiro antes) ---
    // Reinicializa o tabuleiro para remover a cruz
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[9][3] = navio1[0]; tabuleiro[9][4] = navio1[1]; tabuleiro[9][5] = navio1[2];
    tabuleiro[3][3] = navio2[0]; tabuleiro[4][3] = navio2[1]; tabuleiro[5][3] = navio2[2];
    tabuleiro[6][4] = navio3[0]; tabuleiro[7][5] = navio3[1]; tabuleiro[8][6] = navio3[2];
    tabuleiro[1][9] = navio4[0]; tabuleiro[2][8] = navio4[1]; tabuleiro[3][7] = navio4[2];

    l_origem = 5;
    c_origem = 2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int l_tabuleiro = l_origem - 2 + i;
            int c_tabuleiro = c_origem - 2 + j;
            if (l_tabuleiro >= 0 && l_tabuleiro < 10 && c_tabuleiro >= 0 && c_tabuleiro < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[l_tabuleiro][c_tabuleiro] != 3) {
                    tabuleiro[l_tabuleiro][c_tabuleiro] = 5;
                }
            }
        }
    }
    

    // Exibir o tabuleiro com a HABILIDADE OCTAEDRO (reinicializa o tabuleiro antes) ---
    // Reinicializa o tabuleiro para remover a cruz
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[9][3] = navio1[0]; tabuleiro[9][4] = navio1[1]; tabuleiro[9][5] = navio1[2];
    tabuleiro[3][3] = navio2[0]; tabuleiro[4][3] = navio2[1]; tabuleiro[5][3] = navio2[2];
    tabuleiro[6][4] = navio3[0]; tabuleiro[7][5] = navio3[1]; tabuleiro[8][6] = navio3[2];
    tabuleiro[1][9] = navio4[0]; tabuleiro[2][8] = navio4[1]; tabuleiro[3][7] = navio4[2];

    l_origem = 5;
    c_origem = 2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int l_tabuleiro = l_origem - 2 + i;
            int c_tabuleiro = c_origem - 2 + j;
            if (l_tabuleiro >= 0 && l_tabuleiro < 10 && c_tabuleiro >= 0 && c_tabuleiro < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[l_tabuleiro][c_tabuleiro] != 3) {
                    tabuleiro[l_tabuleiro][c_tabuleiro] = 5;
                }
            }
        }
    }
    printf("\nTabuleiro com a Habilidade: Octaedro\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}