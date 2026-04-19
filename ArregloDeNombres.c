#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIONES
void MostrarPersonas(char *V[]);

void BuscarNombre(char *V[], int id);

//MAIN
void main(){
    char nombre[20];
    char *V[5];
    int i,longitud;

    for(i=0;i<5;i++){
        printf("Ingrese el nombre de la persona numero %d: ",i+1);
        gets(nombre);
        longitud = strlen(nombre);

        V[i] = (char *)malloc((longitud + 1) * sizeof(char));
        strcpy(V[i],nombre);
    }
    MostrarPersonas(V);

    //liberar memoria
    for(i=0;i<5;i++){
        free(V[i]);
    }
}

//FUNCIONES
void MostrarPersonas(char *V[]){
    int i;
    for(i=0;i<5;i++){
        printf("Persona numero %d: ",i+1);
        puts(V[i]);
    }
}

void BuscarNombre(char *V[], int id){
    if (id > 4 || id < 0){
        printf("\n----no se encontro el valor buscado----\n");
    }
    else{
        printf("\nNombre ubicado en la posicion %d: ",id);
        puts(V[id]);
    }
}