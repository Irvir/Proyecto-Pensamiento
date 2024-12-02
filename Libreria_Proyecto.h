#include <stdio.h>
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
    int *numero_de_cuenta;
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
    int numero_de_sucursal;
    int numero_de_cuenta;
}Sucursal;

void encontrar_interes(char *nombre, char *apellidos, int *rut, int *sucursal, int *opcion, int *estado, int *numero_cuenta) {
    FILE *archivo;
    int numero_cuenta_encontrar, sucursal_encontrar, rut_encontrar;
    int tipo_cuenta_encontrar, comision_encontrar, interes_encontrar;
    int saldo_encontrar = 0, activo_encontrar = 0, giro_encontrar = 0;
    char nombre_encontrar[50], apellidos_encontrar[50];
    int bandera = 0;

    int interes_final = 0, tiempo = 0;
    int *saldo=(int *)malloc(sizeof(int));
    printf("Seleccion su tipo de Cuenta (1.Corriente/2.Ahorro/3.Vista): ");
    scanf("%i",opcion);
    printf("Cuanto tiempo desea ver su interes? (en meses): ");
    scanf("%i", &tiempo);

    archivo = fopen("Cuentas.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fscanf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
        &numero_cuenta_encontrar, &tipo_cuenta_encontrar, &sucursal_encontrar, nombre_encontrar, apellidos_encontrar,
        &rut_encontrar, &saldo_encontrar, &comision_encontrar, &interes_encontrar, &activo_encontrar, &giro_encontrar) == 11&&bandera==0) {
        if (*numero_cuenta == numero_cuenta_encontrar &&  *opcion==tipo_cuenta_encontrar) {
            interes_final = interes_encontrar;
            *saldo = saldo_encontrar;
            bandera = 1;
            break;
        }else {
            bandera = 0;
        }
        }

    fclose(archivo);

    if (bandera==0) {
        printf("Cuenta no encontrada.\n");
        return;
    }

    int monto_final = *saldo + ((*saldo) * interes_final * tiempo) / 100;

    printf("Su saldo es: %i\n",*saldo);
    printf("El saldo final es: %i en %i meses\n", monto_final, tiempo);
}

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
        case 2:
            if (*saldo <= 150000) {
                interes = 5;
            } else if (*saldo > 150000 && *saldo < 600000) {
                interes = 10;
            } else if (*saldo >= 600000 && *saldo < 1500000) {
                interes = 15;
            } else {
                interes = 25;
            }
            // Cuenta Ahorro
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
        case 2:
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
            // Cuenta Ahorro
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
void depositar(char *nombre, char *apellidos, int *rut, int *sucursal, int *opcion, int *estado, int *numero_cuenta, int *deposito) {
    FILE *archivo;
    FILE *archivo2;

    int numero_cuenta_encontrar;
    int sucursal_encontrar;
    char nombre_encontrar[50];
    char apellidos_encontrar[50];
    int *encontrar_rut = (int *)malloc(sizeof(int) * 10);
    int bandera = 0;

    int rut_encontrar, tipo_cuenta_encontrar, comision_encontrar, interes_encontrar;
    int saldo_encontrar = 0;
    int activo_encontrar = 0;
    int giro_encontrar = 0;
    int verificarSaldo;
    int i = 0;
    int n = 0;
    archivo = fopen("Cuentas.txt", "r");
    archivo2 = fopen("Backup.txt", "w");

    while (fscanf(archivo, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                  &numero_cuenta_encontrar, &tipo_cuenta_encontrar, &sucursal_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar, &saldo_encontrar, &comision_encontrar,
                  &interes_encontrar, &activo_encontrar, &giro_encontrar) == 11) {
        if (*numero_cuenta == numero_cuenta_encontrar && tipo_cuenta_encontrar == *opcion) {
            n = saldo_encontrar;
            if (tipo_cuenta_encontrar == 3) {
                if (giro_encontrar < 0) {
                    printf("Debido a su cantidad de giros: %i (4 giros gratuitos)\nSe le cobrará 400 pesos a su saldo\n", giro_encontrar);
                    saldo_encontrar -= 400;
                }
            }
            switch (*opcion) {
                case 1:
                case 2:
                case 3:
                    if (*opcion == 3 && verificar_saldo(&saldo_encontrar, *opcion) == 0) {
                        printf("Lamentablemente su deposito es demasiado grande debido al tipo de cuenta\n"
                               "Recuerde que el saldo limite es de 2.5 millones de pesos!");
                    } else {
                        saldo_encontrar += *deposito;
                        activo_encontrar = 1;
                    }
                    break;
            }
            fprintf(archivo2, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    numero_cuenta_encontrar, tipo_cuenta_encontrar, sucursal_encontrar, nombre_encontrar, apellidos_encontrar, rut_encontrar,
                    saldo_encontrar, comision_encontrar, interes_encontrar, activo_encontrar, giro_encontrar - 1);
            bandera = 1;
        } else {
            fprintf(archivo2, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    numero_cuenta_encontrar, tipo_cuenta_encontrar, sucursal_encontrar, nombre_encontrar, apellidos_encontrar, rut_encontrar,
                    saldo_encontrar, comision_encontrar, interes_encontrar, activo_encontrar, giro_encontrar);
        }

        i++;
    }
    fclose(archivo2);
    fclose(archivo);
    archivo2 = fopen("Backup.txt", "r");
    archivo = fopen("Cuentas.txt", "w");
    bandera = 0;
    while (fscanf(archivo2, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                  &numero_cuenta_encontrar, &tipo_cuenta_encontrar, &sucursal_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar, &saldo_encontrar, &comision_encontrar,
                  &interes_encontrar, &activo_encontrar, &giro_encontrar) == 11) {
        fprintf(archivo, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                numero_cuenta_encontrar, tipo_cuenta_encontrar, sucursal_encontrar, nombre_encontrar, apellidos_encontrar, rut_encontrar,
                saldo_encontrar, comision_encontrar, interes_encontrar, activo_encontrar, giro_encontrar);
    }

    printf("DEPOSITO-Operacion Exitosa!\nNuevo Saldo: %i\n", n + *deposito);

    fclose(archivo);
    fclose(archivo2);
}

void retirar(char *nombre, char *apellidos, int *rut, int *sucursal, int *opcion, int *estado, int *numero_cuenta, int *retiro) {
    FILE *archivo;
    FILE *archivo2;
    int bandera=0;
    int numero_cuenta_encontrar;
    int sucursal_encontrar;
    char nombre_encontrar[50];
    char apellidos_encontrar[50];
    int rut_encontrar, tipo_cuenta_encontrar, comision_encontrar, interes_encontrar;
    int saldo_encontrar = 0;
    int activo_encontrar = 0;
    int giro_encontrar = 0;
    int i = 0;
    int n;
    archivo = fopen("Cuentas.txt", "r");
    archivo2 = fopen("Backup.txt", "w");

    while (fscanf(archivo, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                  &numero_cuenta_encontrar, &tipo_cuenta_encontrar, &sucursal_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar, &saldo_encontrar, &comision_encontrar,
                  &interes_encontrar, &activo_encontrar, &giro_encontrar) == 11) {
        if (*numero_cuenta == numero_cuenta_encontrar && tipo_cuenta_encontrar == *opcion) {
            n = saldo_encontrar;
            if (tipo_cuenta_encontrar == 3) {
                if (giro_encontrar < 0) {
                    printf("Debido a su cantidad de giros: %i (4 giros gratuitos)\nSe le cobrara 400 pesos a su saldo\n", giro_encontrar);
                    saldo_encontrar -= 400;
                }
            }
            switch (*opcion) {
                case 1:
                    if (*retiro > saldo_encontrar) {
                        activo_encontrar = 0;
                    } else {
                        saldo_encontrar -= *retiro;
                        activo_encontrar = 1;
                    }
                    break;
                case 2:
                    if (*retiro > 50000) {
                        activo_encontrar = 0;
                    } else {
                        saldo_encontrar -= *retiro;
                        activo_encontrar = 1;
                    }
                    break;
                case 3:
                    if (*retiro < 0) {
                        activo_encontrar = 0;
                    } else {
                        saldo_encontrar -= *retiro;
                        activo_encontrar = 1;
                    }
                    break;
            }
            fprintf(archivo2, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    numero_cuenta_encontrar, tipo_cuenta_encontrar, sucursal_encontrar, nombre_encontrar, apellidos_encontrar, rut_encontrar,
                    saldo_encontrar, comision_encontrar, interes_encontrar, activo_encontrar, giro_encontrar - 1);
            bandera = 1;
        } else {
            fprintf(archivo2, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    numero_cuenta_encontrar, tipo_cuenta_encontrar, sucursal_encontrar, nombre_encontrar, apellidos_encontrar, rut_encontrar,
                    saldo_encontrar, comision_encontrar, interes_encontrar, activo_encontrar, giro_encontrar);
        }

        i++;
    }
    fclose(archivo2);
    fclose(archivo);
    archivo2 = fopen("Backup.txt", "r");
    archivo = fopen("Cuentas.txt", "w");

    while (fscanf(archivo2, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                  &numero_cuenta_encontrar, &tipo_cuenta_encontrar, &sucursal_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar, &saldo_encontrar, &comision_encontrar,
                  &interes_encontrar, &activo_encontrar, &giro_encontrar) == 11) {
        fprintf(archivo, "Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                numero_cuenta_encontrar, tipo_cuenta_encontrar, sucursal_encontrar, nombre_encontrar, apellidos_encontrar, rut_encontrar,
                saldo_encontrar, comision_encontrar, interes_encontrar, activo_encontrar, giro_encontrar);
    }

    switch (*opcion) {
        case 1:
            if (activo_encontrar == 0) {
                printf("Error! su retiro de: %i es mayor a su saldo de: %i", *retiro, saldo_encontrar);
            }
            break;
        case 2:
            if (activo_encontrar == 0) {
                printf("Error! su retiro de: %i tiene que ser menor a 50 mil pesos", *retiro);
            }
            break;
        case 3:
            if (activo_encontrar == 0) {
                printf("Error! su retiro de: %i tiene que ser mayor que 0 pesos", *retiro);
            }
            break;
    }

    printf("RETIRAR-Operacion Exitosa!\nNuevo Saldo: %i\n", n - *retiro);

    fclose(archivo);
    fclose(archivo2);
}


void registrar_cuenta(char *nombre,char *apellidos,int *rut,int *encontrado,int *sucursal,int *opcion, int *estado,int *numero_cuenta){

    FILE *archivo;
    Sucursal sucursal_;

    //COSAS A ENCONTRAR PARA ARCHIVOS
    char nombre_encontrar[50],apellidos_encontrar[50];
    int rut_encontrar,saldo_encontrar,interes_encontrar,comision_encontrar;
    int *saldo=(int *)malloc(sizeof(int)*1);
    int *nuevo_saldo=(int *)malloc(sizeof(int)*1);
    int interes_final,comision_final;
    int *activo=(int *)malloc(sizeof(int)*1);
    int activo_encontrar,decision_crear_cuenta,numero_cuenta_encontrar,sucursal_encontrar,tipo_cuenta_encontrar;

    Ahorro ahorro;
    Corriente corriente;
    Vista vista;
    int decision_saldo;
    //-------------------------SE ENCUENTRA CUENTA EN SUCURSAL------------------------
    int contador=0;
    int bandera=0;
    int cuenta_a_encontrar;
    int verificar;
    int giros_encontrar;
    archivo=fopen("Cuentas.txt","a+");
    switch (*opcion) {
        case 1:
            giros_encontrar=-1;
            cuenta_a_encontrar=1;
            break;
        case 2:
            giros_encontrar=-1;
            cuenta_a_encontrar=2;
        break;
        case 3:
            giros_encontrar=4;
            cuenta_a_encontrar=3;
            break;
    }
    int contador_rut=0;
    int contador_n_cuenta=0;
        //-----------------------BUSCAR CUENTA DENTRO DE LA ESTRUCURA: CORRIENTE---------------------
    if(*encontrado==1) {
        while (fscanf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
            &numero_cuenta_encontrar,&tipo_cuenta_encontrar,&sucursal_encontrar,nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&comision_encontrar,
            &interes_encontrar,&activo_encontrar,giros_encontrar)==11 && bandera==0) {
            if(numero_cuenta_encontrar==*numero_cuenta || rut_encontrar==*rut) {
                contador_n_cuenta++;
                contador_rut++;
                if(contador_n_cuenta>1 || contador_rut>1) {
                    printf("Lamentablemente su rut o su numero de cuenta ya están registrados, intenta con otro rut");
                    bandera=1;
                    *encontrado=1;
                }
            }
            if(*numero_cuenta==numero_cuenta_encontrar && cuenta_a_encontrar==*opcion && sucursal_encontrar==*sucursal) {
                strcpy(nombre,nombre_encontrar);
                strcpy(apellidos,apellidos_encontrar);

                *encontrado=1;
                bandera=1;
            }


            else {
                *encontrado=0;
            }

        }
        if(*encontrado==1 && cuenta_a_encontrar==*opcion) {
            printf("%i === %i",cuenta_a_encontrar==*opcion);
            printf("ERROR! Estimado(a): %s %s, su cuenta ya esta registrado(a)\nPor lo que el programa se cerrara",nombre , apellidos, rut);

            return;
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
                    corriente.estado=*activo;
                    corriente.saldo=*saldo;
                    interes_final=interes(opcion,saldo);
                    comision_final=comision(opcion,saldo);
                    corriente.interes=interes_final;
                    corriente.comision_mensual=comision_final;
                    corriente.giro=-1;
                    fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    *numero_cuenta,*opcion,*sucursal,nombre,apellidos,*rut,corriente.saldo,corriente.comision_mensual,corriente.interes,corriente.estado,corriente.giro);
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
                        else {
                            *activo=1;
                            ahorro.estado=*activo;
                            ahorro.saldo=*saldo-100000;
                            interes_final=interes(opcion,saldo);
                            comision_final=comision(opcion,saldo);
                            ahorro.interes=interes_final;
                            ahorro.comision_mensual=comision_final;
                            ahorro.giro=-1;
                            fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    *numero_cuenta,*opcion,*sucursal,nombre,apellidos,*rut,ahorro.saldo,ahorro.comision_mensual,ahorro.interes,ahorro.estado,ahorro.giro);
                        }
                    }else {
                        *estado=0;
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
                    ahorro.giro=-1;

                    fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    *numero_cuenta,*opcion,*sucursal,nombre,apellidos,*rut,ahorro.saldo,ahorro.comision_mensual,ahorro.interes,ahorro.estado,ahorro.giro);
                }
                break;
            case 3:
                if(verificar_saldo(saldo,3)==0) {
                    printf("Su saldo es mayor a lo debido para crear su cuenta (Maximo 1.2 Millones de pesos).\nDesea registrar "
                           "de nuevo su saldo ?(1.SI/0.NO): ");
                    scanf("%i",&decision_saldo);

                    if(decision_saldo==1) {
                        printf("Ingresa tu saldo: \n");
                        scanf("%i",nuevo_saldo);
                        if(verificar_saldo(nuevo_saldo,2)==0) {
                            printf("Demasiados intentos fallidos!.\n Se saldra del programa");
                            return;
                        }
                        else {
                            *activo=1;
                            vista.estado=*activo;
                            vista.saldo=*saldo;
                            interes_final=interes(opcion,saldo);
                            comision_final=comision(opcion,saldo);
                            vista.interes=interes_final;
                            vista.comision_mensual=comision_final;
                            vista.giro=4;
                            fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                            *numero_cuenta,*opcion,*sucursal,nombre,apellidos,*rut,vista.saldo,vista.comision_mensual,vista.interes,vista.estado,vista.giro);
                        }
                    }else {
                        *estado=0;
                    }
                }
                if(verificar_saldo(saldo,3)==1) {
                    *activo=1;
                    vista.estado=*activo;
                    vista.saldo=*saldo;
                    interes_final=interes(opcion,saldo);
                    comision_final=comision(opcion,saldo);
                    vista.interes=interes_final;
                    vista.comision_mensual=comision_final;
                    vista.giro=4;
                    fprintf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
                    *numero_cuenta,*opcion,*sucursal,nombre,apellidos,*rut,vista.saldo,vista.comision_mensual,vista.interes,vista.estado,vista.giro);
                }
                break;

        }

    }


    fclose(archivo);
}



//------------------------ENCONTRAR CUENTA EN GENERAL----------
void encontrar_cuenta(char *nombre, char *apellidos,int *rut,int *sucursal,int *encontrado,int *numero_Cuenta) {
    Sucursal s;
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
    //EN CASO PARA ENCONTRAR
    int rut_encontrar, cuenta_encontrar;

    *encontrado=0;
    s.numero_de_cuenta=*numero_Cuenta;
    s.rut=*rut;
    int contador_n_cuenta=0;
    int contador_rut=0;
    int bandera=0;
    if(archivo!=NULL) {
        char nombre_encontrar[50], apellidos_encontrar[50];
        while (fscanf(archivo, "Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n",
                  &cuenta_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar) == 4 && bandera==0) {
            if(s.numero_de_cuenta==*numero_Cuenta || rut_encontrar==*rut) {
                contador_n_cuenta++;
                contador_rut++;
                if(contador_n_cuenta>1 || contador_rut>1) {
                    printf("Lamentablemente su rut o su numero de cuenta ya estan registrados, intenta con otro rut\n");
                    bandera=1;
                    *encontrado=1;
                }
            }
            if ( s.numero_de_cuenta == cuenta_encontrar && s.rut==rut_encontrar) {
                strcpy(nombre_encontrar,nombre);
                strcpy(apellidos_encontrar,apellidos);
                *encontrado = 1;
                *numero_Cuenta = cuenta_encontrar;
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
    getchar();
    printf("Escribe tu nombre: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("Escribe tu apellido: ");
    fgets(apellidos, 50, stdin);
    apellidos[strcspn(apellidos, "\n")] = '\0';
    fprintf(archivo,"Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n",*numero_Cuenta,nombre,apellidos,*rut);

    fclose(archivo);

}

//------------------------IMPRIMIR DATOS DE LAS CUENTAS REGISTRADAS----------
void imprimir_datos_cuentas(char *nombre, char *apellidos,int *rut,int *sucursal,int *tipo_cuenta,int *numero_Cuenta ) {
    FILE *archivo;
    int rut_encontrar, cuenta_encontrar;
    int bandera=0;
    switch (*sucursal) {
        case 1:
            archivo = fopen("Sucursal 1.txt","r");
        break;
        case 2:
            printf("Encargado(a): Jimmy Barrera\n");
        break;
        case 3:
            printf("Encargado(a): Juana Ashe\n");
        archivo = fopen("Sucursal 3.txt","r");
        break;
        case 4:
            printf("Encargado(a): Maria Alarcon\n");
            archivo = fopen("Sucursal 4.txt","r");
        break;
        case 5:
            printf("Encargado(a): Ester Castillo\n");
            archivo = fopen("Sucursal 5.txt","r");

        break;
    }
        char nombre_encontrar[50], apellidos_encontrar[50];
        while (fscanf(archivo, "Cuenta: %i Nombre: %s Apellidos: %s Rut: %i\n",
                  &cuenta_encontrar, nombre_encontrar, apellidos_encontrar, &rut_encontrar) == 4 && bandera==0) {
            if ( *numero_Cuenta == cuenta_encontrar &&  *rut==rut_encontrar) {
                printf("INFORMACION DE LA CUENTA\nNombre: %s. \nApellidos: %s.\n Rut: %i.\nNumero de cuenta:%i.\n",nombre_encontrar,apellidos_encontrar,rut_encontrar,cuenta_encontrar);
                bandera=1;
                break;
            }
                  }
    fclose(archivo);
        //-----------IMPRESION DE CUENTAS--------------
    int tipo_cuenta_encontrar,sucursal_encontrar,interes_encontrar,activo_encontrar,saldo_encontrar,comision_encontrar,giros_encontrar;
    bandera=0;
    char activo[50];
    int *encontrado_=(int*)malloc(sizeof(int));
    archivo=fopen("Cuentas.txt","r");
    while (fscanf(archivo,"Cuenta: %i Tipo_Cuenta: %i Sucursal: %i Nombre: %s Apellidos: %s Rut: %i Saldo: %i Comision: %i Interes: %i Estado: %i Giros: %i\n",
            &cuenta_encontrar,&tipo_cuenta_encontrar,&sucursal_encontrar,nombre_encontrar,apellidos_encontrar,&rut_encontrar,&saldo_encontrar,&comision_encontrar,
            &interes_encontrar,&activo_encontrar,&giros_encontrar)==11 && bandera==0) {
        *encontrado_=0;
        if(cuenta_encontrar==*numero_Cuenta && tipo_cuenta_encontrar==*tipo_cuenta && sucursal_encontrar==*sucursal) {
            if(activo_encontrar==0) {
                strcpy(activo,"Inactivo");
            }
            else{strcat(activo,"Activo");}
            *encontrado_=1;
            bandera=1;

        }
        printf("N_cuenta %i ==%i\nT_Cuenta %i == %i\n",*numero_Cuenta,cuenta_encontrar,*tipo_cuenta,tipo_cuenta_encontrar);
    }
    if(*encontrado_==0) {
        printf("Estimado Cliente usted no tiene este tipo de cuenta en esta sucursal");
    }
    if(*encontrado_==1) {
        printf("Saldo: %i.\nComision: %i.\nInteres: %i.\nEstado: %s.\n",saldo_encontrar,comision_encontrar,interes_encontrar,activo);
        bandera=1;
    }
    printf("%i",activo_encontrar);
    fclose(archivo);

}


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
    if(*encontrado==0) {
        switch (*opcion) {
            case 1:registrar_cuenta(nombres,apellidos,rut,encontrado,sucursal,opcion,estado,numero_cuenta);break;
            case 2:registrar_cuenta(nombres,apellidos,rut,encontrado,sucursal,opcion,estado,numero_cuenta);break;
            case 3:registrar_cuenta(nombres,apellidos,rut,encontrado,sucursal,opcion,estado,numero_cuenta);break;

        }
    }else {
        imprimir_datos_cuentas(nombres,apellidos,rut,sucursal,opcion,numero_cuenta);
    }


    getchar();

}