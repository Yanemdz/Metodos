#include <stdio.h>

void combina(int destino[], int fuente[], int inf, int mitad, int sup) {
    int i_inf, i_sup, i_destino;
    i_inf = i_destino = inf;
    i_sup = mitad + 1;

    while (i_inf <= mitad && i_sup <= sup) {
        if (fuente[i_inf] < fuente[i_sup]) {
            destino[i_destino++] = fuente[i_inf++];
        } else {
            destino[i_destino++] = fuente[i_sup++];
        }
    }

    while (i_inf <= mitad)
        destino[i_destino++] = fuente[i_inf++];

    while (i_sup <= sup)
        destino[i_destino++] = fuente[i_sup++];
}

void mergeSort(int arreglo[], int temp[], int inf, int sup) {
    if (inf < sup) {
        int mitad = (inf + sup) / 2;

        // Llama recursivamente para dividir el arreglo en mitades
        mergeSort(arreglo, temp, inf, mitad);
        mergeSort(arreglo, temp, mitad + 1, sup);

        // Combina las mitades ordenadas
        combina(temp, arreglo, inf, mitad, sup);

        // Copia los elementos ordenados de nuevo al arreglo original
        for (int i = inf; i <= sup; i++) {
            arreglo[i] = temp[i];
        }
    }
}

void imprimeArreglo(int arreglo[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    int arreglo[] = {38, 27, 43, 3, 9, 82, 10};
    int tam = sizeof(arreglo) / sizeof(arreglo[0]);
    int temp[tam];  // Arreglo temporal para combinar

    printf("Arreglo original:\n");
    imprimeArreglo(arreglo, tam);

    // Ordena el arreglo con Merge Sort
    mergeSort(arreglo, temp, 0, tam - 1);

    printf("Arreglo ordenado:\n");
    imprimeArreglo(arreglo, tam);

    return 0;
}
