#include <stdio.h>
#include <stdlib.h>

//PILAS DE CDs
//Las operaciones de inserción y eliminación se producen por un extremo --> “tope” de la pila
// No es posible acceder a un elemento del medio sin sacar antes los anteriores.

struct s_nodo{

    int valor;
    struct s_nodo* sig;

};
typedef struct s_nodo* t_nodo;

void push(t_nodo * direccionDelNodoDeLaPila, int numeroNuevo);
int pop(t_nodo * direccionDelNodoDelaPila);


int main(){

    t_nodo pilaDeNumeros = NULL;
    push(&pilaDeNumeros, 2);
    push(&pilaDeNumeros, -5);
    push(&pilaDeNumeros, 0);
    push(&pilaDeNumeros, 1);
    push(&pilaDeNumeros, 21);

    printf("---ELEMENTOS DE LA PILA---\n");
    while(pilaDeNumeros != NULL){
        printf("%d\n", pop(&pilaDeNumeros));
    }
    printf("\n");

    return 0;
}

void push(t_nodo * direccionDelNodoDeLaPila, int numeroNuevo){

    t_nodo nuevoNodo = malloc( sizeof(struct s_nodo) );
    nuevoNodo->valor = numeroNuevo;
    nuevoNodo->sig = (*direccionDelNodoDeLaPila);
    (*direccionDelNodoDeLaPila) = nuevoNodo;
}

int pop(t_nodo * direccionDelNodoDelaPila){

    t_nodo nodoAuxiliar = NULL;
    int primerNumeroDeLaPila = 0;

    nodoAuxiliar = (*direccionDelNodoDelaPila);
    primerNumeroDeLaPila = nodoAuxiliar->valor;
    (*direccionDelNodoDelaPila) = nodoAuxiliar->sig;
    free(nodoAuxiliar);

    return primerNumeroDeLaPila;
}
