#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
 int ProductoID;        //Numerado en ciclo iterativo
 int Cantidad;          // entre 1 y 10
 char *TipoProducto;    // Algún valor del arreglo TiposProductos
 float PrecioUnitario;  // entre 10 - 100
}Producto;

typedef struct {
int ClienteID;                  // Numerado en el ciclo iterativo
char *NombreCliente;            // Ingresado por usuario
int CantidadProductosAPedir;    // (aleatorio entre 1 y 5)
Producto *Productos;            //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}Cliente;

float CostoTotalProducto(Producto P);

int main(){
    srand(time(NULL));

    int cant, i, longitud, j;
    float suma;
    char nombre[20];

    printf("Ingrese la cantidad de clientes a cargar: ");
    scanf("%d",&cant);
    fflush(stdin);

    Cliente *C;
    C = (Cliente *)malloc(cant * sizeof(Cliente));

    //cargar datos de los clientes
    for(i=0;i<cant;i++){
        //cargar nombre
        printf("Ingrese el nombre del cliente numero %d: ",i+1);
        gets(nombre);

            longitud = strlen(nombre);
            C[i].NombreCliente = (char *)malloc((longitud + 1) * sizeof(char));
            strcpy(C[i].NombreCliente,nombre);

        //id,cant productos
        C[i].ClienteID = i;
        C[i].CantidadProductosAPedir = rand()%5 + 1;

        //cargar productos
        C[i].Productos = (Producto *)malloc(C[i].CantidadProductosAPedir * sizeof(Producto));
        for(j=0;j<C[i].CantidadProductosAPedir;j++){
            C[i].Productos[j].ProductoID = j;
            C[i].Productos[j].Cantidad = rand()%10 + 1;
            C[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            C[i].Productos[j].PrecioUnitario = 10 + rand()%91;
        }
    }


    //mostrar
    for(i=0;i<cant;i++){
        suma = 0;

        printf("\n///======== Cliente numero %d ========///",i+1);
        printf("\nId: %d",C[i].ClienteID);
        printf("\nNombre: ");
        puts(C[i].NombreCliente);
        printf("Cantidad de productos distintos: %d",C[i].CantidadProductosAPedir);

        printf("\n--------Lista de productos--------");
        for(j=0;j<C[i].CantidadProductosAPedir;j++){

            printf("\n\tProducto numero %d",j+1);
            printf("\nId del producto: %d",C[i].Productos[j].ProductoID);
            printf("\nTipo de producto: ");
                puts(C[i].Productos[j].TipoProducto);
            printf("Cantidad: %d",C[i].Productos[j].Cantidad);
            printf("\nPrecio Unitario: %.2f",C[i].Productos[j].PrecioUnitario);

            suma = suma + CostoTotalProducto(C[i].Productos[j]);
        }
        printf("\n----------------------------------");
        printf("\nTOTAL A PAGAR: %.2f",suma);
        printf("\n///===================================///\n");
    }

    //Liberar Memoria
    for(i=0;i<cant;i++){
        free(C[i].NombreCliente);
        free(C[i].Productos);
    }
    free(C);

    return 0;
}

//FUNCIONES
float CostoTotalProducto(Producto P){
    float total;
    total = P.Cantidad * P.PrecioUnitario;
    return total;
}