#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <string.h>

typedef struct{
    int idCliente;
    char nombre[30];
    char apellido[30];
    int edad;
    float saldo;
} stCliente;

float sumarSaldoIterativa(stCliente clientes[], int validos);
float sumarSaldoRecursiva(stCliente clientes[], int validos);
int cargarCliente(stCliente clientes[], int validos, int max);
void mostrarCliente(stCliente);

#endif // CLIENTE_H_INCLUDED
