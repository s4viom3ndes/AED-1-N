#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
        heapSort(arr, n);
        t2 = clock();

        // Cálculo do tempo de execução em segundos
        time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

        // Impressão dos resultados
        printf("Tamanho de entrada: %d\n", n);
        printf("Tempo de execucao: %f segundos\n\n", time_taken);
    }

    return 0;
}
