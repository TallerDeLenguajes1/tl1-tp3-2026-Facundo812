#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIONES
void MostrarPersonas(char *V[]);

int BuscarNombrePorPalabra(char *V[], char palabra[]);

void BuscarNombrePorId(char *V[], int id);

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

    int opcionElegida;
    printf("\n\n----SELECCION----\n");
    printf("Opcion 1: Buscar por ID (ingrese 1)\nOpcion 2:Buscar por Palabra (ingrese 2)\nSeleccione una Opcion: ");
    scanf("%d",&opcionElegida);
    fflush(stdin);
        if(opcionElegida == 1){
            int id;
            printf("\nIngrese un ID (numero de 0 a 4): ");
            scanf("%d",&id);
            BuscarNombrePorId(V,id);
        }
        else if(opcionElegida == 2){
            char palabra[20];
            printf("\nIngrese la palabra buscada: ");
            gets(palabra);
                int resultado = BuscarNombrePorPalabra(V,palabra);
            
                if(resultado == -1){
                    printf("\n----No se encontro----");
                }
                else{
                    printf("\nResultado: ");
                    puts(V[resultado]);
                }
        }
        else{
            printf("\n----No se eligio ninguna opcion----");
        }
    
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

int BuscarNombrePorPalabra(char *V[], char palabra[]){
    int i;
    for(i=0;i<5;i++){
        if (strstr(V[i],palabra) != NULL){
            return (i);
        }
    }
    return(-1);
}

void BuscarNombrePorId(char *V[], int id){
    if (id > 4 || id < 0){
        printf("\n----no se encontro el valor buscado----\n");
    }
    else{
        printf("\nNombre ubicado en la posicion %d: ",id);
        puts(V[id]);
    }
}