#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

int main()
{
    stAlumno a;
    stAlumno a2;

    a.legajo = 1;
//    a.nombre = "Juan";
//    a.apellido = "Perez";
    a.dia = 20;
    a.mes = 5;
    a.anio = 2000;

    a2 = cargaUnAlumno();
    mostrarUnAlumno(a2);

    printf("El peso en memoria del alumno es de %d.\n", sizeof(a2));

    return 0;
}
