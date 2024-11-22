#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tabuleiro[3][3];
    int rodada;
}Tabuleiro;

void printarTabuleiro(Tabuleiro tabuleiro);
void realizarJogada(Tabuleiro *tabuleiro, int jogador);
int checarVitoria(Tabuleiro tabuleiro, int jogador);
void jogoDaVelha();
void limparBuffer();
