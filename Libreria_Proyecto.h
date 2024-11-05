#include <stdio.h>

//Cuenta: Sucursal
typedef struct sucursales {
    char nombre[50];
    char apellidos[50];
    int rut;
    int saldo;
    int interes;
}Sucursal;

//Cuenta Corriente
typedef struct cuenta_corriente {
    int saldo;
    float interes;
    float comision_mensual;
}Corriente;
//Lista de Estructuras
Corriente corriente_s1[1000]={0};
Corriente corriente_s2[1000]={0};
Corriente corriente_s3[1000]={0};
Corriente corriente_s4[1000]={0};
Corriente corriente_s5[1000]={0};


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

void registrar_corriente(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal) {
    FILE *archivo;
    Corriente *corriente;
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar;
    int saldo_encontrar;

    int decision_crear_cuenta;

    switch (*sucursal) {
        case 1:
            corriente = corriente_s1;
            break;
        case 2:
            corriente = corriente_s2;
            break;
        case 3:
            corriente = corriente_s3;
            break;
        case 4:
            corriente = corriente_s4;
            break;
        case 5:
            corriente = corriente_s5;
        break;

    }

    //SE ENCUENTRA CUENTA EN SUCURSAL
    int contador=0;

    if(*encontrado==1) {
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
        //Buscar cuenta dentro de la corriente
        int bandera=0;
        while (fscanf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i",nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar)==4 && bandera==0) {
            printf("a");
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut &&saldo_encontrar==0) {
                *encontrado=1;
                printf("Existe en corriente");
                bandera=1;
            }
            contador++;
        }
        bandera=0;

        //NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO
        if(bandera==0) {
            printf("No se encuentra en su cuenta Corriente en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
            scanf("%i",&decision_crear_cuenta);
            if(decision_crear_cuenta==1) {
                printf("Ingrese su saldo:  ");
                scanf("%i",&(corriente[contador].saldo));
                printf("Contador = %i",contador);
                fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i\n",nombre,apellidos,*rut,corriente[contador].saldo);

                printf("Creado");
            }

        }
    }

    //Cuando No se encuentra el archivo. FUNCIONA
    if(*encontrado==0) {
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
            printf("Digite su saldo");
            scanf("%i",&(corriente->saldo));
            fprintf(archivo,"Nombre: %s Apellido: %s Rut: %i Saldo: %i\n",nombre,apellidos,*rut,corriente_s1[contador].saldo);
            printf("Contador = %i",contador);
            printf("Existe corriente");



    }
    fclose(archivo);
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


void encontrar_cuenta(char *nombre, char *apellidos,int *rut,int *sucursal,int *encontrado) {
    FILE *archivo;

    switch (*sucursal) {
        case 1:
            archivo = fopen("Sucursal 1.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 1.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 2:
            archivo = fopen("Sucursal 2.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 2.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 3:
            archivo = fopen("Sucursal 3.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 3.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 4:
            archivo = fopen("Sucursal 4.txt","r");
            if(archivo==NULL) {
                archivo=fopen("Sucursal 4.txt","w");
                *encontrado=0;
                fclose(archivo);
            }
            break;
        case 5:
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


    printf("Ingrese su Rut: ");
    scanf("%i", rut);
    getchar();

    encontrar_cuenta(nombre,apellidos,rut,sucursal,&encontrado);
}
void ver_cuentas(int *opcion,char *nombres,char *apellidos,int *encontrado,int *rut, int *sucursal) {

    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista\nOpcion: ");
    scanf("%i",opcion);


    switch (*opcion) {
        case 1:

            registrar_corriente(nombres,apellidos,rut,encontrado,sucursal);
            printf("------\n");

            break;

        case 2:
            break;
        case 3:
            break;
    }

}