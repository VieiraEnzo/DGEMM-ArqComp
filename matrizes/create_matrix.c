#include <stdio.h>
#include <stdlib.h>

int main() {
    
    const int n = 6000;


    printf("iniciando...\n");
    double *matriz = (double *)malloc(n * n * sizeof(double));

    // inicializar a matriz com alguns valores de exemplo
    printf("gerando valores...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i * n + j] = rand() / (double)RAND_MAX;
        }
    }

    // abrir o arquivo para escrita
    printf("abrindo arquivo...\n");
    FILE *fp = fopen("matrizB.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // escrever a matriz no arquivo
    printf("escrevendo valores...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%.2f,", matriz[i * n + j]);
        }
        fprintf(fp, "\n");
    }

    // fechar o arquivo
    fclose(fp);

    printf("Matriz escrita com sucesso no arquivo!\n");

    return 0;
}
