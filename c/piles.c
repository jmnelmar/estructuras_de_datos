#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int dato;
  char nombre[30];
  struct node *siguiente;
}node;

node *anteriorNodo=NULL;
void insert_node();
void print_nodes();
void search_node(int id);
int menu();

int main(void){
  int opcion=0;
  opcion=menu();
  system("clear");
  while(opcion!=4){
    system("clear");
    //clrscr();
    if(opcion==1){
      insert_node();
    }
    if(opcion==2){
      int idx;
      printf("Ingrese el ID a busar: ");
      scanf("%d",&idx);
      search_node(idx);
    }
    if(opcion==3){
      print_nodes();
    }

    opcion=menu();
  }
  system("clear");
  return 0;
}

void insert_node(){
  node *nuevoNodo= (node *)malloc(sizeof(node));
  printf("Ingrese el nodo\n");
  printf("ID:");
  scanf("%i",&nuevoNodo->dato);
  printf("nombre:");
  scanf("%s",nuevoNodo->nombre);
  nuevoNodo->siguiente=anteriorNodo;
  anteriorNodo=nuevoNodo;
}

void print_nodes(){
  node *actual= (node *)malloc(sizeof(node));
  actual=anteriorNodo;
  if(anteriorNodo!=NULL){
    printf("Los nodos se listan a continuacion\n");
    while(actual != NULL){
      printf("Id: %d , Nombre: %s\n",actual->dato,actual->nombre);
      actual=actual->siguiente;
    }
  }else{
    printf("La pila esta vacia");
  }
  printf("Precione una tecla para continuar");
  getchar();
  getchar();
}

void search_node(int id){
  node *actual= (node *)malloc(sizeof(node));
  actual=anteriorNodo;
  if(anteriorNodo!=NULL){
    while(actual != NULL){
      if(actual->dato==id){
          printf("El nodo con ID: %i fue encontrado\n",id);
          printf("Id: %d , Nombre: %s\n",actual->dato,actual->nombre);
      }

      actual=actual->siguiente;
    }
  }else{
    printf("El nodo con el ID %i no pude ser encontrado.",id);
  }
  printf("Precione una tecla para continuar");
  getchar();
  getchar();
}

int menu(){
  system("clear");
  int opcion;
  printf("Bienvenido\n");
  printf("1 - Insertar un nodo.\n");
  printf("2 - Buscar un nodo.\n");
  printf("3 - Ver todos los nodos.\n");
  printf("4 - Salir.\n");
  printf("Seleccione una opcion: ");
  scanf("%i",&opcion);
  return opcion;
}
