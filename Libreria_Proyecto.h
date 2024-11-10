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
//------------------------NODO:CORRIENTE--------------------
typedef struct nodo_corriente {
    Corriente corriente;
    struct nodo *siguiente;
}Nodo_C;
//------------------------LISTA:CORRIENTE--------------------

typedef struct lista_c {
    Nodo_C *primer_Elemento;
}Lista_c;
//-------------------------IMPRIMIR LISTA ENLAZADA:CORRIENTE---------------
void imprimir_lista_c(Lista_c *l){
    if(l->primer_Elemento == NULL){
        printf("--> NULL\n");
    }else{
        Nodo_C *aux = l->primer_Elemento;
        while(aux != NULL){
            printf("--> %i", aux->corriente.saldo);
            aux = aux->siguiente;
        }

        printf("--> NULL\n");
    }
}
//-------------------------CREAR LISTA: CUENTA CORRIENTE----------------
Lista_c *crearLista_Corriente() {
    Lista_c *l=(Lista_c*)malloc(sizeof(Lista_c)*1);
    l->primer_Elemento=NULL;
    return l;
};
//-------------------------CREAR NODO CORRIENTE-------
Nodo_C* crearNodo_Corriente(Corriente c){
    Nodo_C *n = (Nodo_C*)malloc(sizeof(Nodo_C)*1);
    n->corriente = c;
    n->siguiente = NULL ;
    return n;
}
//------------------------AGREGAR AL FINAL: CUENTA CORRIENTE----------
void agregar_final_Corriente(Lista_c *l, Corriente c) {

    Nodo_C *nuevoNodo = crearNodo_Corriente(c);
    if (l->primer_Elemento == NULL) {
        l->primer_Elemento = nuevoNodo;
    } else {
        Nodo_C *aux = l->primer_Elemento;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}
//------------------------NODO:AHORRO--------------------
typedef struct nodo_ahorro {
    Ahorro ahorro;
    struct nodo *siguiente;
}Nodo_A;
//------------------------LISTA:AHORRO--------------------

typedef struct lista {
    Nodo_A *primer_Elemento;
}Lista_a;
//-------------------------IMPRIMIR LISTA ENLAZADA:AHORRO---------------
void imprimir_lista_a(Lista_a *l){
    if(l->primer_Elemento == NULL){
        printf("--> NULL\n");
    }else{
        Nodo_A*aux = l->primer_Elemento;
        while(aux != NULL){
            printf("--> %i", aux->ahorro.saldo);
            aux = aux->siguiente;
        }

        printf("--> NULL\n");
    }
}
//-------------------------CREAR:CUENTA AHORRO----------------
Lista_a *crearLista_Ahorro() {
    Lista_a *l=(Lista_a*)malloc(sizeof(Lista_a)*1);
    l->primer_Elemento=NULL;
    return l;
};
//-------------------------CREAR NODO: AHORRO-------
Nodo_A* crearNodo_Ahorro(Ahorro a){
    Nodo_A *n = (Nodo_A*)malloc(sizeof(Nodo_A)*1);
    n->ahorro= a;
    n->siguiente = NULL ;
    return n;
}
//------------------------AGREGAR AL FINAL: AHORRO----------
void agregar_final_ahorro(Lista_a *l, Ahorro a) {

    Nodo_A *nuevoNodo = crearNodo_Ahorro(a);
    if (l->primer_Elemento == NULL) {
        l->primer_Elemento = nuevoNodo;
    } else {
        Nodo_A *aux = l->primer_Elemento;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}

//------------------------NODO:VISTA--------------------
typedef struct nodo_vista {
    Vista vista;
    struct nodo *siguiente;
}Nodo_V;
//------------------------LISTA:VISTA--------------------

typedef struct lista_vista {
    Nodo_V *primer_Elemento;
}Lista_v;
//-------------------------IMPRIMIR LISTA ENLAZADA:AHORRO---------------
void imprimir_lista_v(Lista_v *l){
    if(l->primer_Elemento == NULL){
        printf("--> NULL\n");
    }else{
        Nodo_V *aux = l->primer_Elemento;
        while(aux != NULL){
            printf("--> %i", aux->vista.saldo);
            aux = aux->siguiente;
        }

        printf("--> NULL\n");
    }
}
//-------------------------CREAR:CUENTA VISTA----------------
Lista_v *crearLista_Vista() {
    Lista_v *l=(Lista_v*)malloc(sizeof(Lista_v)*1);
    l->primer_Elemento=NULL;
    return l;
};
//-------------------------CREAR NODO: VISTA-------
Nodo_V* crearNodo_Vista(Vista v){
    Nodo_V *n = (Nodo_V*)malloc(sizeof(Nodo_V)*1);
    n->vista= v;
    n->siguiente = NULL ;
    return n;
}
//------------------------AGREGAR AL FINAL: VISTA----------
void agregar_final_vista(Lista_v *l, Vista v) {

    Nodo_V *nuevoNodo = crearNodo_Vista(v);
    if (l->primer_Elemento == NULL) {
        l->primer_Elemento = nuevoNodo;
    } else {
        Nodo_V *aux = l->primer_Elemento;
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
void registrar_corriente(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal) {
    FILE *archivo;
    Lista_c *l=crearLista_Corriente();
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar;
    int saldo_encontrar;
    int saldo;
    int decision_crear_cuenta;
    Corriente corriente;


    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=0;
    int bandera=0;
        switch (*sucursal) {

            case 1:archivo=fopen("Corriente 1.txt","r");
                if(archivo == NULL) {
                    *encontrado=0;
                    archivo=fopen("Corriente 1.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Corriente 1.txt","a+");
                }

                break;
            case 2:archivo=fopen("Corriente 2.txt","r");
                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Corriente 2.txt","a+");}
                else {
                    fclose(archivo);
                    archivo=fopen("Corriente 2.txt","a+");
                }
                break;
            case 3:archivo=fopen("Corriente 3.txt","r");
                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Corriente 3.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Corriente 3.txt","a+");
                }
                break;
            case 4:archivo=fopen("Corriente 4.txt","r");
                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Corriente 4.txt","a+");
                }
                else {
                    fclose(archivo);
                    archivo=fopen("Corriente 4.txt","a+");
                }
                break;
            case 5:archivo=fopen("Corriente 5.txt","r");
                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Corriente 5.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Corriente 5.txt","a+");
                }
                break;

        }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i\n",nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar)==4 && bandera==0) {
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut) {
                *encontrado=1;
                bandera=1;
            }
            corriente.saldo=saldo_encontrar;
            contador++;
            agregar_final_Corriente(l,corriente);



        }

        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        if(*encontrado==0) {
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

    }

    if(*encontrado==0) {
        printf("No se encuentra su cuenta");
        printf("Ingresa tu saldo: \n");
        scanf("%i",&saldo);
        corriente.saldo=saldo;
        agregar_final_Corriente(l,corriente);
        fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,corriente.saldo);

    }
    fclose(archivo);
    }

//------------------------REGISTRAR CUENTA AHORRO----------
void registrar_ahorro(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal) {
    FILE *archivo;
    Lista_a *l=crearLista_Ahorro();
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar;
    int saldo_encontrar;
    int saldo;
    int decision_crear_cuenta;
    Ahorro ahorro;
    int contador=0;
    int bandera=0;
        switch (*sucursal) {

            case 1:archivo=fopen("Ahorro 1.txt","r");
                if(archivo == NULL) {
                    *encontrado=0;
                }else {
                    fclose(archivo);
                    archivo=fopen("Ahorro 1.txt","a+");

                    *encontrado=0;
                }

                break;
            case 2:archivo=fopen("Ahorro 2.txt","r");
                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Ahorro 2.txt","a+");}
                else {
                    fclose(archivo);
                    archivo=fopen("Ahorro 2.txt","a+");
                }
                break;
            case 3:archivo=fopen("Ahorro 3.txt","r");
                if(archivo==NULL) {
                    archivo=fopen("Ahorro 3.txt","a+");
                    *encontrado=0;
                }else {
                    fclose(archivo);
                    archivo=fopen("Ahorro 3.txt","a+");
                }
                break;
            case 4:archivo=fopen("Ahorro 4.txt","r");

                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Ahorro 4.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Ahorro 4.txt","a+");
                }
                break;
            case 5:archivo=fopen("Ahorro 5.txt","r");

                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Ahorro 5.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Ahorro 5.txt","a+");
                }
                printf("encontrado %i",*encontrado);
                break;

        }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i\n",nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar)==4 && bandera==0) {
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut) {
                *encontrado=1;
                bandera=1;
            }
            ahorro.saldo=saldo_encontrar;
            contador++;
            agregar_final_ahorro(l,ahorro);

        }

        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        if(*encontrado==0) {
            printf("No se encuentra en su cuenta Corriente en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
            scanf("%i",&decision_crear_cuenta);
            if(decision_crear_cuenta==1) {
                printf("Ingrese su saldo:  ");
                scanf("%i",&saldo);
                ahorro.saldo=saldo;
                agregar_final_ahorro(l,ahorro);
                printf("Contador = %i",contador);
                fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,ahorro.saldo);

                printf("Creado,%i\n",ahorro.saldo);
            }

        }

    }

    if(*encontrado==0) {
        printf("No se encuentra su cuenta");
        printf("Ingresa tu saldo: \n");
        scanf("%i",&saldo);
        ahorro.saldo=saldo;
        agregar_final_ahorro(l,ahorro);
        fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,ahorro.saldo);

    }
    fclose(archivo);
    }

//------------------------REGISTRAR CUENTA AHORRO----------
void registrar_vista(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal) {
    FILE *archivo;
    Lista_v *l= crearLista_Vista();
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar;
    int saldo_encontrar;
    int saldo;
    int decision_crear_cuenta;
    Vista vista;
    int contador=0;
    int bandera=0;
        switch (*sucursal) {

            case 1:archivo=fopen("Vista 1.txt","r");
                if(archivo == NULL) {
                    *encontrado=0;
                }else {
                    fclose(archivo);
                    archivo=fopen("Vista 1.txt","a+");

                    *encontrado=0;
                }

                break;
            case 2:archivo=fopen("Vista 2.txt","r");
                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Vista 2.txt","a+");}
                else {
                    fclose(archivo);
                    archivo=fopen("Vista 2.txt","a+");
                }
                break;
            case 3:archivo=fopen("Vista 3.txt","r");
                if(archivo==NULL) {
                    archivo=fopen("Vista 3.txt","a+");
                    *encontrado=0;
                }else {
                    fclose(archivo);
                    archivo=fopen("Vista 3.txt","a+");
                }
                break;
            case 4:archivo=fopen("Vista 4.txt","r");

                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Vista 4.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Vista 4.txt","a+");
                }
                break;
            case 5:archivo=fopen("Vista 5.txt","r");

                if(archivo==NULL) {
                    *encontrado=0;
                    archivo=fopen("Vista 5.txt","a+");
                }else {
                    fclose(archivo);
                    archivo=fopen("Vista 5.txt","a+");
                }
                printf("encontrado %i",*encontrado);
                break;

        }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i\n",nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar)==4 && bandera==0) {
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut) {
                *encontrado=1;
                bandera=1;
            }
            vista.saldo=saldo_encontrar;
            contador++;
            agregar_final_vista(l,vista);

        }

        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        if(*encontrado==0) {
            printf("No se encuentra en su cuenta Corriente en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
            scanf("%i",&decision_crear_cuenta);
            if(decision_crear_cuenta==1) {
                printf("Ingrese su saldo:  ");
                scanf("%i",&saldo);
                vista.saldo=saldo;
                agregar_final_vista(l,vista);
                printf("Contador = %i",contador);
                fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,vista.saldo);

                printf("Creado,%i\n",vista.saldo);
            }

        }

    }

    if(*encontrado==0) {
        printf("No se encuentra su cuenta");
        printf("Ingresa tu saldo: \n");
        scanf("%i",&saldo);
        vista.saldo=saldo;
        agregar_final_vista(l,vista);
        fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",nombre,apellidos,*rut,vista.saldo);

    }
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

void ver_cuentas(int *opcion,char *nombres,char *apellidos,int *encontrado,int *rut, int *sucursal) {

    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista\nOpcion: ");
    scanf("%i",opcion);
    switch (*opcion) {
        case 1:registrar_corriente(nombres,apellidos,rut,encontrado,sucursal );break;
        case 2:registrar_ahorro(nombres,apellidos,rut,encontrado,sucursal );break;
        case 3:registrar_vista(nombres,apellidos,rut,encontrado,sucursal);break;
    }

}