#include <stdio.h>

int main(){

    int tabuleiro [10][10];
    int navioHorizontal[3] = {3,3,3};
    int navioVertical[3] = {3,3,3};
    
    for (int i = 0; i < 10; i++){
       for (int j = 0; j < 10; j++){
        tabuleiro[i][j] = 0;
       }
       
    }

    // Posição inicial do navio horizontal
    int linhaH = 2;   // linha 3 no tabuleiro
    int colunaH = 4;  // coluna E
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posição inicial do navio vertical
    int linhaV = 5;   // linha 6 no tabuleiro
    int colunaV = 7;  // coluna H
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }
    
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");

    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j); // Letras A até J
    }
    printf("\n");


   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}

    
    return 0;
}