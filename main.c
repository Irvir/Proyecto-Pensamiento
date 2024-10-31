#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria_Proyecto.h"
typedef struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int saldo;
    int interes;
}Sucursal;

typedef struct cuenta_corriente {

}Corriente;

void menu(int opcion) {
    int sucursal;
    int resultado_final;
    char nombre[50];
    char apellidos[50];
    int rut;
    int decision_crear_cuenta;
    int encontrado;

    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta\n3.Operacion de cuentas\n0.Salir\nEscriba su opcion:");
    scanf("%i", &opcion);
    switch (opcion) {
        case 1:
            datos(encontrado,sucursal,nombre,apellidos,&rut);
            encontrar_cuenta(nombre,apellidos,&rut,sucursal,&encontrado);
            if (encontrado == 0) {
                printf("Estimado(a) %s %s, no se encuentra registrado en la sucursal %i.\nDesea crear una cuenta? (1.Si / 2.No): ", nombre, apellidos, sucursal);
                scanf("%i", &decision_crear_cuenta);

                if (decision_crear_cuenta == 1) {
                    registrar_cuenta_sucursal(nombre,apellidos,rut,sucursal);

                }
            } else {
                printf("Bienvenido(a) estimado(a): %s %s (Rut: %i)\n", nombre, apellidos, rut);
            }
            break;
        case 2:
            printf("Ingrese su sucursal (1-5): ");
            scanf("%i", &sucursal);

            getchar();
            printf("Escriba su nombre: ");
            fgets(nombre, 50, stdin);
            nombre[strcspn(nombre, "\n")] = '\0';

            printf("Escriba sus apellidos: ");
            fgets(apellidos, 50, stdin);
            apellidos[strcspn(apellidos, "\n")] = '\0';

            printf("Ingrese su Rut (sin puntos ni digito verificador): ");
            scanf("%i", &rut);
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
    menu(0);
    return 0;
}
