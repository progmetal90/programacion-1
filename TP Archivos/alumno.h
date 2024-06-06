#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <string.h>
#include <stdio.h>

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
//a�o que cursa, recordar que no podemos utilizar la � para definir variables
} stAlumno;

stAlumno cargarAlumnoRandom();
void cargarNombreRandom(char nombre[]);
stAlumno modificarAlumno(stAlumno alumno);

#endif // ALUMNO_H_INCLUDED
