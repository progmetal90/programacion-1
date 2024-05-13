#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        malloc()
        realloc()
        calloc()
        free()
    */

    int num;
    int *p = NULL;
    int *p2 = NULL;
    int i;

    puts("Numero de elementos:");
    scanf("%d", &num);

    //p = (int *) calloc(num, sizeof(int)); // Tambien es valido
    p = (int *) malloc(sizeof(int) * num);

    reservar(&p2, num);


    puts("\nNumeros:");

    for(i = 0; i < num; i++){
        printf("%d ", p[i]);
    }

    // LIBERAR MEMORIA!
    free(p);
    p = NULL;

    return 0;
}

int * reservarDevolviendo(int *ptr, int num){
    ptr = (int *) malloc(sizeof(int) * num);
    if(ptr == NULL){ // if(!p)
        puts("\nError de memoria!");
    }
    else{
        printf("\nHe reservado en %p", ptr);
    }

    return ptr;
}

void reservar(int **ptr, int dim){
    *ptr = (int *) malloc(sizeof(int) * dim);

    if(*ptr == NULL){ // if(!p)
        puts("\nError de memoria!");
    }
    else{
        printf("\nHe reservado en %p", *ptr);
    }
}

void liberar(int **ptr){
    free(*ptr);
    *ptr = NULL;
}
