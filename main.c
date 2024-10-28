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

void encontrar_cuenta(struct sucursales s1[], struct sucursales s2[], struct sucursales s3[], struct sucursales s4[], struct sucursales s5[],
                      int opcion, char *nombre, char *apellidos, int rut, int *resultado_final) {
    int iterador = 0;
    *resultado_final = 1;
    struct sucursales *sucursal;

    switch(opcion) {
        case 1: sucursal = s1; break;
        case 2: sucursal = s2; break;
        case 3: sucursal = s3; break;
        case 4: sucursal = s4; break;
        case 5: sucursal = s5; break;
    }

    while (iterador < 100) {
        if (sucursal[iterador].rut == rut &&
            strcmp(sucursal[iterador].nombre, nombre) == 0 &&
            strcmp(sucursal[iterador].apellidos, apellidos) == 0) {
            *resultado_final = 0;
            break;
        }
        iterador++;
    }
}

void registrar_cuenta_sucursal(struct sucursales s1[], struct sucursales s2[], struct sucursales s3[], struct sucursales s4[],
                               struct sucursales s5[], int sucursal, char *nombre, char *apellidos, int rut) {
    int iterador = 0;
    struct sucursales *s;

    switch (sucursal) {
        case 1: s = s1; break;
        case 2: s = s2; break;
        case 3: s = s3; break;
        case 4: s = s4; break;
        case 5: s = s5; break;
    }

    while (iterador < 100) {
        if (s[iterador].rut == 0) {
            strcpy(s[iterador].nombre, nombre);
            strcpy(s[iterador].apellidos, apellidos);
            s[iterador].rut = rut;
            break;
        }
        iterador++;
    }
}

void imprimir(struct sucursales s1[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (s1[i].rut != 0) {
            printf("Nombre: %s\n", s1[i].nombre);
            printf("Apellidos: %s\n", s1[i].apellidos);
            printf("Rut: %i\n", s1[i].rut);
            printf("---------------------\n");
        }
    }
}

void menu(int opcion, struct sucursales s1[], struct sucursales s2[], struct sucursales s3[], struct sucursales s4[], struct sucursales s5[]) {
    int sucursal;
    int resultado_final;
    char nombre[50];
    char apellidos[50];
    int rut;
    int decision_crear_cuenta;

    printf("Menu de opciones:\n1.Ver Cuenta\n2.Crear Cuenta\n3.Operacion de cuentas\n0.Salir\nEscriba su opcion:");
    scanf("%i", &opcion);

    if (opcion == 1) {
        printf("Ingrese su sucursal (1-5): ");
        scanf("%i", &sucursal);

        getchar();  // Limpia el buffer
        printf("Escriba su nombre: ");
        fgets(nombre, 50, stdin);
        nombre[strcspn(nombre, "\n")] = '\0';

        printf("Escriba sus apellidos: ");
        fgets(apellidos, 50, stdin);
        apellidos[strcspn(apellidos, "\n")] = '\0';

        printf("Ingrese su Rut (sin puntos ni dígito verificador): ");
        scanf("%i", &rut);

        encontrar_cuenta(s1, s2, s3, s4, s5, sucursal, nombre, apellidos, rut, &resultado_final);

        if (resultado_final == 1) {
            printf("Estimado(a) %s %s, no se encuentra registrado en la sucursal %i.\nDesea crear una cuenta? (1.Si / 2.No): ", nombre, apellidos, sucursal);
            scanf("%i", &decision_crear_cuenta);

            if (decision_crear_cuenta == 1) {
                registrar_cuenta_sucursal(s1, s2, s3, s4, s5, sucursal, nombre, apellidos, rut);
                imprimir(s1, 100);
            }
        } else {
            printf("Bienvenido(a) estimado(a): %s %s (Rut: %i)\n", nombre, apellidos, rut);
        }
    }
}

int main(void) {
    struct sucursales s1[100] = {0};
    struct sucursales s2[100] = {0};
    struct sucursales s3[100] = {0};
    struct sucursales s4[100] = {0};
    struct sucursales s5[100] = {0};

    menu(0, s1, s2, s3, s4, s5);
    return 0;
}
