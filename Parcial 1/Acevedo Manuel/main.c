#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void mostrarPila(Pila *p);
void cargarValoresManual(Pila *p, char mensaje[]);
int contarElementosEnPila(Pila *p);
int sumarElementosEnPila(Pila *p);
float promediarElementosEnPila(Pila *p);
int insertarDatoEnArregloOrdenado(int a[], int v, int dim, int numero);
int pasarDePilaAArreglo(Pila *p, int a[], float promedio);


const int DIM = 50;

int main()
{
    int arregloEnteros [DIM];
    int validos;

    char mensaje [] = "Ingrese un valor (rango 1-100): ";

    Pila valores;
    inicpila(&valores);

    int cantidadElementosEnPila;
    int sumaElementosEnPila;
    float promedioElementosEnPila;
    int elementoABuscar;
    int posicionElemento;

    cargarValoresManual(&valores, mensaje);
    puts("Pila valores luego de cargar: ");
    mostrarPila(&valores);

    cantidadElementosEnPila = contarElementosEnPila(&valores);
    printf("Hay %d elementos en la pila.\n\n", cantidadElementosEnPila);

    sumaElementosEnPila = sumarElementosEnPila(&valores);
    printf("La suma de los elementos en la pila es de %d.\n\n", sumaElementosEnPila);

    promedioElementosEnPila = promediarElementosEnPila(&valores);
    printf("El promedio de los elementos en la pila es de %.2f.\n\n", promedioElementosEnPila);

    validos = pasarDePilaAArreglo(&valores, arregloEnteros, promedioElementosEnPila);
    printf("Fueron cargados %d valores.\n\n", validos);

    printf("Arreglo cargado de manera ordenada: ");
    mostrarArregloEnteros(arregloEnteros, validos);

    // El elemento a buscar puede ser pasado por parametro.
    // Lo carga el usuario y luego se pasa a la funcion.
    printf("Ingrese un elemento a buscar: ");
    scanf("%d", &elementoABuscar);
    posicionElemento = buscarElementoEnArreglo(arregloEnteros, validos, elementoABuscar);

    printf("\n\n");

    if(posicionElemento == -1){
        printf("El elemento ingresado no existe en el arreglo.");
    }
    else{
        printf("El elemento ingresado se encuentra en la posicion %d.", posicionElemento);
    }

    return 0;
}

void mostrarArregloEnteros(int a[], int v){
    for(int i = 0; i < v; i++){
        if(i % 10 == 0){
            printf("\n");
        }
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

int buscarElementoEnArreglo(int a[], int v, int elemento){
    // Inciso 8

    // Si hay multiples repeticiones del mismo dato,
    // devuelve la posicion de la primera vez que el dato aparece en el arreglo.
    int encontrado = 0;
    int posicion = -1;

    // Se puede comprobar si fue encontrado tanto con un for como con un while.
    // En el inciso 6 uso una flag en un while para salir del bucle.
    // Este ejercicio lo resolvi con for loop.
    for(int i = 0; i < v && encontrado == 0; i++){
        if(a[i] == elemento){
            posicion = i;
            encontrado = 1;
        }
    }

    return posicion;
}

int pasarDePilaAArreglo(Pila *p, int a[], float promedio){
    // Inciso 7

    Pila aux;
    inicpila(&aux);

    // Se asume que el arreglo a cargar esta vacio.
    // La consigna dice que los parametros necesarios son una pila, un arreglo y el promedio.
    // Para cargar un arreglo con datos preexistentes, se necesitarian los validos del mismo.
    int validos = 0;

    while(!pilavacia(p)){
        if(tope(p) > promedio){
            validos = insertarDatoEnArregloOrdenado(a, validos, DIM, tope(p));
        }
        apilar(&aux, desapilar(p));
    }

    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }

    return validos;
}

int insertarDatoEnArregloOrdenado(int a[], int v, int dim, int numero){
    // Inciso 6
    int insertado = 0; // Bandera para cortar el ciclo si se inserto el dato.
    int i = v - 1;
    int validos = v;

    if(v >= dim){
        printf("No hay espacio para insertar datos!");
    }
    else if(v == 0){
        // El arreglo no tiene ningun valor cargado.
        // Insertar en el primer indice.
        a[0] = numero;
        validos = 1;
    }
    else{
        while(i >= 0 && insertado == 0){
            if(a[i] > numero){
                a[i + 1] = a[i];
                i--;
            }
            else{
                a[i + 1] = numero;
                insertado = 1;
            }
        }

        if(insertado == 0){
            // Se recorrio todo el arreglo y no se pudo insertar.
            // El numero es menor a todos los elementos del arreglo.
            // Insertar al principio.
            a[0] = numero;
        }
        validos++;
    }

    return validos;
}

float promediarElementosEnPila(Pila *p){
    // Inciso 5

    int suma, cantidad;

    suma = sumarElementosEnPila(p);
    cantidad = contarElementosEnPila(p);

    return (float) suma / cantidad;
}

int sumarElementosEnPila(Pila *p){
    // Inciso 4

    Pila aux;
    inicpila(&aux);

    int suma = 0;

    while(!pilavacia(p)){
        suma += tope(p);
        apilar(&aux, desapilar(p));
    }

    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }

    return suma;
}

int contarElementosEnPila(Pila *p){
    // Inciso 3

    Pila aux;
    inicpila(&aux);

    int cantidadElementos = 0;

    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
        cantidadElementos++;
    }

    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }

    return cantidadElementos;
}

void cargarValoresManual(Pila *p, char mensaje[]){
    // Inciso 1

    char opcion = 's';
    int valor;
    int cargados = 0;

    do{
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &valor);

        if(valor <= 0 || valor > 100){
            system("cls");
            printf("ERROR! Fuera de rango!\n");
        }
        else{
            apilar(p, valor);
            cargados++;
            printf("Presione ESC para finalizar la carga o una tecla cualquiera para continuar: ");
            opcion = getch();
            system("cls");
        }
    }while(opcion != 27 && cargados <= 50);
}

void mostrarPila(Pila *p){
    // Inciso 2

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p)){
        printf("%d | ", tope(p));
        apilar(&aux, desapilar(p));
    }

    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }

    printf("\n\n");
}
