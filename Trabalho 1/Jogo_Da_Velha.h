#include <stdio.h>

typedef struct
{
    int tabuleiro[3][3];
    int rodada;
}Tabuleiro;

void printarTabuleiro(Tabuleiro tabuleiro);
int checarVitoria(Tabuleiro tabuleiro, int jogador);
void jogoDaVelha();
