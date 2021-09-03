#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define F 2
#define C 2

//------------------------------------------DECLARACION DE FUNCIONES-----------------------------------------------------------
void cargarMat (int matriz[F][C]);
void imprimirMat (int matriz[F][C]);
float promedio(int matriz[F][C]);



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

     for (i = 0; i < F; i++){

        for( j = 0; j < C; j++){

            printf("%i ",matriz[i][j]);

        }
        printf("\n");
    }
}

float promedio(int matriz[F][C]){

    float suma = 0.00;
    float contador = 0.00;
    float resultado = 0.00;
    int i = 0;
    int j = 0;

    for (i = 0; i < F; i++){

        for( j = 0; j < C; j++){

            suma += (float)matriz[i][j];
            contador++;
        }
    }

    resultado = (float)suma / (float)contador;

    return resultado;
}

int main(){

    int matriz[F][C];
    cargarMat(matriz);
    imprimirMat(matriz);
    printf("\n");
    printf("El promedio de los elementos de la matriz es: %.2f", promedio(matriz));
    printf("\n");

    return 0;
}
