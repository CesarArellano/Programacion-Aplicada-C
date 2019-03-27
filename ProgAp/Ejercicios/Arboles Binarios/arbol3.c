#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  char letra;
  struct nodo *izq, *der;
} TipoNodo;

void Inserta(TipoNodo *Raiz, TipoNodo *Elemento);
void Imprime(TipoNodo *Raiz);
void Borrar(TipoNodo *Raiz);

int main (void)
{
  system("clear");
  char Letra;
  TipoNodo *Raiz=NULL, *Elemento;
  printf("Teclea letras, seguido por un caracter numérico\n");
  do
  {
    scanf(" %c", &Letra);
    {
      Elemento=(TipoNodo *) malloc(sizeof(TipoNodo));
      Elemento->letra=Letra;
      Elemento->izq=NULL;
      Elemento->der=NULL;
      if((Letra>='a' && Letra<='z') || (Letra>='A' && Letra<='Z'))
      {
        if(Raiz==NULL)
          Raiz=Elemento;
        else
          Inserta(Raiz,Elemento);
      }
    }
  }while ((Letra>='a' && Letra<='z') || (Letra>='A' && Letra<='Z'));
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
    if(Elemento->letra > Avanza->letra)
    {
      if(Avanza->der !=NULL)
        Inserta(Avanza->der,Elemento);
      else
      {
        Avanza->der= Elemento;
        return;
      }
    }
    if (Elemento->letra <= Avanza->letra)
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
    printf("%c\n",Raiz->letra);
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
