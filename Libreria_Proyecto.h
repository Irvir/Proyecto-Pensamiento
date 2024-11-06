#include <stdio.h>
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
//------------------------NODO--------------------
typedef struct nodo {
    Corriente corriente;
    struct nodo *siguiente;
}Nodo;
typedef struct lista {
    Nodo *primer_Elemento;
}Lista;
//-------------------------IMPRIMIR---------------
void imprimir_lista(Lista *l){
    if(l->primer_Elemento == NULL){
        printf("--> NULL\n");
    }else{
        Nodo *aux = l->primer_Elemento;
        while(aux != NULL){
            printf("--> %i", aux->corriente.saldo);
            aux = aux->siguiente;
        }

        printf("--> NULL\n");
    }
}
//-------------------------CREAR LISTA----------------
Lista *crearLista_Corriente() {
    Lista *l=(Lista*)malloc(sizeof(Lista)*1);
    l->primer_Elemento=NULL;
    return l;
};
//-------------------------CREAR NODO CORRIENTE-------
Nodo* crearNodo_Corriente(Corriente c){
    Nodo *n = (Nodo*)malloc(sizeof(Nodo)*1);
    n->siguiente = (Nodo*)malloc(sizeof(Nodo)*1);
    n->corriente = c;
    n->siguiente = NULL;
    return n;
}
//------------------------AGREGAR AL FINAL----------
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

//------------------------ESTRUCTURAS SUCURSAL----------
typedef struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int saldo;
    int interes;
}Sucursal;


//------------------------REGISTRAR CUENTA CORRIENTE----------
void registrar_corriente(Lista *l,char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal) {
    FILE *archivo;
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar;
    int saldo_encontrar;
    int saldo;
    int decision_crear_cuenta;
    Corriente corriente;

    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=1;
    int bandera=0;
        switch (*sucursal) {

            case 1:archivo=fopen("Corriente 1.txt","a+");
                if(archivo == NULL) {
                    printf("Se abrio <]con w");
                    archivo=fopen("Corriente 1.txt","w");
                }
                else {printf("Se abrio con a+");
                }
                break;
            case 2:archivo=fopen("Corriente 2.txt","a+");
                if(archivo==NULL) {
                    archivo=fopen("Corriente 2.txt","w");}
                break;
            case 3:archivo=fopen("Corriente 3.txt","a+");
                if(archivo==NULL) {
                    archivo=fopen("Corriente 3.txt","w");
                }
                break;
            case 4:archivo=fopen("Corriente 4.txt","a+");
                if(archivo==NULL) {
                    archivo=fopen("Corriente 4.txt","w");
                }
                break;
            case 5:archivo=fopen("Corriente 5.txt","a+");
                if(archivo==NULL) {
                    archivo=fopen("Corriente 5.txt","w");
                }
                break;

        }
        //-----------------------Buscar cuenta dentro de la corriente---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i",nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar)==4 && bandera==0) {
            printf("a");
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut &&saldo_encontrar==0) {
                *encontrado=1;
                printf("Existe en corriente");
                bandera=1;
            }
            contador++;
        }

        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        printf("No se encuentra en su cuenta Corriente en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
        scanf("%i",&decision_crear_cuenta);
        if(decision_crear_cuenta==1) {
            printf("Ingrese su saldo:  ");
            scanf("%i",&saldo);
            corriente.saldo=saldo;
            agregar_final_Corriente(l,corriente);
            printf("Contador = %i",contador);
            fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,corriente.saldo);

            printf("Creado,%i\n",corriente.saldo);
        }
    }

    if(*encontrado==0) {
        printf("No se encuentra su cuenta");
        printf("Ingresa tu saldo: \n");
        scanf("%i",&saldo);
        corriente.saldo=saldo;
        agregar_final_Corriente(l,corriente);
        fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,corriente.saldo);

    }
    imprimir_lista(l);
    fclose(archivo);
    }



//------------------------ENCONTRAR CUENTA EN GENERAL----------
void encontrar_cuenta(char *nombre, char *apellidos,int *rut,int *sucursal,int *encontrado) {
    FILE *archivo;

    switch (*sucursal) {
        case 1:

            archivo = fopen("Sucursal 1.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 1.txt","w");
                *encontrado=0;
                fclose(archivo);
            }else {
                printf("Encargado(a): Hernesto Fernando\n");

            }
            break;
        case 2:
            printf("Encargado(a): Jimmy Barrera\n");
            archivo = fopen("Sucursal 2.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 2.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 3:
            printf("Encargado(a): Juana Ashe\n");
            archivo = fopen("Sucursal 3.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 3.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 4:
            printf("Encargado(a): Maria Alarcon\n");
            archivo = fopen("Sucursal 4.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 4.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 5:
            printf("Encargado(a): Ester Castillo\n");
            archivo = fopen("Sucursal 5.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 5.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
    }
    char encontrar_nombre[50],encontrar_apellidos[50];
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
                *encontrado=1;
                bandera=1;
                break;
            }
            i++;
        }

    }

    fclose(archivo);
}
//------------------------REGISTRAR CUENTA SUCURSAL----------
void registrar_cuenta_sucursal(char *nombre, char *apellidos, int *rut,int *sucursal) {
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
    fprintf(archivo,"%s %s %s %s %s %i\n",nombres_,nombre,apellidos_,apellidos,rut_,*rut);

    fclose(archivo);

}

//------------------------RELLENAR DATOS----------

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
    printf("Ingrese su Rut: (sin numeros ni digito verificador)");
    scanf("%i", rut);
    getchar();

    encontrar_cuenta(nombre,apellidos,rut,sucursal,encontrado);
}
//------------------------VER TODAS LAS CUENTAS----------

void ver_cuentas(Lista *lista_corriente,int *opcion,char *nombres,char *apellidos,int *encontrado,int *rut, int *sucursal) {

    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista\nOpcion: ");
    scanf("%i",opcion);


    switch (*opcion) {
        case 1:

            registrar_corriente(lista_corriente,nombres,apellidos,rut,encontrado,sucursal );
            printf("------\n");

            break;

        case 2:
            break;
        case 3:
            break;
    }

}