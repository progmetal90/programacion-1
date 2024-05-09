#include "pila.h"


void inicpila(P_Pila p)
{
    int *aux;
    aux = (int *)malloc(50*sizeof(int));
    p->valores = aux;
    p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(P_Pila p)
{
    int z = p->valores[p->postope -1];
    p->postope--;
    return z;
}

int tope(P_Pila p)
{
    return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
    return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void mostrar2(P_Pila p)
{
    int i;
    int max = valorEspacios(p);
    int espacio;

    printf("\n -TOPE- \n");

    for(i = p->postope; i > 0; i--)
    {
        espacio = max-cantidadCaracteres(p->valores[i-1]);

        printf("|");
        printf("%d", p->valores[i-1]);
        espacios(espacio);
        printf("| \n");
    }
    printf("\n -BASE-\n");

}

int valorEspacios(P_Pila p)
{

    int mayor;
    int i;

    for(i=0; i < p->postope; i++)
    {
        if(i == 0)
        {
            mayor =  p->valores[i];
        }
        else
        {
            if(p->valores[i] > mayor)
            {

                mayor = p->valores[i];
            }
        }
    }
    return cantidadCaracteres(mayor);
}

void espacios(int valor)
{
    for(int i = 0; i<valor; i++)
        printf(" ");
}

int cantidadCaracteres(int numero)
{
    int i = 1;
    while(numero>10)
    {
        numero = numero/10;
        i++;
    }
    return i;
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}
