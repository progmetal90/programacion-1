#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int menu();
void imprimirEspacios(int cantidad);
void cargarMatriz(int filas, int columnas, int matriz [filas][columnas]);
void cargarMatrizManual(int filas, int columnas, int matriz[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int matriz [filas][columnas]);
int sumarElementos(int filas, int columnas, int matriz[filas][columnas]);
float promedioElementos(int filas, int columnas, int matriz[filas][columnas]);
int existeElemento(int filas, int columnas, int matriz[filas][columnas], int elemento);
int cargarArregloStrings(int cantidadCaracteres, char arregloStrings[][cantidadCaracteres], int validos, int cantidadStringsTotal);
void mostrarArregloStrings(int filas, int longitudPalabra, char arregloStrings[][longitudPalabra]);
int cargarArregloStringsRandom(int cantidadCaracteres, char arregloStrings[][cantidadCaracteres], int validos, int cantidadStringsTotal, int cantidadRandom, char palabrasRandom[][cantidadRandom]);
void ordenarPorSeleccion(int cantCaracteres, char arregloStrings[][cantCaracteres], int validos, int cantStrings);
void mostrarVotos(int filas, int columnas, int matriz [filas][columnas]);
int obtenerCantidadDigitos(int numero);
void mostrarArregloEnteros(int arreglo[], int validos);
void mostrarGanador(float porcentajes[], int validos);
char candidato(int indice);
void calcularVotos(int distritos, int candidatos, int votos[distritos][candidatos]);
int obtenerCandidatoMasVotado(int candidatos, int votos[]);
int existeStringEnArreglo(int validos, int cantCaracteres, char arreglo[][cantCaracteres], char string []);
int busquedaBinaria(int cantCaracteres, char arregloStrings[][cantCaracteres], int validos, char buscador[]);


const int cantidadRandom = 10;

const int candidatos = 4;
const int distritos = 5;

int main()
{
    srand(time(NULL));


    char palabrasRandom[10][10] = {
        "provide",
        "ceiling",
        "account",
        "musical",
        "digital",
        "country",
        "dismiss",
        "bracket",
        "cruelty",
        "dribble"
    };

    int filas = 3;
    int columnas = 4;

    int matriz [filas][columnas];
    int matrizManual [filas][columnas];

    int cantStrings = 7;
    int cantCaracteres = 8; // NO OLVIDARSE DEL NULL!
    char arregloStrings[cantStrings][cantCaracteres];
    int validosStrings = 0;

    int suma;
    float promedio;
    int elementoABuscar = 6;
    int existe;

    int votos[4][5] = {
        194, 48, 206, 45,
        180, 20, 320, 16,
        221, 90, 140, 20,
        432, 51, 821, 14,
        820, 61, 940, 18
    };

    cargarMatriz(filas, columnas, matriz);
    printf("Matriz cargada con numeros aleatorios: \n\n");
    mostrarMatriz(filas, columnas, matriz);
    printf("\n");

    int opcion = menu();
    system("cls");

    switch(opcion){
        case 1:
            cargarMatrizManual(filas, columnas, matrizManual);
            mostrarMatriz(filas, columnas, matrizManual);
            break;
        case 2:
            printf("\n");
            mostrarMatriz(filas, columnas, matriz);
            break;
        case 3:
            printf("\nYa mostrada arriba!\n");
            break;
        case 4:
            suma = sumarElementos(filas, columnas, matriz);
            printf("La suma de los elementos en la matriz es %d.\n", suma);
        case 5:
            promedio = promedioElementos(filas, columnas, matriz);
            printf("El promedio de los elementos en la matriz es %.2f.\n", promedio);
            break;
        case 6:
            existe = existeElemento(filas, columnas, matriz, elementoABuscar);
            printf("\nEl elemento %d ", elementoABuscar);
            if(existe == 0){
                printf("NO ");
            }
            printf("existe en la matriz.");
            break;
        case 7:
            validosStrings = cargarArregloStrings(cantCaracteres, arregloStrings, validosStrings, cantStrings);
            mostrarArregloStrings(validosStrings, cantCaracteres, arregloStrings);
            break;
        case 8:
            validosStrings = cargarArregloStringsRandom(cantCaracteres, arregloStrings, validosStrings, cantStrings, cantidadRandom, palabrasRandom);
            mostrarArregloStrings(validosStrings, cantCaracteres, arregloStrings);
            break;
        case 9:
            validosStrings = cargarArregloStringsRandom(cantCaracteres, arregloStrings, validosStrings, cantStrings, cantidadRandom, palabrasRandom);
            mostrarArregloStrings(validosStrings, cantCaracteres, arregloStrings);

            existe = existeStringEnArreglo(validosStrings, cantCaracteres, arregloStrings, "provide");
            printf("\nEl elemento %s ", "provide");
            if(existe == -1){
                printf("NO ");
            }
            printf("existe en el arreglo.");
            break;
        case 10:
            validosStrings = cargarArregloStringsRandom(cantCaracteres, arregloStrings, validosStrings, cantStrings, cantidadRandom, palabrasRandom);
            ordenarPorSeleccion(cantCaracteres, arregloStrings, validosStrings, cantStrings);
            mostrarArregloStrings(validosStrings, cantCaracteres, arregloStrings);

            existe = busquedaBinaria(cantCaracteres, arregloStrings, validosStrings, "account");
            printf("%d", existe);
            break;
        case 11:
            validosStrings = cargarArregloStringsRandom(cantCaracteres, arregloStrings, validosStrings, cantStrings, cantidadRandom, palabrasRandom);
            mostrarArregloStrings(validosStrings, cantCaracteres, arregloStrings);
            printf("\n");
            ordenarPorSeleccion(cantCaracteres, arregloStrings, validosStrings, cantStrings);
            mostrarArregloStrings(validosStrings, cantCaracteres, arregloStrings);
            break;
        case 12:
            printf("Ejercicio no resuelto aun!");
            break;
        case 13:
            printf("Ejercicio no resuelto aun!");
            break;
        case 14:
            mostrarVotos(distritos, candidatos, votos);
            calcularVotos(distritos, candidatos, votos);

            break;
        }

    return 0;
}

int busquedaBinaria(int cantCaracteres, char arregloStrings[][cantCaracteres], int validos, char buscador[]){
    int encontrado = 0; // 0: buscando, 1: encontrado, 2: no encontrado
    int iMenor = 0;
    int iMayor = validos-1;
    int i = iMayor / 2;

    while(encontrado == 0){
        // Partir desde la mitad del rango disponible.
        // Comprobar si es igual, mayor o menor.
        int comparacion = strcmp(buscador, arregloStrings[i]);

        if(comparacion == 0){
            encontrado = 1;
        }
        else if(comparacion < 0){
            // Nuestra palabra es menor a la comparada.
            iMayor = i;
            i = iMayor / 2;
        }
        else if(comparacion > 0){
            // Nuestra palabra es mayor a la comparada.
            iMenor = i;
            i = (iMayor - iMenor + 1) / 2 + iMenor;
        }

        if(iMayor - iMenor == 0 && encontrado == 0){
            // No hay mas nada que buscar
            encontrado = 2;
        }
    }

    if(encontrado == 2){
        i = -1;
    }
    return i;
}

void calcularVotos(int distritos, int candidatos, int votos[distritos][candidatos]){
    int totalVotos = 0;
    int candidatoMasVotado;
    int votosPorCandidato[] = {0, 0, 0, 0};
    float porcentajeVotosPorCandidato[] = {0.0, 0.0, 0.0, 0.0};

    for(int i = 0; i < distritos; i++){
        for(int j = 0; j < candidatos; j++){
            int votosCandidato = votos[i][j];
            totalVotos += votosCandidato;
            votosPorCandidato[j] += votosCandidato;
        }
    }

    for(int i = 0; i < candidatos; i++){
        porcentajeVotosPorCandidato[i] = (float)votosPorCandidato[i] * 100 / totalVotos;
    }

    printf("Total de votos emitidos: %d.\n", totalVotos);
    printf("Votos por candidato: ");
    mostrarArregloEnteros(votosPorCandidato, candidatos);

    candidatoMasVotado = obtenerCandidatoMasVotado(candidatos, votosPorCandidato);

    printf("El candidato mas votado fue el candidato %c.\n\n", 65+candidatoMasVotado);

    mostrarGanador(porcentajeVotosPorCandidato, candidatos);

    printf("\n");
}

void mostrarGanador(float porcentajes[], int validos){
    int mayor = 0;
    int segundo = 0;

    for(int i = 0; i < validos && porcentajes[mayor] < 50; i++){
        if(porcentajes[i] > porcentajes[mayor]){
            mayor = i;
        }
    }

    if(porcentajes[mayor] > 50){
        printf("El candidato %c es el ganador con el %.2f%% de los votos.", candidato(mayor), porcentajes[mayor]);
    }
    else{
        if(segundo == 0){
            segundo++;
        }

        for(int i = 0; i < candidatos; i++){
            if(i != mayor){
                if(porcentajes[i] > porcentajes[segundo]){
                    segundo = i;
                }
            }
        }
        printf("Los candidatos %c (%.2f%%) y %c (%.2f%%) competiran en ballotage!\n", candidato(mayor), porcentajes[mayor], candidato(segundo), porcentajes[segundo]);
    }
}

char candidato(int indice){
    return indice+65;
}

int obtenerCandidatoMasVotado(int candidatos, int votos[]){
    int masVotado = 0;

    for(int i = 1; i < candidatos; i++){
        if(votos[i] > votos[masVotado]){
            masVotado = i;
        }
    }

    return masVotado;
}

void mostrarVotos(int filas, int columnas, int matriz [filas][columnas]){
    int ancho = 12;
    printf("DISTRITO    | CANDIDATO A | CANDIDATO B | CANDIDATO C | CANDIDATO D |\n");
    for(int i = 0; i < filas; i++){
        printf("%d", i+1);
        imprimirEspacios(ancho-1);
        for(int j = 0; j < columnas; j++){
            int valor = matriz[i][j];
            int padding = ancho - obtenerCantidadDigitos(valor);
            printf("| %d", valor);
            imprimirEspacios(padding);
        }
        printf("|\n");
    }
}

void mostrarArregloEnteros(int arreglo[], int validos){
    for(int i = 0; i < validos; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int obtenerCantidadDigitos(int numero){
    int digitos = 0;

    if(numero < 0){
        digitos++;
    }

    numero = abs(numero);

    if(numero == 0){
        digitos = 1;
    }
    else{
        while(numero != 0){
        numero /= 10;
        digitos++;
        }
    }

    return digitos;
}

void ordenarPorSeleccion(int cantCaracteres, char arregloStrings[][cantCaracteres], int validos, int cantStrings){
    char aux [cantCaracteres];

    for(int i = 0; i < validos; i++){
        for(int j = i; j < validos; j++){
            // menor
            if(strcmp(arregloStrings[j], arregloStrings[i]) < 0){
                strcpy(aux, arregloStrings[j]);
                strcpy(arregloStrings[j], arregloStrings[i]);
                strcpy(arregloStrings[i], aux);
            }
        }
    }
}

int existeStringEnArreglo(int validos, int cantCaracteres, char arreglo[][cantCaracteres], char string []){
    int indice = -1;
    int encontrado = 0;
    for(int i = 0; i < validos && encontrado == 0; i++){
        if(strcmp(arreglo[i], string) == 0){
            indice = i;
            encontrado = 1;
        }
    }

    return indice;
}

int cargarArregloStringsRandom(int cantidadCaracteres, char arregloStrings[][cantidadCaracteres], int validos, int cantidadStringsTotal, int cantidadRandom, char palabrasRandom[][cantidadRandom]){
    int randNum;
    int i;

    for(i = validos; i < cantidadStringsTotal; i++){
        randNum = rand()%cantidadRandom;

        if(cantidadCaracteres <= cantidadRandom){
            strcpy(arregloStrings[i], palabrasRandom[randNum]);
        }
    }

    return i;
}

int cargarArregloStrings(int cantidadCaracteres, char arregloStrings[][cantidadCaracteres], int validos, int cantidadStringsTotal){
    int i = validos; // Validos es la cantidad de palabras que hay en el array de strings.
    char option = 's';
    char temp [cantidadCaracteres];

    while(validos < cantidadStringsTotal && option != 27){
        printf("Ingrese el string %d. Max %d caracteres: ", i, cantidadCaracteres);
        fflush(stdin);
        gets(temp);

        if(strlen(temp) < cantidadCaracteres){
            strcpy(arregloStrings[i], temp);
            i++;
            validos++;
        }
        else{
            printf("ERROR! String mayor al tamanio maximo de caracteres.\n");
        }

        printf("Presione ESC para finalizar la carga u otra tecla para continuar.");
        fflush(stdin);
        option = getch();
        system("cls");
    }

    return i;
}

void mostrarArregloStrings(int filas, int longitudPalabra, char arregloStrings[][longitudPalabra]){
    for(int i = 0; i < filas; i++){
        printf("%s", arregloStrings[i]);
        printf("\n");
    }
}

int existeElemento(int filas, int columnas, int matriz[filas][columnas], int elemento){
    int existe = 0; // 0: no existe, 1: existe
    for(int i = 0; i < filas && existe == 0; i++){
        for(int j = 0; j < columnas && existe == 0; j++){
            if(matriz[i][j] == elemento){
                existe = 1;
            }
        }
    }

    return existe;
}

float promedioElementos(int filas, int columnas, int matriz[filas][columnas]){
    int elementos = filas * columnas;
    int suma = sumarElementos(filas, columnas, matriz);

    return (float)suma / elementos;
}

int sumarElementos(int filas, int columnas, int matriz[filas][columnas]){
    int suma = 0;

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            suma += matriz[i][j];
        }
    }

    return suma;
}

void cargarMatrizManual(int filas, int columnas, int matriz[filas][columnas]){
    int restantes = filas * columnas;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            int numero;
            printf("Ingrese un numero (%d restantes): ", restantes);
            scanf("%d", &numero);
            matriz[i][j] = numero;
            restantes--;
        }
    }
}

void mostrarMatriz(int filas, int columnas, int matriz [filas][columnas]){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            int valor = matriz[i][j];
            int padding;

            // Agregar espacios según largo del nro
            // Hasta 3 dígitos
            if(valor >= 0 && valor < 10){
                padding = 3;
            }
            else if (valor >= 10 && valor < 100){
                padding = 2;
            }
            else{
                padding = 1;
            }

            printf("| %d", valor);
            imprimirEspacios(padding);
        }
        printf("|\n");
    }
}

void imprimirEspacios(int cantidad){
    for(int i = 0; i < cantidad; i++){
        printf(" ");
    }
}

void cargarMatriz(int filas, int columnas, int matriz [filas][columnas]){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            matriz[i][j] = rand()%10;
        }
    }
}

int menu(){
    int opcion;
    printf("Ingresar nro de ejercicio: ");
    scanf("%d", &opcion);

    return opcion;
}
