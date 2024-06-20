#include "cliente.h"

float sumarSaldoIterativa(stCliente clientes[], int validos){
    float suma = 0.0;
    for(int i = 0; i < validos; i++){
        suma = suma + clientes[i].saldo;
    }
    return suma;
}

float sumarSaldoRecursiva(stCliente clientes[], int validos){
    // Inciso 3

    float suma = 0;
    if(validos == 0){
        suma = 0.0;
    }
    else{
        suma = clientes[validos - 1].saldo + sumarSaldoRecursiva(clientes, validos - 1);
    }

    return suma;
}

void mostrarClientesIterativa(stCliente clientes[], int validos){
    for(int i = 0; i < validos; i++){
        mostrarCliente(clientes[i]);
    }
}

void mostrarClientesRecursiva(stCliente clientes[], int validos){
    // Inciso 2

    if(validos != 0){
        mostrarClientesRecursiva(clientes, validos - 1);
        mostrarCliente(clientes[validos - 1]);
    }
}

void mostrarCliente(stCliente cliente){
    printf("ID: %d\n", cliente.idCliente);
    printf("Nombre y Apellido: %s %s\n", cliente.nombre, cliente.apellido);
    printf("Edad: %d\n", cliente.edad);
    printf("Saldo: $%.2f\n", cliente.saldo);
}

int cargarCliente(stCliente clientes[], int validos, int max){
    // Inciso 1

    if(validos < max){
        stCliente cliente;
        char aux[30];
        char opcion = 's';

        do{
            printf("Ingrese el ID de cliente: ");
            scanf("%d", &cliente.idCliente);

            printf("Ingrese el nombre del cliente: ");
            fflush(stdin);
            gets(cliente.nombre);

            printf("Ingrese el apellido del cliente: ");
            fflush(stdin);
            gets(cliente.apellido);

            printf("Ingrese la edad del cliente: ");
            scanf("%d", &cliente.edad);

            printf("Ingrese el saldo del cliente: ");
            scanf("%f", &cliente.saldo);

            clientes[validos] = cliente;
            validos++;
            printf("validos = %d\n", validos);
            printf("Desea seguir cargando? ESC para salir u otra tecla para continuar\n");
            fflush(stdin);
            opcion = getch();

        }while(opcion != 27 && validos < max);
    }
    else{
        printf("El arreglo esta lleno!\n");
    }

    return validos;
}
