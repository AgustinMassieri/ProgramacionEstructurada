#include <stdio.h>
#include <stdlib.h>

void cargaDeConjunto (int ** arreglo);
int estaEnLista(int*arreglo,int num);
void difSim(int* A, int* B, int**inter);
void imprimir(int * arreglo);
void unionDeArreglos(int*A, int*B,int **arreglo);
void interseccion(int * A, int *B, int **arreglo);


int main(){

    int * A = NULL;
    int * B = NULL;
    int * difS = NULL;
    int * unionC = NULL;
    int * inter = NULL;

    printf("\nCONJUNTO 1\n");
    cargaDeConjunto(&A);


    printf("\n\nCONJUNTO 2\n");
    cargaDeConjunto(&B);

    printf("\n\nCONJUNTO 1: ");
    imprimir(A);

    printf("\n\nCONJUNTO 2: ");
    imprimir(B);

    difSim(A,B,&difS);

    printf("\n\nDIFERENCIA SIMETRICA: ");
    imprimir(difS);

    unionDeArreglos(A,B,&unionC);

    printf("\n\nUNION: ");
    imprimir(unionC);

    interseccion(A,B,&inter);

    printf("\n\nINTERSECCION: ");
    imprimir(inter);

    printf("\n\n");

    return 0;
}

void cargaDeConjunto (int ** arreglo){

    int num = 0;
    int i = 0;
    *arreglo = malloc(sizeof(int));

    printf("Carga de conjunto (finalice con 0): ");
    scanf("%d",&num);

    while (num!=0){

        *((*arreglo)+i) = num;
        i++;
        *arreglo = realloc(*arreglo,(1+i)*sizeof(int));

        printf("Carga de conjunto (finalice con 0): ");
        scanf("%d",&num);
        }

        *((*arreglo)+i) = 0;
}

void difSim(int* A, int* B, int**inter){

    *inter = malloc(sizeof(int));
    int i = 0;
    int j = 0;
    int cont = 0;

    for (i = 0 ; *(A+i) != 0; i++){

        if (!estaEnLista(B,*(A+i))){

            *(*(inter)+cont) = *(A+i);
            cont++;
            *inter = realloc(*inter,(1+cont)*sizeof(int));
        }
    }

        for (j = 0 ; *(B+j) != 0 ;j++){

        if (!estaEnLista(A,*(B+j))){

            *(*(inter)+cont) = *(B+j);
            cont++;
            *inter = realloc(*inter,(1+cont)*sizeof(int));
        }
    }

    *(*(inter)+cont) = 0;
}

int estaEnLista(int*arreglo,int num){

    int rta = 0;
    int i = 0;

    for (i = 0 ; *(arreglo+i) != 0 ;i++){

        if(*(arreglo+i) == num){

            rta = 1;
        }
    }

    return rta;

}

void imprimir(int * arreglo){

    int i = 0;

    printf("{");

    for (i = 0; *(arreglo+i) != 0 ;i++){

        printf("%d,",*(arreglo+i));
    }
    printf("}");

}

void unionDeArreglos(int*A, int*B,int **arreglo){

    int cont = 0;
    int i = 0;

    *arreglo = malloc(sizeof(int));

    for (i = 0; *(A+i) != 0 ;i++){

        if(!estaEnLista(*arreglo,*(A+i))){
            *(*(arreglo)+cont) = *(A+i);
            cont++;
            *arreglo = realloc(*arreglo,(1+cont)*sizeof(int));
        }
    }

    for (int j = 0; *(B+j) != 0 ;j++){

        if (!estaEnLista(*arreglo,*(B+j))){

            *((*arreglo)+cont) = *(B+j);
            cont++;
            *arreglo = realloc(*arreglo,(cont+1)*sizeof(int));
        }
    }

    *(*(arreglo)+cont) = 0;
}

void interseccion(int * A, int *B, int **arreglo){

    int i = 0;
    int cont = 0;
    *arreglo = malloc(sizeof(int));

    for ( i = 0 ; *(A+i) ; i++){

        if(estaEnLista(B,*(A+i))){

            *(*(arreglo)+cont) = *(A+i);
            cont++;
            *arreglo = realloc(*arreglo,(1+cont)*sizeof(int));
        }
    }
    *(*(arreglo)+cont) = 0;
}
