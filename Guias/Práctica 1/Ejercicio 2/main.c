#include <stdio.h>
#include <stdlib.h>

float suma(float primer_num,float segundo_num){

    return primer_num + segundo_num;
}

float resta(float primer_num,float segundo_num){

    return primer_num - segundo_num;
}

float multiplicacion(float primer_num,float segundo_num){

    return primer_num * segundo_num;
}

float division(float primer_num,float segundo_num){

    return primer_num / segundo_num;
}

int main(){

    float primer_num;
    float segundo_num;
    char operacion;

    printf("Ingrese el primer numero: \n");
    scanf("%f", &primer_num);

    printf("Ingrese el segundo numero: \n");
    scanf("%f", &segundo_num);
    getchar();

    printf("Ingrese una operacion: \n");
    scanf("%c", &operacion);

    if (operacion == '+')

        printf("%f",suma(primer_num,segundo_num));

    else if (operacion == '-')

        printf("%f",resta(primer_num,segundo_num));

    else if (operacion == '*')

        printf("%f",multiplicacion(primer_num,segundo_num));

    else if (operacion == '/')

        printf("%f",division(primer_num,segundo_num));


    return 0;
}
