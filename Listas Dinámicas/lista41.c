#include <stdio.h>
#include <stdlib.h>

typedef struct def_elemento
{
  int dato;
  struct def_elemento *ant;
  struct def_elemento *sig;
} TipoElemento;

void Inserta_Fin(TipoElemento **Inicio, int numero);
void Inserta_Inicio(TipoElemento **Inicio, int numero);
void ImprimirDerecha(TipoElemento *Inicio);
void ImprimirIzquierda(TipoElemento *Inicio);
void Imprimir(TipoElemento *Inicio);
void Borrar_Lista(TipoElemento *Inicio);

int main (void)
{
  TipoElemento *Primero=NULL;
  int valor,Opcion,Verificado=0;
  do {
      system("clear");
      printf("Menú\n\n");
      printf("1.- Insertar Número Inicio.\n");
      printf("2.- Inserta Número Fin\n");
      printf("3.- Imprimir Derecha.\n");
      printf("4.- Imprimir Izquierda.\n");
      printf("5.- Salir.\n\n");
      printf("Ingresa la opción a usar\n");
      scanf(" %d", &Opcion);
      switch(Opcion)
      {
        case 1:
        system("clear");
        printf("¿Qué número desea insertar?\n");
        if(scanf(" %d", &valor)==1);
        Inserta_Inicio(&Primero,valor);
        printf("\nPresione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 2:
        system("clear");
        printf("¿Qué número desea insertar?\n");
        if(scanf(" %d", &valor)==1);
        Inserta_Fin(&Primero,valor);
        printf("\nPresione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 3:
        system("clear");
        printf("Número en lista: \n");
        ImprimirDerecha(Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 4:
        system("clear");
        printf("Número en lista: \n");
        ImprimirIzquierda(Primero);
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
        case 5:
        Borrar_Lista(Primero);
        printf("Saliendo del programa...\n");
        Verificado=1;
        break;
        default:
        printf("Opción errónea, inténtelo de nuevo\n");
        printf("Presione enter para continuar\n");
        __fpurge(stdin);
        getchar();
        break;
      }
  } while(Verificado==0);
}

void Inserta_Inicio (TipoElemento **Inicio, int numero)
{
  TipoElemento *temp;
  temp=(TipoElemento *)malloc(sizeof(TipoElemento));
  temp->dato=numero;
  temp->ant=NULL;
  temp->sig=*Inicio;
  if(*Inicio!=NULL)
    (*Inicio)->ant=temp;
  (*Inicio)=temp;
}

void Inserta_Fin(TipoElemento **Inicio, int numero)
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
  if(Inicio==NULL)
  {
    printf("No hay elementos en la lista\n");
  }
  else
  {
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
