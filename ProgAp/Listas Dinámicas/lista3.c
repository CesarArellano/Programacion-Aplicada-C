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
  int valor,Opcion,Verificado=0;
  do {
      system("clear");
      printf("Menú\n\n");
      printf("1.- Insertar Número.\n");
      printf("2.- Mostrar Número.\n");
      printf("3.- Salir.\n\n");
      printf("Ingresa la opción a usar\n");
      scanf(" %d", &Opcion);
      switch(Opcion)
      {
        case 1:
        system("clear");
        printf("¿Qué número desea insertar?\n");
        if(scanf(" %d", &valor)==1);
        Ordenar(&Primero,valor);
        printf("\nPresione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 2:
        system("clear");
        printf("Número en lista: \n");
        Imprimir(Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 3:
        Borrar_Lista(Primero);
        printf("Saliendo del programa...\n");
        Verificado=1;
        break;
        default:
        printf("Opción errónea, inténtelo de nuevo\n");
        break;
      }
  } while(Verificado==0);
}

void Ordenar(TipoElemento **Inicio, int numero)
{
  TipoElemento *pos, *temp2, *nuevo;
  nuevo=(TipoElemento *)malloc(sizeof(TipoElemento));
  nuevo->dato=numero;
  pos=*Inicio;
  while((pos!=NULL)&&(numero>pos->dato))
    pos=pos->sig;

  if(pos==NULL)
      Inserta_Fin(Inicio,nuevo);
  else
  {
    if(pos==*Inicio)
      Inserta_Inicio(Inicio,nuevo);
    else
      {
        temp2=*Inicio;
    	  while(temp2->sig!=pos)
    	    temp2=temp2->sig;
    	  nuevo->sig=pos;
    	  temp2->sig=nuevo;
      }

  }
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
