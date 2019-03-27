#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int num;
  struct nodo *izq, *der;
} TipoNodo;

void Inserta(TipoNodo **Raiz, int numero);
void Eliminar(TipoNodo **Nodo);
void Imprime(TipoNodo *Raiz);
void Borrar(TipoNodo *Raiz);

int main (void)
{
  int numero,Opcion,Salir=0;
  TipoNodo *Raiz=NULL;
  do
  {
    printf("Menú Árbol Binario:\n");
    printf("1.- Insertar número\n");
    printf("2.- Borrar número\n");
    printf("3.- Imprimir Árbol\n");
    printf("4.- Salir\n");
    printf("Escoga una opción\n");
    scanf(" %d", &Opcion);
    switch(Opcion)
    {
      case 1:
      printf("Teclea enteros, seguido por un caracter no numérico\n");
      Inserta(&Raiz,numero);
      break;
      case 2:
      break;
      case 3:
      printf("Números, impresion en orden:\n");
      Imprime(Raiz);
      break;
      case 4:
      Salir=1;
      break;
    }

  } while(Salir==1);
  Borrar(Raiz);
  printf("Gracias por utilizar el programa\n");
}

void Inserta(TipoNodo **Raiz, int numero)
{
  TipoNodo *Avanza, *Nuevo;
  Avanza=*Raiz;
  if((Nuevo=(TipoNodo *) malloc(sizeof(TipoNodo)))==NULL)
  {
    printf("No hay memoria\n");
    exit(1);
  }
  Nuevo->num=numero;
  Nuevo->izq=NULL;
  Nuevo->der=NULL;

  while (Avanza!=NULL)
  {
    if(numero > Avanza->num)
    {
      if(Avanza->der !=NULL)
        Avanza= Avanza->der;
      else
      {
        Avanza->der= Nuevo;
        return;
      }
    }
    if (numero <= Avanza->num)
    {
      if(Avanza->izq !=NULL)
        Avanza= Avanza->izq;
      else
      {
        Avanza->izq= Nuevo;
        return;
      }
    }
  }
  Avanza=Nuevo;
  *Raiz=Avanza;
}

void Eliminar(TipoNodo **Nodo)
{
  int numero,Verificado=0;
  TipoNodo *temp;
  temp= *Nodo;
  temp2= *Nodo;
  printf("Ingrese el número a insertar\n");
  scanf(" %d", &numero);
  while (temp!=NULL && Verificado==0)
  {
    if(temp->num==numero)
    {
      if(temp->izq==NULL && temp->der==NULL) // Dos lados NULL
      {
        free(temp);
        Verificado=1;
      }
      if(temp->izq==NULL && temp->der!=NULL) // Lado Izquierdo NULL
      {
        while(temp2->izq!=temp && temp2->der!=temp)
        {
          if(temp2->izq==temp)
          {
            temp2->izq = temp->der;
            free(temp);
            Verificado=1;
          }
          else
          {
            temp2->der = temp->der;
            free(temp);
            Verificado=1;
          }
            Eliminar(Raiz->izq);
            Eliminar(Raiz->der);
        }
      }
      else // Lado Derecha NULL
      {
        while(temp2->izq!=temp && temp2->der!=temp)
        {
          if(temp2->izq==temp)
          {
            temp2->izq = temp->izq;
            free(temp);
            Verificado=1;
          }
          else
          {
            temp2->der = temp->izq;
            free(temp);
            Verificado=1;
          }
            Eliminar(Raiz->izq);
            Eliminar(Raiz->der);
        }
      }
      if(temp->izq!=NULL && temp->der!=NULL)
      {
        temp2=temp->der;
        while(temp2!=NULL)
        {
          
        }
        Verificado=1;
      }

    }
    else
    {
      Eliminar(Raiz->izq);
      Eliminar(Raiz->der);
    }
  }

}

void Imprime(TipoNodo *Raiz)
{
  if(Raiz!=NULL)
  {
    Imprime(Raiz->izq);
    printf("%d\n",Raiz->num);
    Imprime(Raiz->der);
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
