#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

#define ARCHIVO_DEUDORES "deudores.dat"
#define ARCHIVO_ACREDORES "acredores.dat"
#define MAX_CLIENTES 50

void guardarDeudoresYAcredores(stCliente clientes[], int validos, char nombreAcredores[], char nombreDeudores[]);
void mostrarRegistrosSuperandoValor(char nombreArchivo[], float saldo);
int contarElementosEnArchivo(char nombreArchivo[], int tamanioDato);
float sumarSaldoClientesEnArchivo(char nombreArchivo[]);
void mostrarBalanceBanco(char nombreAcredores[], char nombreDeudores[]);

int main()
{
    stCliente clientes [50];
    int validosClientes = 0;

    float saldoTotal;

    validosClientes = cargarCliente(clientes, validosClientes, MAX_CLIENTES);
//    mostrarClientesIterativa(clientes, validosClientes);
//    printf("\nClientes en arreglo:\n");
//    mostrarClientesRecursiva(clientes, validosClientes);

    saldoTotal = sumarSaldoRecursiva(clientes, validosClientes);
//    saldoTotal = sumarSaldoIterativa(clientes, validosClientes);
    printf("El saldo total es $%.2f.\n", saldoTotal);

//    guardarDeudoresYAcredores(clientes, validosClientes, ARCHIVO_ACREDORES, ARCHIVO_DEUDORES);
//    printf("\n\nAcredores:\n");
//    mostrarRegistrosSuperandoValor(ARCHIVO_ACREDORES, 0);
//    printf("Deudores:\n");
//    mostrarRegistrosSuperandoValor(ARCHIVO_DEUDORES, -9999);

//    int elementosEnArchivo = contarElementosEnArchivo(ARCHIVO_ACREDORES, sizeof(stCliente));
//    printf("\nHay %d elementos en el archivo %s.\n", elementosEnArchivo, ARCHIVO_ACREDORES);

//    mostrarBalanceBanco(ARCHIVO_ACREDORES, ARCHIVO_DEUDORES);

    return 0;
}

void mostrarBalanceBanco(char nombreAcredores[], char nombreDeudores[]){
    FILE * archiAcredores = fopen(nombreAcredores, "rb");
    FILE * archiDeudores = fopen(nombreDeudores, "rb");


    if(archiAcredores && archiDeudores){
        // Porcentaje sobre total de deudores y acredores.
        int cantAcredores = contarElementosEnArchivo(nombreAcredores, sizeof(stCliente));
        int cantDeudores = contarElementosEnArchivo(nombreDeudores, sizeof(stCliente));
        int totalClientes = cantAcredores + cantDeudores;
        float porcentajeAcredores = (float)cantAcredores * 100 / totalClientes;
        float porcentajeDeudores = (float)cantDeudores * 100 / totalClientes;

        float saldoAcredores = sumarSaldoClientesEnArchivo(nombreAcredores);
        float saldoDeudores = sumarSaldoClientesEnArchivo(nombreDeudores);

        printf("Porcentaje de deudores: %.2f\n", porcentajeDeudores);
        printf("Porcentaje de acredores: %.2f\n", porcentajeAcredores);
        printf("Balance total del banco: %.2f\n", saldoAcredores + saldoDeudores);

        fclose(archiAcredores);
        fclose(archiDeudores);
    }
}

float sumarSaldoClientesEnArchivo(char nombreArchivo[]){
    FILE * archi = fopen(nombreArchivo, "rb");
    float saldoTotal = 0;

    if(archi){
        stCliente buffer;

        while(fread(&buffer, sizeof(stCliente), 1, archi) > 0){
            saldoTotal += buffer.saldo;
        }

        fclose(archi);
    }
    else{
        printf("No se pudo abrir!\n");
    }

    return saldoTotal;
}

int contarElementosEnArchivo(char nombreArchivo[], int tamanioDato){
    // Inciso 6

    FILE * archi = fopen(nombreArchivo, "rb");
    int elementos = -1; // Devuelve -1 si no se pudo abrir correctamente.

    if(archi){
        fseek(archi, 0, SEEK_END);
        elementos = ftell(archi) / tamanioDato;
        fclose(archi);
    }
    else{
        printf("No se pudo abrir!\n");
    }

    return elementos;
}

void mostrarRegistrosSuperandoValor(char nombreArchivo[], float saldo){
    // Inciso 5

    FILE * archi = fopen(nombreArchivo, "rb");
    stCliente aux;


    if(archi){
        while(fread(&aux, sizeof(stCliente), 1, archi) > 0){
            if(aux.saldo > saldo){
                mostrarCliente(aux);
            }
        }

        fclose(archi);
    }
}

void guardarDeudoresYAcredores(stCliente clientes[], int validos, char nombreAcredores[], char nombreDeudores[]){
    // Inciso 4

    FILE * archiAcredores = fopen(nombreAcredores, "wb"); // Podría ser modo ab si se necesita agregar al final
    FILE * archiDeudores = fopen(nombreDeudores, "wb"); // Use wb para probar mas facil

    if(archiAcredores && archiDeudores){
        for(int i = 0; i < validos; i++){
            if(clientes[i].saldo < 0){
                fwrite(&clientes[i], sizeof(stCliente), 1, archiDeudores);
            }
            else{
                fwrite(&clientes[i], sizeof(stCliente), 1, archiAcredores);
            }
        }

        fclose(archiAcredores);
        fclose(archiDeudores);
    }
    else{
        printf("No se pudo guardar!\n");
    }
}
