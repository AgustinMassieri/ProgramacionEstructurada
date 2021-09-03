#include <stdio.h>
#include <stdlib.h>

void redondearAlMasProximoDouble(double * punteroDelNumero);

int main(){

    double numero = 1.9;

    redondearAlMasProximoDouble(&numero);
    printf("%lf\n", numero);

    return 0;
}

void redondearAlMasProximoDouble(double * punteroDelNumero){

    double numero = *punteroDelNumero;
    int numeroSinDecimales = numero;

    if(numero - numeroSinDecimales != 0){
        *punteroDelNumero = numeroSinDecimales + 1;
    }

}
