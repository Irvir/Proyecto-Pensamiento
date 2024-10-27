#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hALO
struct sucursales {
    char *nombre;
    char *apellidos;
    int rut;
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
void encontrar_cuenta(struct sucursales s1,struct sucursales s2,struct sucursales s3,
    struct sucursales s4,struct sucursales s5, int opcion,char *nombre,char *apellido,
    int rut,int *resultado_final){
    FILE *archivo;
    switch(opcion) {
        case 1:
            archivo = fopen("Sucursal1.txt","r");
            if(archivo == NULL) {
                archivo = fopen("Sucursal 1.txt","a+");
                while(fscanf(archivo,"%50s %50 %i",nombre,apellido,rut)==3) {
                }
                *resultado_final=1;
                fclose(archivo);
            }
            else {
                  while(fscanf(archivo,"%50s %50 %i",nombre,apellido,rut)==3) {
                  }
            *resultado_final=1;

            }
            break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
    }

}
//Apellidos,Nombre,Rut
void menu(int opcion) {
    FILE *archivo;
    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta.\n3.Operacion de cuentas.\n0.Salir\nEscriba su opcion:");
    scanf("%i",&opcion);
    getchar();


    char *nombre=(char*)malloc(10*sizeof(char)*5);
    char *apellidos=(char*)malloc(10*sizeof(char)*5);
    int rut;

    int sucursal;
    struct sucursales s1,s2,s3,s4,s5;
    int estado_cuenta;
    int *resultado_final=(int*)malloc(10*sizeof(int));

    int decision_crear_cuenta;

    switch (opcion) {
        case 1:
            printf("Ingrese su sucursal:\nSucursal 1.\nSucursal 2.\nSucursal 3.\nSucursal 4.\nSucursal 5.\n");
            scanf("%i",&sucursal);
            switch (sucursal) {
                case 1:
                    getchar();
                    printf("Escriba su nombre:\n");
                    fgets(nombre,50,stdin);
                    nombre[strcspn(nombre,"\n")]='\0';

                    printf("%s\n",nombre);
                    printf("Escriba sus apellidos:\n");
                    fgets(apellidos,50,stdin);
                    apellidos[strcspn(apellidos,"\n")]='\0';

                    printf("Ingrese su Rut (sin puntos ni digito verificador?): ");
                    scanf("%i",&rut);
                    getchar();

                    encontrar_cuenta(s1,s2,s3,s4,s5,sucursal,nombre,apellidos,rut,resultado_final);
                    if(*resultado_final==1) {
                        printf("Estimado(a): %s %s no se encuentra registrado(a) en la sucursal %i.\nDesea crear una cuenta?\n 1.Si\n2.no",nombre,apellidos,opcion);
                        scanf("%i",&decision_crear_cuenta);
                        switch(decision_crear_cuenta) {
                            case 1:
                                break;
                            case 2:
                                opcion=0;
                                break;
                        }
                    }


                    break;
            }
            break;
        case 2:
            printf("Ingrese su sucursal");
        case 3:
            printf("Ingrese su sucursal");
        case 0:
            break;
    }

}
int main(void) {
    menu(0);

    return 0;
}
