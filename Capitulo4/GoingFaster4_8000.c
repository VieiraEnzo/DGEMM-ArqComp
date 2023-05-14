#include <x86intrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define UNROLL (4)

void dgemm(size_t n, double* A, double* B, double* C)
{
    for(size_t i = 0; i <n; i+= UNROLL * 4)
        for(size_t j = 0; j < n ; j ++){
            __m256d c[4];
            for (int x =0; x < UNROLL; x++)
                c[x] = _mm256_load_pd(C+i+x*4+j*n);
            
            for(int k = 0; k < n ; k ++){
                __m256d b = _mm256_broadcast_sd(B+k+j*n);
                for(int x  =0; x <UNROLL; x++)
                c[x] = _mm256_add_pd(c[x],
                _mm256_mul_pd(_mm256_load_pd(A+n*k+x*4+i),b));
            }

            for(int x  =0 ; x < UNROLL; x++)
            _mm256_store_pd(C+i+x*4+j*n, c[x]);
        }
}

int main() {

    printf("mallocking space\n");
    const int n = 8000;
    double *A = (double*)malloc(n * n * sizeof(double));
    double *B = (double*)malloc(n * n * sizeof(double));
    double *C = (double*)malloc(n * n * sizeof(double));

    // Initialize matrices A and B
    printf("loading matrix\n");
    FILE *Ma = fopen("D:\\ProgGaming\\C\\TrabalhoArq\\matrizes\\matrizA_8000.csv", "r");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(Ma, "%lf,", &A[i+j*n]);
        }
    }
    fclose(Ma);

    FILE *Mb = fopen("D:\\ProgGaming\\C\\TrabalhoArq\\matrizes\\matrizB_8000.csv", "r");
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
    FILE *result = fopen("results_4.csv", "a");
    fprintf(result, "Tempo_teste_O3,%lf\n",elapsed_time);
    fclose(result);

    // Cleanup
    free(A);
    free(B);
    free(C);

    printf("done\n");
    return 0;
}

