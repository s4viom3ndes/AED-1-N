#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main() {
    int n, i, j;
    clock_t t1, t2;
    double time_taken;

    // Array para armazenar os valores de entrada
    int arr[20000];

    // Loop para testar diferentes tamanhos de entrada
    for (n = 5000; n <= 20000; n += 5000) {
        // Preenchimento do array com números aleatórios
        for (i = 0; i < n; i++) {
            arr[i] = rand();
        }

        // Medição do tempo de execução
        t1 = clock();
        mergeSort(arr, 0, n - 1);
        t2 = clock();

        // Cálculo do tempo de execução em segundos
        time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

        // Impressão dos resultados
        printf("Tamanho de entrada: %d\n", n);
        printf("Tempo de execucao: %f segundos\n\n", time_taken);
    }

    return 0;
}
