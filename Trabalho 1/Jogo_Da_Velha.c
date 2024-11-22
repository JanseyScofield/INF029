#include "Jogo_Da_Velha.h"

void limparBuffer(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    
}

void inicializarTabuleiro(Tabuleiro *tabuleiro){
    int iCont, jCont;

    for(iCont = 0; iCont  < 3; iCont++){
        for(jCont = 0; jCont < 3; jCont++){
            tabuleiro->tabuleiro[iCont][jCont] = 0;
        }
    }

    tabuleiro->rodada = 1;
}

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

    condicaoD = tabuleiro.tabuleiro[0][2] == jogador && tabuleiro.tabuleiro[1][1] == jogador && tabuleiro.tabuleiro[2][0] == jogador;

    return condicaoD;
    
}

void realizarJogada(Tabuleiro *tabuleiro, int jogador){
    char casa[3];
    char letras[] = {'A', 'B', 'C'};
    char numeros[]  = {'1', '2', '3'};
    int iCont;
    int posicaoLetra = -1, posicaoNumero  = -1;

    while(1){
        printf("Digite a casa que deseja jogar: ");
        fgets(casa,3,stdin);
        
        for(iCont = 0; iCont < 3; iCont++){
            if(letras[iCont] == casa[0]){
                posicaoLetra  = iCont;
            }
        }

        for(iCont = 0; iCont < 3; iCont++){
            if(numeros[iCont] == casa[1]){
                posicaoNumero  = iCont;
            }
        }

        if(posicaoLetra == -1 || posicaoNumero == -1){
            printf("Casa invalida. Digite novamente.\n");
        }
        else{
            if(tabuleiro->tabuleiro[posicaoLetra][posicaoNumero] != 0){
                printf("Essa casa ja esta preenchida, digite outra.\n");
            }
            else{
                tabuleiro->tabuleiro[posicaoLetra][posicaoNumero] = jogador;
                break;
            }
        }
    }

}

void jogoDaVelha(){
    Tabuleiro tabuleiro;
    inicializarTabuleiro(&tabuleiro);
    int vitoria = 0;
    int jogadorRodada;

    while(vitoria == 0){
        jogadorRodada = tabuleiro.rodada % 2 == 0? 2 : 1;
        printf("Jogador %d: \n", jogadorRodada);
        printarTabuleiro(tabuleiro);
        realizarJogada(&tabuleiro, jogadorRodada);
        vitoria = checarVitoria(tabuleiro, jogadorRodada);
        tabuleiro.rodada++;
        if(tabuleiro.rodada == 9){
            break;
        }
        limparBuffer();
    }

    printf("\n");
    printarTabuleiro(tabuleiro);

    if(vitoria == 0){
        printf("Empate!\n");
    }
    else{
        printf("Jogador %d venceu!\n", jogadorRodada);
    }
}


int main(){
    jogoDaVelha();
    return 1;
}
