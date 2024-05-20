#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

stAlumno cargarAlumnoRandom();
stAlumno cargarAlumno();
void mostrarAlumno(stAlumno a);

#endif // ALUMNO_H_INCLUDED
