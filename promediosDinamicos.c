#include <stdio.h>
#include <stdlib.h>

double* cantidadPracticas2(tam);
void ingresaCalif(tam);

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;

    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i",&opcion);

        switch(opcion){
        case 1:

        case 2:
            //se libera la memoria reservada

            //mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;
        default:
            //opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }

}
