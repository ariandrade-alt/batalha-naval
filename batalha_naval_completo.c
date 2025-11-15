#include <stdio.h>
#include <stdlib.h>

#define TAM 10        // tamanho do tabuleiro
#define NAVIO_TAM 3   // tamanho dos navios
#define HAB 7         // tamanho das matrizes de habilidade

//-------------------------------------
// FUNÇÕES PARA CRIAR AS HABILIDADES
//-------------------------------------

void criarCone(int cone[HAB][HAB]) {
    int meio = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= meio - i && j <= meio + i && i <= meio)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

void criarCruz(int cruz[HAB][HAB]) {
    int meio = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

void criarOctaedro(int oct[HAB][HAB]) {
    int meio = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

//-------------------------------------
// FUNÇÃO PARA APLICAR HABILIDADE NO TABULEIRO
//-------------------------------------

void aplicarHabilidade(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {
    int desloc = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (hab[i][j] == 1) {

                int linha = origemL + (i - desloc);
                int coluna = origemC + (j - desloc);

                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {

                    if (tab[linha][coluna] == 0) 
                        tab[linha][coluna] = 5;
                }
            }
        }
    }
}

//-------------------------------------
// FUNÇÃO PARA IMPRIMIR O TABULEIRO
//-------------------------------------
void mostrarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

//-------------------------------------
// PROGRAMA PRINCIPAL
//-------------------------------------
int main() {

    int tabuleiro[TAM][TAM];

    // =============================
    // NÍVEL 1 – Criar tabuleiro e 2 navios
    // =============================
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // navio horizontal
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[2][3 + i] = 3;

    // navio vertical
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[5 + i][7] = 3;

    // =============================
    // NÍVEL 2 – 2 navios diagonais
    // =============================

    // diagonal principal ↘
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[0 + i][0 + i] = 3;

    // diagonal secundária ↙
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[0 + i][9 - i] = 3;

    // =============================
    // NÍVEL 3 – Criar habilidades
    // =============================
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int oct[HAB][HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    // =============================
    // Aplicar habilidades (origens)
    // Você pode mudar os pontos abaixo:
    // =============================
    aplicarHabilidade(tabuleiro, cone, 1, 5);   // origem do cone
    aplicarHabilidade(tabuleiro, cruz, 5, 5);   // origem da cruz
    aplicarHabilidade(tabuleiro, oct, 8, 3);    // origem do octaedro

    // =============================
    // Mostrar tabuleiro final
    // =============================
    printf("\n======= TABULEIRO FINAL =======\n\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}
