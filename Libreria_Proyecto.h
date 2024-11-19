#include <stdio.h>
#include "Libreria_2,_SOLO_ESTRUCTURAS.h"
#define regitrar_ahorro
int verificar_saldo(int *saldo,int tipo_de_cuenta) {
    int activo;
    switch (tipo_de_cuenta) {
        case 1:
            activo=1;
            break;
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
int retornar_saldo(int *saldo) {
    return *saldo-100000;
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
//------------------------DEPOSITO------------------------
void retirar(char *nombre,char *apellidos,int *rut,int *sucursal,int *opcion, int *estado,int *numero_cuenta, int *retiro) {
    Corriente corriente;
    Ahorro ahorro;
    Vista vista;
    FILE *archivo;
    Lista_c *c=crearLista_Corriente();
    Lista_a *a=crearLista_Ahorro();
    Lista_v *v=crearLista_Vista();
    int numero_cuenta_encontrar;
    char encontrar_nombre[50];
    char encontrar_apellidos[50];
    int *encontrar_rut=(int *)malloc(sizeof(int)*10);
    int bandera=0;
    int tipo_cuenta_encontrar;
    Nodo_C *nodo_c;
    Nodo_A *nodo_a;
    Nodo_V *nodo_v;
    printf("e");

    archivo=fopen("Cuentas .txt","r");
     while (fscanf(archivo, "Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n", &numero_cuenta_encontrar, encontrar_nombre, encontrar_apellidos, &encontrar_rut) == 4 && bandera == 0) {
            if (*numero_cuenta == numero_cuenta_encontrar && tipo_cuenta_encontrar == *opcion && strcmp(encontrar_nombre, nombre) == 0 && strcmp(encontrar_apellidos, apellidos) == 0)
                printf("ll");
                bandera=1;
            }
        if (bandera == 1) { switch (*opcion) { case 1:
                ahorro.saldo = ahorro.saldo - *retiro; agregar_final_ahorro(a, ahorro); break;
            case 2:
                ahorro.saldo = ahorro.saldo - *retiro; agregar_final_ahorro(a, ahorro); break;
            case 3:vista.saldo = vista.saldo - *retiro; agregar_final_vista(v, vista); break; }

            printf("saldo final:%i ",ahorro.saldo);

                    }
}

//------------------------REGISTRAR CUENTA AHORRO----------
void registrar_cuenta(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion, int *estado,int *numero_cuenta){
    FILE *archivo;
    Sucursal sucursal_;
    Lista_s *s=crearLista_Sucursal();

    //COSAS A ENCONTRAR PARA ARCHIVOS
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar,saldo_encontrar,interes_encontrar,comision_encontrar;
    int *saldo=(int *)malloc(sizeof(int)*1);
    int *nuevo_saldo=(int *)malloc(sizeof(int)*1);
    int interes_final,comision_final;
    int *activo=(int *)malloc(sizeof(int)*1);
    int activo_encontrar,decision_crear_cuenta,numero_cuenta_encontrar,sucursal_encontrar,tipo_cuenta_encontrar;

    Ahorro ahorro;
    int decision_saldo;
    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=0;
    int bandera=0;
    int cuenta_a_encontrar;
    int verificar;

    archivo=fopen("Cuentas.txt","r");
    switch (*opcion) {
        case 1:
            cuenta_a_encontrar=1;
            break;
        case 2:
            cuenta_a_encontrar=2;
        break;
        case 3:
            cuenta_a_encontrar=3;
            break;
    }
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {

        while (fscanf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i\n",
            &numero_cuenta_encontrar,&tipo_cuenta_encontrar,&sucursal_encontrar,nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&comision_encontrar,
            &interes_encontrar,&activo_encontrar)==10 && bandera==0) {
            if(*numero_cuenta==numero_cuenta_encontrar && tipo_cuenta_encontrar== *opcion && strcmp(nombre_encontrar,apellidos_encontrar)==0 && strcmp(nombre_encontrar,apellidos_encontrar)==0) {
                strcpy(nombre,nombre_encontrar);
                strcpy(apellidos,apellidos_encontrar);
                strcpy(sucursal_.nombre,nombre);
                agregar_final_sucursal(s,sucursal_);

                *encontrado=1;
                bandera=1;
            }else {
                *encontrado=0;
            }
        }
        if(*encontrado==1 && *opcion==1) {
            ahorro.saldo=saldo_encontrar;
            ahorro.interes=interes_encontrar;
            ahorro.comision_mensual=comision_encontrar;
            ahorro.estado=activo_encontrar;
            sucursal_.rut=rut_encontrar;
            contador++;
            agregar_final_ahorro(a,ahorro);
            printf("\n---CUENTA AHORRO---\nInformacion de la cuenta:\nTipo de Cuenta:%i \nSucursal: %i\nNombre: %s \nApellidos: %s \nRut: %i\nSaldo:%i \nInteres: %i\nComision %i\nEstado: %i\n",
                tipo_cuenta_encontrar,*sucursal,nombre_encontrar,apellidos_encontrar,sucursal_.rut,ahorro.saldo,ahorro.interes,ahorro.comision_mensual,ahorro.estado);

        }else{
            printf("Ingrese su saldo:  ");
            scanf("%i", saldo);
            switch (*opcion) {
                case 1:
                    if(verificar_saldo(saldo,1)==1) {
                        *activo=1;
                        ahorro.estado=*activo;
                        ahorro.saldo=*saldo;
                        interes_final=interes(opcion,saldo);
                        comision_final=comision(opcion,saldo);
                        ahorro.interes=interes_final;
                        ahorro.comision_mensual=comision_final;
                        agregar_final_ahorro(a,ahorro);

                    }
                break;
                case 2:
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
                        *activo=1;
                        *encontrado=1;
                        *opcion=0;
                    }
                }
                if(verificar_saldo(saldo,2)==1) {
                    ahorro.saldo=*saldo-100000;

                    printf("----------------------------------------El saldo es: %i",*saldo);
                    *activo=1;
                    *encontrado=1;
                    ahorro.estado=*activo;
;
                    interes_final=interes(opcion,saldo);
                    comision_final=comision(opcion,saldo);
                    ahorro.interes=interes_final;
                    ahorro.comision_mensual=comision_final;
                    agregar_final_ahorro(a,ahorro);
                }
                break;
                case 3:
                    if(verificar_saldo(saldo,3)==0) {
                        printf("Su saldo es mayor a lo debido para crear su cuenta (Maximo: 2.500.000 pesos).\nDesea registrar "
                               "de nuevo su saldo ?(1.SI/0.NO): ");
                        scanf("%i",&decision_saldo);
                        if(decision_saldo==1) {
                            printf("Ingresa tu saldo:-- \n");
                            scanf("%i",nuevo_saldo);
                            if(verificar_saldo(nuevo_saldo,3)==0) {
                                printf("Demasiados intentos fallidos!.\n Se saldra del programa");
                                return;
                            }
                        }else {
                            *activo=1;
                            *encontrado=1;
                            *opcion=0;
                        }
                    }
                    if(verificar_saldo(saldo,2)==1) {
                        *saldo=retornar_saldo(saldo);
                        *activo=1;
                        *encontrado=1;
                        ahorro.estado=*activo;
                        ahorro.saldo=*saldo;
                        interes_final=interes(opcion,saldo);
                        comision_final=comision(opcion,saldo);
                        ahorro.interes=interes_final;
                        ahorro.comision_mensual=comision_final;
                        agregar_final_ahorro(a,ahorro);
                    }
                    break;
            }
            fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i\n",
            *numero_cuenta,*opcion,*sucursal,nombre_encontrar,apellidos_encontrar,rut_encontrar,ahorro.saldo-100000,ahorro.comision_mensual,ahorro.interes,ahorro.estado);





        }

    }

    if(*encontrado==0) {
        printf("Cuenta No Registrada\n");
        printf("Ingresa tu saldo: \n");
        scanf("%i",saldo);
        switch (*opcion) {
            case 1:
                if(verificar_saldo(saldo,1)==1) {
                    *activo=1;
                    ahorro.estado=*activo;
                    ahorro.saldo=*saldo;
                    interes_final=interes(opcion,saldo);
                    comision_final=comision(opcion,saldo);
                    ahorro.interes=interes_final;
                    ahorro.comision_mensual=comision_final;
                    agregar_final_ahorro(a,ahorro);

                }
                break;
            case 2:
                printf("entre");
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
                }
                if(verificar_saldo(saldo,2)==1) {
                    *activo=1;
                    ahorro.estado=*activo;
                    ahorro.saldo=*saldo-100000;
                    interes_final=interes(opcion,saldo);
                    comision_final=comision(opcion,saldo);
                    ahorro.interes=interes_final;
                    ahorro.comision_mensual=comision_final;
                    agregar_final_ahorro(a,ahorro);
                }
                break;
            case 3:break;
        }


        fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i\n",
            *numero_cuenta,*opcion,*sucursal,nombre,apellidos,*rut,ahorro.saldo,ahorro.comision_mensual,ahorro.interes,ahorro.estado);
    }


    imprimir_lista_a(a);
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

void ver_cuentas(int *opcion,char *nombres,char *apellidos,int *encontrado,int *rut, int *sucursal, int *estado,int *numero_cuenta) {

    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista\nOpcion: ");
    scanf("%i",opcion);
    switch (*opcion) {
        case 1:registrar_cuenta(nombres,apellidos,rut,encontrado,sucursal,opcion,estado,numero_cuenta);break;
        case 2:registrar_cuenta(nombres,apellidos,rut,encontrado,sucursal,opcion,estado,numero_cuenta);break;
        case 3:registrar_cuenta(nombres,apellidos,rut,encontrado,sucursal,opcion,estado,numero_cuenta);break;

    }

    getchar();

}