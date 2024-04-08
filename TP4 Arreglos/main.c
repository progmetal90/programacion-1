#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int menu();
int cargarArreglo(int arreglo[], int dim);
int cargarArregloRandomEnteros(int arreglo[], int dim, int cantidadACargar);
void mostrarArreglo(int arreglo[], int validos);
void mostrarArregloCaracteres(char arreglo[], int validos);
int sumarElementosEnteros(int arreglo[], int dim);
void cargarArregloEnPila(int arreglo[], int dim, Pila *destino);
int cargarArregloRandomReales(float arreglo[], int dim, int cantidadACargar);
float sumarElementosReales(float arreglo[], int dim);
int existeElemento(char caracter, char arreglo[], int dim);
int insertarCaracterEnArregloOrdenado(char caracter, char arreglo[], int dim, int validos);
char maximoCaracter(char arreglo[], int validos);
int arregloEsCapicua(char arreglo[], int validos);
void invertirPosiciones(int arreglo[], int validos);
void ordenarPorSeleccion(int enteros[], int validos);
void ordenarPorInsercion(char caracteres[], int validos);
int intercalarCaracteres(char arreglo1[], int validos1, char arreglo2[], int validos2, char intercalados[]);

const int cantidadEjercicios = 14;

const int dimensionEnteros = 10;
const int dimensionReales = 100;
const int dimensionCaracteres = 10;
const int dimensionCaracteres2 = 6;
const int dimensionCaracteresIntercalados = 12;
const int dimensionTexto = 13;

int main()
{
    srand(time(NULL));

    Pila destino;
    inicpila(&destino);

    int enteros [dimensionEnteros];
    int validosEnteros;

    float reales [dimensionReales];
    int validosReales;

    char caracteresOrdenados [] = {'A', 'C', 'a', 'b', 'c', 'e', 'f', 0, 0, 0};
    int validosCaracteres = 7;
    char caracteresOrdenados2 [] = {'B', 'E', 'd', 'g', 'h', 0};
    int validosCaracteres2 = 5;

    char caracteresIntercalados [14];
    int validosCaracteresIntercalados = 0;

    char texto [] = "Hola, mundo!";
    int validosTexto = 12;
    char capicua [] = "neuquen";

    int vector [] = {1, 5, 6, 7, 8};
    int vectorValidos = 5;
    int vectorSuma [vectorValidos];

    int existe = 0;
    int sumaEnteros = 0;
    int esCapicua;
    float sumaReales = 0;
    char maximo;

    int opcion = menu();

    switch(opcion){
        case 1:
            validosEnteros = cargarArreglo(enteros, dimensionEnteros);
            mostrarArreglo(enteros, validosEnteros);
            break;
        case 2:
            validosEnteros = cargarArregloRandomEnteros(enteros, dimensionEnteros, 4);
            mostrarArreglo(enteros, validosEnteros);
            break;
        case 3:
            validosEnteros = cargarArregloRandomEnteros(enteros, dimensionEnteros, 15);
            sumaEnteros = sumarElementosEnteros(enteros, validosEnteros);
            printf("La suma de los enteros en el arreglo es %d.\n", sumaEnteros);
            break;
        case 4:
            validosEnteros = cargarArregloRandomEnteros(enteros, dimensionEnteros, 30);
            cargarArregloEnPila(enteros, validosEnteros, &destino);
            mostrar(&destino);
            break;
        case 5:
            validosReales = cargarArregloRandomReales(reales, dimensionReales, 6);
            sumaReales = sumarElementosReales(reales, validosReales);
            printf("La suma de los reales en el arreglo es %.2f.\n", sumaReales);
            break;
        case 6:
            existe = existeElemento('H', texto, validosTexto);
            if(existe == 1){
                printf("El elemento existe en el arreglo.");
            }
            else{
                printf("El elemento NO existe en el arreglo.");
            }
            break;
        case 7:
            mostrarArregloCaracteres(caracteresOrdenados, validosCaracteres);
            validosCaracteres = insertarCaracterEnArregloOrdenado('F', caracteresOrdenados, dimensionCaracteres, validosCaracteres);
            mostrarArregloCaracteres(caracteresOrdenados, validosCaracteres);
            break;
        case 8:
            maximo = maximoCaracter(texto, validosTexto);
            printf("El caracter mayor es %c.\n", maximo);
            break;
        case 9:
            esCapicua = arregloEsCapicua(capicua, sizeof(capicua));
            if(esCapicua == 1){
                printf("El arreglo es capicua");
            }
            else{
                printf("El arreglo NO es capicua");
            }
            break;
        case 10:
            validosEnteros = cargarArregloRandomEnteros(enteros, dimensionEnteros, 10);
            mostrarArreglo(enteros, validosEnteros);
            invertirPosiciones(enteros, validosEnteros);
            mostrarArreglo(enteros, validosEnteros);
            break;
        case 11:
            // 11a
            validosEnteros = cargarArregloRandomEnteros(enteros, dimensionEnteros, 10);
            mostrarArreglo(enteros, validosEnteros);
            ordenarPorSeleccion(enteros, validosEnteros);
            mostrarArreglo(enteros, validosEnteros);
            break;
        case 12:
            // 11b
            mostrarArregloCaracteres(texto, validosTexto);
            ordenarPorInsercion(texto, validosTexto);
            mostrarArregloCaracteres(texto, validosTexto);
            break;
        case 13:
            // 12
            mostrarArregloCaracteres(caracteresOrdenados, validosCaracteres);
            mostrarArregloCaracteres(caracteresOrdenados2, validosCaracteres2);
            validosCaracteresIntercalados = intercalarCaracteres(caracteresOrdenados, validosCaracteres, caracteresOrdenados2, validosCaracteres2, caracteresIntercalados);
            mostrarArregloCaracteres(caracteresIntercalados, validosCaracteresIntercalados);
            break;
        case 14:
            mostrarArreglo(vector, vectorValidos);
            sumaVector(vector, vectorSuma, vectorValidos);
            mostrarArreglo(vectorSuma, vectorValidos);
            break;
        }

    return 0;
}

void sumaVector(int vector[], int vectorSuma[], int validos){
    for(int i = 0; i < validos; i++){
        vectorSuma[i] = 0;
        for(int j = 0; j <= i; j++){
            vectorSuma[i] += vector[j];
        }
    }
}

int intercalarCaracteres(char arreglo1[], int validos1, char arreglo2[], int validos2, char intercalados[]){
    int validosIntercalados = 0;

    for(int i = 0; i < validos1; i++){
        intercalados[i] = arreglo1[i];
        validosIntercalados++;
    }

    for(int i = 0; i < validos2; i++){
        validosIntercalados = insertarCaracterEnArregloOrdenado(arreglo2[i], intercalados, dimensionCaracteresIntercalados, validosIntercalados);
    }

    return validosIntercalados;
}

void ordenarPorInsercion(char caracteres[], int validos){
    char aux [validos];
    int auxValidos = 0;

    for(int i = 0; i < validos; i++){
        auxValidos = insertarCaracterEnArregloOrdenado(caracteres[i], aux, validos, auxValidos);
    }

    for(int i = 0; i < auxValidos; i++){
        caracteres[i] = aux[i];
    }
}

void ordenarPorSeleccion(int enteros[], int validos){
    int aux;
    int indiceMenor;

    for(int i = 0; i < validos; i++){
        indiceMenor = i;

        for(int j = i; j < validos; j++){
            // Elegir el menor valor y guardar el indice
            if(enteros[j] < enteros[indiceMenor]){
                indiceMenor = j;
            }
        }

        // Invertir las posiciones
        aux = enteros[i];
        enteros[i] = enteros[indiceMenor];
        enteros[indiceMenor] = aux;
    }
}

void invertirPosiciones(int arreglo[], int validos){
    int aComprobar = validos / 2;
    int aux;

    for(int i = 0; i < aComprobar; i++){
        int indiceInverso = validos - i - 1;
        aux = arreglo[i];
        arreglo[i] = arreglo[indiceInverso];
        arreglo[indiceInverso] = aux;
    }
}

int arregloEsCapicua(char arreglo[], int validos){
    int esCapicua = 1; // 0: no es capicúa; 1: es capicúa

    if(arreglo[validos - 1] == 0){
        // Ignorar NULL.
        validos--;
    }

    int aComprobar = validos / 2;

    for(int i = 0; i < aComprobar && esCapicua == 1; i++){
            if(arreglo[i] != arreglo[validos - i - 1]){
            esCapicua = 0;
        }
    }

    return esCapicua;
}

char maximoCaracter(char arreglo[], int validos){
    // Asumir el primer elemento como máximo.
    char maximo = arreglo[0];

    // Comprobar a partir del 2do elemento.
    for(int i = 1; i < validos; i++){
        if(arreglo[i] > maximo){
            maximo = arreglo[i];
        }
    }

    return maximo;
}

int insertarCaracterEnArregloOrdenado(char caracter, char arreglo[], int dim, int validos){
    int fueEncontrado = 0;
    int indiceObjetivo = 0;

    if(dim == 0 || validos >= dim){
        // El arreglo no tiene espacio para agregar un elemento.
        // Hacer algo?
        printf("ERROR! No hay espacio para agregar elemento!\n");
    }
    else if(validos == 0 && dim > 0){
        // El arreglo no tiene ningún elemento válido, insertar al inicio.
        arreglo[0] = caracter;
        validos = 1;
    }
    else{
        for(int i = validos - 1; i >= 0 && fueEncontrado == 0; i--){
            if(caracter > arreglo[i]){
                arreglo[i + 1] = caracter;
                fueEncontrado = 1;
            }
            else{
                arreglo[i+1] = arreglo[i];
            }
        }

        if(fueEncontrado == 0){
            // El caracter a insertar es menor que cualquiera de los valores
            arreglo[0] = caracter;
        }

        validos++;
    }

    return validos;
}

int existeElemento(char caracter, char arreglo[], int dim){
    int existe = 0; // 0: no existe; 1: existe
    for(int i = 0; i < dim; i++){
        if(arreglo[i] == caracter){
            existe = 1;
        }
    }
    return existe;
}

float sumarElementosReales(float arreglo[], int dim){
    float suma = 0;
    for(int i = 0; i < dim; i++){
        suma += arreglo[i];
    }
    return suma;
}

int cargarArregloRandomReales(float arreglo[], int dim, int cantidadACargar){
    int validos = 0;
    int maximo = 0;
    int i;

    if(cantidadACargar > dim){
        maximo = dim;
    }
    else{
        maximo = cantidadACargar;
    }

    for(i = 0; i < maximo; i++){
        arreglo[i] = (float)(rand()%10+1) + (float)(rand()%10+1)/10;
    }

    validos = i;

    return validos;
}

void cargarArregloEnPila(int arreglo[], int dim, Pila *destino){
    for(int i = 0; i < dim; i++){
        apilar(destino, arreglo[i]);
    }
}

int sumarElementosEnteros(int arreglo[], int dim){
    int suma = 0;

    for(int i = 0; i < dim; i++){
        suma += arreglo[i];
    }

    return suma;
}

int menu(){
    int opcion = 0;

    printf("Ingrese el nro de ejercicio: ");

    do{
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > cantidadEjercicios);

    return opcion;
}

int cargarArreglo(int arreglo[], int dim){
    int valoresCargados = 0;

    do{
        printf("Inserte un valor a cargar: ");
        scanf("%d", &arreglo[valoresCargados]);

        valoresCargados++;
    }while(valoresCargados < dim);

    return valoresCargados;
}

int cargarArregloRandomEnteros(int arreglo[], int dim, int cantidadACargar){
    int validos = 0;
    int maximo = 0;
    int i;

    if(cantidadACargar > dim){
        maximo = dim;
    }
    else{
        maximo = cantidadACargar;
    }

    for(i = 0; i < maximo; i++){
        arreglo[i] = rand()%10+1;
    }

    validos = i;

    return validos;
}

void mostrarArreglo(int arreglo[], int validos){
    for(int i = 0; i < validos; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

void mostrarArregloCaracteres(char arreglo[], int validos){
    for(int i = 0; i < validos; i++){
        printf("%c", arreglo[i]);
    }
    printf("\n");
}
