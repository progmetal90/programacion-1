#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#include "alumno.h"

#define NOMBRE_ARCHIVO_INT "datos_int.bin"
#define NOMBRE_ARCHIVO_ALUMNOS "alumnos.bin"

int agregarElementoAlFinal(int elemento);
void mostrarArchivo();
int contarElementosEnArchivo();
void mostrarAlumno(stAlumno alumno);
void cargarCincoAlumnosRandom();
void mostrarArchivoAlumnos(char nombreArchivo[]);
void agregarAlFinalManual();
void cargarLegajosMayores(Pila * p);
int contarAlumnosMayores(int edad);
void mostrarAlumnoMayorEdad();
int contarAlumnosEnAnio(int anio);
int archivoAlArreglo(stAlumno **alumnos, char nombreArchivo[]);
void arregloAlArchivo(stAlumno *alumnos, int validos, char nombreArchivo[]);
int contarRegistrosEnArchivo(char nombreArchivo[], int tamanio);
void mostrarRegistro(char nombreArchivo[], int desplazamiento);


int main()
{
    srand(time(NULL));
    Pila legajosMayores;
    inicpila(&legajosMayores);
    int entrada = 0;
    int cantidadMayores = 0;
    int alumnosEnAnio;
    int anio;
    int registrosEnArchivo;

    char mensajeRangoMenor[] = "Ingrese el limite inferior de edad a buscar: ";
    char mensajeRangoMayor[] = "Ingrese el limite superior de edad a buscar: ";
    int menor;
    int mayor;

    stAlumno alumnos[100];
    int vAlumnos = 0;
    stAlumno * alumnosDinamico = NULL;
    int vAlumnosDinamico = 0;

//    int numeroUsuario = 0;
//    int cantElementosEnArchivo = 0;
//
//    printf("Ingrese un numero: ");
//    fflush(stdin);
//    scanf("%d", &numeroUsuario);
//
//    agregarElementoAlFinal(numeroUsuario);
//    mostrarArchivo(NOMBRE_ARCHIVO_INT);
//
//    cantElementosEnArchivo = contarElementosEnArchivo();
//    printf("Hay %d elementos en el archivo.\n", cantElementosEnArchivo);

//    cargarCincoAlumnosRandom();
//    mostrarArchivoAlumnos(NOMBRE_ARCHIVO_ALUMNOS);
//
//    agregarAlFinalManual();
//    mostrarArchivoAlumnos(NOMBRE_ARCHIVO_ALUMNOS);

//    printf("Ingrese una edad para contar mayores: ");
//    fflush(stdin);
//    scanf("%d", &entrada);
//
//    cantidadMayores = contarAlumnosMayores(entrada);
//    printf("Hay %d alumnos mayores a %d anios.\n", cantidadMayores, entrada);

//    menor = leerEntero(mensajeRangoMenor);
//    mayor = leerEntero(mensajeRangoMayor);
//
//    mostrarNombresEnRangoDeEdad(menor, mayor);

//    mostrarAlumnoMayorEdad();

//    anio = 2;
//    alumnosEnAnio = contarAlumnosEnAnio(anio);
//    printf("Hay %d alumnos en el anio %d.", alumnosEnAnio, anio);


//    registrosEnArchivo = contarRegistrosEnArchivo(NOMBRE_ARCHIVO_ALUMNOS, sizeof(stAlumno));
//
//    printf("Hay %d registros en el archivo.\n", registrosEnArchivo);
//
//    vAlumnosDinamico = archivoAlArreglo(&alumnosDinamico, NOMBRE_ARCHIVO_ALUMNOS);
//
//    arregloAlArchivo(alumnosDinamico, vAlumnosDinamico, "alumnos_copia.bin");
//
//    registrosEnArchivo = contarRegistrosEnArchivo("alumnos_copia.bin", sizeof(stAlumno));
//
//    printf("Hay %d registros en el archivo copia.\n", registrosEnArchivo);

//    mostrarArchivoAlumnos("alumnos_copia.bin");

//    printf("Ingrese un numero entre 0 y 9: ");
//    scanf("%d", &entrada);
//
//    if(entrada >= 0 && entrada <= 9){
//        mostrarRegistro(NOMBRE_ARCHIVO_ALUMNOS, entrada);
//    }

//    mostrarRegistro(NOMBRE_ARCHIVO_ALUMNOS, 0);
//    modificarRegistro(NOMBRE_ARCHIVO_ALUMNOS, 0);
//    mostrarRegistro(NOMBRE_ARCHIVO_ALUMNOS, 0);

    return 0;
}

void modificarRegistro(char nombreArchivo[], int desplazamiento){
    // Inciso 15

    stAlumno buffer;
    int registros = contarRegistrosEnArchivo(nombreArchivo, sizeof(stAlumno));

    FILE * archi = fopen(nombreArchivo, "r+b");

    if(archi && desplazamiento < registros){
        fseek(archi, desplazamiento * sizeof(stAlumno), SEEK_SET);
        fread(&buffer, sizeof(stAlumno), 1, archi);

        buffer = modificarAlumno(buffer);

        fseek(archi, (-1)* sizeof(stAlumno), SEEK_CUR);
        fwrite(&buffer, sizeof(stAlumno), 1, archi);

        fclose(archi);
    }
}

void mostrarRegistro(char nombreArchivo[], int desplazamiento){
    // Inciso 14

    stAlumno buffer;
    int registros = contarRegistrosEnArchivo(nombreArchivo, sizeof(stAlumno));
    int i = 0;

    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi && desplazamiento < registros){
        fseek(archi, desplazamiento * sizeof(stAlumno), SEEK_SET);
        fread(&buffer, sizeof(stAlumno), 1, archi);
        fclose(archi);

        mostrarAlumno(buffer);
    }
}

int contarRegistrosEnArchivo(char nombreArchivo[], int tamanio){
    // Inciso 13

    int cantRegistros = 0;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi){
        fseek(archi, 0, SEEK_END);
        cantRegistros = ftell(archi)/tamanio;

        fclose(archi);
    }
    else{
        cantRegistros = -1;
    }

    return cantRegistros;
}

void arregloAlArchivo(stAlumno *alumnos, int validos, char nombreArchivo[]){
    // Inciso 12

    FILE * archi = fopen(nombreArchivo, "ab");

    if(archi){
        fwrite(alumnos, sizeof(stAlumno), validos, archi);

        fclose(archi);
    }
    else{
        puts("Error escribiendo archivo!");
    }
}

int archivoAlArreglo(stAlumno **alumnos, char nombreArchivo[]){
    // Inciso 12

    int registros = contarRegistrosEnArchivo(nombreArchivo, sizeof(stAlumno));

    stAlumno buffer;

    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi){
        *alumnos = (stAlumno *) malloc(sizeof(stAlumno) * registros + 20); // Agrego 20 para que haya espacio para agregar

        fread(*alumnos, sizeof(stAlumno), registros, archi);

        fclose(archi);
    }

    return registros;
}

int contarAlumnosEnAnio(int anio){
    // Inciso 11

    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "rb");
    stAlumno buffer;
    int cantidad = 0;

    if(archi){
        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            if(buffer.anio == anio){
                cantidad++;
            }
        }

        fclose(archi);
    }
    else{
        // En caso de no poder abrir el archivo, devuelve -1 (error).
        cantidad = -1;
    }

    return cantidad;
}

void mostrarAlumnoMayorEdad(){
    // Inciso 10

    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "rb");
    stAlumno buffer;
    stAlumno mayor;
    mayor.edad = -1;

    if(archi){
        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            if(buffer.edad > mayor.edad){
                mayor = buffer;
            }
        }
        fclose(archi);
    }

    if(mayor.edad == -1){
        puts("El archivo esta vacio.");
    }
    else{
        mostrarAlumno(mayor);
    }
}

void mostrarNombresEnRangoDeEdad(int min, int max){
    // Inciso 9

    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "rb");
    stAlumno buffer;

    if(archi){
        printf("Nombres de alumnos entre %d y %d anios: \n\n", min, max);

        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            if(buffer.edad >= min && buffer.edad <= max){
                printf("%s (%d anios)\n", buffer.nombreYapellido, buffer.edad);
            }
        }
        fclose(archi);
    }

}

int leerEntero(char mensaje[]){
    int entrada;

    puts(mensaje);
    scanf("%d", &entrada);

    return entrada;
}

int contarAlumnosMayores(int edad){
    // Inciso 8

    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "rb");
    stAlumno buffer;
    int cantidad = 0;

    if(archi){
        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            if(buffer.edad > edad){
                cantidad++;
            }
        }
        fclose(archi);
    }

    return cantidad;
}

void cargarLegajosMayores(Pila * p){
    // Inciso 7

    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "rb");
    stAlumno buffer;

    if(archi){
        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            if(buffer.edad >= 18){
                apilar(p, buffer.edad);
            }
        }
        fclose(archi);
    }
}

void agregarAlFinalManual(){
    // Inciso 6

    stAlumno alumno;
    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "ab");

    if(archi){
        printf("Ingrese el nro de legajo: ");
        scanf("%d", &alumno.legajo);

        printf("Ingrese el nombre (maximo 30 caracteres): ");
        fflush(stdin);
        gets(alumno.nombreYapellido);

        printf("Ingrese la edad: ");
        scanf("%d", &alumno.edad);

        printf("Ingrese el anio de cursada: ");
        scanf("%d", &alumno.anio);

        fwrite(&alumno, sizeof(stAlumno), 1, archi);

        fclose(archi);
    }
}

void mostrarArchivoAlumnos(char nombreArchivo[]){
    // Inciso 5

    FILE * archi = fopen(nombreArchivo, "rb");
    stAlumno buffer;

    puts("");

    if(archi){
        while(fread(&buffer, sizeof(stAlumno), 1, archi) > 0){
            mostrarAlumno(buffer);
        }

        fclose(archi);
    }
}

void cargarCincoAlumnosRandom(){
    // Inciso 4

    FILE * archi = fopen(NOMBRE_ARCHIVO_ALUMNOS, "ab");
    stAlumno alumno;

    if(archi){
        for(int i = 0; i < 5; i++){
            alumno = cargarAlumnoRandom();
            fwrite(&alumno, sizeof(stAlumno), 1, archi);
        }

        fclose(archi);
    }
}

void mostrarAlumno(stAlumno alumno){
    printf("\n----------------------\n");
    printf("Legajo: %d\n", alumno.legajo);
    printf("Nombre: %s\n", alumno.nombreYapellido);
    printf("Edad: %d\n", alumno.edad);
    printf("Anio que cursa: %d\n", alumno.anio);
}

int contarElementosEnArchivo(){
    // Inciso 3

    int cantElementos = 0;
    int buffer;

    FILE * archi = fopen(NOMBRE_ARCHIVO_INT, "rb");

    if(archi){
        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            cantElementos++;
        }

        fclose(archi);
    }

    return cantElementos;
}

void mostrarArchivo(){
    // Inciso 2

    FILE * archi = fopen(NOMBRE_ARCHIVO_INT, "rb");

    int buffer = 0;

    if(archi){
        while(fread(&buffer, sizeof(buffer), 1, archi) > 0){
            printf("%d | ", buffer);
        }
        printf("\n");

        fclose(archi);
    }
}

int agregarElementoAlFinal(int elemento){
    // Inciso 1
    // Devuelve 1 si agrego el elemento al final del archivo exitosamente.
    // Si es menor a 1, hubo un error.

    int escritos = -1;

    FILE * archi = fopen(NOMBRE_ARCHIVO_INT, "ab");

    if(archi){
        escritos = fwrite(&elemento, sizeof(elemento), 1, archi);

        fclose(archi);
    }

    return escritos;
}
