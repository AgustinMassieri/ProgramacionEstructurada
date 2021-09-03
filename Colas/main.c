#include <stdio.h>
#include <stdlib.h>

struct s_nodo {

    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

struct s_cola{

    t_nodo nodoFrente;
    t_nodo nodoFinal;
};
typedef struct s_cola t_cola;

void queue(t_cola * direccionDeLaCola, int nuevoNumero);
int dequeue(t_cola * direccionDeLaCola);

int main(){

    t_cola colaDeNumeros;
    colaDeNumeros.nodoFrente = NULL;
    colaDeNumeros.nodoFinal = NULL;

    queue(&colaDeNumeros, 10);
    queue(&colaDeNumeros, 6);
    queue(&colaDeNumeros, -5);
    queue(&colaDeNumeros, 7);

    printf("---ELEMENTOS DE LA COLA---\n");
    while(colaDeNumeros.nodoFinal != NULL){
        printf("%d\n", dequeue(&colaDeNumeros));
    }
    printf("\n");

    return 0;
}

void queue(t_cola * direccionDeLaCola, int nuevoNumero){

    t_nodo nodoNuevo = NULL;
    nodoNuevo = malloc(sizeof(struct s_nodo));
    nodoNuevo->valor = nuevoNumero;
    nodoNuevo->sig = NULL;

    if(direccionDeLaCola->nodoFinal == NULL && direccionDeLaCola->nodoFrente == NULL){
        direccionDeLaCola->nodoFinal = nodoNuevo;
        direccionDeLaCola->nodoFrente = nodoNuevo;
    }
    else{
        direccionDeLaCola->nodoFinal->sig = nodoNuevo;
        direccionDeLaCola->nodoFinal = nodoNuevo;
    }

}

int dequeue(t_cola * direccionDeLaCola){

    int primerNumeroDeLaCola = 0;
    t_nodo nodoAuxiliar =  direccionDeLaCola->nodoFrente;
    direccionDeLaCola->nodoFrente = direccionDeLaCola->nodoFrente->sig;
    primerNumeroDeLaCola =  nodoAuxiliar->valor;

    free(nodoAuxiliar);

    if(direccionDeLaCola->nodoFrente == NULL){
        direccionDeLaCola->nodoFinal = NULL;
    }

    return primerNumeroDeLaCola;
}
