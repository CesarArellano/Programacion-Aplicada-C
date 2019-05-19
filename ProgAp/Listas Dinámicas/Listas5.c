#include <stdio.h>
#include <stdlib.h>

typedef struct def_Elemento
{
  int dato;
  struct def_Elemento *sig;
  struct def_Elemento *ant;
}TipoElemento;

void InsertaInicio (TipoElemento **Inicio, int numero);
void InsertaFin(TipoElemento **Inicio, int numero);
void ImprimirDerecha(TipoElemento *Inicio);
void ImprimirIzquierda(TipoElemento *Inicio);
void Borrar_Lista(TipoElemento *Inicio);

int main(void)
{
  TipoElemento *Primero=NULL;
  int valor;
  printf("Ingrese numeros (letra para terminar)\n");
  while(scanf("%d",&valor)==1)
    InsertaFin(&Primero,valor);
  printf("Los valores son: \n");
  ImprimirDerecha(Primero);
  ImprimirIzquierda(Primero);
  Borrar_Lista(Primero);  
}

/*void InsertaInicio (TipoElemento **Inicio, int numero)
{
  TipoElemento *temp;
  temp=(TipoElemento *)malloc(sizeof(TipoElemento));
  temp->dato=numero;
  temp->ant=NULL;
  temp->sig=*Inicio;
  if(*Inicio!=NULL)
    *Inicio->ant=temp;
  *Inicio=temp;
  }*/

void InsertaFin(TipoElemento **Inicio, int numero)
{
  TipoElemento *temp, *temp2;
  temp=(TipoElemento *)malloc(sizeof(TipoElemento));
  temp->dato=numero;
  temp->sig=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->sig!=NULL)
	temp2=temp2->sig;
      temp->ant=temp2;
      temp2->sig=temp;
    }
  else
    {
      temp->ant=NULL;
      *Inicio=temp;
    }
}
void ImprimirDerecha(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      printf("%d\n",temp->dato);
      temp=temp->sig;
    }
}
void ImprimirIzquierda(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  while(temp->sig!=NULL)
    {
      temp=temp->sig;
    }
  while(temp!=NULL)
    {
      printf("%d\n",temp->dato);
    temp=temp->ant;
    }
}
void Borrar_Lista(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}
