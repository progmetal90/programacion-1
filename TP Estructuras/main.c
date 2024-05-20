#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "alumno.h"

void mostrarArregloAlumnos(stAlumno a[], int v);
int cargarArregloAlumnos(stAlumno a[], int v);
int cargarArregloAlumnosRandom(stAlumno a[], int v, int dim, int cant);
void inicArregloAlumnos(stAlumno **ptr, int dim);
void mostrarAlumnoPorMatricula(stAlumno a[], int v, int matricula);
void ordenarPorSeleccion(stAlumno a[], int v);
void mostrarAlumnosPorGenero(stAlumno a[], int v, char genero);
int insertarAlumnoEnArregloOrdenado(stAlumno a[], int v, int dim, stAlumno nuevo);
int insertarAlumnoEnArregloOrdenadoPorNombre(stAlumno a[], int v, int dim, stAlumno nuevo);
void ordenarPorNombre(stAlumno* a[], int v, int dim);
int contarAlumnosPorGenero(stAlumno a[], int v, char genero);

int main()
{
    srand(time(NULL));

    int cantidadPorGenero = 0;

    int dim = 50;
    stAlumno *alumnos = NULL;
    int validos = 0;

    inicArregloAlumnos(&alumnos, dim);

//    validos = cargarArregloAlumnos(alumnos, validos);
    validos = cargarArregloAlumnosRandom(alumnos, validos, dim, 10);
//    ordenarPorSeleccion(alumnos, validos);

//    mostrarArregloAlumnos(alumnos, validos);
//    mostrarAlumnoPorMatricula(alumnos, validos, 1);
//    mostrarAlumnosPorGenero(alumnos, validos, 'm');

    ordenarPorNombre(&alumnos, validos, dim);
    mostrarArregloAlumnos(alumnos, validos);

    char genero = 'm';
    cantidadPorGenero = contarAlumnosPorGenero(alumnos, validos, 'genero');
    printf("%d alumnos de genero %c", cantidadPorGenero, genero);

    return 0;
}

int contarAlumnosPorGenero(stAlumno a[], int v, char genero){
    // Inciso 8

    int cantidad = 0;

    for(int i = 0; i < v; i++){
        if(a[i].genero == genero){
            cantidad++;
        }
    }

    return cantidad;
}

void ordenarPorNombre(stAlumno* a[], int v, int dim){
    // Inciso 7

    stAlumno *ordenado = NULL;
    int validosOrdenado = 0;

    inicArregloAlumnos(&ordenado, dim);

    for(int i = 0; i < v; i++){
        validosOrdenado = insertarAlumnoEnArregloOrdenadoPorNombre(ordenado, validosOrdenado, dim, (*a)[i]);
    }

    free(*a);
    *a = ordenado; // PREGUNTAR POR QUE NO INTERCAMBIA CORRECTAMENTE!
}

int insertarAlumnoEnArregloOrdenadoPorNombre(stAlumno a[], int v, int dim, stAlumno nuevo){
    // Inciso 6

    int insertado = 0;

    if(v >= dim){
        printf("No hay espacio para insertar!");
    }
    else if(v == 0){
        a[0] = nuevo;
        v = 1;
    }
    else{
        for(int i = v - 1; i >= 0 && insertado == 0; i--){
            if(strcmp(nuevo.nombre, a[i].nombre) > 0){
                a[i+1] = nuevo;
                v++;
                insertado = 1;
            }
            else{
                a[i+1] = a[i];
            }
        }

        if(insertado == 0){
            a[0] = nuevo;
        }
    }

    return v;
}

int insertarAlumnoEnArregloOrdenado(stAlumno a[], int v, int dim, stAlumno nuevo){
    // Inciso 6

    int insertado = 0;

    if(v >= dim){
        printf("No hay espacio para insertar!");
    }
    else if(v == 0){
        a[0] = nuevo;
        v = 1;
    }
    else{
        for(int i = v - 1; i >= 0 && insertado == 0; i--){
            if(nuevo.matricula > a[i].matricula){
                a[i+1] = nuevo;
                v++;
                insertado = 1;
            }
            else{
                a[i+1] = a[i];
            }
        }

        if(insertado == 0){
            a[0] = nuevo;
        }
    }

    return v;
}

void mostrarAlumnosPorGenero(stAlumno a[], int v, char genero){
    // Inciso 5

    for(int i = 0; i < v; i++){
        if(a[i].genero == genero){
            mostrarAlumno(a[i]);
        }
    }
}

void ordenarPorSeleccion(stAlumno a[], int v){
    // Inciso 4
    // Se podría separar el codigo en funciones...

    int posMenor;
    stAlumno aux;

    // Buscar el menor
    for(int i = 0; i < v; i++){
        posMenor = i;

        for(int j = i + 1; j < v; j++){
            if(a[j].matricula < a[posMenor].matricula){
                posMenor = j;
            }
        }

        // Intercambiar
        aux = a[i];
        a[i] = a[posMenor];
        a[posMenor] = aux;
    }
}

void mostrarAlumnoPorMatricula(stAlumno a[], int v, int matricula){
    // Inciso 3

    int encontrado = 0;

    for(int i = 0; i < v && encontrado == 0; i++){
        stAlumno alumno = a[i];

        if(alumno.matricula == matricula){
            mostrarAlumno(alumno);
            encontrado = 1;
        }
    }

    if(encontrado == 0){
        printf("\nEl alumno matricula %d no existe en la base de datos.\n", matricula);
    }
}

int cargarArregloAlumnosRandom(stAlumno a[], int v, int dim, int cant){
    int limite = v + cant <= dim ? cant : dim;

    for(int i = v; i < limite; i++){
       a[i] = cargarAlumnoRandom();
       v++;
    }

    return v;
}

void inicArregloAlumnos(stAlumno **ptr, int dim){
    *ptr = (stAlumno *) malloc(sizeof(stAlumno) * dim);

    if(ptr == NULL){
        printf("Error reservando memoria!");
    }
}

int cargarArregloAlumnos(stAlumno a[], int v){
    // Inciso 1
    a[v] = cargarAlumno();
    v++;
    return v;
}

void mostrarArregloAlumnos(stAlumno a[], int v){
    // Inciso 2

    for(int i = 0; i < v; i++){
        mostrarAlumno(a[i]);
    }
}
