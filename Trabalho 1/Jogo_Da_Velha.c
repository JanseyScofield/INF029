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

int checarVitoria(Tabuleiro tabuleiro, int jogador){
    int condicaoA, condicaoB, condicaoC, condicaoD;
    int iCont, jCont;

     condicaoB = condicaoC = 0;

    for(iCont = 0; iCont < 3; iCont++){
        condicaoA = 0;
        for(jCont = 0; jCont < 3; jCont++){
            if(tabuleiro.tabuleiro[iCont][jCont] == jogador){
                condicaoA++;
            }
            else{
                break;
            }
        }
        if(condicaoA == 3) return 1;
    }

    for(iCont = 0; iCont < 3; iCont++){
        condicaoB = 0;
        for(jCont = 0; jCont < 3; jCont++){
            if(tabuleiro.tabuleiro[jCont][iCont] == jogador){
                condicaoB++;
            }
            else{
                break;
            }
        }
        if(condicaoB == 3) return 1;
    }

    condicaoC = 0;
    
    for(iCont = 0; iCont < 3; iCont++){
        if(tabuleiro.tabuleiro[iCont][iCont]  == jogador){
            condicaoC++;
        }
        if(condicaoC == 3) return 1;
    }

    condicaoD = tabuleiro.tabuleiro[2][2] == jogador && tabuleiro.tabuleiro[1][1] == jogador && tabuleiro.tabuleiro[2][0] == jogador;

    return condicaoD;
    
}
