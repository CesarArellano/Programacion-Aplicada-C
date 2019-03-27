#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int num;
  struct nodo *izq, *der;
} TipoNodo;

void Inserta(TipoNodo **Raiz, int numero);
void Imprime(TipoNodo *Raiz);
void Borrar(TipoNodo *Raiz);

int main (void)
{
  int numero;
  TipoNodo *Raiz=NULL;
  printf("Teclea enteros, seguido por un caracter no numérico\n");
  while(scanf(" %d", &numero)==1)
    Inserta(&Raiz,numero);
  printf("Números impresiones en orden\n");
  Imprime(Raiz);
  Borrar(Raiz);
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
