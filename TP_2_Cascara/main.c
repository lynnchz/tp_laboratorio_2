#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 3

int main(){
    ePersona personas[CANT];
    inicializarEstadoPersona(personas,CANT);
    int opcion = 0;

    do{
        int funcionMenu();
        switch(funcionMenu()){
            case 1:
                AgregarP(personas,CANT);
                break;
            case 2:
                BorrarP(personas,CANT);
                break;
            case 3:
                mostrarPersonas(personas,CANT);
                break;
            case 4:
                break;
            case 'ESC':
                break;
        }
    }while(opcion != 'ESC');

    return 0;
}
