#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

/* Ejercicio 3 de arreglos y matrices
   El programa lee números dinámicamente y calcula las estadísticas de frecuencias.
   Entradas:
   int n = cantidad de números que van a ser procesados.
   int arr[i] = leer del teclado los números y almacenarlos en un arreglo creado dinámicamente del tamaño que indicó el usuario.
   Salidas:
   a. Frecuencia absoluta de cada número: número de veces que aparece el número en la serie.
   b. Frecuencia absoluta acumulada: número de veces que aparecen los valores menores o iguales a cada valor en la serie.
   c. Frecuencia relativa acumulada: es la frecuencia absoluta acumulada dividida entre N.


/* Funcion para las frecuencias absolutas, absolutas acumuladas y relativas acumuladas
   Nota importante: La funcion esta prevista para un array ordenado.
   En la funcion main, luego de ingresar los elementos del array, se ordena antes de llama a frencuencias()
   Por lo tanto, si no estuviera ordenado, solo daria las frecuencias absolutas bien.*/
int frecuencias(int arr[], int freq[], int acum[], int n) {
    int i,j,frecuencia, total;
    total = 0;
    /* Busca repeticiones y cuenta la frecuencia de cada numero */
    for (i=0; i<n; i++){
        frecuencia = 1;
        for (j=i+1; j<n; j++) {
            if (arr[i] == arr[j]) {
                frecuencia++;
                freq[j] = 0;
                acum[j] = 0;
            }
        }
        /* Ingresa en el arreglo freq, las frecuencias
           Suma cada frecuencia absoluta a la frecuencia absoluta total
           Ingresa al arreglo acum la frecuencia absoluta acumulada */
        if (freq[i]!=0) {
            total += frecuencia;
            freq[i] = frecuencia;
            acum[i] = total;
        }
    }
    /* Output */
    std::cout << "Frecuencia absoluta de cada numero \n";
    for (i=0; i<n; i++) {
            if (freq[i]!=0) {
                std::cout << "\nNumero ";
                std::cout << arr[i];
                std::cout << "\n Frecuencia absoluta ";
                std::cout << freq[i];
                std::cout << "\n Frecuencia absoluta acumulada ";
                std::cout << acum[i];
                std::cout << "\n Frecuencia relativa acumulada ";
                std::cout << float (float (acum[i])/ float(total)); /*Resultado mas preciso con decimales */
            }
    }
    std::cout << "\n\nFrecuencia absoluta total ";
    std::cout << total;
    return 0;
}

/* Function main begins program execution */
int main(void) {
    int arr[1000], freq[1000], acum[1000];
    int n,i;
    /*Input n*/
    std::cout << "Ingrese el tamano del array:";
    std::cin >> n;
    /*Input elementos del array*/
    std::cout << "Ingrese los elementos del array:";
    for (i = 0; i<n; i++){
        std::cin >> arr[i];
        freq[i] = -1;
        acum[i] = -1;
    }
    /* Ordena el array */
    std::sort(arr, arr + n);

    frecuencias(arr, freq, acum, n);

    return 0;
}
