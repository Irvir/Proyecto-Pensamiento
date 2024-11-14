cmake_minimum_required(VERSION 3.29)
project(Proyecto_Pensamiento C)

set(CMAKE_C_STANDARD 99)
#main.c
#"Funcion encontrar y registrar.c"
add_executable(Proyecto_Pensamiento
        main.c
        Libreria_Proyecto.h
        "Registro de cuentas.h"


)
