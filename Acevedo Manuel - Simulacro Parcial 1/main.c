#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void mostrarTemperaturas(int temperaturas[], int validos);
int cargarTemperaturas(int temperaturas[], int validos, int cantidadTemperaturas);
int calcularSumaTemperaturas(int temperaturas[], int validos);
float calcularPromedioTemperaturas(int temperaturas[], int validos);
void obtenerTemperaturasDebajoDelPromedio(int temperaturas[], int validos, float promedio, Pila *menores);
int obtenerTemperaturaMasBaja(Pila * temperaturas);
int obtenerPosicionTemperaturaMasAlta(int temperaturas[], int validos);

int main()
{
    Pila temperaturasMenoresAlPromedio;
    inicpila(&temperaturasMenoresAlPromedio);

    int cantidadTemperaturas = 24;

    int temperaturas [cantidadTemperaturas];
    int validosTemperaturas;

    int sumaTemperaturas;
    float promedioTemperaturas;
    int temperaturaMasBaja;
    int temperaturaMasAltaPosicion;

    validosTemperaturas = cargarTemperaturas(temperaturas, validosTemperaturas, cantidadTemperaturas);
    system("cls");

    mostrarTemperaturas(temperaturas, validosTemperaturas);

    promedioTemperaturas = calcularPromedioTemperaturas(temperaturas, validosTemperaturas);

    printf("El promedio de las temperaturas es de %.2f.\n\n", promedioTemperaturas);

    obtenerTemperaturasDebajoDelPromedio(temperaturas, validosTemperaturas, promedioTemperaturas, &temperaturasMenoresAlPromedio);

    printf("Las temperaturas menores al promedio son las siguientes: ");
    mostrar(&temperaturasMenoresAlPromedio);

    temperaturaMasBaja = obtenerTemperaturaMasBaja(&temperaturasMenoresAlPromedio);
    if(!pilavacia(&temperaturasMenoresAlPromedio)){
        printf("La menor temperatura registrada fue de %d grados.", temperaturaMasBaja);
    }
    else{
        printf("No hay temperatura minima menor al promedio para mostrar.");
    }
    printf("\n\n");

    temperaturaMasAltaPosicion = obtenerPosicionTemperaturaMasAlta(temperaturas, validosTemperaturas);
    printf("La mayor temperatura registrada fue de %d grados.\n\n", temperaturas[temperaturaMasAltaPosicion]);

    return 0;
}

int obtenerPosicionTemperaturaMasAlta(int temperaturas[], int validos){
    int posicionMayorTemperatura = 0;

    for(int i = 0; i < validos; i++){
        if(temperaturas[i] > temperaturas[posicionMayorTemperatura]){
            posicionMayorTemperatura = i;
        }
    }

    return posicionMayorTemperatura;
}

int obtenerTemperaturaMasBaja(Pila * temperaturas){
    Pila aux;
    inicpila(&aux);
    int temperaturaMenor;

    if(!pilavacia(temperaturas)){
        temperaturaMenor = tope(temperaturas);
    }

    while(!pilavacia(temperaturas)){
        if(tope(temperaturas) < temperaturaMenor){
            temperaturaMenor = tope(temperaturas);
        }

        apilar(&aux, desapilar(temperaturas));
    }

    while(!pilavacia(&aux)){
        apilar(temperaturas, desapilar(&aux));
    }

    return temperaturaMenor;
}

void obtenerTemperaturasDebajoDelPromedio(int temperaturas[], int validos, float promedio, Pila *menores){
    for(int i = 0; i < validos; i++){
        if(temperaturas[i] < promedio){
            apilar(menores, temperaturas[i]);
        }
    }
}

float calcularPromedioTemperaturas(int temperaturas[], int validos){
    int suma;
    float promedio;

    suma = calcularSumaTemperaturas(temperaturas, validos);
    promedio = (float)suma / validos;

    return promedio;
}

int calcularSumaTemperaturas(int temperaturas[], int validos){
    int suma = 0;

    for(int i = 0; i < validos; i++){
        suma += temperaturas[i];
    }

    return suma;
}

int cargarTemperaturas(int temperaturas[], int validos, int cantidadTemperaturas){
    char option = 's';
    int entrada = 0;
    for(int i = validos; i < cantidadTemperaturas && option != 27; i++){
        system("cls");
        do{
            if(entrada < -45 || entrada >60){
                system("cls");
                printf("TEMPERATURA FUERA DE RANGO! Validos: -45 a 60. Intente nuevamente.\n");
            }
            printf("Ingrese una temperatura (rango -45 a 60): ");
            scanf("%d", &entrada);
        }while(entrada < -45 || entrada > 60);

        temperaturas[i] = entrada;

        printf("\nQuiere seguir cargando datos? ");
        printf("Presione ESC para finalizar la carga o cualquier otra tecla para continuar.");

        option = getch();

        printf("\n");
    }
}

void mostrarTemperaturas(int temperaturas[], int validos){
    printf("Temperaturas: ");
    for(int i = 0; i < validos; i++){
        if(i % 8 == 0){
            printf("\n");
        }
        printf("%d ", temperaturas[i]);
    }
    printf("\n\n");
}
