#include <stdio.h>
#include <stdlib.h>

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n");

    int opcion = 0;
    float *calificaciones = NULL; 
    int total = 0;                 

    while (opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
        case 1: {
            char respuesta = 's';

            while (respuesta == 's'){
                int n;
                if (total == 0)
                    printf("\n¿Cuantas calificaciones desea ingresar? ");
                else
                    printf("\n¿Cuantas calificaciones más desea ingresar? ");

                while (scanf("%d", &n) != 1 || n <= 0){
                    printf("Entrada invalida. Ingrese un numero entero positivo: ");
                    while (getchar() != '\n');
                }
                if (calificaciones == NULL)
                    calificaciones = (float *) malloc(n * sizeof(float));
                else
                    calificaciones = (float *) realloc(calificaciones, (total + n) * sizeof(float));

                if (calificaciones == NULL) {
                    printf("Error al asignar memoria.\n");
                    break;
                }
                for (int i = 0; i < n; i++){
                    float cal;
                    printf("Ingrese la calificacion %d: ", total + i + 1);
                    while (scanf("%f", &cal) != 1 || cal < 0 || cal > 10){
                        printf("Valor invalido. Ingrese una calificacion entre 0 y 10: ");
                        while (getchar() != '\n');
                    }

                    *(calificaciones + total + i) = cal; 
                }

                total += n;
                float suma = 0;
                for (int i = 0; i < total; i++)
                    suma += *(calificaciones + i);

                float promedio = suma / total;

                printf("\nPromedio: %lf\n", promedio);
                if (promedio >= 7.0)
                    printf("Estado: APROBADO\n");
                else
                    printf("Estado: REPROBADO\n");

                do {
                    printf("\n¿Desea agregar más calificaciones? (s/n): ");
                    scanf(" %c", &respuesta);
                    if (respuesta != 's' && respuesta != 'n'){
                        printf("Respuesta invalida. Ingrese 's' o 'n'.\n");
                        while (getchar() != '\n');
                    }
                } while (respuesta != 's' && respuesta != 'n');
            }

            break;
        }

        case 2:
        //se libera la memoria reservada
            if (calificaciones != NULL) {
                free(calificaciones);
                calificaciones = NULL;
            }//mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;

        default:
        //opción del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
            while (getchar() != '\n');
        }
    }
}
