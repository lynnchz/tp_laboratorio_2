#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>

void inicializarEstadoPersona(ePersona pers[],int cantidad){
    for(int j=0;j<cantidad;j++)
{
    pers[j].estado = 0;
}
}

int funcionMenu(){
        int opcion;
        system("cls");
        printf("1-Agregar una persona\n");
        printf("2-Borrar una persona\n");
        printf("3-Imprimir lista ordenada por nombre\n");
        printf("4-Grafico\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        return opcion;
};

int obtEspacioL(ePersona pers[],int cantidad){
int indice=-1;
for(int j=0;j<cantidad;j++){
    if(pers[j].estado == 0){
        indice =j;
        break;
        }
}
return indice;
}

int buscarXdni(ePersona pers[],int cantidad,int dni){
int existe = -1;
for(int i=0;i<cantidad;i++){
    if(pers[i].estado == 1 && pers[i].dni == dni){
        existe = i;
        break;
        }
}
return existe;
}

void AgregarP(ePersona pers[], int cantidad){
system("cls");
int dni;
int Esta;
int espacioLibre = obtEspacioL(pers,cantidad);

if(espacioLibre <0){
    printf("El sistema esta lleno.\n");
    system("pause");
}else{
    printf("\tAGREGAR PERSONA\n\n");
    printf("\nDNI sin puntos ni espacios: ");
    scanf("%d",&dni);

    Esta = buscarXdni(pers,cantidad,dni);

    if(Esta == -1)
    {
        pers[espacioLibre].dni = dni;
        printf("\nNombre: ");
        fflush(stdin);
        scanf("%s", pers[espacioLibre].nombre);
        printf("\nEdad: ");
        fflush(stdin);
        scanf("%d", &pers[espacioLibre].edad);
        pers[espacioLibre].estado = 1;
        system("cls");
        printf("Se agrego a la persona con exito!\n");
        printf("Nombre\tedad\tDNI\n\n");
        MostrarP(pers[espacioLibre]);
        system("pause");


    }
    else{
        system("cls");
        printf("El dni ingresado ya esta en el sistema!.\n");
        printf("El dni: %d corresponde a:  \n",dni);
        printf("Nombre\tedad\tDNI\n\n");
        MostrarP(pers[Esta]);
        system("pause");
        system("cls");
    }
}
}//

void MostrarP(ePersona pers){
pers.nombre[0]= toupper(pers.nombre[0]);
printf("%s\t%d\t%d\n",pers.nombre,pers.edad, pers.dni);
}

void mostrarPersonas(ePersona pers[],int cantidad){
    system("cls");
    ordenarPersonas(pers,cantidad);
    printf("LISTA DE PERSONAS\n");
    printf("Nombre\tedad\tDNI\n");
    for(int i=0;i<cantidad;i++){
        if(pers[i].estado==1){
        MostrarP(pers[i]);
        }
    }
    system("pause");
}

void BorrarP(ePersona pers[],int cantidad){
system("cls");
int dni;
char opcion;
int Esta;

printf("\tBorrar Personas\n\n");
printf("Para eliminar a una persona,por favor,ingrese su DNI: ");
scanf("%d",&dni);

Esta=buscarXdni(pers,cantidad,dni);

if(Esta >= 0){
    printf("Persona encontrada: \n");
    printf("Nombre\tedad\tDNI\n");
    MostrarP(pers[Esta]);
    printf("Seguro que quiere eliminarla del sistema? s/n: ");
    fflush(stdin);
    scanf("%c",&opcion);
    if(opcion == 'n')
    {
        printf("Se ha cancelado la baja\n");
        system("pause");

    }
    else
    {
        system("cls");
        printf("%s fue borrado del sistema...\n",pers[Esta].nombre);
        pers[Esta].estado = 0;
        system("pause");
    }
}
else{
    printf("El dni: %d ingresado no existe!\n\n",dni);
    system("pause");
}
}

void ordenarPersonas(ePersona pers[],int cantidad){

ePersona aux;
for(int i=0;i<cantidad-1;i++){
    for(int j=i+1; j<cantidad; j++){
        if(strcmp(pers[i].nombre,pers[j].nombre)>0){
                aux = pers[i];
                pers[i] = pers[j];
                pers[j] = aux;
        }
        else{
            if(strcmp(pers[i].nombre,pers[j].nombre)==0){
                if(pers[i].dni < pers[j].dni){
                aux = pers[i];
                pers[i] = pers[j];
                pers[j] = aux;
                }
            }
        }
    }
}
}
