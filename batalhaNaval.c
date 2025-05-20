#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração do tabuleiro e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha e coluna)
    int linhaNavioH = 2, colunaNavioH = 1; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 4; // Navio vertical

    // Verificação se o navio horizontal cabe no tabuleiro
    if (colunaNavioH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verificação de sobreposição antes de posicionar o navio horizontal
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioH][colunaNavioH + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioH][colunaNavioH + i] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposicao detectada no navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Verificação se o navio vertical cabe no tabuleiro
    if (linhaNavioV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verificação de sobreposição antes de posicionar o navio vertical
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioV + i][colunaNavioV] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposicao detectada no navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro:\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}