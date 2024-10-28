#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int saldo;
    int interes;
};

void encontrar_cuenta(char *nombre, char *apellidos,int rut,int sucursal,int *encontrado) {
    FILE *archivo;
    switch (sucursal) {
        case 1:
            archivo = fopen("Sucursal 1.txt","r");
            break;
        case 2:
            archivo = fopen("Sucursal 2.txt","r");
            break;
        case 3:
            archivo = fopen("Sucursal 3.txt","r");
            break;
        case 4:
            archivo = fopen("Sucursal 4.txt","r");
            break;
        case 5:
            archivo = fopen("Sucursal 5.txt","r");
            break;
    }
    char encontrar_nombre[50],encontrar_apellidos[50];
    int encontrar_rut=rut;
    *encontrado=0;
    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    int bandera=0;
    int i=0;
    if(archivo==NULL) {
        archivo=fopen("Sucursal 1.txt","w");
        *encontrado=0;
    }
    if(archivo!=NULL) {
        while(fscanf(archivo,"%s %s %s %s %s %i",nombres_,encontrar_nombre,apellidos_,encontrar_apellidos,rut_,&encontrar_rut)==6&&bandera==0&&i<1000) {
            if(strcmp(encontrar_nombre,nombre)==0 && strcmp(encontrar_apellidos,apellidos)==0 &&encontrar_rut==rut) {
                *encontrado=1;
                bandera=1;
                break;
            }
        }

    }
    fclose(archivo);
}

void registrar_cuenta_sucursal(char *nombre, char *apellidos, int rut,int opcion) {
    FILE *archivo;
    switch (opcion) {
        case 1:
            archivo=fopen("Sucursal 1.txt","a+");
            break;
        case 2:
            archivo=fopen("Sucursal 2.txt","a+");
            break;
        case 3:
            archivo=fopen("Sucursal 3.txt","a+");
            break;
        case 4:
            archivo=fopen("Sucursal 4.txt","a+");
            break;
        case 5:
            archivo=fopen("Sucursal 5.txt","a+");
            break;

    }

    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    fprintf(archivo,"%s %s %s %s %s %i\n",nombres_,nombre,apellidos_,apellidos,rut_,rut);
    fclose(archivo);

}



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
                printf("Estimado(a) %s %s, no se encuentra registrado en la sucursal %i.\nDesea crear una cuenta? (1.Si / 2.No): ", nombre, apellidos, sucursal);
                scanf("%i", &decision_crear_cuenta);

                if (decision_crear_cuenta == 1) {
                    registrar_cuenta_sucursal(nombre,apellidos,rut,sucursal);

                }
            } else {
                printf("Bienvenido(a) estimado(a): %s %s (Rut: %i)\n", nombre, apellidos, rut);
            }
            break;

    }

}

int main(void) {
    struct sucursales s1[100] = {0};
    struct sucursales s2[100] = {0};
    struct sucursales s3[100] = {0};
    struct sucursales s4[100] = {0};
    struct sucursales s5[100] = {0};

    menu(0);
    return 0;
}
