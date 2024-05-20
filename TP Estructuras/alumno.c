#include <stdio.h>
#include <string.h>
#include "alumno.h"

void mostrarAlumno(stAlumno a){
    printf("\nMatricula: %d\n", a.matricula);
    printf("\nNombre: %s\n", a.nombre);
    printf("\nGenero: %c\n", a.genero);
}

stAlumno cargarAlumnoRandom(){
    stAlumno alumno;

    char *nombres[20] = {
        "Alejandro", "Beatriz", "Carlos", "Diana", "Eduardo",
        "Fernanda", "Gustavo", "Hilda", "Ignacio", "Jimena",
        "Karla", "Luis", "Marta", "Nicolas", "Olga",
        "Pablo", "Rosa", "Santiago", "Teresa", "Vicente"
    };

    char generos[3] = {'m', 'f', 'o'};

    alumno.genero = generos[rand()%3];
    alumno.matricula = rand()%1000;
    strcpy(alumno.nombre, nombres[rand()%20]);

    return alumno;
}

stAlumno cargarAlumno(){
    stAlumno alumno;
    char aux[30];

    printf("Ingrese el nro. de matricula: ");
    fflush(stdin);
    scanf("%d", &alumno.matricula);

    printf("Ingrese el nombre (max. 30 caracteres): ");
    fflush(stdin);    scanf("%s", aux);
    strcpy(alumno.nombre, aux);

    printf("Ingrese el genero (m, f, o): ");
    fflush(stdin);
    scanf("%c", &alumno.genero);

    return alumno;
}
