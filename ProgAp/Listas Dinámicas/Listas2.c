#include <stdio.h>
#include <stdlib.h>

typedef struct def_elemento
{
  int dato;
  float prom;
  struct def_elemento *sig;
} TipoElemento;

void Inserta_Fin(TipoElemento **Inicio, int numero);
void Promedio(TipoElemento *Inicio);
void Imprimir(TipoElemento *Inicio);
void Borrar_Lista(TipoElemento *Inicio);


int main (void)
{
  TipoElemento *Primero=NULL;
  int valor;
  printf("Inserte numeros (letra para terminar)\n");
  while(scanf("%d",&valor)==1)
    Inserta_Fin(&Primero,valor);
  printf("Los valores introducidos son: \n");
  Imprimir(Primero);
  Promedio(Primero);
  Borrar_Lista(Primero);
}

void Inserta_Fin(TipoElemento **Inicio, int numero)
{
  TipoElemento *temp,*temp2;
  temp=(TipoElemento *)malloc(sizeof(TipoElemento));
  temp->dato=numero;
  temp->sig=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->sig!=NULL)
	temp2=temp2->sig;
      temp2->sig=temp;
    }
  else
    *Inicio=temp;
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
void Promedio(TipoElemento *Inicio)
{
  TipoElemento *temp;
  temp=Inicio;
  int i=0;
  float prom=0;
  while(temp!=NULL)
    {
      prom +=temp -> dato;
      i++;
      temp= temp -> sig;
    }
  printf("El promedio de la lista es: %.3f\n", prom / i);
}
