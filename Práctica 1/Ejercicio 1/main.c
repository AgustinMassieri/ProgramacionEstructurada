#include <stdio.h>
#include <stdlib.h>

int redondear (double x){

    int result = x;
    double p_decimal = x - result;

    if (p_decimal > 0.5)

        result = result + 1;

    return result;
}

int techo (double x){

    int result = x;

    if (result == x)

        return result;

    else

        return result + 1;

}

int piso (double x){

    int result = x;

    return result;


}


int main(){

    double x;
    printf("Ingrese un numero:\n");
    scanf("%lf", &x);
    printf("Usted ingreso: %6.3lf\n",x);

    printf("Redondeo: %d\n",redondear(x));

    printf("Piso: %d\n", piso(x));

    printf("Techo: %d\n", techo(x));

    return 0;
}
