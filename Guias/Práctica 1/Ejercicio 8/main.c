#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define F 3
#define C 3

//------------------------------------------DECLARACION DE FUNCIONES-----------------------------------------------------------
void cargarMat(int matriz[F][C]);
void imprimirMat (int matriz[F][C]);
void transponer (int matriz[F][C]);


void cargarMat (int matriz[F][C]){

    int i = 0;
    int j = 0;

    for (i = 0; i < F; i++){

        for( j = 0; j < C; j++){

                printf("Digite un numero para su matriz[%i][%i]: ",i,j);
                scanf("%i",&matriz[i][j]);
        }
    }

    printf("\n");

}

void imprimirMat (int matriz[F][C]) {

    int i = 0;
    int j = 0;

    printf("La matriz ingresada es: \n\n");

    for (i = 0; i < F; i++){

        for( j = 0; j < C; j++){

            printf("%i ",matriz[i][j]);

        }
        printf("\n");
    }

}

void transponer (int matriz[F][C]){

    int i;
    int j;

    int matrizTranspuesta[F][C];

    for ( i = 0; i < F; i++){

        for ( j = 0; j < C; j++){

            matrizTranspuesta[j][i] = matriz[i][j];
        }
    }

    //IMPRIMIRLA

    printf("\n\nLa transpuesta de la matriz ingresada es:\n\n");

    int m = 0;
    int l = 0;

     for (m = 0; m < F; m++){

        for( l = 0; l < C; l++){

            printf("%i ",matrizTranspuesta[m][l]);

        }
        printf("\n");
    }


}

int main(){

    int matriz[F][C];


    cargarMat(matriz);
    imprimirMat(matriz);
    transponer(matriz);


    return 0;
}
