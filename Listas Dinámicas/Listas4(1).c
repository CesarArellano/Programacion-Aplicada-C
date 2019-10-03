#include <stdio.h>
#include <stdlib.h>

typedef struct def_elemento
{
  int dato;
  struct def_elemento *sig;
} TipoElemento;

void Inserta_Fin(TipoElemento **Inicio, TipoElemento *nuevo);
void Inserta_Inicio(TipoElemento **Inicio, TipoElemento *nuevo);
void Ordenar(TipoElemento **Inicio, int numero);
void Imprimir(TipoElemento *Inicio);
void Borrar_Lista(TipoElemento *Inicio);

int main (void)
{
  TipoElemento *Primero=NULL;
  int valor;
  printf("Inserte numeros (letra para terminar)\n");
  while(scanf("%d",&valor)==1)
    Ordenar(&Primero,valor);  
  Imprimir(Primero);
  Borrar_Lista(Primero);
}

void Inserta_Inicio(TipoElemento **Inicio, TipoElemento *nuevo)
{
   nuevo->sig=*Inicio;
  *Inicio=nuevo;
}

void Inserta_Fin(TipoElemento **Inicio, TipoElemento *nuevo)
{
  TipoElemento *temp2;
  nuevo->sig=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->sig!=NULL)
	temp2=temp2->sig;
      temp2->sig=nuevo;
    }
  else
    *Inicio=nuevo;
}
void Ordenar(TipoElemento **Inicio, int numero)
{
  TipoElemento *temp, *temp2, *nuevo;
  nuevo=(TipoElemento *)malloc(sizeof(TipoElemento));
  nuevo->dato=numero;
  temp=*Inicio;
  while((temp!=NULL)&&(numero>temp->dato))
    temp=temp->sig;
  
  if(temp!=NULL)
    {
      if(temp!=*Inicio)
	{
	  temp2=*Inicio;
	  while(temp2->sig!=temp)
	    temp2=temp2->sig;
	  nuevo->sig=temp;
	  temp2->sig=nuevo;
	}
      else
	Inserta_Inicio(Inicio,nuevo);
    }
  else
    Inserta_Fin(Inicio,nuevo);
}


void Imprimir(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      printf("%d\n",temp->dato);
      temp=temp->sig;
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
