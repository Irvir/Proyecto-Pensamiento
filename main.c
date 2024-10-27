#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hALO
struct sucursales {
    char *nombre;
    char *apellidos;
    int saldo;
    int interes;
};
struct cuenta_Corriente {
    int saldo;
    int interes;
    int estado;
};
struct cuenta_Vista {
    int saldo;
    int interes;
    int estado;
};
struct cuenta_Ahorro {
    int saldo;
    int interes;
    int estado;
};
void compara_existencia_cuentas(struct sucursales s1,struct sucursales s2, struct sucursales s3, struct sucursales s4,struct sucursales s5) {
    int nombre=0;
    int apellido=0;
    int *encontrar=(int*)malloc(10*sizeof(int)*1);
    if(strcmp(s1.nombre,s2.nombre)==0 && strcmp(s2.nombre,s3.nombre)==0 && strcmp(s3.nombre,s4.nombre)==0 && strcmp(s4.nombre,s5.nombre)==0) {
        nombre=1;
        printf("son iguales");
    }
    if(strcmp(s1.apellidos,s2.apellidos)==0 && strcmp(s2.apellidos,s3.apellidos)==0 && strcmp(s3.apellidos,s4.apellidos)==0 && strcmp(s4.nombre,s5.nombre)==0) {
        apellido=1;
        printf("son iguales");
    }
    if(nombre+apellido==2) {
        printf("son iguales");
        encontrar=1;
    }

}
//Apellidos,Nombre,Rut
void menu(int opcion) {
    FILE *archivo;
    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta.\n3.Operacion de cuentas.\n0.Salir\nEscriba su opcion:");
    scanf("%i",&opcion);
    int rut;
    char *nombre;
    int *encontrar=(int*)malloc(10*sizeof(int)*1);
    int sucursal;
    struct sucursales s1,s2,s3,s4,s5;

    switch (opcion) {
        case 1:
            printf("Ingrese su sucursal:\nSucursal 1.\nSucursal 2.\nSucursal 3.\nSucursal 4.\nSucursal 5.\n");
            scanf("%i",&sucursal);
            printf("Escriba su nombre y apellidos:\n");
        case 2:
            printf("Ingrese su sucursal");
        case 3:
            printf("Ingrese su sucursal");
    }

}
int main(void) {
    menu(0);

    return 0;
}
