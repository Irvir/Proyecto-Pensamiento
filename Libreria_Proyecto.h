void encontrar_cuenta(char *nombre, char *apellidos,int *rut,int sucursal,int *encontrado) {
    FILE *archivo;
    switch (sucursal) {
        case 1:
            archivo = fopen("Sucursal 1.txt","r");
            break;
        case 2:
            archivo = fopen("Sucursal 2.txt","r");
            break;
        case 3:
            archivo = fopen("Sucursal 3.txt","r");
            break;
        case 4:
            archivo = fopen("Sucursal 4.txt","r");
            break;
        case 5:
            archivo = fopen("Sucursal 5.txt","r");
            break;
    }
    char encontrar_nombre[50],encontrar_apellidos[50];
    int encontrar_rut=rut;
    *encontrado=0;
    char nombres_[]="Nombre:";
    char apellidos_[]="Apellidos:";
    char rut_[]="Rut:";
    int bandera=0;
    int i=0;
    if(archivo==NULL) {
        archivo=fopen("Sucursal 1.txt","w");
        *encontrado=0;
        fclose(archivo);
    }
    if(archivo!=NULL) {
        while(fscanf(archivo,"%s %s %s %s %s %i",nombres_,encontrar_nombre,apellidos_,encontrar_apellidos,rut_,&encontrar_rut)==6&&bandera==0&&i<1000) {
            if(strcmp(encontrar_nombre,nombre)==0 && strcmp(encontrar_apellidos,apellidos)==0 &&  encontrar_rut== *rut) {
                *encontrado=1;
                bandera=1;
                break;
            }
        }

    }
    fclose(archivo);
}

void registrar_cuenta_sucursal(char *nombre, char *apellidos, int rut,int opcion) {
    FILE *archivo;
    switch (opcion) {
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
    fprintf(archivo,"%s %s %s %s %s %i\n",nombres_,nombre,apellidos_,apellidos,rut_,rut);
    fclose(archivo);

}
void datos(int *encontrado,int sucursal,char *nombre, char *apellidos,int  *rut ) {
    printf("Ingrese su sucursal (1-5): ");
    scanf("%i", &sucursal);

    getchar();
    printf("Escriba su nombre: ");
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("Escriba sus apellidos: ");
    fgets(apellidos, 50, stdin);
    apellidos[strcspn(apellidos, "\n")] = '\0';

    printf("Ingrese su Rut (sin puntos ni digito verificador): ");
    scanf("%i", rut);

    encontrar_cuenta(nombre,apellidos,rut,sucursal,&encontrado);
}
void opcion_1() {
    printf("1. Ver Cuenta Corriente\n2. Ver Cuenta Ahorro\n3. Ver Cuenta Vista");
}