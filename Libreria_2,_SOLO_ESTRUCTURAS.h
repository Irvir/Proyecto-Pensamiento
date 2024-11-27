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


//------------------------ESTRUCTURAS SUCURSAL----------
typedef struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int interes;
}Sucursal;
