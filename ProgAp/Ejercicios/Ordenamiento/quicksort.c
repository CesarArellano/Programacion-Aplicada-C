#include <stdio.h>
#define SIZE 10

int Particion(int Arreglo[], int l, int r);
void QuickSort(int Arreglo[], int l, int r);

int main(void)
{
  int Arreglo[SIZE], i;
  for(i=0; i<SIZE;i++)
  {
    printf("Ingrese el elemento %d:\n",i+1);
    scanf(" %d", &Arreglo[i]);
  }
  QuickSort(Arreglo,0,9);
  printf("Despues del QuickSort de elementos\n");
  for(i=0; i<SIZE;i++)
    printf("%d\t",Arreglo[i]);
  printf("\n");
  getchar();
}

void QuickSort(int Arreglo[], int l, int r)
{
  int j;
  if(l < r) //dividir
  {
    j= Particion(Arreglo,l,r);
    QuickSort(Arreglo,l,j-1);
    QuickSort(Arreglo,j+1,r);
  }
}

int Particion(int Arreglo[], int l, int r)
{
  int pivote, i,j,t;
  pivote = Arreglo[l];
  i = l;
  j = r+1;
  while(1)
  {
    do
      ++i;
    while((Arreglo[i] <= pivote) && (i <= r));
    do
      --j;
    while(Arreglo[j]> pivote);
    if(i >= j)
      break;
      t= Arreglo[i];
      Arreglo[i]= Arreglo[j];
      Arreglo[j]= t;
  }
  t= Arreglo[l];
  Arreglo[l]= Arreglo[j];
  Arreglo[j]= t;
  return j;
}
