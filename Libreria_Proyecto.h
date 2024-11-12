#include <stdio.h>
#include "Libreria_2,_SOLO_ESTRUCTURAS.h"

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
    printf("||||||||||||%i",interes);
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

//------------------------REGISTRAR CUENTA AHORRO----------
void registrar_ahorro(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion) {
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
            nombre_encontrar[strcspn(nombre_encontrar, "\n")] = '\0';
            apellidos_encontrar[strcspn(apellidos_encontrar, "\n")] = '\0';

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
void registrar_vista(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion) {
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
        case 1:registrar_corriente(nombres,apellidos,rut,encontrado,sucursal,opcion);break;
        case 2:registrar_ahorro(nombres,apellidos,rut,encontrado,sucursal,opcion );break;
        case 3:registrar_vista(nombres,apellidos,rut,encontrado,sucursal,opcion);break;
    }

}