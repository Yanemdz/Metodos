#include <stdio.h>

void classi_rap(int datos[], int inf, int sup)
{
    int i, j, tmp, elem_de_divi;
    if (sup > inf) {
        elem_de_divi = datos[sup];  // Elige el pivote
        i = inf - 1;
        j = sup;

        while (1) {
            // Encuentra un elemento mayor que el pivote desde la izquierda
            while (datos[++i] < elem_de_divi);

            // Encuentra un elemento menor que el pivote desde la derecha
            while (j > inf && datos[--j] > elem_de_divi);
            
            if (i >= j) break;

            // Intercambia los elementos
            tmp = datos[i];
            datos[i] = datos[j];
            datos[j] = tmp;
        }
        
        // Intercambia el pivote con el elemento en la posición i
        tmp = datos[i];
        datos[i] = datos[sup];
        datos[sup] = tmp;

        // Llamada recursiva para ordenar las dos mitades
        classi_rap(datos, inf, i - 1);
        classi_rap(datos, i + 1, sup);
    }
}

void imprimeArreglo(int datos[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");
}

int main() {
    int datos[] = {38, 27, 43, 3, 9, 82, 10};
    int tam = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo original:\n");
    imprimeArreglo(datos, tam);

    // Llamada a la función Quick Sort
    classi_rap(datos, 0, tam - 1);

    printf("Arreglo ordenado:\n");
    imprimeArreglo(datos, tam);

    return 0;
}
