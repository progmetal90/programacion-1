#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pila.h"

void CargarPila(Pila *p);
void MostrarPila(Pila *p);
void IngresarElementosAPila(Pila *p);
void MoverElementosDePilaAOtra(Pila *p1, Pila *p2);
void MoverElementosDePilaAOtraConservandoOrden(Pila *p1, Pila *p2);
int EliminarMenorValorDeUnaPila(Pila *p);
void OrdenarPilaPorSeleccion(Pila *dada, Pila *ordenada);
void InsertarElemento(Pila *ordenada, int elemento);
void OrdenarPilaPorInsercion(Pila *p, Pila *ordenada);
int SumarTopeYAnterior(Pila *p);
float Promedio(Pila *p);
int Sumar(int num1, int num2);
float Dividir(int num1, int num2);
void IncrementarContador(int *contador);
int TransformarDigitosEnDecimal(Pila *p);

int main()
{
    printf("**TP Funciones con pilas**\n\n");

    srand(time(NULL));

    // NO OLVIDAR CARGAR ARCHIVOS pila.c Y pila.h EN PROYECTO!!!
    Pila dada, resultado, dadaOrdenada;
    inicpila(&dada);
    inicpila(&resultado);
    inicpila(&dadaOrdenada);

    int ejercicio = 0;

    // Variables auxiliares.
    int menor = 0;
    int suma = 0;
    float promedio = 0;
    int decimal = 0;

    do{
        printf("Ingrese el nro. de ejercicio a ejecutar: ");
        scanf("%d", &ejercicio);
    }while(ejercicio < 0 || ejercicio > 10);

    printf("Pila dada: \n");
    CargarPila(&dada);
    MostrarPila(&dada);
    printf("\n");

    switch(ejercicio){
        case 1:
            IngresarElementosAPila(&dada);
            MostrarPila(&dada);
            break;
        case 2:
            MoverElementosDePilaAOtra(&dada, &resultado);
            MostrarPila(&resultado);
            break;
        case 3:
            MoverElementosDePilaAOtraConservandoOrden(&dada, &resultado);
            MostrarPila(&resultado);
            break;
        case 4:
            menor = EliminarMenorValorDeUnaPila(&dada);
            MostrarPila(&dada);
            printf("El menor valor es: %d\n", menor);
            break;
        case 5:
            OrdenarPilaPorSeleccion(&dada, &resultado);
            MostrarPila(&resultado);
            break;
        case 6:
            printf("Pila dadaOrdenada: \n");
            OrdenarPilaPorSeleccion(&dada, &dadaOrdenada);
            MostrarPila(&dadaOrdenada);
            InsertarElemento(&dadaOrdenada, rand()%10+1);
            MostrarPila(&dadaOrdenada);
            break;
        case 7:
            OrdenarPilaPorInsercion(&dada, &resultado);
            MostrarPila(&resultado);
            break;
        case 8:
            suma = SumarTopeYAnterior(&dada);
            printf("La suma del tope y el anterior es %d.\n", suma);
            break;
        case 9:
            promedio = Promedio(&dada);
            printf("El promedio de los valores de la pila es %f.", promedio);
            break;
        case 10:
            // Si son muchos digitos, el numero retornado es ligeramente distinto
            // Error de precision?
            decimal = TransformarDigitosEnDecimal(&dada);
            printf("El numero formado a partir de los digitos en la pila es %d\n", decimal);
            break;
    }

    return 0;
}

int TransformarDigitosEnDecimal(Pila *p){
    Pila aux;
    inicpila(&aux);

    float numero = 0;
    int contador = 0;

    while(!pilavacia(p)){
        if(tope(p) != 0){
            numero += tope(p) * pow(10, contador);
        }
        apilar(&aux, desapilar(p));
        IncrementarContador(&contador);
    }

    MoverElementosDePilaAOtra(&aux, p);

    return numero;
}

float Dividir(int num1, int num2){
    return (float)num1 / num2;
}

int Sumar(int num1, int num2){
    return num1 + num2;
}

void IncrementarContador(int *contador){
    *contador += 1;
}

float Promedio(Pila *p){
    Pila aux;
    inicpila(&aux);

    int suma = 0;
    int contador = 0;
    float promedio;

    if(pilavacia(p)){
        promedio = -9999999;
    }
    else{
        while(!pilavacia(p)){
            suma = Sumar(tope(p), suma);
            apilar(&aux, desapilar(p));
            IncrementarContador(&contador);
        }

        MoverElementosDePilaAOtra(&aux, p);

        promedio = Dividir(suma, contador);
    }

    return promedio;
}

int SumarTopeYAnterior(Pila *p){
    int sumaTopeYAnterior = 0;

    if(!pilavacia(p)){
        int valorTope = desapilar(p);
        if(!pilavacia(p)){
            sumaTopeYAnterior = tope(p) + valorTope;
        }
        else{
            sumaTopeYAnterior = valorTope;
        }
        apilar(p, valorTope);
    }
    return sumaTopeYAnterior;
}

void OrdenarPilaPorInsercion(Pila *p, Pila *resultado){
    while(!pilavacia(p)){
        InsertarElemento(resultado, desapilar(p));
    }
}

void InsertarElemento(Pila *ordenada, int elemento){
    Pila aux;
    int anterior = 0;
    int fueInsertado = 0;
    inicpila(&aux);

    if(pilavacia(ordenada) || elemento >= tope(ordenada)){
        apilar(ordenada, elemento);
    }
    else{
        apilar(&aux, desapilar(ordenada));
        anterior = tope(&aux);

        while(!pilavacia(ordenada) && fueInsertado == 0){
            if(elemento >= tope(ordenada) && elemento <= anterior){
                apilar(ordenada, elemento);
                while(!pilavacia(&aux)){
                    apilar(ordenada, desapilar(&aux));
                }
                fueInsertado = 1;
            }
            else{
                apilar(&aux, desapilar(ordenada));
                anterior = tope(&aux);
            }
        }
        if(fueInsertado == 0){
            apilar(ordenada, elemento);
            while(!pilavacia(&aux)){
                apilar(ordenada, desapilar(&aux));
            }
        }
    }
}

void OrdenarPilaPorSeleccion(Pila *dada, Pila *ordenada){
    while(!pilavacia(dada)){
        apilar(ordenada, EliminarMenorValorDeUnaPila(dada));
    }
}

int EliminarMenorValorDeUnaPila(Pila *p){
    Pila aux;
    inicpila(&aux);
    int fueEliminado = 0; // 0 = no, 1 = si
    int menorValor;

    if(!pilavacia(p)){
        menorValor = tope(p);
    }
    else{
        menorValor = -9999999;
    }

    while(!pilavacia(p)){
        if(tope(p) < menorValor){
            menorValor = tope(p);
        }
        apilar(&aux, desapilar(p));
    }

    while(!pilavacia(&aux)){
        if(tope(&aux) == menorValor && fueEliminado == 0){
            desapilar(&aux);
            fueEliminado = 1;
        }
        else{
            apilar(p, desapilar(&aux));
        }
    }

    return menorValor;
}

void MoverElementosDePilaAOtraConservandoOrden(Pila *p1, Pila *p2){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(p1)){
        apilar(&aux, desapilar(p1));
    }
    while(!pilavacia(&aux)){
        apilar(p2, desapilar(&aux));
    }

    MostrarPila(p2);
}

void MoverElementosDePilaAOtra(Pila *p1, Pila *p2){
    while(!pilavacia(p1)){
        apilar(p2, desapilar(p1));
    }
    MostrarPila(p2);
}

void IngresarElementosAPila(Pila *p){
    int numerosACargar = 0;
    printf("Ingrese la cantidad de numeros a cargar: ");
    scanf("%d", &numerosACargar);

    for(int i = 0; i < numerosACargar; i++){
        leer(p);
    }
}

void CargarPila(Pila *p){
    for(int i = 0; i < 5; i++){
        apilar(p, rand()%10);
    }
}

void MostrarPila(Pila *p){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
    }
    printf("Contenido de pila (base a tope):\n");
    while(!pilavacia(&aux)){
        printf("%d ", tope(&aux));
        apilar(p, desapilar(&aux));
    }
    printf("\n\n");
}
