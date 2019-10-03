#include <stdio.h>

void Insercion(int m[], int elementos);

int main(void)
{
  int m[]={25,2,7,3,67,43,1,15,9,32};
  int i;
  printf("Arreglo original\n");
  for(i=0; i<10; i++)
  printf("%d ", m[i]);
  printf("\n");
  printf("Arreglo ordenado\n");
  Insercion(m,10);
  for(i=0; i<10; i++)
  printf("%d ", m[i]);
  printf("\n");
}

void Insercion(int m[], int elementos)
{
  int i, k, x;
  //desde el segundo elemento.
  for(i=1; i<elementos; i++)
  {
    x=m[i];
    k=i-1;
    while (k>=0 && x<m[k])
    {
      m[k+1]=m[k]; //hacer espacio para insertar
      k--;
    }
    m[k+1]=x;
  }
}
