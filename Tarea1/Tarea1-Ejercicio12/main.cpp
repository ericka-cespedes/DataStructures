#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/* Function to determine repeating numbers */
void repetidos(int arr[], int arr_size){
    /* Variable declaration */
  int i, j;
  std::cout << "Repetidos: ";
  std::cout << "\n";

  for(i = 0; i < arr_size; i++){
        /* Pick elements one by one */
    for(j = i+1; j < arr_size; j++){
        /* Count number of occurrences of the picked element */
      if(arr[i] == arr[j]){
        std::cout << arr[i];
        std::cout << "\n";
      }
    }
  }
}

/* Function main begins program execution */
int randomNumber(int n) {
    /*Variable declaration*/
    int numero;
    int resultado[365]; /* Output */

    /*Random Number */
    srand(time(NULL)); /* Different numbers each time */
    /* Loops n times */
    for (int i = 1; i <= n; i++) {
        /* Random number from 1 to 365 (365 days) */
        numero = 1 + (rand() % 365);
        /* Each random number is saved to compare later */
        resultado[i-1] = 0+numero;
        std::cout << resultado[i-1];
        std::cout << "\n";
    }
    repetidos(resultado, n);
    return 0;
}

/* Execute 10 experiments per n; n=5, 10, 15, 20, …, 100. Output how many had repeated dates */
/* Function main begins program execution */
int main(void) {

    /* Results */
    std::cout << "Resultados";
    std::cout << "\n";
    std::cout << "n = 5,10,15 \n";
    std::cout << "Para los 10 experimentos: No hay repetidos \n";
    std::cout << "n = 20 \n";
    std::cout << "Experimentos 2,3,4,5,6 con numeros repetidos \n";
    std::cout << "5/10 experimentos \n";
    std::cout << "n = 25 \n";
    std::cout << "Experimentos 3,4,6,7,8,9,10 con numeros repetidos \n";
    std::cout << "7/10 experimentos \n";
    std::cout << "n = 30 \n";
    std::cout << "Experimentos 2,3,4,7,8,9 con numeros repetidos \n";
    std::cout << "6/10 experimentos \n";
    std::cout << "n = 35 \n";
    std::cout << "Experimentos 2,3,4,5,6,7,8,9,10 con numeros repetidos \n";
    std::cout << "9/10 experimentos \n";
    std::cout << "n = 40 \n";
    std::cout << "Experimentos 2,4,5,6,7,8,9,10 con numeros repetidos \n";
    std::cout << "8/10 experimentos \n";
    std::cout << "n = 45 \n";
    std::cout << "Experimentos 1,3,4,5,6,7,8,9,10 con numeros repetidos \n";
    std::cout << "9/10 experimentos \n";
    std::cout << "n = 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 \n";
    std::cout << "Todos los experimentos con numeros repetidos \n";
    std::cout << "10/10 experimentos \n\n";
    std::cout << "Conclusiones \n";
    std::cout << "Conforme se aumentaba n, aumentaba tanto los experimentos en los cuales se repetian los numeros y la cantidad de numeros repetidos \n";
    std::cout << "Los numeros se empezaron a repetir desde n=20. \n";
    std::cout << "De n=20 a 25 se repetian de 1 a 2 numeros. \n";
    std::cout << "Luego de n=30 se empezaban a repetir 4 numeros. \n";
    std::cout << "Luego de n=50 todos los numeros eran repetidos. \n";
    std::cout << "En n=20 5/10 experimentos tuvieron numeros repetidos. \n";
    std::cout << "En n=25 7/10 experimentos tuvieron numeros repetidos. \n";
    std::cout << "Se puede decir que la paradoja del cumpleanos es correcta. \n";
    std::cout << "Existe una probabilidad del 50% de que al menos dos personas cumplan anos el mismo dia si hay al menos 23 personas reunidas. \n\n";
    std::cout << "Intente el experimento usted mismo: \n\n";
    /*Input n*/
    int n;
    std::cout << "Ingrese n: ";
    std::cin >> n;
    randomNumber(n);
    /* Se intento automatizar el resultado pero quedaba en un loop infinito
    for (int n = 5; n<= 100; n+5) {
            for (int i=1; i<=10; i++) {
                std::cout << i, n;
                randomNumber(n);
            }
    }*/
    return 0;
}
