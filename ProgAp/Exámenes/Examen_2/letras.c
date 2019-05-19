#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_Arbol
{
  char Letra;
  struct def_Arbol *izq,*der;
}TipoNodo;

void Insertar_Arbol(TipoNodo **Raiz, char Letra);
void Imprimir_Arbol(TipoNodo *Raiz);
void Num_Nodos(TipoNodo *Raiz, int *Nodos);
void AlturaArbol(TipoNodo *Raiz, int *Altura);
void Calcular_Alt(TipoNodo *Raiz, int Contador, int *Altura);
void Num_Hojas(TipoNodo *Raiz, int *Hojas);
void Borrar(TipoNodo *Raiz);

int main (void)
{
  TipoNodo *Raiz=NULL, *Elemento;
  FILE *Archivo;
  char Nombre_Arch[50],Renglon[200],Letra;
  int Opcion=0, Nodos=0, Altura=0, Hojas=0;
  system("clear");
  printf("Escriba el nombre del archivo\n");
  gets(Nombre_Arch);
  Archivo = fopen(Nombre_Arch,"rt");
  if(Archivo==NULL)
    {
      printf("El archivo no existe\n");
      printf("Saliendo del programa...");
      exit(0);
    }
  else
    {
      while(fgets(Renglon,100,Archivo)!=NULL)
	{
	  Renglon[strlen(Renglon)-1]='\0';
	  for(int i=0; Renglon[i]!='\0'; i++)
	    {
	      if((Renglon[i]>= 'A' && Renglon[i]<= 'Z') || (Renglon[i]>= 'a' && Renglon[i]<= 'z'))
		{
		  Letra=Renglon[i];
		  Insertar_Arbol(&Raiz,Letra);
		  Opcion=1;
		}
	    }
	}
      if(Opcion==0)
	{
	  printf("No hay letras en el documento, intentelo de nuevo\n");
	  printf("Saliendo del programa\n");
	  exit(0);
	}
    }
  printf("El árbol se ha creado éxitosamente.\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  
  do
    {
      system("clear");
      printf("Menú:\n");
      printf("1.- Imprimir en orden\n");
      printf("2.- Número de nodos\n");
      printf("3.- Altura del árbol\n");
      printf("4.- Número de hojas\n");
      printf("5.- Salir\n\n");
      printf("Escoge una opción:\n");
      scanf(" %d", &Opcion);
      system("clear");
      switch(Opcion)
	{
	case 1:
	  printf("Impresion en Orden:\n");
	  Imprimir_Arbol(Raiz);
	  break;
	case 2:
	  Num_Nodos(Raiz,&Nodos);
	  printf("El número de nodos que hay en el árbol es: %d\n",Nodos);
	  Nodos=0;
	  break;
	case 3:
	  AlturaArbol(Raiz,&Altura);
	  printf("La altura del árbol es: %d\n",Altura);
	  Altura=0;
	  break;
	case 4:
	  Num_Hojas(Raiz,&Hojas);
	  printf("El número de hojas que hay en el arból es: %d\n",Hojas);
	  Hojas=0;
	  break;
	case 5:
	  printf("Saliendo del programa...\n");
	  Borrar(Raiz);
	  exit(0);
	  break;
	default:
	  printf("Opción Inválida\n");
	  break;
	}
      printf("Presione Enter para continuar...\n");
      __fpurge(stdin);
      getchar();  
    } while(Opcion!=5);
  
}

void Insertar_Arbol(TipoNodo **Raiz, char Letra)
{
  TipoNodo *avanza, *nuevo;

  avanza = *Raiz;
  if((nuevo=(TipoNodo *)malloc(sizeof(TipoNodo)))==NULL)
    {
      printf("No hay memoria\n");
      exit(0);
    }
  nuevo->Letra=Letra;
  nuevo->izq=NULL;
  nuevo->der=NULL;

  while(avanza != NULL)
    {
      if(Letra > avanza->Letra) //muevete a la derecha
	{
	  if(avanza->der != NULL)
	    avanza = avanza->der;
	  else
	    {
	      avanza->der=nuevo;
	      return;
	    }
	}
      if(Letra <= avanza->Letra) //muevete a la izquierda
	{
	  if(avanza->izq != NULL)
	    avanza = avanza->izq;
	  else
	    {
	      avanza->izq = nuevo;
	      return;
	    }
	}
    }
  avanza = nuevo;
  *Raiz = avanza;
}

void Imprimir_Arbol(TipoNodo *Raiz)
{
  if(Raiz!=NULL)
  {
    Imprimir_Arbol(Raiz->izq);
    printf("%c\n",Raiz->Letra);
    Imprimir_Arbol(Raiz->der);
  }
}

void Num_Nodos(TipoNodo *Raiz, int *Nodos)
{
  if(Raiz!=NULL)
  {
    Num_Nodos(Raiz->izq,Nodos);
    (*Nodos)++;
    Num_Nodos(Raiz->der,Nodos);
  }
}

void AlturaArbol(TipoNodo *Raiz, int *Altura)
{
  int Contador=1;
  (*Altura)=0; 
  Calcular_Alt(Raiz,Contador,Altura);
}
void Calcular_Alt(TipoNodo *Raiz, int Contador, int *Altura)
{
  if(Raiz->izq!=NULL)
    Calcular_Alt(Raiz->izq,Contador+1,Altura);
  if(Raiz->der!=NULL)
    Calcular_Alt(Raiz->der,Contador+1,Altura);

  if((Raiz->izq==NULL && Raiz->der==NULL) && Contador > *Altura)
    (*Altura)= Contador;
  
}
void Num_Hojas(TipoNodo *Raiz, int *Hojas)
{
  if(Raiz!=NULL)
  {
    if(Raiz->izq==NULL && Raiz->der==NULL)
      (*Hojas)++;
    Num_Hojas(Raiz->izq,Hojas);
    Num_Hojas(Raiz->der,Hojas);
  }
}
void Borrar(TipoNodo *Raiz)
{
  if(Raiz!=NULL)
  {
    Borrar(Raiz->izq);
    Borrar(Raiz->der);
    free(Raiz);
  }
}
