#include <stdio.h>

#define SIZE 10

void Seleccion(int Arreglo[]);

int main(void)
{
  int Arreglo[SIZE], i;
  for(i=0; i<SIZE;i++)
  {
    printf("Ingrese el elemento %d:\n",i+1);
    scanf(" %d", &Arreglo[i]);
  }
  Seleccion(Arreglo);
  printf("Despues de la seleccion de elementos\n");
  for(i=0; i<SIZE;i++)
    printf("%d\t",Arreglo[i]);
  printf("\n");
  getchar();
}

void Seleccion(int Arreglo[])
{
  int i,j,min,temp;
  for(i=0; i<SIZE; i++)
  {
    min=i;
    for(j=i+1; j<SIZE; j++)
        if(Arreglo[j]<Arreglo[min])
          min=j;
    temp= Arreglo[i];
    Arreglo[i]=Arreglo[min];
    Arreglo[min]=temp;
  }
}
