#include <stdio.h>
#include <stdlib.h>

struct s_nodo_bin{

    int valor;
    struct s_nodo_bin * nodoIzquierda;
    struct s_nodo_bin * nodoDerecha;
};

typedef struct s_nodo_bin * nodoArbolBinario;

void agregarNumeroAlArbolBinario(nodoArbolBinario * direccionDelArbolDeNumeros, int numeroNuevo);
void eliminarArbolDeNumeros(nodoArbolBinario * direccionDelArbolDeNumeros);
void eliminarValorDelArbol(nodoArbolBinario * direccionDelArbolDeNumeros, int valor);
nodoArbolBinario * darDireccionDelNodoDelNumero (nodoArbolBinario * direccionDelArbolDeNumeros, int numeroBuscado);
void inorder(nodoArbolBinario arbolBinarioDeNumeros);
void preorder(nodoArbolBinario arbolBinarioDeNumeros);
void postorder(nodoArbolBinario arbolBinarioDeNumeros);
void porNivel(nodoArbolBinario arbolBinarioDeNumeros, int nivel);

int main() {

    nodoArbolBinario arbolBinarioDeNumeros = NULL;
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 2);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -5);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 10);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 25);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 1);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 0);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -2);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 17);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -3);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -1);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 100);

    printf("---IMPRIMIR INORDER---\n");
    inorder(arbolBinarioDeNumeros);
    printf("\n");

    printf("---IMPRIMIR POR NIVELES---\n");
    porNivel(arbolBinarioDeNumeros,5);
    printf("\n");

    eliminarValorDelArbol(&arbolBinarioDeNumeros, 10);

    printf("---IMPRIMIR INORDER---\n");
    inorder(arbolBinarioDeNumeros);
    printf("\n");



    return 0;
}

void agregarNumeroAlArbolBinario(nodoArbolBinario * direccionDelArbolDeNumeros, int numeroNuevo){

    if( (*direccionDelArbolDeNumeros) == NULL ){
        (*direccionDelArbolDeNumeros) = malloc( sizeof(struct s_nodo_bin) );
        (*direccionDelArbolDeNumeros)->nodoDerecha = NULL;
        (*direccionDelArbolDeNumeros)->nodoIzquierda = NULL;
        (*direccionDelArbolDeNumeros)->valor = numeroNuevo;
    }

    else{
        if( (*direccionDelArbolDeNumeros)->valor > numeroNuevo )
            agregarNumeroAlArbolBinario( &((*direccionDelArbolDeNumeros)->nodoIzquierda) , numeroNuevo);
        else if( (*direccionDelArbolDeNumeros)->valor < numeroNuevo )
            agregarNumeroAlArbolBinario( &((*direccionDelArbolDeNumeros)->nodoDerecha) , numeroNuevo);
    }

}

void eliminarValorDelArbol(nodoArbolBinario * direccionDelArbolDeNumeros, int valor){
    nodoArbolBinario * direccionDelNodo = darDireccionDelNodoDelNumero(direccionDelArbolDeNumeros,valor);
    eliminarArbolDeNumeros(direccionDelNodo);
}

void eliminarArbolDeNumeros(nodoArbolBinario * direccionDelArbolDeNumeros){

    if((*direccionDelArbolDeNumeros) != NULL){
        eliminarArbolDeNumeros(&((*direccionDelArbolDeNumeros)->nodoIzquierda));
        eliminarArbolDeNumeros(&((*direccionDelArbolDeNumeros)->nodoDerecha));

        free(*direccionDelArbolDeNumeros);
        (*direccionDelArbolDeNumeros) = NULL;
    }
}

nodoArbolBinario * darDireccionDelNodoDelNumero (nodoArbolBinario * direccionDelArbolDeNumeros, int numeroBuscado){

    if((*direccionDelArbolDeNumeros) == NULL){
        return NULL;
    }

    else{
        if((*direccionDelArbolDeNumeros)->valor == numeroBuscado){
            return direccionDelArbolDeNumeros;
        }

        else{
            if(numeroBuscado < (*direccionDelArbolDeNumeros)->valor){
                return darDireccionDelNodoDelNumero ( &((*direccionDelArbolDeNumeros)->nodoIzquierda), numeroBuscado);
            }
            if(numeroBuscado > (*direccionDelArbolDeNumeros)->valor){
                return darDireccionDelNodoDelNumero ( &((*direccionDelArbolDeNumeros)->nodoDerecha), numeroBuscado);
            }
        }
    }
}

void inorder(nodoArbolBinario arbolBinarioDeNumeros){
    if(arbolBinarioDeNumeros != NULL){
        inorder(arbolBinarioDeNumeros->nodoIzquierda);
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
        inorder(arbolBinarioDeNumeros->nodoDerecha);
    }
}


void preorder(nodoArbolBinario arbolBinarioDeNumeros){

    if(arbolBinarioDeNumeros != NULL){
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
        preorder(arbolBinarioDeNumeros->nodoIzquierda);
        preorder(arbolBinarioDeNumeros->nodoDerecha);
    }
}

void postorder(nodoArbolBinario arbolBinarioDeNumeros){
    if(arbolBinarioDeNumeros != NULL){
        postorder(arbolBinarioDeNumeros->nodoIzquierda);
        postorder(arbolBinarioDeNumeros->nodoDerecha);
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
    }
}

void porNivel(nodoArbolBinario arbolBinarioDeNumeros, int nivel){
    if(arbolBinarioDeNumeros != NULL){
        if( nivel > 0 ){//Si estamos en el nivel 0, estamos en el nivel que queremos imprimir
            porNivel(arbolBinarioDeNumeros->nodoIzquierda, nivel - 1 );
            porNivel(arbolBinarioDeNumeros->nodoDerecha, nivel - 1 );
        }
        else if(nivel == 0){
            printf("%d\n", arbolBinarioDeNumeros->valor);
        }
    }
}
