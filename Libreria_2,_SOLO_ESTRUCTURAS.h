//Cuenta Corriente
typedef struct cuenta_corriente {
    int numero_de_cuenta;
    int saldo;
    int interes;
    int comision_mensual;
    int estado;
    int giro;
}Corriente;

//Cuenta Ahorro
typedef struct cuenta_ahorro {
    int estado;
    int numero_de_cuenta;
    long saldo;
    int interes;
    int comision_mensual;
    int giro;
}Ahorro;

//Cuenta Vista
typedef struct cuenta_vista {
    int estado;
    int numero_de_cuenta;
    int saldo;
    int interes;
    int comision_mensual;
    int giro;
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
            printf("\n--> SUELDO:%i || INTERES: %i", aux->corriente.saldo,aux->corriente.interes);
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
    int interes;
}Sucursal;
//------------------------NODO:VISTA--------------------
typedef struct nodo_sucursal {
    Sucursal sucursal;
    struct nodo *siguiente;
}Nodo_S;
typedef struct lista_s {
    Nodo_S *primer_Elemento;
}Lista_s;

//-------------------------CREAR:CUENTA SUCURSAL----------------
Lista_s *crearLista_Sucursal() {
    Lista_s *l=(Lista_s*)malloc(sizeof(Lista_s)*1);
    l->primer_Elemento=NULL;
    return l;
};


//-------------------------CREAR NODO: VISTA-------
Nodo_S* crearNodo_Sucursal(Sucursal s){
    Nodo_S *n = (Nodo_S*)malloc(sizeof(Nodo_S));
    n->sucursal= s;
    n->siguiente = NULL ;
    return n;
}
//------------------------AGREGAR AL FINAL: VISTA----------
void agregar_final_sucursal(Lista_s *l, Sucursal s) {

    Nodo_S *nuevoNodo = crearNodo_Sucursal(s);
    if (l->primer_Elemento == NULL) {
        l->primer_Elemento = nuevoNodo;
    } else {
        Nodo_S *aux = l->primer_Elemento;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}
void imprimir_lista_s(Lista_s *l) {
    if (l->primer_Elemento == NULL) {
        printf("--> NULL\n");
    } else {
        Nodo_S* aux = l->primer_Elemento;
        while (aux != NULL) {
            printf("--> Nombre: %s\n", aux->sucursal.nombre);
            aux = aux->siguiente;
        }
        printf("--> NULL\n");
    }
}

