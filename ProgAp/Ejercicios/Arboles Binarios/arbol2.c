#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int num;
  struct nodo *izq, *der;
} TipoNodo;

void Inserta(TipoNodo *Raiz, TipoNodo *Elemento);
void Imprime(TipoNodo *Raiz);
void Borrar(TipoNodo *Raiz);

int main (void)
{
  int numero;
  TipoNodo *Raiz=NULL, *Elemento;
  printf("Teclea enteros, seguido por un caracter no numérico\n");
  while(scanf(" %d", &numero)==1)
  {
    Elemento=(TipoNodo *) malloc(sizeof(TipoNodo));
    Elemento->num=numero;
    Elemento->izq=NULL;
    Elemento->der=NULL;
    if(Raiz==NULL)
      Raiz=Elemento;
    else
      Inserta(Raiz,Elemento);
  }
  printf("Números impresiones en orden\n");
  Imprime(Raiz);
  Borrar(Raiz);
}
void Inserta(TipoNodo *Raiz, TipoNodo *Elemento)
{
  TipoNodo *Avanza;
  Avanza=Raiz;
  if (Avanza!=NULL)
  {
    if(Elemento->num > Avanza->num)
    {
      if(Avanza->der !=NULL)
        Inserta(Avanza->der,Elemento);
      else
      {
        Avanza->der= Elemento;
        return;
      }
    }
    if (Elemento->num <= Avanza->num)
    {
      if(Avanza->izq !=NULL)
        Inserta(Avanza->izq,Elemento);
      else
      {
        Avanza->izq= Elemento;
        return;
      }
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
