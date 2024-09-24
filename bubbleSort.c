#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Ingrese el numero de elementos a generar: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El numero de elementos debe ser mayor a 0.\n");
        return 1;
    }

    int arr[n];

    srand(time(0));

    // Generar números aleatorios y llenar el arreglo
    printf("Numeros generados:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Generar números aleatorios entre 0 y 999
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}