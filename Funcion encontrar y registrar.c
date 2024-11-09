#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cuenta Corriente
typedef struct cuenta_corriente {
    int saldo;
    float interes;
    float comision_mensual;
} Corriente;

// Nodo y Lista
typedef struct nodo {
    Corriente corriente;
    struct nodo *siguiente;
} Nodo;

typedef struct lista {
    Nodo *primer_Elemento;
} Lista;

// Crear lista
Lista *crearLista_Corriente() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->primer_Elemento = NULL;
    return l;
}

// Crear nodo corriente
Nodo* crearNodo_Corriente(Corriente c) {
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    n->corriente = c;
    n->siguiente = NULL;
    return n;
}

// Agregar al final
void agregar_final_Corriente(Lista *l, Corriente c) {
    Nodo *nuevoNodo = crearNodo_Corriente(c);

    if (l->primer_Elemento == NULL) {
        l->primer_Elemento = nuevoNodo;
    } else {
        Nodo *aux = l->primer_Elemento;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}

// Imprimir lista
void imprimir_lista(Lista *l) {
    if (l->primer_Elemento == NULL) {
        printf("--> NULL\n");
    } else {
        Nodo *aux = l->primer_Elemento;
        while (aux != NULL) {
            printf("--> %i", aux->corriente.saldo);
            aux = aux->siguiente;
        }
        printf("--> NULL\n");
    }
}

// Función para registrar cuenta corriente
void registrar_corriente(char *nombre, char *apellidos, int *rut, int *encontrado, int *sucursal, Lista *l) {
    FILE *archivo;
    char nombre_encontrar[50], apellidos_encontrar[50];
    int rut_encontrar, saldo_encontrar;
    int saldo, decision_crear_cuenta;
    Corriente corriente;
    int bandera = 0;

    switch (*sucursal) {
        case 1: archivo = fopen("Corriente 1.txt", "a+"); break;
        case 2: archivo = fopen("Corriente 2.txt", "a+"); break;
        case 3: archivo = fopen("Corriente 3.txt", "a+"); break;
        case 4: archivo = fopen("Corriente 4.txt", "a+"); break;
        case 5: archivo = fopen("Corriente 5.txt", "a+"); break;
        default: printf("Sucursal no válida\n"); return;
    }

    if (*encontrado == 1) {
        while (fscanf(archivo, "Nombre: %s Apellidos: %s Rut: %i Saldo: %i", nombre_encontrar, apellidos_encontrar, &rut_encontrar, &saldo_encontrar) == 4 && bandera == 0) {
            if (strcmp(nombre_encontrar, nombre) == 0 && strcmp(apellidos_encontrar, apellidos) == 0 && rut_encontrar == *rut) {
                printf("Existe en corriente\n");
                bandera = 1;
            }
        }

        if (bandera == 0) {
            printf("No se encuentra en su cuenta Corriente en la sucursal %i, desea agregar?\n(1.Si/2.No)", *sucursal);
            scanf("%i", &decision_crear_cuenta);
            if (decision_crear_cuenta == 1) {
                printf("Ingrese su saldo: ");
                scanf("%i", &saldo);
                corriente.saldo = saldo;
                agregar_final_Corriente(l, corriente);
                fprintf(archivo, "Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n", nombre, apellidos, *rut, corriente.saldo);
                printf("Cuenta creada con saldo: %i\n", corriente.saldo);
            }
        }
    } else {
        printf("No se encuentra su cuenta. Ingrese su saldo: ");
        scanf("%i", &saldo);
        corriente.saldo = saldo;
        agregar_final_Corriente(l, corriente);
        fprintf(archivo, "Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n", nombre, apellidos, *rut, corriente.saldo);
    }

    imprimir_lista(l);
    fclose(archivo);
}

// Función principal y otras funciones no modificadas permanecen iguales...
int main() {
    Lista *lista = crearLista_Corriente();

    char nombre[50], apellidos[50];
    int rut, sucursal = 1, encontrado = 0;

    // Prueba de agregar cuentas
    imprimir_lista(lista);
    return 0;
}
