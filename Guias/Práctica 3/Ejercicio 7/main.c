#include <stdio.h>
#include <stdlib.h>

#define T 100

//-----------------------------------------------MEMORIA DINAMICA-------------------------------------------------------------

//---------------------------------------------------FUNCIONES----------------------------------------------------------------

void cargarStrDin();

int main(){

    char frase[T];
    cargarStrDin(frase);

    return 0;
}

void cargarStrDin(char frase[T]){

    int i = 0;
    char c = 0;

    printf("Introduzca una frase: ");
    c = getche();

    while (i < T-1 && c != '\r'){

        frase[i] = c;

        i++;

        c = getche();
    }

    frase[i]='\0';

    printf("\n");

    printf("\nLa frase ingresada es: %s\n", frase);


    void* malloc(size_t);

}

