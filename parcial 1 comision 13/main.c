#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void mostrarPila(Pila *p);
void cargarTemperaturasUsuario(Pila *p);
void separarTemperaturas(Pila p, Pila *menores, Pila *mayores);
int obtenerTemperaturaMinima(Pila *p);
int contarTemperaturasMayores(Pila p, int valor);
int sumarTemperaturasMayores(Pila p, int valor);

const int dim = 50;

int main()
{
    Pila temperaturas, menores, mayores;
    inicpila(&temperaturas);
    inicpila(&menores);
    inicpila(&mayores);

    int temperaturaMinima;
    int temperaturasMayoresDado;
    int temperaturaDada = 3;
    int cantidadTemperaturasMayoresADado;
    int sumaTemperaturasMayores;

    int arreglo [dim];
    int validos = 0;

    cargarTemperaturasUsuario(&temperaturas);

    mostrarPila(&temperaturas);

    separarTemperaturas(temperaturas, &menores, &mayores);

    puts("Menores: ");
    mostrarPila(&menores);
    puts("Mayores: ");
    mostrarPila(&mayores);
    puts("Pila original: ");
    mostrarPila(&temperaturas);

    temperaturaMinima = obtenerTemperaturaMinima(&temperaturas);
    printf("La temperatura minima fue de %d.\n", temperaturaMinima);

    puts("Pila original sin temperatura minima: ");
    mostrarPila(&temperaturas);

    cantidadTemperaturasMayoresADado = contarTemperaturasMayores(temperaturas, temperaturaDada);
    printf("Hay %d temperaturas mayores a %d\n", cantidadTemperaturasMayoresADado, temperaturaDada);

    sumaTemperaturasMayores = sumarTemperaturasMayores(temperaturas, temperaturaDada);
    printf("La suma de las temperaturas mayores a %d es %d.\n", temperaturaDada, sumaTemperaturasMayores);

    validos = cargarArregloOrdenado(arreglo, dim, &temperaturas);
    printf("Validos: %d\n", validos);

    puts("Arreglo de temperaturas ordenadas de menor a mayor: ");
    mostrarArregloEnteros(arreglo, validos);


    return 0;
}
void mostrarArregloEnteros(int a[], int v){
    // Punto 8

    for(int i = 0; i < v; i++){
        if(i % 20 == 0){
            printf("\n");
        }

        printf("%d ", a[i]);
    }
}

int cargarArregloOrdenado(int a[], int dim, Pila *p){
    // Punto 7

    int cargados = 0;

    while(!pilavacia(p)){
        int numero = desapilar(p);
        cargados = insertarEnteroEnArreglo(a, cargados, dim, numero);
    }

    return cargados;
}

int insertarEnteroEnArreglo(int a[], int v, int dim, int numero){
    int fueInsertado = 0;

    if(v >= dim){
        printf("No hay espacio para insertar.\n");
    }
    else if(v == 0){
        // El arreglo no tiene elementos, insertar en el primer indice.
        a[0] = numero;
        v = 1;
    }
    else{
        for(int i = v - 1; v >= 0 && fueInsertado == 0; i--){
            if(numero > a[i]){
                a[i + 1] = numero;
                fueInsertado = 1;
            }
            else{
                a[i + 1] = a[i];
            }
        }

        if(fueInsertado == 0){
            // El numero es menor a todos, insertar al principio
            a[0] = numero;
        }
        v++;
    }

    return v;
}

int sumarTemperaturasMayores(Pila p, int valor){
    // Punto 6

    int temperatura = 0;
    int suma = 0;

    while(!pilavacia(&p)){
        temperatura = desapilar(&p);

        if(temperatura > valor){
            suma += temperatura;
        }
    }

    return suma;
}

int contarTemperaturasMayores(Pila p, int valor){
    // Punto 5

    int temperatura = 0;
    int contador = 0;

    while(!pilavacia(&p)){
        temperatura = desapilar(&p);

        if(temperatura > valor){
            contador++;
        }
    }

    return contador;
}

int obtenerTemperaturaMinima(Pila *p){
    // Punto 4

    Pila aux;
    inicpila(&aux);

    int minima = tope(p);
    apilar(&aux, desapilar(p));

    while(!pilavacia(p)){
        if(tope(p) < minima){
            minima = tope(p);
        }
        apilar(&aux, desapilar(p));
    }

    while(!pilavacia(&aux)){
        if(tope(&aux) == minima){
            // Descartar temperatura menor
            // De esta manera se desapilan todas las que tengan el mismo valor.
            // Se podria implementar una flag para que solo se descarte una.
            desapilar(&aux);
        }
        else{
            // Devolver el resto de las temperaturas a la pila original.
            apilar(p, desapilar(&aux));
        }
    }

    return minima;
}

void separarTemperaturas(Pila p, Pila *menores, Pila *mayores){
    // Punto 3
    // Trabajo con copia de pila para no perder los datos originales.

    while(!pilavacia(&p)){
        if(tope(&p) <= 0){
            apilar(menores, desapilar(&p));
        }
        else{
            apilar(mayores, desapilar(&p));
        }
    }
}

void cargarTemperaturasUsuario(Pila *p){
    // Punto 1

    char opcion = 's';
    int cargados = 0;
    int entrada;

    do{
        system("cls");
        printf("Ingrese una temperatura: ");
        scanf("%d", &entrada);

        if(entrada < -10 || entrada > 40){
            printf("Temperatura fuera de rango! Valido -10 a 40.");
        }
        else{
            apilar(p, entrada);
            cargados++;

            printf("Presione ESC para finalizar la carga, o cualquier otra tecla para continuar: ");
            fflush(stdin);
            opcion = getch();
        }

    }while(opcion != 27 && cargados <= 50);

    printf("\n");
}

void mostrarPila(Pila *p){
    // Punto 2

    Pila aux;
    inicpila(&aux);
    int temperatura;
    int mostradas = 0;

    while(!pilavacia(p)){
        temperatura = tope(p);
        apilar(&aux, desapilar(p));
        printf("%d | ", temperatura);
        mostradas++;

        if(mostradas % 15 == 0){
            printf("\n");
            mostradas = 0;
        }
    }

    while(!pilavacia(&aux)){
        apilar(p, desapilar((&aux)));
    }

    printf("\n");
}
