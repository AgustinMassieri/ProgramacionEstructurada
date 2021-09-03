#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define T 7

void cargarArreglo(int arreglo[T]);
void imprimirArreglo(int arreglo[T]);
int esPositivio(int aux);
int estaEnArreglo(int aux,int arreglo[T]);

int main(){

    int arreglo[T] = {0};

    cargarArreglo(arreglo);
    imprimirArreglo(arreglo);

    return 0;
}


void cargarArreglo (int arreglo[T]){

    int i = 0;
    int aux;

    printf("Ingrese un numero para su lista: ");
    scanf("%d",&aux);

    while (i<T-1 && aux!=0){

        if (esPositivio(aux) && !estaEnArreglo(aux,arreglo)){

            arreglo[i] = aux;
            i++;
        }
        printf("Ingrese un numero para su lista: ");
        scanf("%d",&aux);

    }
}

void imprimirArreglo (int arreglo[T]){

    int i;
    printf("\n\n");
    printf("Su lista es: ");
    for (i = 0; i < T && arreglo[i] != 0; i++){
        printf(" %d ",arreglo[i]);
    }
    printf("\n\n");
}


int esPositivio (int aux){

    int resultado = 0;

    if (aux >= 0){

        resultado = 1;
    }
    return resultado;

}

int estaEnArreglo (int aux,int arreglo [T]){

    int i;
    int condicion = 0;

    for (i = 0; i<T && arreglo[i] != 0; i++){

        if (arreglo[i] == aux){

            condicion = 1;
        }
    }

    return condicion;
}


