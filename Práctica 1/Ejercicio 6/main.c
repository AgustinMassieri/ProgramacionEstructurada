#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define T 1000

void cargarText (char arreglo[T]);
void imprimirText (char arreglo[T]);
int esMinuscula(char letra);
void pasarMayuscula (char arreglo[T]);
void finPunto (char arreglo[T]);
void ajusteEspacios (char arreglo [T]);
void normalizar (char arreglo[T]);


void cargarText (char arreglo[T]){

    int i = 0;
    char c = 0;

    printf("Ingrese un texto, presione ENTER para finalizar: ");
    c = getche();

        while (i < T-1 && c != '\r'){

        arreglo[i] = c;

        i++;

        c = getche();
    }

    arreglo[i]='\0';

    printf("\n");

}

void imprimirText (char arreglo[T]){

    printf("\n\n");
    printf("El texto ingresado es: %s",arreglo);
    printf("\n\n");
}


int esMinuscula(char letra){

    int condicion = 0;
    if (letra >= 'a' && letra<= 'z'){

        condicion = 1;
    }

    return condicion;
}

void pasarMayuscula (char arreglo[T]){

    if (esMinuscula(arreglo[0])){

        arreglo[0] = arreglo[0] - 32;

        printf("El texto modificado con su mayuscula es: %s",arreglo);

        printf("\n\n");
    }

}

void finPunto (char arreglo[T]){

    int i = 0;

    for ( i = 0; arreglo[i] != '\0' ; i++);

    if (arreglo[i-1] != '.'){
        arreglo[i] = '.';
        arreglo[i+1] = '\0';
    }

    printf("El texto modificado con el punto es: %s",arreglo);
    printf("\n\n");
}

void ajusteEspacios (char arreglo [T]){

    int j;
    int f;

    for (j = 0; arreglo[j] != '\0'; j++){
        while (arreglo[j] == ' ' && arreglo[j+1] == ' '){
            for (f = j + 1; arreglo[f] != '\0'; f++){
                arreglo[f] = arreglo[f+1];
            }
        }
    }

    printf("El texto modificado con los espacios es: %s",arreglo);
    printf("\n\n");

}

void normalizar (char arreglo[T]){

    pasarMayuscula(arreglo);
    finPunto(arreglo);
    ajusteEspacios(arreglo);
}


int main(){

    char arreglo[T];

    cargarText(arreglo);
    imprimirText(arreglo);
    normalizar(arreglo);



    return 0;
}
