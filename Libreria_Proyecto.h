#include <stdio.h>
#include "Libreria_2,_SOLO_ESTRUCTURAS.h"
void verificar_saldo(int *saldo,int tipo_de_cuenta,int *activo) {
    switch (tipo_de_cuenta) {
        case 1:break;
        case 2:
            if(*saldo<100000) {
                *activo=0;
            }
            *activo=1;
            break;
        case 3:
            if(*saldo>2500000) {
                *activo=0;
            }
            *activo=1;
            break;

    }


}
int interes(int *tipo_cuenta, int *saldo) {
    int interes=0;
    printf("-----------------\n");
    printf("Saldo: %i\n", *saldo);
    switch (*tipo_cuenta) {
        case 1:  // Cuenta Corriente
            if (*saldo <= 150000) {
                Corriente corriente;
                interes = 5;
                corriente.interes = interes;
            } else if (*saldo > 150000 && *saldo < 600000) {
                interes = 10;
            } else if (*saldo >= 600000 && *saldo < 1500000) {
                interes = 15;
            } else {
                interes = 25;
            }
        break;
        case 2:  // Cuenta Ahorro
        case 3:  // Cuenta Vista
            if (*saldo <= 150000) {
                interes = 5;
            } else if (*saldo > 150000 && *saldo < 600000) {
                interes = 10;
            } else if (*saldo >= 600000 && *saldo < 1500000) {
                interes = 15;
            } else {
                interes = 25;
            }
        break;
    }
    printf("||||||||||||%i",interes);
    return interes;
}

int comision(int *tipo_cuenta, int *saldo) {
    int comision=0;
    Corriente corriente;
    Ahorro ahorro;
    Vista vista;
    printf("-----------------\n");
    switch (*tipo_cuenta) {
        case 1:  // Cuenta Corriente
            if (*saldo <= 150000) {
                comision = 10000;
                corriente.comision_mensual = comision;

            } else if (*saldo > 150000 && *saldo < 600000) {
                comision = 20000;
                corriente.comision_mensual = comision;
            } else if (*saldo >= 600000 && *saldo < 1500000) {
                comision = 50000;
                corriente.comision_mensual = comision;
            } else {
                comision = 100000;
                corriente.comision_mensual = comision;
            }
        break;
        case 2:  // Cuenta Ahorro
        case 3:  // Cuenta Vista
            if (*saldo <= 150000) {
                comision = 10000;
                vista.comision_mensual = comision;

            } else if (*saldo > 150000 && *saldo < 600000) {
                comision = 20000;
                vista.comision_mensual = comision;
            } else if (*saldo >= 600000 && *saldo < 1500000) {
                comision = 50000;
                vista.comision_mensual = comision;
            } else {
                comision = 100000;
                vista.comision_mensual = comision;
            }
        break;
    }
    return comision;
}

//------------------------REGISTRAR CUENTA CORRIENTE----------
void registrar_corriente(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion) {
    FILE *archivo;
    Lista_c *l=crearLista_Corriente();
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar,saldo_encontrar,interes_encontrar,comision_encontrar;
    int *saldo=(int *)malloc(sizeof(int)*1);
    int interes_final,comision_final;

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
        while (fscanf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i Interes: %i Comision: %i\n",nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&interes_encontrar,&comision_encontrar)==6 && bandera==0) {
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut) {
                interes(opcion,saldo);
                *encontrado=1;
                bandera=1;
            }
            corriente.saldo=saldo_encontrar;
            corriente.interes=interes_encontrar;
            corriente.comision_mensual=comision_encontrar;
            contador++;
            agregar_final_Corriente(l,corriente);



        }

        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        if(*encontrado==0) {
            printf("No se encuentra en su cuenta Corriente en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
            scanf("%i",&decision_crear_cuenta);
            if(decision_crear_cuenta==1) {
                printf("Ingrese su saldo:  ");
                scanf("%i",saldo);
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
        scanf("%i",saldo);
        corriente.saldo=*saldo;
        interes_final=interes(opcion,saldo);
        comision_final=comision(opcion,saldo);
        corriente.interes=interes_final;
        corriente.comision_mensual=comision_final;
        agregar_final_Corriente(l,corriente);
        fprintf(archivo,"Nombre: %s Apellidos: %s Rut: %i Saldo: %i Interes: %i Comision: %i\n",nombre,apellidos,*rut,corriente.saldo,interes_final,corriente.comision_mensual);

    }
    printf("\n---CUENTA CORRIENTE---\nInformacion de la cuenta:\nNombre: %s \nApellidos: %s \nRut: %i\nSaldo:%i \nInteres: %i\nComision %i",nombre,apellidos,*rut,corriente.saldo,corriente.interes,corriente.comision_mensual);
    imprimir_lista_c(l);
    fclose(archivo);
    }



//------------------------ENCONTRAR CUENTA EN GENERAL----------
void encontrar_cuenta(char *nombre, char *apellidos,int *rut,int *sucursal,int *encontrado,int *numero_Cuenta) {

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

    int numero_cuenta_encontrar;
    int i=0;
    int bandera=0;
    printf("ENCONTRE AUQI: %i\n",*encontrado);



    if(archivo!=NULL && *encontrado!=1) {
        while(fscanf(archivo,"Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n",&numero_cuenta_encontrar,
            encontrar_nombre,encontrar_apellidos,&encontrar_rut)==4 && bandera==0) {
            if(numero_cuenta_encontrar==*numero_Cuenta) {
                *encontrado=1;
                bandera=1;
                break;
            }

        }

    }

    fclose(archivo);
}
void mensaje_bienvenido(char *nombre, char *apellidos,int *rut,int *sucursal,int *numero_Cuenta) {
    FILE *archivo;

    switch (*sucursal) {
        case 1:
            archivo = fopen("Sucursal 1.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 1.txt","w");
            fclose(archivo);
        }

        break;
        case 2:
            printf("Encargado(a): Jimmy Barrera\n");
        archivo = fopen("Sucursal 2.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 2.txt","w");
            fclose(archivo);
        }
        break;
        case 3:
            printf("Encargado(a): Juana Ashe\n");
        archivo = fopen("Sucursal 3.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 3.txt","w");
            fclose(archivo);
        }
        break;
        case 4:
            printf("Encargado(a): Maria Alarcon\n");
        archivo = fopen("Sucursal 4.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 4.txt","w");
            fclose(archivo);
        }
        break;
        case 5:
            printf("Encargado(a): Ester Castillo\n");
        archivo = fopen("Sucursal 5.txt","r");
        if(archivo==NULL) {
            archivo=fopen("Sucursal 5.txt","w");
            fclose(archivo);
        }
        break;
    }
    char encontrar_nombre[50],encontrar_apellidos[50];
    int encontrar_rut=*rut;

    int numero_cuenta_encontrar;
    int i=0;
    int bandera=0;

    while(fscanf(archivo,"Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n",&numero_cuenta_encontrar,
            encontrar_nombre,encontrar_apellidos,&encontrar_rut)==4 && bandera==0) {
        if(numero_cuenta_encontrar==*numero_Cuenta) {
            printf("Bienvenido(a) Estimado(a): %s %s (Rut: %i)\n", encontrar_nombre, encontrar_apellidos, encontrar_rut);
            bandera=1;
            break;
        }

            }
}
//------------------------REGISTRAR CUENTA SUCURSAL----------
void registrar_cuenta_sucursal(char nombre[], char apellidos[], int *rut,int *sucursal,int *numero_Cuenta) {
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



    printf("Digite su Rut: ");
    scanf("%i",rut);
    getchar();

    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    char cuenta_[]= "Cuenta:";
    fprintf(archivo,"Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n",*numero_Cuenta,nombre,apellidos,*rut);

    fclose(archivo);

}

//------------------------RELLENAR DATOS----------

void datos(int *encontrado,int *sucursal,char *nombre, char *apellidos,int  *rut, int *numero_Cuenta) {
    printf("Escriba su Numero de Cuenta: ");
    scanf("%i",numero_Cuenta);
    printf("Ingrese su sucursal (1-5): ");
    scanf("%i", sucursal);
    encontrar_cuenta(nombre,apellidos,rut,sucursal,encontrado,numero_Cuenta);
}
//------------------------VER TODAS LAS CUENTAS----------

void ver_cuentas(int *opcion,char *nombres,char *apellidos,int *encontrado,int *rut, int *sucursal) {

    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista\nOpcion: ");
    scanf("%i",opcion);
    switch (*opcion) {
        case 1:registrar_corriente(nombres,apellidos,rut,encontrado,sucursal,opcion);break;
    }
    getchar();

}