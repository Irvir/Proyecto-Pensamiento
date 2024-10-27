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

// Cambiar resultado_final a un puntero
void encontrar_cuenta(struct sucursales s1[], char *nombre, char *apellidos, int rut, int *resultado_final) {
    int iterador = 0;
    int bandera = 0;
    *resultado_final = 1; // Asumimos que no se encuentra la cuenta

    while (iterador < 100 && bandera == 0) {
        if (s1[iterador].rut == rut && strcmp(s1[iterador].apellidos, apellidos) == 0 && strcmp(s1[iterador].nombre, nombre) == 0) {
            *resultado_final = 0; // Cuenta encontrada
            bandera = 1;
        }
        iterador++;
    }
}

void registrar_cuenta_sucursal(struct sucursales s1[], char *nombre, char *apellidos, int rut) {
    int iterador = 0;
    int bandera = 0;

    while (iterador < 100 && bandera == 0) {
        if (s1[iterador].rut == 0) {
            strcpy(s1[iterador].nombre, nombre);
            strcpy(s1[iterador].apellidos, apellidos);
            s1[iterador].rut = rut;
            bandera = 1;
        }
        iterador++;
    }
}

void imprimir(struct sucursales s1[], int cantidad) {
    printf("Lista de sucursales:\n");
    for (int i = 0; i < cantidad; i++) {
        if (s1[i].rut != 0) { // Solo imprimir cuentas válidas
            printf("Nombre: %s\n", s1[i].nombre);
            printf("Apellidos: %s\n", s1[i].apellidos);
            printf("Rut: %i\n", s1[i].rut);
            printf("---------------------\n");
        }
    }
}

int main() {
    int resultado_final;
    struct sucursales s1[100] = {0}; // Inicializar el arreglo de sucursales
    char nombre[50] = "Martin", apellidos[50] = "Droguett";
    int rut = 10; // Rut de ejemplo

    char nombre2[50]="Pepe",apellidos2[50]="juan";
    int rut2=292929;

    encontrar_cuenta(s1, nombre, apellidos, rut, &resultado_final);
    if (resultado_final == 1) {
        registrar_cuenta_sucursal(s1, nombre, apellidos, rut);
    }

    encontrar_cuenta(s1, nombre, apellidos, rut, &resultado_final);
    if (resultado_final == 1) {
        registrar_cuenta_sucursal(s1, nombre, apellidos, rut);
    }

    encontrar_cuenta(s1, nombre2, apellidos2, rut, &resultado_final);
    if (resultado_final == 1) {
        registrar_cuenta_sucursal(s1, nombre, apellidos, rut2);
    }
    imprimir(s1, 100);

    return 0;
}
