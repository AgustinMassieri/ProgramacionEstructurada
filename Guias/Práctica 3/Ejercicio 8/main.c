#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//------------------------------------------------FUNCIONES-------------------------------------------------------------------


char* cargarStrDin1();
void cargarStrDin2(char** pun_arreglo);
void escribirArch(const char* nombreArch, char* frase);
int imprimirArch (const char* nombreArch);


int main(){

    char* pun_arreglo;

    char* frase = cargarStrDin1();

    escribirArch("frase.txt",frase);

    return 0;
}

char* cargarStrDin1(){

    int contador = 0;
    char* arreglo;

    arreglo= malloc(sizeof(char));

    char caracter = getche();

    while (caracter != '\r'){

        *(arreglo + contador)= caracter;
        contador ++;

        arreglo = realloc(arreglo, (contador +1) * sizeof(char));
        caracter = getche();

    }

    *(arreglo + contador) = '\0';

    return arreglo;

}

void cargarStrDin2(char** pun_arreglo){

    int contador = 0;

    *pun_arreglo = malloc(sizeof(char));

    char caracter = getche();

    while (caracter != '\r'){

        **(pun_arreglo + contador)= caracter;
        contador ++;

        *pun_arreglo = realloc( *pun_arreglo, (contador +1) * sizeof(char));
        caracter = getche();

    }

    **(pun_arreglo + contador) = '\0';


    }

void escribirArch(const char* nombreArch, char* frase){


    FILE* archivo;

    archivo = fopen(nombreArch,"w");

    fprintf(archivo,"%s",frase);

}



int imprimirArch(const char* nombreArch){

    FILE* archivo;

    archivo = fopen(nombreArch,"r");



}
