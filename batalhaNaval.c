#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro (10x10)
#define NAVIO 3    // Tamanho fixo dos navios
#define MAR 0      // Representa água
#define NAV 3      // Representa navio

// Função para verificar se é possível posicionar o navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;

        // Verifica se está dentro dos limites
        if (novaLinha < 0 || novaLinha >= TAM || novaColuna < 0 || novaColuna >= TAM) {
            return 0; // não pode
        }

        // Verifica sobreposição
        if (tabuleiro[novaLinha][novaColuna] != MAR) {
            return 0; // não pode
        }
    }
    return 1; // pode
}

// Função para posicionar navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        tabuleiro[novaLinha][novaColuna] = NAV;
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = MAR;
        }
    }

    // ---- POSICIONAR 4 NAVIOS ----
    // 1º navio horizontal (linha fixa, coluna crescente)
    if (podePosicionar(tabuleiro, 2, 4, 0, 1)) { 
        posicionarNavio(tabuleiro, 2, 4, 0, 1);
    }

    // 2º navio vertical (coluna fixa, linha crescente)
    if (podePosicionar(tabuleiro, 5, 7, 1, 0)) { 
        posicionarNavio(tabuleiro, 5, 7, 1, 0);
    }

    // 3º navio diagonal ↘
    if (podePosicionar(tabuleiro, 0, 0, 1, 1)) {
        posicionarNavio(tabuleiro, 0, 0, 1, 1);
    }

    // 4º navio diagonal ↙
    if (podePosicionar(tabuleiro, 0, 9, 1, -1)) {
        posicionarNavio(tabuleiro, 0, 9, 1, -1);
    }

    // ---- EXIBIR TABULEIRO ----
    printf("\n     ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
