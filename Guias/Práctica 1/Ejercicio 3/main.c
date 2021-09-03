#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define T 10

void cargarArreglo (char texto[T]){

    int i = 0;
    char c = 0;

    printf("Introduzca un texto:");
    c = getche();

    while (i < T-1 && c != '\r'){

        texto[i] = c;

        i++;

        c = getche();
    }

    texto[i]='\0';

    printf("\n");
}

void reemplazar (char texto[T],char caract_reemplazar,char caract_reemplazo){

    int i = 0;

    while (i < T - 1){

        if (texto[i] == caract_reemplazar){

            texto[i] = caract_reemplazo;
        }

        i++;
    }

    printf("\n");
    printf("Texto reemplazado: %s",texto);
    printf("\n");

}


int main(){
    char texto[T];
    char caract_reemplazar;
    char caract_reemplazo;

    cargarArreglo(texto);

    printf("\nIngrese un caracter a reemplazar:");
    caract_reemplazar = getche();
    printf("\n");

    printf("\nIngrese un caracter de reemplazo:");
    caract_reemplazo = getche();
    printf("\n");

    reemplazar(texto,caract_reemplazar,caract_reemplazo);

    return 0;
}
