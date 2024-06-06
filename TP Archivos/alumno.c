#include "alumno.h"

char nombresRandom[][30] = {
    "Pablo Perez",
    "Ricardo Gomez",
    "Esteban Estevanez",
    "Pedro Pedraza",
    "Marcos Marconi",
    "Valentin Valentinez"
};

stAlumno cargarAlumnoRandom(){
    stAlumno alumno;

    alumno.legajo = rand()%1000;
    alumno.anio = rand()%5+1;
    alumno.edad = rand()%25+18;
    cargarNombreRandom(alumno.nombreYapellido);

    return alumno;
}

stAlumno modificarAlumno(stAlumno alumno){
    int opcion;

    puts("Ingrese una opcion a modificar:");
    puts("1 - legajo");
    puts("2 - nombre");
    puts("3 - anio");
    puts("4 - edad");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Ingrese el nro de legajo: ");
            scanf("%d", &alumno.legajo);
            break;
        case 2:
            printf("Ingrese el nombre (maximo 30 caracteres): ");
            fflush(stdin);
            gets(alumno.nombreYapellido);
            break;
        case 3:
            printf("Ingrese el anio de cursada: ");
            scanf("%d", &alumno.anio);
            break;
        case 4:
            printf("Ingrese la edad: ");
            scanf("%d", &alumno.edad);
            break;
        default:
            puts("Opcion incorrecta!");
            break;
    }

    return alumno;
}

void cargarNombreRandom(char nombre[]){
    int cantidadNombres = sizeof(nombresRandom) / 30;

    strcpy(nombre, nombresRandom[rand()%cantidadNombres]);
}
