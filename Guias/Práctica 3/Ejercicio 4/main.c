#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------STRUCT---------------------------------------------------------------------
struct s_carta{
    int numero, valor;
    char palo;
};

typedef struct s_carta t_carta;

//--------------------------------------------------FUNCIONES-----------------------------------------------------------------
void ordenarCartas(t_carta * punteroCarta1, t_carta * punteroCarta2, t_carta * punteroCarta3); //ordena de menor a mayor

int main(){

    t_carta carta1, carta2, carta3;

    carta1.numero = 1;
    carta1.valor = 14;
    carta1.palo = 'e';

    carta2.numero = 7;
    carta2.valor = 12;
    carta2.palo = 'e';

    carta3.numero = 7;
    carta3.valor = 11;
    carta3.palo = 'o';

    printf("Cartas desordenadas: \n");
    printf("Carta 1: %d %d %c\n", carta1.numero, carta1.valor, carta1.palo);
    printf("Carta 2: %d %d %c\n", carta2.numero, carta2.valor, carta2.palo);
    printf("Carta 3: %d %d %c\n", carta3.numero, carta3.valor, carta3.palo);

    ordenarCartas(&carta1, &carta2, &carta3);

    printf("\n");

    printf("Cartas ordenadas de menor a mayor: \n");

    printf("Carta 1: %d %d %c\n", carta1.numero, carta1.valor, carta1.palo);
    printf("Carta 2: %d %d %c\n", carta2.numero, carta2.valor, carta2.palo);
    printf("Carta 3: %d %d %c\n", carta3.numero, carta3.valor, carta3.palo);

    return 0;
}

void ordenarCartas(t_carta * punteroCarta1, t_carta * punteroCarta2, t_carta * punteroCarta3){

    t_carta cartaAuxiliar;

    if( (*punteroCarta1).valor > (*punteroCarta2).valor ){
        cartaAuxiliar = *punteroCarta1;
        *punteroCarta1=*punteroCarta2;
        *punteroCarta2=cartaAuxiliar;
    }

    if( (*punteroCarta1).valor > (*punteroCarta3).valor ){
        cartaAuxiliar = *punteroCarta1;
        *punteroCarta1=*punteroCarta3;
        *punteroCarta3=cartaAuxiliar;
    }

    if( (*punteroCarta2).valor > (*punteroCarta3).valor ){
        cartaAuxiliar = *punteroCarta2;
        *punteroCarta2=*punteroCarta3;
        *punteroCarta3=cartaAuxiliar;
    }
}
