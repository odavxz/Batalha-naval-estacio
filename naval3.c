#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int linha, int coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = linha + i - 2; // Centraliza a habilidade
            int y = coluna + j - 2;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM && habilidade[i][j] == 1) {
                tabuleiro[x][y] = HABILIDADE; // Marca a área afetada
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com 0 (água)

    // Posiciona navios
    tabuleiro[2][2] = NAVIO; // Navio horizontal
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[5][5] = NAVIO; // Navio vertical
    tabuleiro[6][5] = NAVIO;
    tabuleiro[7][5] = NAVIO;

    // Matrizes de habilidades
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 1);      // Cone na posição (1, 1)
    aplicarHabilidade(tabuleiro, cruz, 4, 4);     // Cruz na posição (4, 4)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7); // Octaedro na posição (7, 7)

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}