#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria_Proyecto.h"




void menu(int opcion) {
    int sucursal;
    char nombre[50];
    char apellidos[50];
    int rut;
    int *numero_de_cuenta=(int *)malloc(sizeof(int));
    int decision_crear_cuenta;
    int encontrado;
    int decision_ver_cuenta;
    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta\n3.Operacion de cuentas\n4.Simulacion de interes en el "
           "tiempo\n0.Salir\nEscriba su opcion:");
    scanf("%i", &opcion);
    getchar();
    switch (opcion) {
        case 1:
            datos(&encontrado,&sucursal,nombre,apellidos,&rut,numero_de_cuenta);
            encontrar_cuenta(nombre,apellidos,&rut,&sucursal,&encontrado,numero_de_cuenta);

            if (encontrado == 0) {
                printf("Estimado(a) Cliente su cuenta no se encuentra registrada en la Sucursal: %i.\n"
                       "Desea registrarla?(1.Si / 2.No): ",sucursal);
                        scanf("%i", &decision_crear_cuenta);
                        getchar();
                if (decision_crear_cuenta == 1) {
                    printf("Escribe tu nombre: ");
                    fgets(nombre, 50, stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';  // Elimina el salto de línea
                    printf("Escribe tu apellido: ");
                    fgets(apellidos, 50, stdin);
                    apellidos[strcspn(apellidos, "\n")] = '\0';  // Elimina el salto de línea
                    registrar_cuenta_sucursal(nombre,apellidos,&rut,&sucursal,numero_de_cuenta);
                    ver_cuentas(&decision_ver_cuenta,nombre,apellidos,&encontrado,&rut,&sucursal);

                }
            } else {
                printf("encontre:%i\n",encontrado);
                mensaje_bienvenido(nombre,apellidos,&rut,&sucursal,numero_de_cuenta);

                ver_cuentas(decision_ver_cuenta,nombre,apellidos,&encontrado,&rut,&sucursal);

            }
            break;
        case 2:
            datos(encontrado,sucursal,nombre,apellidos,&rut,numero_de_cuenta);
        encontrar_cuenta(nombre,apellidos,rut,sucursal,&encontrado,numero_de_cuenta);
        if (encontrado == 0) {
            printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", nombre, apellidos, sucursal);
            registrar_cuenta_sucursal(nombre,apellidos,rut,sucursal,numero_de_cuenta);
        } else {
            printf("Error! Estimado(a): %s %s (Rut: %i), su cuenta ya está registrada\n", nombre, apellidos, rut);
        }
        break;
        case 3:break;
        case 4:break;

    }
    free(numero_de_cuenta);


}

int main(void) {

    menu(0);

    return 0;
}
