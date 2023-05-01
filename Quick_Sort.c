#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        quickSort(arr, 0, n - 1);
        t2 = clock();

        // Cálculo do tempo de execução em segundos
        time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

        // Impressão dos resultados
        printf("Tamanho de entrada: %d\n", n);
        printf("Tempo de execucao: %f segundos\n\n", time_taken);
    }

    return 0;
}
