#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria_Proyecto.h"




void menu(int opcion) {
    Sucursal s;
    int sucursal;
    char nombre[50];
    char apellidos[50];
    int *rut=(int *)malloc(sizeof(int));
    int *numero_de_cuenta=(int *)malloc(sizeof(int));
    int decision_crear_cuenta;
    int *encontrado=(int *)malloc(sizeof(int));
    int *decision_ver_cuenta=(int *)malloc(sizeof(int)*1);
    int *estado= (int *)malloc(sizeof(int)*1);
    int retiro;
    int deposito;

    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta\n3.Operacion de cuentas\n4.Simulacion de interes en el "
           "tiempo\n0.Salir\nEscriba su opcion:");
    scanf("%i", &opcion);
    getchar();
    switch (opcion) {
        case 1:
            printf("Escribe tu nombre: ");
            fgets(nombre, 50, stdin);
            nombre[strcspn(nombre, "\n")] = '\0';

            printf("Escribe tu apellido: ");
            fgets(apellidos, 50, stdin);
            apellidos[strcspn(apellidos, "\n")] = '\0';
            printf("Ingrese su rut:");
            scanf("%i",rut);
            datos(encontrado,&sucursal,nombre,apellidos,rut,numero_de_cuenta);
            encontrar_cuenta(nombre,apellidos,rut,&sucursal,encontrado,numero_de_cuenta);

            if (*encontrado == 0) {
                printf("Estimado(a) Cliente su cuenta no se encuentra registrada en la Sucursal: %i.\n",sucursal);
            } else {
                mensaje_bienvenido(nombre,apellidos,rut,&sucursal,numero_de_cuenta);
                ver_cuentas(decision_ver_cuenta,nombre,apellidos,encontrado,rut,&sucursal,estado,numero_de_cuenta);

            }
            break;
        case 2:
            printf("Decida que cuenta desea crear:\n1.Cuenta Sucursal\n2.Cuentas: Ahorro-Corriente-Vista"
                   "\nOpcion:");
            scanf("%i", &opcion);
            getchar();

            switch (opcion) {
                case 1:
                    printf("Escribe tu nombre: ");
                    fgets(nombre, 50, stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';

                    printf("Escribe tu apellido: ");
                    fgets(apellidos, 50, stdin);
                    apellidos[strcspn(apellidos, "\n")] = '\0';
                    datos(encontrado,&sucursal,nombre,apellidos,rut,numero_de_cuenta);
                    encontrar_cuenta(nombre,apellidos,rut,&sucursal,encontrado,numero_de_cuenta);
                    if (encontrado == 0) {
                        printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", nombre, apellidos, sucursal);
                        registrar_cuenta_sucursal(nombre,apellidos,rut,&sucursal,numero_de_cuenta);
                    } else {
                        printf("Error! Estimado(a): %s %s (Rut: %i), su cuenta ya está registrada\n",nombre , apellidos, rut);
                    }
                    break;
                case 2:
                    printf("Primero para registrarse a una Cuenta necesita estar registrado a una sucursal\n");
                    printf("Escribe tu nombre: ");
                    fgets(nombre, 50, stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';

                    printf("Escribe tu apellido: ");
                    fgets(apellidos, 50, stdin);
                    apellidos[strcspn(apellidos, "\n")] = '\0';
                    printf("Ingrese su rut:");
                    scanf("%i",rut);
                    datos(encontrado,&sucursal,nombre,apellidos,rut,numero_de_cuenta);
//----------------------------------------TRABAJANDO AQUI----------------------------------------
                    if (*encontrado == 0) {
                        printf("-----%i",*encontrado);
                        printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", nombre, apellidos, sucursal);
                        registrar_cuenta_sucursal(nombre,apellidos,rut,&sucursal,numero_de_cuenta);
                        ver_cuentas(decision_ver_cuenta,nombre,apellidos,encontrado,rut,&sucursal,estado,numero_de_cuenta);


                    } else {
                        printf("ERROR! Estimado(a): %s %s, su cuenta ya esta registrado(a)\nPor lo que el programa se cerrara",nombre , apellidos, rut);

                    }
                    break;

            }



        break;
        case 3:
            int opcion_operaciones;
            printf("Que operacion desea realizar?\n1.Retiro\n2.Deposito\n3.Transferencia de Saldo\n4.Verificar Saldo\nOpcion:");
            scanf("%i", &opcion_operaciones);
            getchar();
            printf("Escribe tu nombre: ");
            fgets(nombre, 50, stdin);
            nombre[strcspn(nombre, "\n")] = '\0';

            printf("Escribe tu apellido: ");
            fgets(apellidos, 50, stdin);
            apellidos[strcspn(apellidos, "\n")] = '\0';
            printf("Ingrese su rut:");
            scanf("%i",rut);

            datos(encontrado,&sucursal,nombre,apellidos,rut,numero_de_cuenta);
            encontrar_cuenta(nombre,apellidos,rut,&sucursal,encontrado,numero_de_cuenta);
//-------------------------------------RETIRO-----------------------------------
            if (*encontrado == 1) {
                switch (opcion_operaciones) {
                    case 1:
                    printf("Cuanto dinero desea retirar?: ");
                    scanf("%i",&retiro);
                    getchar();
                    printf("Digite su tipo de cuenta(1.Ahorro/2.Corriente/3.Vista)\nOpcion: ");
                    scanf("%i",&opcion);
                    retirar(nombre,apellidos,rut,&sucursal,&opcion,estado,numero_de_cuenta,&retiro);
                    break;
                    case 2:
                        printf("Cuanto dinero desea depositar?: ");
                        scanf("%i",&deposito);
                        getchar();
                        printf("Digite su tipo de cuenta(1.Ahorro/2.Corriente/3.Vista)\nOpcion: ");
                        scanf("%i",&opcion);
                        depositar(nombre,apellidos,rut,&sucursal,&opcion,estado,numero_de_cuenta,&deposito);
                        break;
                }

            }
            else {
                printf("Error estimado usuario no se encuentra registrado ");
            }
            break;
        case 4:break;

    }
    free(numero_de_cuenta);


}

int main(void) {

    menu(0);

    return 0;
}
