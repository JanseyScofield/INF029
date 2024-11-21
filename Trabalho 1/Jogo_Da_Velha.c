#include "Jogo_Da_Velha.h"


void printarTabuleiro(Tabuleiro tabuleiro){
    char letras[] = {'A', 'B','C'};
    int numeros[] = {1, 2, 3};
    int iCont, jCont;

    printf("Rodada %d\n",  tabuleiro.rodada);
    printf("     1   2   3\n");
    for(iCont = 0; iCont < 3; iCont++){
        printf("%c  |", letras[iCont]);
        for(jCont = 0; jCont < 3; jCont++){
            switch (tabuleiro.tabuleiro[iCont][jCont])
            {
            case 1: 
                printf(" X |");
                break;
            case 2:
                printf(" O |");
                break;
            default:
                printf("   |");
            }
        }
        if(iCont != 2){
            printf("\n ------------------\n");
        }
    }
    printf("\n");
}
