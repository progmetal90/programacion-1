#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int selected;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            funcion_x();
            break;
        case 2:
            funcion_x();
            break;
        case 3:
            funcion_x();
            break;
        case 4:
            funcion_x();
            break;
        case 5:
            funcion_x();
            break;
        case 6:
            funcion_x();
            break;
        case 7:
            funcion_x();
            break;
        case 8:
            funcion_x();
            break;
        case 9:
            funcion_x();
            break;
        case 10:
            funcion_x();
            break;
        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");

            break;
        }

    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}
int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Agrega elementos a Pila");
    printf("\n2-Pasa elemento de una pila a otra");
    printf("\n3-Pasa elementos de una pila a otra (conserva el orden)");
    printf("\n4-Retorna el menor elemento de una lista");
    printf("\n5-Pasa elementos de una pila a otra y genera una nueva pila ordenada");
    printf("\n6-Inserta un elemento en una pila ordenada (conserva el orden)");
    printf("\n7-Pasa los elementos de una pila a otra, genera una ordenada (usa funcion 6)");
    printf("\n8-Suma y retorna primeros 2 elementos de una pila,sin alterar su contenido");
    printf("\n9-Calcula promedio de una pila (usa funcion de suma, division y cuenta)");
    printf("\n10-Recibe pila con numeros de un digito y los transforma en un numero decimal");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}
funcion_x()
{
    system("cls");
    system("color 1E");
    printf("\n\naca deberia estar la funcion pedida en cada ejercicio de la practica\n");
    system("PAUSE");
}
