#include <stdio.h>

#define TAM 5

// Função para imprimir uma matriz
void exibir_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Preenche a matriz com padrão de cone
void habilidade_cone(int matriz[TAM][TAM]) {
    // Zera a matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;

    // Aplica o padrão do cone
    matriz[0][2] = 1;

    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;

    for (int j = 0; j < TAM; j++)
        matriz[2][j] = 1;
}

// Preenche a matriz com padrão de cruz
void habilidade_cruz(int matriz[TAM][TAM]) {
    // Zera a matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;

    for (int j = 0; j < TAM; j++)
        matriz[1][j] = 1;

    matriz[0][2] = 1;
    matriz[2][2] = 1;
}

// Preenche a matriz com padrão de octaedro
void habilidade_octaedro(int matriz[TAM][TAM]) {
    // Zera a matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;

    matriz[0][2] = 1;

    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;

    matriz[2][2] = 1;
}

int main() {
    int cone[TAM][TAM], cruz[TAM][TAM], octaedro[TAM][TAM];

    // Preenche padrões
    habilidade_cone(cone);
    habilidade_cruz(cruz);
    habilidade_octaedro(octaedro);

    // Exibe cada habilidade
    printf("Habilidade: Cone\n");
    exibir_matriz(cone);

    printf("\nHabilidade: Cruz\n");
    exibir_matriz(cruz);

    printf("\nHabilidade: Octaedro\n");
    exibir_matriz(octaedro);

    return 0;
}