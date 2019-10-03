#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int num;
  struct nodo *izq, *der;
} TipoNodo;

void Inserta(TipoNodo **Raiz, int numero);
void Imprime(TipoNodo *Raiz);
void Cambiar(TipoNodo **Raiz, TipoNodo **temp);
void Eliminar(TipoNodo **Raiz, int numero);
void Borrar(TipoNodo *Raiz);

int main (void)
{
  int numero,Opcion,Salir=0;
  TipoNodo *Raiz=NULL;
  do
  {
  	system("clear");
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
      scanf(" %d",&numero);
      Inserta(&Raiz,numero);
      break;
      case 2:
	  printf("Ingrese el número a eliminar\n");
  	  scanf(" %d", &numero);
      Eliminar(&Raiz,numero);
      break;
      case 3:
      printf("Números, impresion en orden:\n");
      Imprime(Raiz);
      getchar();
 	  getchar();
      break;
      case 4:
      Salir=1;
      break;
    }

  } while(Salir==0);
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

void Eliminar(TipoNodo **Raiz, int numero)
{
  TipoNodo *temp;

  if (*Raiz == NULL)
    return;

  if ((*Raiz)->num < numero)
    Eliminar(&(*Raiz)->der, numero);
  else if ((*Raiz)->num > numero)
    Eliminar(&(*Raiz)->izq, numero);
  else if ((*Raiz)->num == numero)
  {
    temp = *Raiz;
    if ((*Raiz)->izq == NULL)
      *Raiz = (*Raiz)->der;
    else if ((*Raiz)->der == NULL)
      *Raiz = (*Raiz)->izq;
    else
      Cambiar(&(*Raiz)->izq, &temp);
    free(temp);
  }
}

void Cambiar(TipoNodo **Raiz, TipoNodo **temp)
{
  if ((*Raiz)->der == NULL)
  {
    (*temp)->num = (*Raiz)->num;
    *temp = *Raiz;
    *Raiz = (*Raiz)->izq;
  }
  else
    Cambiar(&(*Raiz)->der, temp);
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
