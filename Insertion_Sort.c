#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        insertionSort(arr, n);
        t2 = clock();

        // Cálculo do tempo de execução em segundos
        time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

        // Impressão dos resultados
        printf("Tamanho de entrada: %d\n", n);
        printf("Tempo de execucao: %f segundos\n\n", time_taken);
    }

    return 0;
}
