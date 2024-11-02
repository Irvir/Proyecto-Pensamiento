#include <stdio.h>

//Cuenta: Sucursal
typedef struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int saldo;
    int interes;
}Sucursal;

//Cuenta Corriente
typedef struct cuenta_corriente {
    int saldo;
    float interes;
    float comision_mensual;
}Corriente;

//Cuenta Ahorro
typedef struct cuenta_ahorro {
    int saldo;
    float interes;
    float comision_mensual;
}Ahorro;

//Cuenta Vista
typedef struct cuenta_vista {
    int saldo;
    float interes;
    float comision_mensual;
}Vista;

void crear_archivo_w(int *tipo_de_cuenta,int *sucursal, FILE *archivo) {
    //Tomo como 1: Corriente, 2: Ahorro, Vista
    switch (*tipo_de_cuenta) {
        case 1:
            switch (*sucursal) {
                case 1:
                    archivo=fopen("Corriente 1.txt","w");
                    break;
                case 2:
                    archivo=fopen("Corriente 2.txt","w");
                    break;

                case 3:
                    archivo=fopen("Corriente 3.txt","w");

                    break;
                case 4:
                    archivo=fopen("Corriente 4.txt","w");

                    break;
                case 5:
                    archivo=fopen("Corriente 5.txt","w");
                    break;


            }
            break;
        case 2:
            switch (*sucursal) {
                case 1:
                    archivo=fopen("Ahorro 1.txt","w");
                    break;
                case 2:
                    archivo=fopen("Ahorro 2.txt","w");
                    break;
                case 3:
                    archivo=fopen("Ahorro 3.txt","w");
                    break;
                case 4:
                    archivo=fopen("Ahorro 4.txt","w");
                    break;
                case 5:
                    archivo=fopen("Ahorro 5.txt","w");
                    break;

            }
            break;
        case 3:
            switch (*sucursal) {
                case 1:
                    archivo=fopen("Vista 1.txt","w");
                    break;
                case 2:
                    archivo=fopen("Vista 2.txt","w");
                    break;
                case 3:
                    archivo=fopen("Vista 3.txt","w");
                    break;
                case 4:
                    archivo=fopen("Vista 4.txt","w");
                    break;
                case 5:
                    archivo=fopen("Vista 5.txt","w");
                    break;
            }
            break;

    }
}

void crear_archivo_a(int *tipo_de_cuenta,int *sucursal, FILE *archivo) {
    //Tomo como 1: Corriente, 2: Ahorro, Vista
    switch (*tipo_de_cuenta) {
        case 1:
            switch (*sucursal) {
                case 1:
                    archivo=fopen("Corriente 1.txt","a+");
                    break;
                case 2:
                    archivo=fopen("Corriente 2.txt","a+");
                    break;

                case 3:
                    archivo=fopen("Corriente 3.txt","a+");

                    break;
                case 4:
                    archivo=fopen("Corriente 4.txt","a+");

                    break;
                case 5:
                    archivo=fopen("Corriente 5.txt","a+");
                    break;


            }
            break;
        case 2:
            switch (*sucursal) {
                case 1:
                    archivo=fopen("Ahorro 1.txt","a+");
                    break;
                case 2:
                    archivo=fopen("Ahorro 2.txt","a+");
                    break;
                case 3:
                    archivo=fopen("Ahorro 3.txt","a+");
                    break;
                case 4:
                    archivo=fopen("Ahorro 4.txt","a+");
                    break;
                case 5:
                    archivo=fopen("Ahorro 5.txt","a+");
                    break;

            }
            break;
        case 3:
            switch (*sucursal) {
                case 1:
                    archivo=fopen("Vista 1.txt","a+");
                    break;
                case 2:
                    archivo=fopen("Vista 2.txt","a+");
                    break;
                case 3:
                    archivo=fopen("Vista 3.txt","a+");
                    break;
                case 4:
                    archivo=fopen("Vista 4.txt","a+");
                    break;
                case 5:
                    archivo=fopen("Vista 5.txt","a+");
                    break;
            }
            break;

    }
}


void encontrar_cuenta(char *nombre, char *apellidos,int *rut,int *sucursal,int *encontrado) {
    FILE *archivo;

    switch (*sucursal) {
        case 1:
            archivo = fopen("Sucursal 1.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 1.txt","w");
            *encontrado=0;
            fclose(archivo);
        }
        break;
        case 2:
            archivo = fopen("Sucursal 2.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 2.txt","w");
            *encontrado=0;
            fclose(archivo);
        }
        break;
        case 3:
            archivo = fopen("Sucursal 3.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 3.txt","w");
            *encontrado=0;
            fclose(archivo);
        }
        break;
        case 4:
            archivo = fopen("Sucursal 4.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 4.txt","w");
            *encontrado=0;
            fclose(archivo);
        }
        break;
        case 5:
            archivo = fopen("Sucursal 5.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 5.txt","w");
            *encontrado=0;
            fclose(archivo);
        }
        break;
    }
    char encontrar_nombre[50],encontrar_apellidos[50];
    printf("llegue");
    int encontrar_rut=*rut;
    *encontrado=0;
    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    int bandera=0;
    int i=0;


    if(archivo!=NULL) {
        while(fscanf(archivo,"%s %s %s %s %s %i",nombres_,encontrar_nombre,apellidos_,encontrar_apellidos,rut_,&encontrar_rut)==6&&bandera==0&&i<1000) {
            if(strcmp(encontrar_nombre,nombre)==0 && strcmp(encontrar_apellidos,apellidos)==0 &&  encontrar_rut== *rut) {
                printf("se encuentra en: %i",i);
                *encontrado=1;
                bandera=1;
                break;
            }
            i++;
        }

    }
    printf("llegue aqui tambien");
    fclose(archivo);
}

void registrar_cuenta_sucursal(char *nombre, char *apellidos, int rut,int *sucursal) {
    FILE *archivo;
    switch (*sucursal) {
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
void rellenar_datos_cuentas(int sucursal,int *iterador) {
    FILE *archivo;

}
void datos(int *encontrado,int *sucursal,char *nombre, char *apellidos,int  *rut ) {
    printf("Ingrese su sucursal (1-5): ");
    scanf("%i", sucursal);

    getchar();
    printf("Escriba su nombre: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("Escriba sus apellidos: ");
    fgets(apellidos, 50, stdin);
    apellidos[strcspn(apellidos, "\n")] = '\0';

    printf("Ingrese su Rut (sin puntos ni digito verificador): ");
    scanf("%i", rut);

    encontrar_cuenta(nombre,apellidos,rut,sucursal,&encontrado);
}
void ver_cuentas(int opcion) {
    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista");
    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }
}