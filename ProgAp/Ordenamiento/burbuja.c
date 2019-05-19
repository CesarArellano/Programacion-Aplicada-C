#include <stdio.h>

void Burbuja(int m[], int elementos);

int main(void)
{
  int m[]={25,2,7,3,67,43,1,15,9,32};
  int i;
  printf("Arreglo original\n");
  for(i=0; i<10; i++)
  printf("%d ", m[i]);
  printf("\n");
  printf("Arreglo ordenado\n");
  Burbuja(m,10);
  for(i=0; i<10; i++)
  printf("%d ", m[i]);
  printf("\n");
}

void Burbuja(int m[], int elementos)
{
  int aux, i, s=1;

  while(s && (--elementos>0))
  {
    s=0;
    for(i=1; i<=elementos; i++)
      if(m[i-1]>m[i])
      {
        aux=m[i-1];
        m[i-1]=m[i];
        m[i]=aux;
        s=1;
      }
  }
}
