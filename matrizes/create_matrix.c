#include <stdio.h>
#include <stdlib.h>

int main() {
    
    const int n = 8000;


    printf("iniciando...\n");
    double *matrizA = (double *)malloc(n * n * sizeof(double));
    double *matrizB = (double *)malloc(n * n * sizeof(double));

    // inicializar a matriz com alguns valores de exemplo
    printf("gerando valores...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizA[i * n + j] = rand() / (double)RAND_MAX;
            matrizB[i * n + j] = rand() / (double)RAND_MAX;
        }
    }

    // abrir o arquivo para escrita A
    printf("abrindo arquivo...\n");
    FILE *fp = fopen("matrizA_8000.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // escrever a matriz no arquivo A
    printf("escrevendo valores...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%.2f,", matrizA[i * n + j]);
        }
        fprintf(fp, "\n");
    }

    // fechar o arquivo A
    fclose(fp);

        // abrir o arquivo para escrita B
    printf("abrindo arquivo...\n");
    FILE *fp = fopen("matrizB_8000.csv", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // escrever a matriz no arquivo B
    printf("escrevendo valores...\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%.2f,", matrizB[i * n + j]);
        }
        fprintf(fp, "\n");
    }

    // fechar o arquivo B
    fclose(fp);


    printf("Matriz escrita com sucesso no arquivo!\n");

    return 0;
}
