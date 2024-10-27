#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//h
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

void encontrar_cuenta(struct sucursales s1[],struct sucursales s2[],struct sucursales s3[],struct sucursales s4[],struct sucursales s5[],
    int opcion,char *nombre,char *apellidos,int rut,int *resultado_final){

    int iterador = 0;
    int bandera = 0;
    *resultado_final = 1;
    switch(opcion) {
        case 1:
            while (iterador < 100 && bandera == 0) {
                if (s1[iterador].rut == rut && strcmp(s1[iterador].apellidos,apellidos) == 0 && strcmp(s1[iterador].nombre,nombre) == 0) {
                    *resultado_final = 0;
                    bandera = 1;
                }
                iterador++;
            }
            break;

        case 2:
            while (iterador < 100 && bandera == 0) {
                if (s2[iterador].rut == rut && strcmp(s2[iterador].apellidos,apellidos) == 0 && strcmp(s2[iterador].nombre,nombre) == 0) {
                    *resultado_final = 0;
                    bandera = 1;
                }
                iterador++;
            }
            break;
        case 3:
            while (iterador < 100 && bandera == 0) {
                if (s3[iterador].rut == rut && strcmp(s3[iterador].apellidos,apellidos) == 0 && strcmp(s3[iterador].nombre,nombre) == 0) {
                    *resultado_final = 0;
                    bandera = 1;
                }
                iterador++;
            }
            break;
        case 4:
            while (iterador < 100 && bandera == 0) {
                if (s4[iterador].rut == rut && strcmp(s4[iterador].apellidos,apellidos) == 0 && strcmp(s4[iterador].nombre,nombre) == 0) {
                    *resultado_final = 0;
                    bandera = 1;
                }
                iterador++;
            }
            break;
        case 5:
            while (iterador < 100 && bandera == 0) {
                if (s5[iterador].rut == rut && strcmp(s5[iterador].apellidos,apellidos) == 0 && strcmp(s5[iterador].nombre,nombre) == 0) {
                    *resultado_final = 0;
                    bandera = 1;
                }
                iterador++;
            }
            break;
    }

}


void registrar_cuenta_sucursal(struct sucursales s1[], struct sucursales s2[], struct sucursales s3[], struct sucursales s4[],
    struct sucursales s5[], int sucursal,char *nombre,char *apellidos,int rut) {
    int iterador=0;
    int bandera=0;
    //Estructura
    switch(sucursal) {
        case 1:
            while(iterador<100  && bandera==0) {
                if(s1[iterador].rut==0) {
                    strcpy(s1[iterador].nombre,nombre);
                    strcpy(s1[iterador].apellidos,apellidos);
                    s1[iterador].rut=rut;
                    bandera=1;
                }
                iterador++;
            }
            break;
        case 2:
            while(iterador<100  && bandera==0) {
                if(s2[iterador].rut==0) {
                    strcpy(s2[iterador].nombre,nombre);
                    strcpy(s2[iterador].apellidos,apellidos);
                    s2[iterador].rut=rut;
                    bandera=1;
                }
                iterador++;
            }
            break;
        case 3:
            while(iterador<100  && bandera==0) {
                if(s3[iterador].rut==0) {
                    strcpy(s3[iterador].nombre,nombre);
                    strcpy(s3[iterador].apellidos,apellidos);
                    s3[iterador].rut=rut;
                    bandera=1;
                }
                iterador++;
            }
            break;
        case 4:
            while(iterador<100  && bandera==0) {
                if(s4[iterador].rut==0) {
                    strcpy(s4[iterador].nombre,nombre);
                    strcpy(s4[iterador].apellidos,apellidos);
                    s4[iterador].rut=rut;
                    bandera=1;
                }
                iterador++;
            }
            break;
        case 5:
            while(iterador<100  && bandera==0) {
                if(s5[iterador].rut==0) {
                    strcpy(s5[iterador].nombre,nombre);
                    strcpy(s5[iterador].apellidos,apellidos);
                    s5[iterador].rut=rut;
                    bandera=1;
                }
                iterador++;
            }
            break;
    }


}
void imprimir(struct sucursales s1[],struct sucursales s2[],struct sucursales s3[],struct sucursales s4[],struct sucursales s5[], int cantidad,int opcion) {

    switch (opcion) {
        case 1:
            printf("Lista de sucursales:\n");
            for (int i = 0; i < cantidad; i++) {
                if (s1[i].rut != 0) {
                    printf("Nombre: %s\n", s1[i].nombre);
                    printf("Apellidos: %s\n", s1[i].apellidos);
                    printf("Rut: %i\n", s1[i].rut);
                    printf("---------------------\n");
                    }
                }
            break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
    }

}
//Apellidos,Nombre,Rut
void menu(int opcion,struct sucursales s1[],struct sucursales s2[],struct sucursales s3[],struct sucursales s4[],struct sucursales s5[]) {
    FILE *archivo;
    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta.\n3.Operacion de cuentas.\n0.Salir\nEscriba su opcion:");
    scanf("%i",&opcion);



    char nombre[50];
    char apellidos[50];
    int rut;

    int sucursal;


    int estado_cuenta;
    int *resultado_final=(int*)malloc(sizeof(int)*1);

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

                    encontrar_cuenta(s1,s2,s3,s4,s5,sucursal,nombre,apellidos,rut,resultado_final);
                    if(*resultado_final==1) {
                        printf("Estimado(a): %s %s no se encuentra registrado(a) en la sucursal %i.\nDesea crear una cuenta?\n 1.Si\n2.no",nombre,apellidos,opcion);
                        scanf("%i",&decision_crear_cuenta);
                        getchar();
                        switch(decision_crear_cuenta) {
                            case 1:
                                registrar_cuenta_sucursal(s1,s2,s3,s4,s5,sucursal,nombre,apellidos,rut);
                                imprimir(s1,s2,s3,s4,s5,100,opcion);
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
            break;
        case 3:
            printf("Ingrese su sucursal");
            break;
        case 0:
            break;
    }

}
int main(void) {

    struct sucursales s1[100]={0};
    struct sucursales s2[100]={0};
    struct sucursales s3[100]={0};
    struct sucursales s4[100]={0};
    struct sucursales s5[100]={0};
    menu(0,s1,s2,s3,s4,s5);
    return 0;
}
