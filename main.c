#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hALO
struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int saldo;
    int interes;

};
struct cuenta_Corriente {
    int saldo;
    int interes;
    int comision_mensual;
    int estado;
};
struct cuenta_Vista {
    int saldo;
    int interes;
    int comision_mensual;
    int estado;
};
struct cuenta_Ahorro {
    int saldo;
    int interes;
    int comision_mensual;
    int estado;
};

void encontrar_cuenta(struct sucursales s1[],struct sucursales s2[],struct sucursales s3[],
    struct sucursales s4[],struct sucursales s5[], int opcion,char *nombre,char *apellidos,
    int rut,int *resultado_final,int iterador){

    iterador = 0;
    int bandera = 0;
    *resultado_final = 1; // Inicialmente asumimos que no se encuentra la cuenta

    while (iterador < 100 && bandera == 0) {
        if (s1[iterador].rut == rut && strcmp(s1[iterador].apellidos,apellidos) == 0 && strcmp(s1[iterador].nombre,nombre) == 0) {
            *resultado_final = 0; // Cuenta encontrada
            bandera = 1;
            break;
        }
        iterador++;
    }
}


void registrar_cuenta_sucursal(struct sucursales s1[], struct sucursales s2[], struct sucursales s3[], struct sucursales s4[],
    struct sucursales s5[], int sucursal,char *nombre,char *apellidos,int rut) {


    FILE *archivo;
    int iterador=0;
    int bandera=0;
    switch(sucursal) {
        case 1:
            //Estructura
            while(iterador<100  && bandera==0) {
                if(s1[iterador].rut==0) {
                    strcpy(s1[iterador].nombre,nombre);
                    strcpy(s1[iterador].apellidos,apellidos);
                    s1[iterador].rut=rut;
                    bandera=1;
                }
                iterador++;
            }
            //Archivo
            archivo = fopen("Sucursal 1.txt","a+");
            fprintf(archivo,"Nombre: %s Apellidos: %s RUT: %i\n",nombre,apellidos,rut);
            fclose(archivo);
            break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        default:return;
    }
}
//Apellidos,Nombre,Rut
void menu(int opcion) {
    FILE *archivo;
    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta.\n3.Operacion de cuentas.\n0.Salir\nEscriba su opcion:");
    scanf("%i",&opcion);
    getchar();


    char nombre[50];
    char apellidos[50];
    int rut;

    int sucursal;
    struct sucursales s1[100]={{0}};
    struct sucursales s2[100]={{0}};
    struct sucursales s3[100]={{0}};
    struct sucursales s4[100]={{0}};
    struct sucursales s5[100]={{0}};

    int estado_cuenta;
    int *resultado_final=(int*)malloc(10*sizeof(int));
    int iterador=0;

    int decision_crear_cuenta;

    switch (opcion) {
        case 1:
            printf("Ingrese su sucursal:(1-5):");
            scanf("%i",&sucursal);
            switch (sucursal) {
                case 1:
                    getchar();
                    printf("Escriba su nombre:");
                    fgets(nombre,50,stdin);
                    nombre[strcspn(nombre,"\n")]='\0';


                    printf("Escriba sus apellidos:");
                    fgets(apellidos,50,stdin);
                    apellidos[strcspn(apellidos,"\n")]='\0';

                    printf("Ingrese su Rut (sin puntos ni digito verificador?): ");
                    scanf("%i",&rut);
                    getchar();

                    encontrar_cuenta(s1,s2,s3,s4,s5,sucursal,nombre,apellidos,rut,resultado_final,iterador);
                    if(*resultado_final==1) {
                        printf("Estimado(a): %s %s no se encuentra registrado(a) en la sucursal %i.\nDesea crear una cuenta?\n 1.Si\n2.no",nombre,apellidos,opcion);
                        scanf("%i",&decision_crear_cuenta);
                        switch(decision_crear_cuenta) {
                            case 1:
                                registrar_cuenta_sucursal(s1,s2,s3,s4,s5,sucursal,nombre,apellidos,rut);
                                break;
                            case 2:
                                opcion=0;
                                break;
                        }
                    }
                    if(*resultado_final==0) {
                        printf("Bienvenido estimado(a): %s %s rut:%i\n",nombre,apellidos,rut);
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
