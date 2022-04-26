#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* Ejercicio 2 de arreglos y matrices
    Un programa que lee los coeficientes de dos polinomios de grado 5, los presenta en pantalla y luego imprime el resultado de:
    la multiplicación y la suma de ambos polinomios.
   Entradas:
   int arr[i] = lee los coeficientes de dos polinomios de grado 5
   Salidas:
   1. 2 polinomios
   2. Suma
   3. Multiplicacion */


/* Funcion que imprime 1 polinomios de grado 5*/

int imprimir(int pol[], int i) {
    /* Output */
    for (i; i>-1; i--) {
            /* No imprime si el coeficiente es 0 */
            if (pol[i]!=0) {
                    /* Evitar x^0 */
                    if (i != 0) {
                            /* Evitar agregar un exponente a x^1 */
                            if (i!=1) {
                                /* Evitar el 1x^ */
                                if (pol[i]!=1) {
                                    std::cout << pol[i];
                                }
                                std::cout << "x^" << i;
                            }
                            else {
                                std::cout << pol[i] << "x";
                            }

                    }
                    else {
                        std::cout << pol[i];
                        break;
                    }
                    std::cout << " + ";
            }
    }
    return 0;
}

/* Funcion que suma dos polinomios de grado 5*/

int sumas(int pol1[], int pol2[]) {
    int i;
    int resultado[6];
    /* Polinomios de grado 5 */
    int n=6;

    /* Suma */
    for (i=0; i<n; i++){
        resultado[i] = pol1[i] + pol2[i];
    }
    /* Output */
    std::cout << "Suma: ";
    imprimir(resultado, 5);
    return 0;
}

/* Funcion que multiplica dos polinomios de grado 5*/

int multiplicacion(int pol1[], int pol2[]) {
    int i,j;
    int resultado[11];

    /* Inicializar el array del resultado */
   for (int i = 0; i<=10; i++){
     resultado[i] = 0;
   }
    /* Tomar el primer polinomio y sus coeficientes */
    for (i=0; i<6; i++) {
        /* Multiplicar cada coeficiente del primer polinomio por los del segundo */
        for (j=0; j<6; j++) {
            resultado[i+j] += pol1[i]*pol2[j];
            }
    }
    /* Output */
    std::cout << "Multiplicacion: ";
    imprimir(resultado, 10);
   return 0;
}


int main() {
    int pol1[6], pol2[6];
    int i;
    /*Input coeficientes polinomio 1*/
    std::cout << "Ingrese los coeficientes del primer polinomio de grado 0 a 5:";
    for (i = 0; i<6; i++){
        std::cin >> pol1[i];
    }
    /*Input coeficientes polinomio 2*/
    std::cout << "Ingrese los coeficientes del segundo polinomio de grado 0 a 5:";
    for (i = 0; i<6; i++){
        std::cin >> pol2[i];
    }
    std::cout << "Polinomio 1: ";
    imprimir(pol1, 5);
    std::cout << "\nPolinomio 2: ";
    imprimir(pol2, 5);
    std::cout << "\n";

    sumas(pol1, pol2);

    std::cout << "\n";

    multiplicacion(pol1, pol2);

    return 0;
}
