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
    if(archivo!=NULL) {
        while(fscanf(archivo,"%s %s %i",encontrar_nombre,encontrar_apellidos,&encontrar_rut)&&*encontrado==0) {
            if(strcmp(encontrar_nombre,nombre)==0 && strcmp(encontrar_apellidos,apellidos)==0 &&encontrar_rut==rut) {
                printf("Existe");
                *encontrado=1;
            }
        }

    }
    fclose(archivo);
}
void registrar_cuenta(char *nombre,char *apellidos,int rut) {

}
int main() {
    int resultado_final;
    struct sucursales s1[100] = {0}; // Inicializar el arreglo de sucursales
    char nombre[50] = "Martin", apellidos[50] = "Droguett";
    int rut = 10;
    int encontrado;
    encontrar_cuenta(nombre,apellidos,rut,&encontrado);

    if(encontrado==1) {
        printf("existe");
        free(encontrado);
    }else {
        printf("no existe lol");
        free(encontrado);
    }

    return 0;
}
