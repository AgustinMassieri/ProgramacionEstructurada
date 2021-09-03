#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------STRUCT-------------------------------------------------------------

typedef struct{

    int a, b, c;
}t_tres;


//----------------------------------------------------FUNCIONES-------------------------------------------------------------

void ordenar( t_tres * estructuraDeTresNumeros); // DE MENOR A MAYOR

int main()
{

    t_tres estructuraDeTresNumeros;

    estructuraDeTresNumeros.a = 2;
    estructuraDeTresNumeros.b = 0;
    estructuraDeTresNumeros.c = 1;

    printf("Numeros desordenados: \n\n");

    printf("%d\n", estructuraDeTresNumeros.a);
    printf("%d\n", estructuraDeTresNumeros.b);
    printf("%d\n", estructuraDeTresNumeros.c);

    printf("\n\n");

    ordenar(&estructuraDeTresNumeros);

    printf("Numeros ordenados de menor a mayor: \n\n");

    printf("%d\n", estructuraDeTresNumeros.a);
    printf("%d\n", estructuraDeTresNumeros.b);
    printf("%d\n", estructuraDeTresNumeros.c);

    printf("\n\n");

    return 0;
}

void ordenar( t_tres * punteroDeEstructura){
    int numeroMemoria;

    if( (*punteroDeEstructura).a > (*punteroDeEstructura).b ) {
        numeroMemoria = (*punteroDeEstructura).a;
        (*punteroDeEstructura).a = (*punteroDeEstructura).b;
        (*punteroDeEstructura).b = numeroMemoria;
    }

    if( (*punteroDeEstructura).a > (*punteroDeEstructura).c ) {
        numeroMemoria = (*punteroDeEstructura).a;
        (*punteroDeEstructura).a = (*punteroDeEstructura).c;
        (*punteroDeEstructura).c = numeroMemoria;
    }

    if( (*punteroDeEstructura).b > (*punteroDeEstructura).c ) {
        numeroMemoria = (*punteroDeEstructura).b;
        (*punteroDeEstructura).b = (*punteroDeEstructura).c;
        (*punteroDeEstructura).c = numeroMemoria;
    }

}
