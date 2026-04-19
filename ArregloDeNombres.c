#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIONES
void MostrarPersonas(char *V[]);

int BuscarNombre(char *V[], char palabra[]);

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
        //puts(V[i]);
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

int BuscarNombre(char *V[], char palabra[]){
    int i;
    for(i=0;i<5;i++){
        if (strstr(V[i],palabra) != NULL){
            return (i);
        }
    }
    return(-1);
}