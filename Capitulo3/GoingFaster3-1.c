#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void dgemm(size_t n, double* A, double* B, double* C)
{
    for(size_t i = 0; i <n; i ++)
        for(size_t j = 0; j < n ; j ++){
            double cij = C[i+j*n]; /*cij = C[i][j]*/
            for (size_t k = 0; k < n; k++)
                cij += A[i+k*n] * B[k+j*n]; /*cij = A[i][k] * B[k][j]*/
            C[i+j*n] = cij; /*C[i][j] = cij*/ 
        }
}


int main() {

    printf("mallocking space\n");
    const int n = 6000;
    double *A = (double*)malloc(n * n * sizeof(double));
    double *B = (double*)malloc(n * n * sizeof(double));
    double *C = (double*)malloc(n * n * sizeof(double));

    // Initialize matrices A and B
    printf("loading matrix\n");
    FILE *Ma = fopen("D:\\ProgGaming\\C\\TrabalhoArq\\matrizes\\matrizA.csv", "r");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(Ma, "%lf,", &A[i+j*n]);
        }
    }
    fclose(Ma);

    FILE *Mb = fopen("D:\\ProgGaming\\C\\TrabalhoArq\\matrizes\\matrizB.csv", "r");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(Mb, "%lf,", &B[i+j*n]);
        }
    }

    fclose(Mb);


    printf("running problem\n");
    clock_t start_time = clock();
    dgemm(n, A, B, C);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.4f seconds\n", elapsed_time);

    printf("writhing results space\n");
    FILE *result = fopen("results_3-1.csv", "a");
    fprintf(result, "Tempo_teste_1,%lf\n",elapsed_time);
    fclose(result);

    // Cleanup
    free(A);
    free(B);
    free(C);

    printf("done\n");
    return 0;
}
