#include <x86intrin.h>
//#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(size_t *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void dgemm(size_t *array, size_t n, double* A, double* B, double* C)
{
    for(int i = 0; i <2000; i++)
        for(size_t j = 0; j < n ; j ++){
            __m256d c0 = _mm256_load_pd(C+array[i]+j*n); /* c0 = C[i][j]*/
            for(size_t k = 0; k < n; k++)
                c0 = _mm256_add_pd(c0, /* c0 += A[i][k] * B[k][j] */
                _mm256_mul_pd(_mm256_load_pd(A+array[i]+k*n),
                _mm256_broadcast_sd(B+k+j*n)));
            _mm256_store_pd(C+array[i]+j*n,c0); /* C[i][j] = c0*/
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

    srand(time(NULL));

    printf("Creating and shuffelling array\n");
    size_t arr[2000];
    int b = 0;
    for(size_t i =0; i < 8000; i+=4){
        arr[b] = i;
        b++;
    }
    shuffle(arr,2000);

    printf("running problem\n");
    clock_t start_time = clock();
    dgemm(arr,n, A, B, C);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.4f seconds\n", elapsed_time);

    printf("writhing results space\n");
    FILE *result = fopen("results_3-2_NoLocality.csv", "a");
    fprintf(result, "Tempo_teste_1,%lf\n",elapsed_time);
    fclose(result);

    // Cleanup
    free(A);
    free(B);
    free(C);

    printf("done\n");
    return 0;
}

