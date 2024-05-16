#include "alumno.h"

stAlumno cargaUnAlumno(){
    stAlumno alumno;

    char aux[100];

    printf("Ingrese el nro de legajo: ");
    scanf("%d", &alumno.legajo);

    printf("Ingrese el DNI: ");
    fflush(stdin);
    scanf("%s", aux);
    strcpy(alumno.dni, aux);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", aux);
    strcpy(alumno.nombre, aux);

    printf("Ingrese el apellido: ");
    fflush(stdin);
    scanf("%s", aux);
    strcpy(alumno.apellido, aux);

    printf("Ingrese el dia de nacimiento: ");
    scanf("%d", &alumno.dia);

    printf("Ingrese el mes de nacimiento: ");
    scanf("%d", &alumno.mes);

    printf("Ingrese el anio de nacimiento: ");
    scanf("%d", &alumno.anio);

    printf("Ingrese el genero: ");
    fflush(stdin);
    scanf("%s", &alumno.genero);

    return alumno;
}

void mostrarUnAlumno(stAlumno alumno){
    printf("\n-----------------------------\n");
    printf("Legajo: %d\n", alumno.legajo);
    printf("Nombre: %s\n", alumno.nombre);
    printf("Apellido: %s\n", alumno.apellido);
    printf("DNI: %s\n", alumno.dni);
    printf("Fecha de nacimiento: %d-%d-%d\n", alumno.dia, alumno.mes, alumno.anio);
    printf("Genero: %c\n", alumno.genero);
    printf("\n-----------------------------\n");
}
