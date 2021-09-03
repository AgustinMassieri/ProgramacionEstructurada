#include <stdio.h>
#include <stdlib.h>

#define T 7

void cargarArreglo(int arreglo[T]){

    int i = 0;
    int aux;

    while (i < T - 1 && aux != 0){

        printf("Ingrese un numero para su lista:  ");
        scanf("%d",&aux);

        if (aux != 0){
            arreglo[i] = aux;
            i++;
        }
    }

    if (i <= T - 1)
        arreglo[i] = 0;
}

void imprimirArreglo (int arreglo[T]){

    int i;
    int r = 0;

    for ( i = 0; arreglo[i] != 0; i++);

    printf("\n\nSu lista tiene %i numeros",i);

    printf("\n\nSu lista es: ");

    for (r = 0; r < i; r++){
        printf("%i",arreglo[r]);
        if (r<i-1)
            printf("-");
    }

    printf("\n\n");
}

void imprimirArregloOrdenado (int arreglo[T]){

    int i;
    int r = 0;

    for ( i = 0; arreglo[i] != 0; i++);

    printf("\n\nSu lista ordenada es: ");

    for (r = 0; r < i; r++){
        printf("%i",arreglo[r]);
        if (r<i-1)
            printf("-");
    }

    printf("\n\n");


}

void ordenar (int arreglo[T]){
    int i ;
    int m = 0;
    int j = 0;
    int aux = 0;

    for ( i = 0; arreglo[i] != 0; i++);

    while (m < i){

        j = 0;
        while (j < (i-m)){

            if ((j + 1 < i - m) && (arreglo[j] > arreglo[j+1])){
                aux = arreglo[j];
                arreglo[j] = arreglo [j+1];
                arreglo[j+1] = aux;
            }
            j+=1;
        }
        m+=1;
    }

}

void invertir (int arreglo[T]){

    int m;
    int i;
    int aux = 0;

    for ( i = 0; arreglo[i] != 0; i++);

    for (m = 0; m<i/2; m++){
        aux = arreglo[m];
        arreglo[m] = arreglo[i-1-m];
        arreglo[i-1-m] = aux;
    }
}

void imprimirArregloInvertido(int arreglo[T]){

    int i;
    int r = 0;

    for ( i = 0; arreglo[i] != 0; i++);

    printf("\n\nSu lista invertida es: ");

    for (r = 0; r < i; r++){
        printf("%i",arreglo[r]);
        if (r<i-1)
            printf("-");
    }

    printf("\n\n");

}

int main()
{
    int arreglo[T];

    cargarArreglo(arreglo);
    imprimirArreglo(arreglo);
    ordenar(arreglo);
    imprimirArregloOrdenado(arreglo);
    invertir(arreglo);
    imprimirArregloInvertido(arreglo);


    return 0;
}
