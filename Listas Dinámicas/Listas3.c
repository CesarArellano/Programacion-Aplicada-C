#include <stdio.h>
#include <stdlib.h>

typedef struct def_elemento
{
  int dato;
  float prom;
  struct def_elemento *sig;
} TipoElemento;

void Inserta_Fin(TipoElemento **Inicio, int numero);
void Buscar_Num(TipoElemento *Inicio, int Buscar);
void Borrar_Lista(TipoElemento *Inicio);

int main (void)
{
  TipoElemento *Primero=NULL;
  int valor,buscnum;
  printf("Inserte numeros (letra para terminar)\n");
  while(scanf("%d",&valor)==1)
    Inserta_Fin(&Primero,valor);
  printf("Ingresa el número a buscar: \n");
  __fpurge(stdin);
  scanf("%d",&buscnum);
  Buscar_Num(Primero,buscnum);
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

void Buscar_Num(TipoElemento *Inicio, int Buscar)
{
  TipoElemento *temp;
  temp=Inicio;
  int veces=0;
  while(temp!=NULL)
    {
      if(Buscar==temp->dato)
      veces++;
      temp=temp->sig;
    }
  if(veces>=1)
    printf("El numero se encontró %d vez/veces en la lista\n", veces);
  else
    printf("No se encontró el número \n");
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
