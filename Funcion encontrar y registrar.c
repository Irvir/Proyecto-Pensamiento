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
int main() {
    int resultado_final;
    char nombre[50] = "Marti", apellidos[50] = "Droguett";
    int rut = 10;
    int encontrado;
    encontrar_cuenta(nombre,apellidos,rut,&encontrado);

    if(encontrado==1) {
        printf("existe");

    }
    if(encontrado==0) {
        printf("no existe lol");
        registrar_cuenta(nombre,apellidos,rut);

    }

    return 0;
}
