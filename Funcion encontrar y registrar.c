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
struct corriente{
  int saldo;

};
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

void encontrar_cuenta(char *nombre, char *apellidos,int rut,int *encontrado) {
    FILE *archivo;
    archivo=fopen("Sucursal 1.txt","r");
    char encontrar_nombre[50],encontrar_apellidos[50];
    int encontrar_rut=rut;
    *encontrado=0;
    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    int bandera=0;
    int i=0;
    if(archivo!=NULL) {
        while(fscanf(archivo,"%s %s %s %s %s %i",nombres_,encontrar_nombre,apellidos_,encontrar_apellidos,rut_,&encontrar_rut)==6&&bandera==0&&i<1000) {
            if(strcmp(encontrar_nombre,nombre)==0 && strcmp(encontrar_apellidos,apellidos)==0 &&encontrar_rut==rut) {
                printf("Existe");
                *encontrado=1;
                bandera=1;
                break;
            }
        }

    }
    fclose(archivo);
}
void registrar_cuenta(char *nombre,char *apellidos,int rut) {
    FILE *archivo;
    printf("a");
    archivo=fopen("Sucursal 1.txt","a+");
    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    fprintf(archivo,"%s %s %s %s %s %i\n",nombres_,nombre,apellidos_,apellidos,rut_,rut);
    fclose(archivo);
}
void registrar_corriente(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal) {
    FILE *archivo;
    char nombre_imprimir[50]="Nombre:";
    char apellido_imprimir[50]="Apellido";
    char rut_imprimir[50]="Rut:";
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar;

    if(*encontrado==1) {
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
        //Buscar cuenta dentro de la corriente
        int bandera=0;
        while (fscanf(archivo,"%s %s %s %s %s %i",nombre_imprimir,nombre_encontrar,apellido_imprimir,apellidos_encontrar,rut_imprimir,rut_encontrar)==6 && bandera==0) {
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut) {
                *encontrado=1;
                printf("Existe en corriente");
                bandera=1;
            }
        }
        bandera=0;
        fclose(archivo);
    }
    //Cuando No se encuentra
    if(*encontrado==0) {
        if(archivo==NULL) {
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

            fclose(archivo);

    }
    }

}
void ver_cuentas(int *encontrado,int opcion,char *nombre,char *apellidos, int *rut,int *sucursal) {
    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista");
    switch (opcion) {
        case 1:
            printf("\nSe escogio la opcion %i",opcion);
            registrar_corriente(nombre,apellidos,rut,encontrado,sucursal);
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

int main() {
    FILE *archivo;
    archivo=fopen("archivo xd.txt","r");
    char nombre[50];
    while(fscanf(archivo,"Hola: %s",nombre)==1) {
        printf("-\n");
        if(strcmp(nombre,"xd")==0) {
            printf("xd");
        }
        printf("-\n");

    }

    fclose(archivo);


    return 0;
}
