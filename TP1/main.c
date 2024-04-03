#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int GenerarAleatorio();
void MostrarMayorYMenor(int, int, int);
int SumarEnterosPositivos(int);
void MostrarTablaDeMultiplicacion(int);
int Sumar(int, int);
int Restar(int, int);
int Multiplicar(int, int);
float Dividir(int, int);
void InvertirSigno(int*);
void AsignarValoresPorReferencia(int*, int*);
void IntercambiarSinAuxiliar(int *num1, int *num2);

int main()
{
    srand(time(NULL));

//    // Ejercicio 1
//    int aleatorio = GenerarAleatorio();
//    printf("%d", aleatorio);


//    // Ejercicio 2
//    int num1 = -1;
//    int num2 = 10;
//    int num3 = 8;
//    MostrarMayorYMenor(num1, num2, num3);

    // Ejercicio 3
//    int entrada = 0;
//    printf("Ingrese un numero: ");
//    scanf("%d", &entrada);
//    int sumatoria = SumarEnterosPositivos(entrada);
//    printf("La sumatoria de numeros menores a %d es %d.\n", entrada, sumatoria);

    // Ejercicio 4
//    int entrada = 0;
//    printf("Ingrese un numero para calcular su tabla de multiplicacion: ");
//    scanf("%d", &entrada);
//    MostrarTablaDeMultiplicacion(entrada);

//    // Ejercicio 5
//    int num1 = 2;
//    int num2 = 5;
//    printf("%d + %d = %d\n", num1, num2, Sumar(num1, num2));
//    printf("%d - %d = %d\n", num1, num2, Restar(num1, num2));
//    printf("%d * %d = %d\n", num1, num2, Multiplicar(num1, num2));
//    printf("%d / %d = %f\n", num1, num2, Dividir(num1, num2));

//    // Ejercicio 6
//    int numero = 5;
//    InvertirSigno(&numero);
//    printf("El numero invertido es %d.\n", numero);

//    // Ejercicio 7
//    int num1 = 0;
//    int num2 = 0;
//    AsignarValoresPorReferencia(&num1, &num2);
//    printf("Los valores asignados son %d y %d.\n", num1, num2);

    // Intercambio sin auxiliar

    int a = 5;
    int b = 3;
    IntercambiarSinAuxiliar(&a, &b);
    printf("a = %d ; b = %d", a, b);
    return 0;
}

void IntercambiarSinAuxiliar(int *num1, int *num2){
    *num1 = *num1 + *num2; // a = 8 ; b = 3
    *num2 = *num1 - *num2; // a = 8 ; b = 5
    *num1 = *num1 - *num2; // a = 3 ; b = 5
}

int GenerarAleatorio(){
    return rand()%101;
}

void MostrarMayorYMenor(int num1, int num2, int num3){
    int mayor = num1;
    int menor = num1;
    if(num2 > mayor){
        mayor = num2;
    }
    if(num2 < menor){
        menor = num2;
    }
    if(num3 > mayor){
        mayor = num3;
    }
    if(num3 < menor){
        menor = num3;
    }
    printf("El mayor numero ingresado es %d\n", mayor);
    printf("El menor numero ingresado es %d\n", menor);
    return;
}

int SumarEnterosPositivos(int numero){
    int sumatoria = 0;
    for(int i = 1; i <= numero; i++){
        sumatoria += i;
    }
    return sumatoria;
}

void MostrarTablaDeMultiplicacion(int numero){
    for(int i = 0; i <= 10; i++){
        printf("%d * %d = %d\n", numero, i, numero * i);
    }
}

int Sumar(int num1, int num2){
    return num1 + num2;
}

int Restar(int num1, int num2){
    return num1 - num2;
}

int Multiplicar(int num1, int num2){
    return num1 * num2;
}

float Dividir(int num1, int num2){
    return (float)num1 / num2;
}

void InvertirSigno(int *num){
    return *num *= -1;
}

void AsignarValoresPorReferencia(int *num1, int *num2){
    printf("Ingrese un valor para asignar al primer numero: ");
    scanf("%d", num1);
    printf("Ingrese un valor para asignar al segundo numero: ");
    scanf("%d", num2);
}
