#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria_Proyecto.h"




void menu(int opcion) {
    Sucursal s;
    Sucursal s2;
    int sucursal;
    int *rut=(int *)malloc(sizeof(int));

    int *numero_de_cuenta=(int *)malloc(sizeof(int));
    int decision_crear_cuenta;
    int *encontrado=(int *)malloc(sizeof(int));
    int *decision_ver_cuenta=(int *)malloc(sizeof(int)*1);
    int *estado= (int *)malloc(sizeof(int)*1);
    int *retiro=(int *)malloc(sizeof(int));
    int *deposito=(int *)malloc(sizeof(int));

    int *rut2=(int*)malloc(sizeof(int));
    int sucursal2;
    int *encontrado2=(int*)malloc(sizeof(int));
    int *numero_de_cuenta2=(int*)malloc(sizeof(int));

    printf("Menu de opciones:\n1.Ver Cuenta (Verificar saldo).\n2.Crear Cuenta.\n3.Operacion de cuentas.\n4.Simulacion de interes en el "
           "tiempo.\n0.Salir.\nEscriba su opcion:");
    scanf("%i", &opcion);
    getchar();
    switch (opcion) {
        case 1:

            printf("Ingrese su rut:");
            scanf("%i",rut);
            datos(encontrado,&sucursal,s.nombre,s.apellidos,rut,numero_de_cuenta);
            encontrar_cuenta(s.nombre,s.apellidos,rut,&sucursal,encontrado,numero_de_cuenta);

            if (*encontrado == 0) {
                printf("Estimado(a) Cliente su cuenta no se encuentra registrada en la Sucursal: %i.\n",sucursal);
            } else {
                mensaje_bienvenido(s.nombre,s.apellidos,rut,&sucursal,numero_de_cuenta);
                ver_cuentas(decision_ver_cuenta,s.nombre,s.apellidos,encontrado,rut,&sucursal,estado,numero_de_cuenta);

            }
            break;
        case 2:
            printf("Decida que cuenta desea crear:\n1.Cuenta Sucursal\n2.Cuentas: Ahorro-Corriente-Vista"
                   "\nOpcion:");
            scanf("%i", &opcion);
            getchar();

            switch (opcion) {
                case 1:
                    printf("Ingrese su rut:");
                    scanf("%i",rut);
                    datos(encontrado,&sucursal,s.nombre,s.apellidos,rut,numero_de_cuenta);
                    encontrar_cuenta(s.nombre,s.apellidos,rut,&sucursal,encontrado,numero_de_cuenta);
                    if (*encontrado == 0) {
                        registrar_cuenta_sucursal(s.nombre,s.apellidos,rut,&sucursal,numero_de_cuenta);
                        printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", s.nombre, s.apellidos, sucursal);

                    } else {

                        printf("Error! Estimado(a): %s %s (Rut: %i), su cuenta ya está registrada\n",s.nombre , s.apellidos, *rut);
                    }
                    break;
                case 2:
                    printf("Ingrese su rut:");
                    scanf("%i",rut);
                    datos(encontrado,&sucursal,s.nombre,s.apellidos,rut,numero_de_cuenta);
                    if (*encontrado == 0) {
                        printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", s.nombre, s.apellidos, sucursal);
                        registrar_cuenta_sucursal(s.nombre,s.apellidos,rut,&sucursal,numero_de_cuenta);
                        ver_cuentas(decision_ver_cuenta,s.nombre,s.apellidos,encontrado,rut,&sucursal,estado,numero_de_cuenta);
                    } else {
                        printf("Estimado(a) %s %s, se ha registrado la cuenta en la sucursal: %i.\n", s.nombre, s.apellidos, sucursal);
                        registrar_cuenta(s.nombre,s.apellidos,rut,encontrado,&sucursal,&opcion,estado,numero_de_cuenta);
                        printf("pipi");
                        ver_cuentas(decision_ver_cuenta,s.nombre,s.apellidos,encontrado,rut,&sucursal,estado,numero_de_cuenta);
                        imprimir_datos_cuentas(s.nombre,s.apellidos,rut,&sucursal,&opcion,numero_de_cuenta);

                    }
                    break;

            }



        break;
        case 3:
            int opcion_operaciones;
            printf("Que operacion desea realizar?\n1.Retiro\n2.Deposito\n3.Transferencia de Saldo\nOpcion:");
            scanf("%i", &opcion_operaciones);
            getchar();
            printf("Ingrese su rut:");
            scanf("%i",rut);

            datos(encontrado,&sucursal,s.nombre,s.apellidos,rut,numero_de_cuenta);

            if (*encontrado == 1) {
                switch (opcion_operaciones) {
                    case 1:
                        printf("Cuanto dinero desea retirar?: ");
                        scanf("%i",retiro);
                        getchar();
                        printf("Digite su tipo de cuenta (1.Ahorro/2.Corriente/3.Vista)\nOpcion: ");
                        scanf("%i",&opcion);
                        retirar(s.nombre,s.apellidos,rut,&sucursal,&opcion,estado,numero_de_cuenta,retiro);

                    break;
                    case 2:
                        printf("Cuanto dinero desea depositar?: ");
                        scanf("%i",deposito);
                        getchar();
                        printf("Digite su tipo de cuenta(1.Ahorro/2.Corriente/3.Vista)\nOpcion: ");
                        scanf("%i",&opcion);
                        depositar(s.nombre,s.apellidos,rut,&sucursal,&opcion,estado,numero_de_cuenta,deposito);
                        break;
                    case 3:
                        getchar();
                        printf("Digite su tipo de cuenta ---(1.Ahorro/2.Corriente/3.Vista)\nOpcion: ");
                        scanf("%i",&opcion);
                        printf("Ahora Digite las credenciales de las cuentas a transferir\n");
                        printf("Ingrese su rut:");
                        scanf("%i",rut2);
                        datos(encontrado2,&sucursal2,s2.nombre,s2.apellidos,rut2,numero_de_cuenta2);
                        if(*encontrado2 == 1) {
                            getchar();
                            printf("Cuanto dinero desea transferir?: ");
                            scanf("%i",retiro);
                            retirar(s.nombre,s.apellidos,rut,&sucursal,&opcion,estado,numero_de_cuenta,retiro);
                            *deposito = *retiro;

                            depositar(s2.nombre,s2.apellidos,rut2,&sucursal2,&opcion,estado,numero_de_cuenta2,deposito);
                        }else {
                            printf("%i--",*encontrado2);

                            printf("No se encontro");
                        }


                        break;
                }

            }
            else {
                printf("Error estimado usuario no se encuentra registrado ");
            }
            break;
        case 4:
            printf("Escribe tu s.nombre: ");
            fgets(s.nombre, 50, stdin);
            s.nombre[strcspn(s.nombre, "\n")] = '\0';

            printf("Escribe tu apellido: ");
            fgets(s.apellidos, 50, stdin);
            s.apellidos[strcspn(s.apellidos, "\n")] = '\0';
            printf("Ingrese su rut:");
            scanf("%i",rut);

            datos(encontrado,&sucursal,s.nombre,s.apellidos,rut,numero_de_cuenta);
            encontrar_cuenta(s.nombre,s.apellidos,rut,&sucursal,encontrado,numero_de_cuenta);
            if (*encontrado == 1) {
                encontrar_interes(s.nombre,s.apellidos,rut,&sucursal,&opcion,estado,numero_de_cuenta);
            }else{}
        break;

    }
    free(numero_de_cuenta);


}

int main(void) {

    menu(0);

    return 0;
}
