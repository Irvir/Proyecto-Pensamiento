#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria_Proyecto.h"



void menu(int opcion, Lista *corriente) {
    int sucursal;
    char nombre[50];
    char apellidos[50];
    int rut;

    int decision_crear_cuenta;
    int encontrado;

    int decision_ver_cuenta;
    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta\n3.Operacion de cuentas\n0.Salir\nEscriba su opcion:");
    scanf("%i", &opcion);
    switch (opcion) {
        case 1:
            datos(&encontrado,&sucursal,nombre,apellidos,&rut);
            encontrar_cuenta(nombre,apellidos,&rut,&sucursal,&encontrado);
            if (encontrado == 0) {
                printf("Estimado(a) %s %s, no se encuentra registrado en la sucursal %i.\nDesea crear una cuenta? (1.Si / 2.No): ", nombre, apellidos, sucursal);
                scanf("%i", &decision_crear_cuenta);

                if (decision_crear_cuenta == 1) {
                    registrar_cuenta_sucursal(nombre,apellidos,&rut,&sucursal);
                    ver_cuentas(&decision_ver_cuenta,nombre,apellidos,&encontrado,&rut,&sucursal);
                }
            } else {
                printf("Bienvenido(a)\n Estimado(a): %s %s (Rut: %i)\n", nombre, apellidos, rut);
                ver_cuentas(&decision_ver_cuenta,nombre,apellidos,&encontrado,&rut,&sucursal);

            }
            break;
        case 2:
            datos(encontrado,sucursal,nombre,apellidos,&rut);
            encontrar_cuenta(nombre,apellidos,rut,sucursal,&encontrado);
            if (encontrado == 0) {
                printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", nombre, apellidos, sucursal);
                registrar_cuenta_sucursal(nombre,apellidos,rut,sucursal);
            } else {
                printf("Error! Estimado(a): %s %s (Rut: %i), su cuenta ya está registrada\n", nombre, apellidos, rut);
            }
            break;

    }


}

int main(void) {
    Lista cuenta_corriente=crearLista_Corriente();
    menu(0,cuenta_corriente);

    return 0;
}
