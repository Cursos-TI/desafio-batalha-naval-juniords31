#include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro
#define TAM_NAVIO 3     // Tamanho fixo dos navios
#define AGUA 0
#define NAVIO 3

// Função para verificar se há espaço e se não há sobreposição
int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * dx;
        int c = coluna + i * dy;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != AGUA) {
            return 0; // Fora dos limites ou sobreposição
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * dx;
        int c = coluna + i * dy;
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa tudo com água (0)

    // Define os navios: linha, coluna, dx, dy
    int navios[4][4] = {
        {1, 1, 0, 1},  // Horizontal
        {3, 4, 1, 0},  // Vertical
        {0, 0, 1, 1},  // Diagonal principal
        {0, 9, 1, -1}  // Diagonal secundária
    };

    // Tenta posicionar cada navio
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int dx = navios[i][2];
        int dy = navios[i][3];

        if (pode_posicionar(tabuleiro, linha, coluna, dx, dy)) {
            posicionar_navio(tabuleiro, linha, coluna, dx, dy);
        } else {
            printf("Erro ao posicionar navio %d: posicao invalida ou sobreposicao.\n", i + 1);
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
