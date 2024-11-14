#include <stdio.h>
#include "Libreria_2,_SOLO_ESTRUCTURAS.h"
int verificar_saldo(int *saldo,int tipo_de_cuenta) {
    int activo;
    switch (tipo_de_cuenta) {
        case 1:break;
        case 2:
            if(*saldo<100000) {
                activo=0;
            }else {
                activo=1;
            }

            break;
        case 3:
            if(*saldo>2500000) {
                activo=0;
            }else {
                activo=1;
            }
            break;

    }
    return activo;


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
    *encontrado=0;
    FILE *archivo;
    Lista_c *l=crearLista_Corriente();
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar,saldo_encontrar,interes_encontrar,comision_encontrar;
    int *saldo=(int *)malloc(sizeof(int)*1);
    int interes_final,comision_final;

    int decision_crear_cuenta;

    Corriente corriente;
    int cuenta;
    int _encontrar_cuenta;
    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=0;
    int bandera=0;
    archivo=fopen("Corriente .txt","r");
    if(archivo == NULL) {
        *encontrado=0;
        archivo=fopen("Corriente .txt","a+");
    }else {
        fclose(archivo);
        archivo=fopen("Corriente .txt","a+");
    }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Interes: %i Comision: %i\n",_encontrar_cuenta,nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&interes_encontrar,&comision_encontrar)==6 && bandera==0) {

            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut && _encontrar_cuenta==*sucursal) {
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

                fprintf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i \n",*sucursal,nombre,apellidos,*rut,corriente.saldo);

                printf("Creado,%i\n",corriente.saldo);
            }

        }

    }

    if(*encontrado==0) {
        char nombre_2[50];
        printf("No se ha encontrado su cuenta\n");
        printf("Ingrese su nombre: ");
        fgets(nombre_2,50,stdin);
        nombre_2[strcspn(nombre, "\n")] = '\0';
        getchar();
        printf("Nombre : %s",nombre_2);

        printf("Ingrese sus apellidos: ");
        fgets(apellidos,50,stdin);
        nombre[strcspn(nombre, "\n")] = '\0';
        getchar();

        printf("Ingres su Rut: ");
        scanf("%i",rut);
        printf("Ingresa tu saldo: \n");
        scanf("%i",saldo);
        corriente.saldo=*saldo;
        interes_final=interes(opcion,saldo);
        comision_final=comision(opcion,saldo);
        corriente.interes=interes_final;
        corriente.comision_mensual=comision_final;
        agregar_final_Corriente(l,corriente);
        fprintf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Interes: %i Comision: %i\n",*sucursal,nombre,apellidos,*rut,corriente.saldo,interes_final,corriente.comision_mensual);

    }
    printf("\n---CUENTA CORRIENTE---\nInformacion de la cuenta:\nNombre: %s \nApellidos: %s \nRut: %i\nSaldo:%i \nInteres: %i\nComision %i",nombre,apellidos,*rut,corriente.saldo,corriente.interes,corriente.comision_mensual);
    imprimir_lista_c(l);
    fclose(archivo);
    }
//------------------------REGISTRAR CUENTA AHORRO----------
void registrar_ahorro(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion) {
    FILE *archivo;
    Lista_c *a=crearLista_Ahorro();
    Sucursal s;
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar,saldo_encontrar,interes_encontrar,comision_encontrar;
    long *saldo=(long *)malloc(sizeof(long)*1);
    long *nuevo_saldo=(long *)malloc(sizeof(long)*1);

    int interes_final,comision_final;
    int *activo=(int *)malloc(sizeof(int)*1);
    int activo_encontrar;
    int decision_crear_cuenta;

    Ahorro ahorro;
    int _encontrar_cuenta;
    int decision_saldo;
    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=0;
    int bandera=0;
    archivo=fopen("Ahorro .txt","r");
    if(archivo == NULL) {
        *encontrado=0;
        archivo=fopen("Ahorro .txt","a+");
    }else {
        fclose(archivo);
        archivo=fopen("Ahorro .txt","a+");
    }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %ld Interes: %i Comision: %i Estado: %i\n",&_encontrar_cuenta,nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&interes_encontrar,&comision_encontrar,&activo_encontrar)==8 && bandera==0) {
            printf("%i == %i ",*rut,rut_encontrar);
            if(*rut==rut_encontrar) {
                *encontrado=1;
                bandera=1;
            }


        }
        *activo=1;
        ahorro.saldo=saldo_encontrar;
        ahorro.interes=interes_encontrar;
        ahorro.comision_mensual=comision_encontrar;
        ahorro.estado=*activo;
        s.rut=rut_encontrar;
        contador++;
        agregar_final_ahorro(a,ahorro);
        printf("\n---CUENTA AHORRO---\nInformacion de la cuenta:\nNombre: %s \nApellidos: %s \nRut: %i\nSaldo:%i \nInteres: %i\nComision %i\nEstado: %i\n",nombre_encontrar,apellidos_encontrar,s.rut,ahorro.saldo,ahorro.interes,ahorro.comision_mensual,ahorro.estado);


        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        if(*encontrado==0) {
            printf("No se encuentra en su cuenta Ahorro en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
            scanf("%i",&decision_crear_cuenta);
            if(decision_crear_cuenta==1) {
                printf("Ingrese su saldo:  ");
                scanf("%i", saldo);
                if(verificar_saldo(saldo,2)==1) {
                    printf("activo: %i",*activo);
                    printf("Su saldo menor a lo debido para crear su cuenta (Minimo: 100.000 pesos), Desea registrar "
                           "de nuevo su saldo ?(1.SI/0.NO)");
                    scanf("%i",saldo);
                }
                ahorro.estado=*activo;
                ahorro.saldo=saldo;
                agregar_final_ahorro(a,ahorro);
                printf("Contador = %i",contador);

                fprintf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Estado: %i",*sucursal,nombre,apellidos,*rut,ahorro.saldo,ahorro.estado);

                printf("Creado,%i\n",ahorro.saldo);
            }

        }

    }

    if(*encontrado==0) {
        printf("Ingresa tu saldo: \n");
        scanf("%ld",saldo);
        if(verificar_saldo(saldo,2)==0) {

            printf("Su saldo es menor a lo debido para crear su cuenta (Minimo: 100.000 pesos).\nDesea registrar "
                   "de nuevo su saldo ?(1.SI/0.NO): ");
            scanf("%i",&decision_saldo);
            if(decision_saldo==1) {
                printf("Ingresa tu saldo: \n");
                scanf("%ld",nuevo_saldo);
                if(verificar_saldo(nuevo_saldo,2)==0) {
                    printf("Demasiados intentos fallidos!.\n Se saldra del programa");
                    return;
                }
            }else {
                *opcion=0;
            }
        }else {
            *activo=1;
            ahorro.estado=*activo;
            ahorro.saldo=*saldo;
            interes_final=interes(opcion,saldo);
            comision_final=comision(opcion,saldo);
            ahorro.interes=interes_final;
            ahorro.comision_mensual=comision_final;
            agregar_final_ahorro(a,ahorro);
            fprintf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %ld Interes: %i Comision: %i Estado: %i\n",*sucursal,nombre,apellidos,*rut,ahorro.saldo,interes_final,ahorro.comision_mensual,ahorro.estado);

        }

    }
    imprimir_lista_a(a);
    fclose(archivo);
    }
//------------------------REGISTRAR CUENTA VISTA----------
void registrar_vista(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion) {
    FILE *archivo;
    Lista_v *v=crearLista_Vista();
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar,saldo_encontrar,interes_encontrar,comision_encontrar;
    int *saldo=(int *)malloc(sizeof(int)*1);
    int *nuevo_saldo=(int *)malloc(sizeof(int)*1);

    int interes_final,comision_final;
    int *activo=(int *)malloc(sizeof(int)*1);
    int activo_encontrar;

    int decision_crear_cuenta;

    Vista vista;
    int _encontrar_cuenta;
    int decision_saldo;
    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=0;
    int bandera=0;
    archivo=fopen("Ahorro .txt","r");
    if(archivo == NULL) {
        *encontrado=0;
        archivo=fopen("Ahorro .txt","a+");
    }else {
        fclose(archivo);
        archivo=fopen("Ahorro .txt","a+");
    }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Interes: %i Comision: %i Estado: %i\n",_encontrar_cuenta,nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&interes_encontrar,&comision_encontrar,&activo_encontrar)==7 && bandera==0) {
            if(strcmp(nombre_encontrar,nombre)==0 && strcmp(apellidos_encontrar,apellidos)==0 && rut_encontrar== *rut && _encontrar_cuenta==*sucursal) {
                interes(opcion,saldo);

                *encontrado=1;
                bandera=1;
            }
            vista.saldo=saldo_encontrar;
            vista.interes=interes_encontrar;
            vista.comision_mensual=comision_encontrar;
            vista.estado=*activo;
            contador++;
            agregar_final_vista(v,vista);



        }

        //-------------------------NO ENCONTRADO CUENTA PERO SI EXISTE EL ARCHIVO---------------------------------------

        if(*encontrado==0) {
            printf("No se encuentra en su cuenta Ahorro en la sucursal %i, desea agregar?\n(1.Si/2.No)",*sucursal);
            scanf("%i",&decision_crear_cuenta);
            if(decision_crear_cuenta==1) {
                printf("Ingrese su saldo:  ");
                scanf("%i", saldo);
                getchar();
                printf("||||||||||||||||||nuevo %i",*saldo);
                if(verificar_saldo(saldo,2)==1) {
                    printf("activo: %i",*activo);
                    printf("Su saldo menor a lo debido para crear su cuenta (Minimo: 100.000 pesos), Desea registrar "
                           "de nuevo su saldo ?(1.SI/0.NO)");
                    scanf("%i",saldo);
                }
                vista.estado=*activo;
                vista.saldo=saldo;
                agregar_final_vista(v,vista);
                printf("Contador = %i",contador);

                fprintf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i \nEstado: %i",*sucursal,nombre,apellidos,*rut,vista.saldo,vista.estado);

                printf("Creado,%i\n",vista.saldo);
            }

        }

    }

    if(*encontrado==0) {
        printf("Ingresa tu saldo: \n");
        scanf("%i",saldo);
        if(verificar_saldo(saldo,2)==0) {

            printf("Su saldo es menor a lo debido para crear su cuenta (Minimo: 100.000 pesos).\nDesea registrar "
                   "de nuevo su saldo ?(1.SI/0.NO): ");
            scanf("%i",&decision_saldo);
            if(decision_saldo==1) {
                printf("Ingresa tu saldo: \n");
                scanf("%i",nuevo_saldo);
                if(verificar_saldo(nuevo_saldo,2)==0) {
                    printf("Demasiados intentos fallidos!.\n Se saldra del programa");
                    return;
                }
            }else {
                *opcion=0;
            }
        }else {
            *activo=1;
            vista.estado=*activo;
            vista.saldo=*saldo;
            interes_final=interes(opcion,saldo);
            comision_final=comision(opcion,saldo);
            vista.interes=interes_final;
            vista.comision_mensual=comision_final;
            agregar_final_vista(v,vista);
            fprintf(archivo,"Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Interes: %i Comision: %iEstado; %i\n",*sucursal,nombre,apellidos,*rut,vista.saldo,interes_final,vista.comision_mensual,vista.estado);

        }

    }
    printf("\n---CUENTA AHORRO---\nInformacion de la cuenta:\nNombre: %s \nApellidos: %s \nRut: %i\nSaldo:%i \nInteres: %i\nComision %i\nEstado: %i\n",nombre,apellidos,*rut,vista.saldo,vista.interes,vista.comision_mensual,vista.estado);
    imprimir_lista_v(v);
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
    *encontrado=0;
    int rut_encontrar, cuenta_encontrar;

    if(archivo!=NULL && *encontrado!=1) {
        char nombre_encontrar[50], apellidos_encontrar[50];//
        while (fscanf(archivo, "Cuenta: %d Nombre: %s Apellidos: %s Rut: %d\n",
                  &cuenta_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar) == 4) {
            if ( *numero_Cuenta == cuenta_encontrar) {
                *encontrado = 1;
                *numero_Cuenta = cuenta_encontrar;
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
    int encontrar_rut;

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
        case 2:registrar_ahorro(nombres,apellidos,rut,encontrado,sucursal,opcion);break;

    }

    getchar();

}