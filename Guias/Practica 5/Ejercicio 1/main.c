#include <stdio.h>
#include <stdlib.h>

struct s_nodo{

    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;


void agregar(t_nodo*, int);

int main(){

    t_nodo lista = NULL;
    agregar(&lista, 14);
    agregar(&lista, 17);
    agregar(&lista, 20);
    agregar(&lista, 23);
}

void agregar(t_nodo* nodo, int valor){

    if ( *nodo == NULL){

        *nodo = (t_nodo) malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }

    else{

    agregar(& (*nodo)->sig, valor);

    }
}
